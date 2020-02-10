package game;

import java.awt.*;
import java.awt.image.BufferStrategy;
import game.display.Display;
import game.gfx.Assets;
import game.input.KeyManager;
import game.input.MouseManager;
import game.states.GameState;
import game.states.HelpState;
import game.states.MenuState;
import game.states.NextState;
import game.states.State;

public class Game implements Runnable{
	
	private Display display;
	public int width, height;
	public String title;
	
	private boolean running = false;
	private Thread thread;
	
	private BufferStrategy bs;
	private Graphics g;
	
	//private BufferedImage testImage;
	//private BufferedImage test;
	//private SpriteSheet sheet;
	
	//States
	public State gameState;
	public State menuState;
	public State helpState;
	public State nextState;
	
	//Input
	private KeyManager keyManager;
	private MouseManager mouseManager;
	
	//Handler
	private Handler handler, handler1;
	
	
	public Game(String title, int width, int height){
		this.width = width;
		this.height = height;
		this.title = title;
		keyManager = new KeyManager();
		mouseManager = new MouseManager();
	}
	
	private void init(){
		display = new Display(title, width, height);
		display.getFrame().addKeyListener(keyManager);
		display.getFrame().addMouseListener(mouseManager);
		display.getFrame().addMouseMotionListener(mouseManager);
		
		display.getCanvas().addMouseListener(mouseManager);
		display.getCanvas().addMouseMotionListener(mouseManager);
		Assets.init();
		
		handler = new Handler(this);
		//testImage = ImageLoader.LoadImage("/textures/iepuras.png");
		//test = ImageLoader.LoadImage("/textures/iepuras.png");
		//sheet = new SpriteSheet(test);
		
		
		nextState = new NextState(handler);
		gameState = new GameState(handler);
		helpState = new HelpState(handler);
		menuState = new MenuState(handler);
		//helpState = new HelpState(handler);
		State.setState(menuState);
	}
	
	
	private void tick(){
		keyManager.tick();
		
		if (State.getState() != null)
			State.getState().tick();
	}
	private void render(){
		bs = display.getCanvas().getBufferStrategy();
		if (bs == null){
			display.getCanvas().createBufferStrategy(3);
			return;
		}
		g = bs.getDrawGraphics();
		//Clear Screen
		g.clearRect(0, 0, width, height);
		// Draw Here!
		
		if (State.getState() != null)
			State.getState().render(g);
		
		//g.drawImage(Assets.grass, x, 20, null);
		
		//g.setColor(Color.red);
		//g.fillRect(10, 50, 50, 70);
		//g.setColor(Color.green);
		//g.drawRect(0, 0, 100, 100);
		
		//g.drawImage(testImage, 20, 20, null);
		//g.drawImage(sheet.crop(0, 0, 100, 100), 5, 5, null);
		
		
		
		//End Drawing
		
		bs.show();
		g.dispose();
	}
	
	public void run(){
		
		init();
		
		int fps = 60;
		double timePerTick = 1000000000 / fps;
		double delta = 0;
		long now;
		long lastTime = System.nanoTime();
		long timer = 0;
		int ticks = 0;
		
		while(running){
			now = System.nanoTime();
			delta += (now - lastTime) / timePerTick;
			timer += now-lastTime;
			lastTime = now;
			
			if (delta>=1){
				tick();
				render();
				ticks++;
				delta--;
			}
			
			if (timer>=1000000000){
				System.out.println("Ticks" + ticks);
				ticks = 0;
				timer = 0;
			}
		}
		stop();
		
	}
	
	public synchronized void start(){
		if (running)
			return;
		running = true;
		thread = new Thread(this);
		thread.start();
	}
	
	public KeyManager getKeyManager(){
		return keyManager;
	}
	public MouseManager getMouseManager(){
		return mouseManager;
	}
	
	public int getWidth(){
		return width;
	}
	
	public int getHeight(){
		return height;
	}
	
	public synchronized void stop(){
		if (!running)
			return;
		running = false;
		try {
			thread.join();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		
	}

}

package game.entities.creatures;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Rectangle;
import java.awt.image.BufferedImage;

import game.Game;
import game.Handler;
import game.entities.Entity;
import game.gfx.Animation;
import game.gfx.Assets;
import game.states.State;
import game.worlds.World;

public class Player extends Creature{
	
	//Animation
	private Animation animRight, animLeft, animUp, animDown;

	public Player(Handler handler, float x, float y, int viata, int bani) {
		super(handler, x, y, Creature.DEFAULT_CREATURE_WIDTH, Creature.DEFAULT_CREATURE_HEIGHT, viata, bani);
		
		bounds.x = 24;
		bounds.y = 24;
		bounds.width = 16;
		bounds.height = 16;
		
		//Animation
		animRight = new Animation(100, Assets.player_right);
		animLeft = new Animation(100, Assets.player_left);
		animUp = new Animation(100, Assets.player_up);
		animDown = new Animation(100, Assets.player_down);
	}

	@Override
	public void tick() {
		
		if (viata<0 || bani<0) {
			viata = 50;
			bani = 50;
			State.setState(handler.getGame().menuState);
		}
		
		//Animations
		animRight.tick();
		animLeft.tick();
		animUp.tick();
		animDown.tick();
		
		
		
		//Movement
		getInput();
		move();
		//Attack
		checkAttacks();
	}
	
	private void checkAttacks(){
		int ok=0;
		Rectangle cb = getCollisionBounds(0, 0);
		//Rectangle ar = new Rectangle();
		//int arSize = 64;
		
		//ar.width = arSize;
		//ar.height = arSize;
		
		/*if (handler.getKeyManager().aUp){
			ar.x = cb.x + cb.width / 2 - arSize / 2;
			ar.y = cb.y - arSize;
		} else 	if (handler.getKeyManager().aDown){
			ar.x = cb.x + cb.width / 2 - arSize / 2;
			ar.y = cb.y + cb.height;
		} else	if (handler.getKeyManager().aLeft){
			ar.x = cb.x - arSize;
			ar.y = cb.y + cb.height / 2 - arSize /2;
		} else	if (handler.getKeyManager().aRight){
				ar.x = cb.x + cb.width;
				ar.y = cb.y + cb.height / 2 - arSize /2;
		} else return;
		*/
		
		for (Entity e : handler.getWorld().getEntityManager().getEntities()){
			if (e.equals(this))
				continue;
			if (e.getCollisionBounds(0, 0).intersects(cb) && e.active == true){
				viata = viata + e.viata;
				bani = bani + e.bani;
				e.active = false;
				return;
			}
		}
		
	}
	
	public void die(){
		
	}
	
	public void getInput(){
		xMove = 0;
		yMove = 0;
		
		if (handler.getKeyManager().up)
			yMove = -speed;
		if (handler.getKeyManager().down)
			yMove = speed;
		if (handler.getKeyManager().left)
			xMove = -speed;
		if (handler.getKeyManager().right)
			xMove = speed;
	}

	@Override
	public void render(Graphics g) {
		g.drawImage(getCurrentAnimationFrame(), (int) x, (int) y, width, height,  null);
//		g.setColor(Color.red);
		
		if (bani<10) g.drawImage(Assets.bani[1], 0, 64*4, 64, 64*3, null);
		else if (bani<20) g.drawImage(Assets.bani[2], 0, 64*4, 64, 64*3, null);
		else if (bani<30) g.drawImage(Assets.bani[3], 0, 64*4, 64, 64*3, null);
		else if (bani<40) g.drawImage(Assets.bani[4], 0, 64*4, 64, 64*3, null);
		else if (bani<50) g.drawImage(Assets.bani[5], 0, 64*4, 64, 64*3, null);
		else if (bani<60) g.drawImage(Assets.bani[6], 0, 64*4, 64, 64*3, null);
		else if (bani<70) g.drawImage(Assets.bani[7], 0, 64*4, 64, 64*3, null);
		else if (bani<80) g.drawImage(Assets.bani[8], 0, 64*4, 64, 64*3, null);
		else if (bani<90) g.drawImage(Assets.bani[9], 0, 64*4, 64, 64*3, null);
		else g.drawImage(Assets.bani[10], 0, 64*4, 64, 64*3, null);
		
		if (viata<10) g.drawImage(Assets.viata[1], 64*12, 64*4, 64, 64*3, null);
		else if (viata<20) g.drawImage(Assets.viata[2], 64*12, 64*4, 64, 64*3, null);
		else if (viata<30) g.drawImage(Assets.viata[3], 64*12, 64*4, 64, 64*3, null);
		else if (viata<40) g.drawImage(Assets.viata[4], 64*12, 64*4, 64, 64*3, null);
		else if (viata<50) g.drawImage(Assets.viata[5], 64*12, 64*4, 64, 64*3, null);
		else if (viata<60) g.drawImage(Assets.viata[6], 64*12, 64*4, 64, 64*3, null);
		else if (viata<70) g.drawImage(Assets.viata[7], 64*12, 64*4, 64, 64*3, null);
		else if (viata<80) g.drawImage(Assets.viata[8], 64*12, 64*4, 64, 64*3, null);
		else if (viata<90) g.drawImage(Assets.viata[9], 64*12, 64*4, 64, 64*3, null);
		else g.drawImage(Assets.viata[10], 64*12, 64*4, 64, 64*3, null);

//		g.fillRect((int)x, (int)y, bounds.width, bounds.height);
	}
	
	private BufferedImage getCurrentAnimationFrame(){
		if (xMove == 0 && yMove == 0) return Assets.player_left[1];
		else
		if (xMove < 0){
			return animLeft.getCurrentFrame();
		} else if (xMove > 0){
			return animRight.getCurrentFrame();
		}else if (yMove < 0){
			return animUp.getCurrentFrame();
		}else{
			return animDown.getCurrentFrame();
		}
	}
	
	

}

package game.worlds;

import java.awt.Graphics;
import java.util.Random;

import game.Game;
import game.Handler;
import game.entities.Ceapa;
import game.entities.EntityManager;
import game.entities.Food;
import game.entities.Inel;
import game.entities.Inel1;
import game.entities.Lantisor;
import game.entities.Lantisor1;
import game.entities.Paine;
import game.entities.StaticEntity;
import game.entities.Varza;
import game.entities.creatures.Player;
import game.gfx.Assets;
import game.tiles.Tile;
import game.utils.Utils;

public class World {
	
	private Handler handler;
	private int width, height;
	private int spawnX, spawnY;
	private int[][] tiles;
	private StaticEntity foods[]= new StaticEntity[50];
	private int okL, okC;
	private Random dice = new Random();
	
	private int speed, index, i;
	public long lastTime, timer;
	
	
	//Entities
	private EntityManager entityManager;
	
	public EntityManager getEntityManager() {
		return entityManager;
	}
	

	
	public World(Handler handler, String path){
		this.handler = handler;
		
		index = 0;
		timer = 0;
		lastTime = System.currentTimeMillis();
		speed = 10000;
		i = 0;
		okL = 1 + dice.nextInt(10);
		okC = 1 + dice.nextInt(6);
		
		
		foods[0]= new Food(handler, 64*okL, 64*okC, 20, -30);
		okL = 1 + dice.nextInt(10);
		okC = 1 + dice.nextInt(6);
		foods[2]= new Varza(handler, 64*okL, 64*okC, 50, -30);
		okL = 1 + dice.nextInt(10);
		okC = 1 + dice.nextInt(6);
		foods[4]= new Ceapa(handler, 64*okL, 64*okC, 10, -20);
		okL = 1 + dice.nextInt(10);
		okC = 1 + dice.nextInt(6);
		foods[6]= new Paine(handler, 64*okL, 64*okC, 20, -50);
		okL = 1 + dice.nextInt(10);
		okC = 1 + dice.nextInt(6);
		foods[7]= new Inel(handler, 64*okL, 64*okC, -30, 20);
		okL = 1 + dice.nextInt(10);
		okC = 1 + dice.nextInt(6);
		foods[5]= new Inel1(handler, 64*okL, 64*okC, -50, 20);
		okL = 1 + dice.nextInt(10);
		okC = 1 + dice.nextInt(6);
		foods[3]= new Lantisor(handler, 64*okL, 64*okC, -20, 10);
		okL = 1 + dice.nextInt(10);
		okC = 1 + dice.nextInt(6);
		foods[1]= new Lantisor1(handler, 64*okL, 64*okC, -30, 50);
		okL = 1 + dice.nextInt(10);
		okC = 1 + dice.nextInt(6);
		
		foods[8]= new Food(handler, 64*okL, 64*okC, 20, -30);
		okL = 1 + dice.nextInt(10);
		okC = 1 + dice.nextInt(6);
		foods[10]= new Varza(handler, 64*okL, 64*okC, 50, -30);
		okL = 1 + dice.nextInt(10);
		okC = 1 + dice.nextInt(6);
		foods[12]= new Ceapa(handler, 64*okL, 64*okC, 10, -20);
		okL = 1 + dice.nextInt(10);
		okC = 1 + dice.nextInt(6);
		foods[14]= new Paine(handler, 64*okL, 64*okC, 20, -50);
		okL = 1 + dice.nextInt(10);
		okC = 1 + dice.nextInt(6);
		foods[15]= new Inel(handler, 64*okL, 64*okC, -50, 20);
		okL = 1 + dice.nextInt(10);
		okC = 1 + dice.nextInt(6);
		foods[13]= new Inel1(handler, 64*okL, 64*okC, -20, 10);
		okL = 1 + dice.nextInt(10);
		okC = 1 + dice.nextInt(6);
		foods[11]= new Lantisor(handler, 64*okL, 64*okC, -20, 20);
		okL = 1 + dice.nextInt(10);
		okC = 1 + dice.nextInt(6);
		foods[9]= new Lantisor1(handler, 64*okL, 64*okC, -30, 50);
		okL = 1 + dice.nextInt(10);
		okC = 1 + dice.nextInt(6);
		
		foods[16]= new Food(handler, 64*5, 64*3, 20, -30);
		foods[18]= new Varza(handler, 64*7, 64*4, 50, -30);
		foods[22]= new Ceapa(handler, 64*3, 64*7, 10, -20);
		foods[20]= new Paine(handler, 64*1, 64*2, 20, -50);
		foods[23]= new Inel(handler, 64*5, 64*5, -30, 20);
		foods[21]= new Inel1(handler, 64*6, 64*1, -50, 20);
		foods[17]= new Lantisor(handler, 64*5, 64*3, -20, 10);
		foods[19]= new Lantisor1(handler, 64*7, 64*5, -30, 50);
		
		foods[28]= new Food(handler, 64*2, 64*5, 20, -30);
		foods[26]= new Varza(handler, 64*5, 64*8, 50, -30);
		foods[24]= new Ceapa(handler, 64*3, 64*7, 10, -20);
		foods[30]= new Paine(handler, 64*1, 64*2, 20, -50);
		foods[29]= new Inel(handler, 64*5, 64*5, -30, 20);
		foods[31]= new Inel1(handler, 64*6, 64*5, -50, 20);
		foods[25]= new Lantisor(handler, 64*5, 64*3, -20, 10);
		foods[27]= new Lantisor1(handler, 64*4, 64*5, -30, 50);
		foods[32]= new Food(handler, 64*5, 64*5, 20, -30);
		
		entityManager = new EntityManager(handler, new Player(handler, 200, 300, 50, 50));
		//entityManager.addEntity(foods[0]);
		//entityManager.removeEntity(food);
		loadWorld(path);
		entityManager.addEntity(foods[0]);
		entityManager.addEntity(foods[1]);
		//entityManager.addEntity(foods[1]);
		//entityManager.getPlayer().setX(spawnX);
		//entityManager.getPlayer().setY(spawnY);
	}
	
	public void tick(){
		//ATENTIE RAMO WAS HERE
		
		timer += System.currentTimeMillis() - lastTime;
		lastTime = System.currentTimeMillis();
		
		if (timer < speed){
			
			if (foods[i].active==false || foods[i+1].active==false){
				timer = speed;
			}
			
		}else {
			
			timer = 0;
			foods[i].active= false;
			foods[i+1].active= false;
			if (i<30){i+=2;
			entityManager.addEntity(foods[i]);
			entityManager.addEntity(foods[i+1]);}
			
		}
		//ATENTIE RAMO WAS HERE
		entityManager.tick();
		
		//entityManager.removeEntity(foods[0]);
		//entityManager.removeEntity(foods[1]);
		
	}
	
	public void render(Graphics g){
		g.drawImage(Assets.iarba, 0, 0, 64*13, 64*9, null);
		for (int y = 0; y < height; y++){
			for (int x = 0; x < width; x++){
				if (getTile(x, y).geId()!=0)
				getTile(x, y).render(g,(int) (x * Tile.TILEWIDTH), (int)(y * Tile.TILEHEIGHT));
			}
		}
		//Entities
		entityManager.render(g);
	}
	
	public Tile getTile(int x, int y){
		if (x<0 || y<0 || x>=width || y>=height)
			return Tile.grassTile;
		
		Tile t = Tile.tiles[tiles[x][y]];
		if (t == null)
			return Tile.grassTile;
		return t;
	}
	
	private void loadWorld(String path){
		String file = Utils.loadFileAsString(path);
		String[] tokens = file.split("\\s+");
		width = Utils.parseInt(tokens[0]);
		height = Utils.parseInt(tokens[1]);
		spawnX = Utils.parseInt(tokens[2]);
		spawnY = Utils.parseInt(tokens[3]);
		
		tiles = new int [width][height];
		for (int y = 0; y < height; y++){
			for (int x = 0; x < width; x++){
				tiles[x][y] = Utils.parseInt(tokens[(x+y*width)+4]);
			}
		}
	}
	
}

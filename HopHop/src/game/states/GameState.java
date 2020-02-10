package game.states;

import java.awt.Graphics;

import game.Game;
import game.Handler;
import game.entities.Food;
import game.entities.creatures.Player;
import game.gfx.Assets;
import game.tiles.Tile;
import game.worlds.World;

public class GameState extends State{

	private World world;
	
	public GameState(Handler handler){
		super (handler);
		world = new World(handler, "res/worlds/world1.txt");
		handler.setWorld(world);
		
	}
	
	@Override
	public void tick() {
		world.tick();
	}
	@Override
	public void render(Graphics g) {
		world.render(g);
		//Tile.tiles[0].render(g, 0, 0);
		
	}

}

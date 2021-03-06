package game.entities;

import java.awt.Graphics;

import game.Handler;
import game.gfx.Assets;
import game.tiles.Tile;

public class Paine extends StaticEntity{

	public Paine(Handler handler, float x, float y, int viata, int bani) {
		super(handler, x, y, Tile.TILEWIDTH, Tile.TILEHEIGHT, viata, bani);
	}
	
	public void die(){
		
	}

	@Override
	public void tick() {
		
	}

	@Override
	public void render(Graphics g) {
		g.drawImage(Assets.paine, (int)(x), (int)(y), width, height, null);
	}

}

package game.tiles;


import game.gfx.Assets;

public class RockTile1 extends Tile{

	public RockTile1(int id) {
		super(Assets.stone1, id);
	}
	
	@Override
	public boolean isSolid(){
		return true;
	}

}

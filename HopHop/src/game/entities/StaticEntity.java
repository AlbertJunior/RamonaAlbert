package game.entities;

import game.Handler;

public abstract class StaticEntity extends Entity {
	
	public StaticEntity(Handler handler, float x, float y, int width, int height, int viata, int bani){
		super(handler, x, y, width, height, viata, bani);
	}
	
	
}

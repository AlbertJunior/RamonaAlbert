package game.states;

import java.awt.Color;
import java.awt.Graphics;

import game.Game;
import game.Handler;
import game.gfx.Assets;
import game.ui.UIImageButton;
import game.ui.UIManager;
import game.ui.ClickListener;

public class MenuState extends State {
	
	private UIManager uiManager;
	
	public MenuState(Handler handler){
		super(handler);
		uiManager = new UIManager(handler);
		handler.getMouseManager().setUIManager(uiManager);
		
		uiManager.addObject(new UIImageButton(64*5+32, 64*4, 128, 64, Assets.btn_start, new ClickListener(){
			public void onClick(){
				//handler.getMouseManager().setUIManager(null);
				State.setState(handler.getGame().gameState);
			}
		}));
		
		uiManager.addObject(new UIImageButton(64*5+32, 64*6, 128, 64, Assets.btn_help, new ClickListener(){
			public void onClick(){
				//handler.getMouseManager().setUIManager(null);
				State.setState(handler.getGame().helpState);
			}
		}));
		
	}
	
	@Override
	public void tick() {
		/*if (handler.getMouseManager().IsLeftPressed() && handler.getMouseManager().IsRightPressed()){
			State.setState(handler.getGame().gameState);
		}
		System.out.println(handler.getMouseManager().getMouseX() + "  " + handler.getMouseManager().getMouseY());
	*/
		uiManager.tick();
	}

	@Override
	public void render(Graphics g) {
		g.drawImage(Assets.meniu, 0, 0, 64*13, 64*9, null);
		g.setColor(Color.YELLOW);
		g.fillRect(handler.getMouseManager().getMouseX(), handler.getMouseManager().getMouseY(), 8, 8);
		uiManager.render(g);
	}
	
	

}

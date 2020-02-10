package game.states;

import java.awt.Color;
import java.awt.Graphics;

import game.Game;
import game.Handler;
import game.gfx.Assets;
import game.ui.UIImageButton;
import game.ui.UIManager;
import game.ui.ClickListener;

public class HelpState extends State {
	
	private UIManager uiManager;
	
	public HelpState(Handler handler){
		super(handler);
		uiManager = new UIManager(handler);
		handler.getMouseManager().setUIManager(uiManager);
		
		
		uiManager.addObject(new UIImageButton(64*9, 64*7, 128, 64, Assets.btn_next, new ClickListener(){
			public void onClick(){
				//handler.getMouseManager().setUIManager(null);
				State.setState(handler.getGame().nextState);
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
		g.drawImage(Assets.help, 0, 0, 64*13, 64*9, null);
		g.setColor(Color.YELLOW);
		g.fillRect(handler.getMouseManager().getMouseX(), handler.getMouseManager().getMouseY(), 8, 8);
		
		uiManager.render(g);
	}
	
	

}

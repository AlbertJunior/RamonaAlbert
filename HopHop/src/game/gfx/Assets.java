package game.gfx;

import java.awt.image.BufferedImage;

public class Assets {
	
	private static final int width = 32, height = 32;
	
	public static BufferedImage player, dirt, grass, stone, stone1, tree, food, varza, ceapa, paine, meniu, iarba, help, next;
	public static BufferedImage inel, inel1, cheie, lantisor, lantisor1; 
	public static BufferedImage[] player_down, player_up, player_left, player_right;
	public static BufferedImage[] btn_start, btn_help, btn_next, btn_meniu;
	public static BufferedImage[] bani, viata;
	
	public static void init(){
		SpriteSheet sheet = new SpriteSheet(ImageLoader.LoadImage("/textures/iepuras.png"));
		
		btn_start = new BufferedImage[2];
		btn_start[0]= ImageLoader.LoadImage("/textures/play_button1.png");
		btn_start[1]= ImageLoader.LoadImage("/textures/play_button2.png");
		
		btn_help = new BufferedImage[2];
		btn_help[0]= ImageLoader.LoadImage("/textures/help_button1.png");
		btn_help[1]= ImageLoader.LoadImage("/textures/help_button2.png");
		
		btn_next = new BufferedImage[2];
		btn_next[0]= ImageLoader.LoadImage("/textures/next_button1.png");
		btn_next[1]= ImageLoader.LoadImage("/textures/next_button2.png");
		
		btn_meniu = new BufferedImage[2];
		btn_meniu[0]= ImageLoader.LoadImage("/textures/menu_button1.png");
		btn_meniu[1]= ImageLoader.LoadImage("/textures/menu_button2.png");
		
		bani = new BufferedImage[11];
		
		bani[1] = ImageLoader.LoadImage("/textures/bani1.png");
		bani[2] = ImageLoader.LoadImage("/textures/bani2.png");
		bani[3] = ImageLoader.LoadImage("/textures/bani3.png");
		bani[4] = ImageLoader.LoadImage("/textures/bani4.png");
		bani[5] = ImageLoader.LoadImage("/textures/bani5.png");
		bani[6] = ImageLoader.LoadImage("/textures/bani6.png");
		bani[7] = ImageLoader.LoadImage("/textures/bani7.png");
		bani[8] = ImageLoader.LoadImage("/textures/bani8.png");
		bani[9] = ImageLoader.LoadImage("/textures/bani9.png");
		bani[10] = ImageLoader.LoadImage("/textures/bani10.png");
		
		
		viata = new BufferedImage[11];
		
		viata[1] = ImageLoader.LoadImage("/textures/viata1.png");
		viata[2] = ImageLoader.LoadImage("/textures/viata2.png");
		viata[3] = ImageLoader.LoadImage("/textures/viata3.png");
		viata[4] = ImageLoader.LoadImage("/textures/viata4.png");
		viata[5] = ImageLoader.LoadImage("/textures/viata5.png");
		viata[6] = ImageLoader.LoadImage("/textures/viata6.png");
		viata[7] = ImageLoader.LoadImage("/textures/viata7.png");
		viata[8] = ImageLoader.LoadImage("/textures/viata8.png");
		viata[9] = ImageLoader.LoadImage("/textures/viata9.png");
		viata[10] = ImageLoader.LoadImage("/textures/viata10.png");
		
		player_right = new BufferedImage[7];
		player_left = new BufferedImage[7];
		player_up = new BufferedImage[7];
		player_down = new BufferedImage[7];
		
		player_left[1] = ImageLoader.LoadImage("/textures/left1.png");
		player_left[2] = ImageLoader.LoadImage("/textures/left2.png");
		player_left[3] = ImageLoader.LoadImage("/textures/left3.png");
		player_left[4] = ImageLoader.LoadImage("/textures/left4.png");
		player_left[5] = ImageLoader.LoadImage("/textures/left5.png");
		player_left[6] = ImageLoader.LoadImage("/textures/left6.png");
		
		player_right[1] = ImageLoader.LoadImage("/textures/right1.png");
		player_right[2] = ImageLoader.LoadImage("/textures/right2.png");
		player_right[3] = ImageLoader.LoadImage("/textures/right3.png");
		player_right[4] = ImageLoader.LoadImage("/textures/right4.png");
		player_right[5] = ImageLoader.LoadImage("/textures/right5.png");
		player_right[6] = ImageLoader.LoadImage("/textures/right6.png");
		
		player_up[1] = ImageLoader.LoadImage("/textures/left1.png");
		player_up[2] = ImageLoader.LoadImage("/textures/left2.png");
		player_up[3] = ImageLoader.LoadImage("/textures/left3.png");
		player_up[4] = ImageLoader.LoadImage("/textures/left4.png");
		player_up[5] = ImageLoader.LoadImage("/textures/left5.png");
		player_up[6] = ImageLoader.LoadImage("/textures/left6.png");
		
		player_down[1] = ImageLoader.LoadImage("/textures/right1.png");
		player_down[2] = ImageLoader.LoadImage("/textures/right2.png");
		player_down[3] = ImageLoader.LoadImage("/textures/right3.png");
		player_down[4] = ImageLoader.LoadImage("/textures/right4.png");
		player_down[5] = ImageLoader.LoadImage("/textures/right5.png");
		player_down[6] = ImageLoader.LoadImage("/textures/right6.png");
		
		meniu = ImageLoader.LoadImage("/textures/meniu.png");
		next = ImageLoader.LoadImage("/textures/next.png");
		iarba = ImageLoader.LoadImage("/textures/iarba.png");
		help = ImageLoader.LoadImage("/textures/help.png");
		
		varza = ImageLoader.LoadImage("/textures/varza.png");
		paine = ImageLoader.LoadImage("/textures/paine.png");
		ceapa = ImageLoader.LoadImage("/textures/ceapa.png");
		food = ImageLoader.LoadImage("/textures/food.png");
		
		lantisor = ImageLoader.LoadImage("/textures/lantisor.png");
		lantisor1 = ImageLoader.LoadImage("/textures/lantisor1.png");
		inel = ImageLoader.LoadImage("/textures/inel.png");
		inel1 = ImageLoader.LoadImage("/textures/inel1.png");
		inel = ImageLoader.LoadImage("/textures/inel.png");
		inel1 = ImageLoader.LoadImage("/textures/inel1.png");
		
		player = sheet.crop(0, 0, width, height);
		dirt = sheet.crop(width, 0, width, height);
		grass = sheet.crop(width * 3, height * 3, width, height);
		stone = ImageLoader.LoadImage("/textures/piatra1.png");
		stone1 =  ImageLoader.LoadImage("/textures/piatra2.png");
		tree = sheet.crop(0, height, width, height);
	}
}

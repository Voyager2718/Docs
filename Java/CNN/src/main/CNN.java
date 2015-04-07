package main;//package要放在import前面

//import java.math.*;

public class CNN{
	/**
	 * 文件头定义
	 */
	static final int sightDistance = 500;//视距
	static final int sightDegree = 45;//视角
	static final int sightFoodQuantity = 5;//“看见”的食物数量
	static final int foodQuantity = 10;//食物的数量
	static final int sightMoveRate = 120;//每秒视线移动速率
	static final int robotMoveRate = 100;//每秒机器人移动速率
	static final int rangeX = 1200;//赛场大小
	static final int rangeY = 600;
	static final int robotRadius = 10;//机器人半径
	public enum Color {DEFAULT,BLUE,BLACK,WHITE,RED,ORANGE,GREEN,YELLOW,CRAY};
	public enum sightDirection{CLOCKWISE, ANTICLOCKWISE};
	
	/**
	 * Robot的位置
	 * @author YANG
	 *
	 */
	public class robotPosition{
		private float[] position = new float[2];
		
		/**
		 * 如果Random是true，则自动随机坐标
		 * @param Random
		 */
		public robotPosition(boolean Random){
			if(Random){
				this.position[0] = (int)Math.random()*rangeX;
				this.position[1] = (int)Math.random()*rangeY;
			}
			else{
				this.position[0] = 0;
				this.position[1] = 0;
			}
		}
		
		public robotPosition(int x, int y){
			this.position[0] = (float)x;
			this.position[1] = (float)y;
		}
		
		public int[] returnPosition(){
			int[] tmp = {(int)this.position[0],(int)this.position[1]};
			return tmp;
		}
		
		public int returnPostitionX(){
			return (int)this.position[0];
		}
		
		public int returnPositionY(){
			return (int)this.position[1];
		}
		
		/**
		 * 如果超出赛场范围则返回true
		 * 
		 */
		public boolean goPosition(int degree)throws Exception{//记得自定义Excetion
			float x, y;
			x = this.position[0]+(float)(robotMoveRate*Math.cos(Math.toDegrees(degree)));
			y = this.position[1]+(float)(robotMoveRate*Math.sin(Math.toDegrees(degree)));
			if(x<robotRadius||x>rangeX-robotRadius)
				return true;
			if(y<robotRadius||y>rangeY-robotRadius)
				return true;
			this.position[0] = x;
			this.position[1] = y;
			return false;
		}
	}
	
	public class foodPosition{
		private float[] position = new float[2];
		
		/**
		 * 如果Random是true，则自动随机坐标
		 * @param Random
		 */
		public foodPosition(boolean Random){
			if(Random){
				this.position[0] = (int)Math.random()*rangeX;
				this.position[1] = (int)Math.random()*rangeY;
			}
			else{
				this.position[0] = 0;
				this.position[1] = 0;
			}
		}
		
		public foodPosition(int x, int y){
			this.position[0] = (float)x;
			this.position[1] = (float)y;
		}
		
		public int[] returnPosition(){
			int[] tmp = {(int)this.position[0],(int)this.position[1]};
			return tmp;
		}
		
		public int returnPostitionX(){
			return (int)this.position[0];
		}
		
		public int returnPostitionY(){
			return (int)this.position[1];
		}
	}
	
	/**
	 * Robot的视线
	 * @author YANG
	 *
	 */
	public class robotSight{
		private float angle;
		
		robotSight(boolean Random){
			if(Random)
				this.angle = (int)Math.random()*360;
			else
				this.angle = 0;
		}
		
		robotSight(int angle){
			this.angle = angle;
		}
		
		public void goAngle(sightDirection sd){
			this.angle = ((sd == sightDirection.CLOCKWISE)?(this.angle -= (float)sightMoveRate):(this.angle += (float)sightMoveRate));
		}
		
		public int returnAngle(){
			return (int)this.angle;
		}
		
		/**
		 * 返回食物坐标
		 */ 
		public foodPosition[] findFood(){
			/*未完成*/
			foodPosition[] fp = new foodPosition[10];
			for(int i = 0; i < 10; i++)
				fp[i] = new foodPosition();
			return fp;
		}
	}
	
	/**
	 * Robot本身
	 * @author YANG
	 *
	 */
	public class Robot{
		private Color color;
		private robotPosition position;
		private robotSight sight;
		private String name;
				
		/**
		 * @param Random 是否随机
		 */
		public Robot(String robot_name, boolean Random){
			this.name = robot_name;
			if(Random){
				this.position = new robotPosition(true);
				this.sight = new robotSight(true);
				switch((int)(Math.random()*Color.values().length)){
					case 0:this.color=Color.BLACK;break;
					case 1:this.color=Color.BLUE;break;
					case 2:this.color=Color.WHITE;break;
					case 3:this.color=Color.RED;break;
					case 4:this.color=Color.ORANGE;break;
					case 5:this.color=Color.GREEN;break;
					case 6:this.color=Color.YELLOW;break;
					case 7:this.color=Color.CRAY;break;
					default:this.color=Color.DEFAULT;break;
					}
			}
			else{
				this.position = new robotPosition(false);
				this.sight = new robotSight((int)(Math.random()*360));
				this.color=Color.DEFAULT;
			}
		}
		
		public Robot(String robot_name, int x, int y, Color color, int angle){
			this.name = robot_name;
			this.position = new robotPosition(x,y);
			this.color = color;
			this.sight = new robotSight(angle);
		}
		
		public void initRobot(int x, int y){
			this.position = new robotPosition(x,y);
		}
		
		public Color returnColor(){
			return this.color;
		}
		
		public int[] returnPosition(){
			int[] tmp = {this.position.returnPostitionX(), this.position.returnPositionY()};
			return tmp;
		}
		
		public int returnRobotSight(){
			return this.sight.returnAngle();
		}
		
		public String returnRobotName(){
			return this.name;
		}
		
		public boolean goPosition(int degree){
			return this.position.goPosition(degree);
		}
	}
	
	public static void main(String argv[]){
		
		System.out.println();
	}
}

import java.util.Random;

//Version 0.14
//Class version 0.10

/**
 subclass of Room, room with a button you have to squeeze 
*/
public class ButtonRoom extends Room {
	String buttons;

	public ButtonRoom() {
		super("Button", "This is a room with a button.");
		this.buttons = this.getRandomString(10);
	}

/**
* function 
@ param : length integer
return String

*/
	private String getRandomString(int length) {
		String base = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
		Random random = new Random();
		StringBuffer sb = new StringBuffer();
		for (int i = 0; i < length; i++) {
			int number = random.nextInt(base.length());
			sb.append(base.charAt(number));
		}
		return sb.toString();
	}

	public String getButtons() {
		return this.buttons;
	}
}

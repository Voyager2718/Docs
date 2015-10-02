//Version 0.14
//Class version 0.20

/**  
* Subclass of Room, a normal room which the player has to cross
*/

public class NormalRoom extends Room {
	protected int position;
	protected boolean found;

	public NormalRoom() {
		super("Normal", "This is a normal(intersection) room.");
		this.position = (int) Math.random() * 10;
		if (this.position > 90)
			this.found = true;
		else
			this.found = false;
	}

	public String getPosition() {
		if (this.position <= 3)
			return "table";
		if (this.position <= 100)
			return "picture";
		else
			return "normal";
	}

/**
*function execute if player found a next room 
*/
	public void found() {
		this.found = true;
	}

	public boolean getFound() {
		return this.found;
	}
}

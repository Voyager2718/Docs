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

	public void found() {
		this.found = true;
	}

	public boolean getFound() {
		return this.found;
	}
}
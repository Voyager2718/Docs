//Version 0.14
//Class version 0.12
public class R {
	protected String type;
	protected String description;

	public R(String type, String description) {
		this.type = type;
		this.description = description;
	}

	public String getType() {
		return this.type;
	}

	protected String getDescription() {
		return this.description;
	}
}
import java.util.HashMap;

public class Room {
	protected String type;
	protected String description;
	HashMap<String, Room> destinations;

	public Room(String type, String description) {
		this.type = type;
		this.description = description;
		destinations = new HashMap<String, Room>();
	}

	public Room changeRoom(String destination) {
		if (destinations.containsKey(destination)) {
			return destinations.get(destination);
		}
		System.out.println("Can't go " + destination);
		return this;
	}
	
	public void fight() {
		System.out.println("There is no monster here");
	}

	public String getType() {
		return type;
	}

	public String getDescription() {
		return description;
	}
}

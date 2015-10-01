//Version 0.14
//Class version 0.10
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Room extends R {
	protected Map<String, R> rooms = new HashMap<String, R>();

	public Room(String type, String description) {
		super(type, description);
	}

	protected boolean directionAvailable(String direction) {
		List<String> dir = new ArrayList<String>();
		dir.add("east");
		dir.add("south");
		dir.add("west");
		dir.add("north");
		if (!dir.contains(direction))
			return false;
		return true;
	}

	protected void addRoom(String direction, R room) {
		if (!this.directionAvailable(direction)) {
			System.out.println("I don't know what you mean, use east, south, west, north please.");
			return;
		}
		if (this.rooms.containsKey(direction)) {
			System.out.println("Already have a room there.");
			return;
		}
		this.rooms.put(direction, room);
	}

	protected R getNextRoom(String direction) throws CantGoException {
		if (!this.directionAvailable(direction)) {
			System.out.println("I don't know what you mean.");
			return null;
		}
		if (!this.rooms.containsKey(direction))
			throw new CantGoException("Can't go " + direction);
		return this.rooms.get(direction);
	}

	protected String getDescription() {
		return this.description;
	}
}
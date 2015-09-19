import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class NormalRoom extends Room {
	public NormalRoom(String type) {
		super(type);
	}

	public void addRoom(String direction, Room room) {
		if (!this.directionAvailable(direction)) {
			System.out.println("I don't know what you mean.");
			return;
		}
		if (this.rooms.containsKey(direction)) {
			System.out.println("Already have a room there.");
			return;
		}
		this.rooms.put(direction, room);
	}

	public boolean isPossibleDirection(String direction) {
		return this.rooms.containsKey(direction);
	}

	public Room getNextRoom(String direction) throws CantGoException {
		if (!this.directionAvailable(direction)) {
			System.out.println("I don't know what you mean.");
			return null;
		}
		if (!this.rooms.containsKey(direction))
			throw new CantGoException("Can't go " + direction);
		return this.rooms.get(direction);
	}
}
import java.util.HashMap;
import java.util.Map;

public class Entrance implements Room {
	protected Map<String, Room> neighbours = new HashMap<String, Room>();
	protected String type;
	protected String condition;

	public Entrance() {
		this.type = "entrance";
		this.condition = "normal";
	}

	@Override
	public void addNextRoom(Room room, String direction) {
		this.neighbours.put(direction, room);
	}

	@Override
	public Room getNextRoom(String direction) {
		if (!isPossibleDirection(direction))
			return null;
		return this.neighbours.get(direction);
	}

	@Override
	public boolean isPossibleDirection(String direction) {
		return this.neighbours.containsKey(direction);
	}

	@Override
	public Room go(String command) throws CantGoException {
		if (isPossibleDirection(command.substring(3))) {
			return getNextRoom(command.substring(3));
		} else
			throw new CantGoException("You can't go there.");
	}

	@Override
	public String getType() {
		return this.type;
	}

	@Override
	public String getCondition() {
		return this.condition;
	}

}

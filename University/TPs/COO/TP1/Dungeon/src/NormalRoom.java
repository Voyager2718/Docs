import java.util.HashMap;
import java.util.Map;

public class NormalRoom implements Room {
	protected Map<String, Room> neighbours = new HashMap<String, Room>();
	protected String type;
	protected String condition;

	/**
	 * Constructor
	 * 
	 * @param type
	 * @param condition
	 */
	public NormalRoom() {
		this.type = "normal room";
		this.condition = "normal";
	}

	public String getType() {
		return this.type;
	}

	public String getCondition() {
		return this.condition;
	}

	/**
	 * Add next room to the map.
	 * 
	 * @param room
	 *            A room.
	 * @param direction
	 *            The direction to place the room.
	 */
	@Override
	public void addNextRoom(Room room, String direction) {
		this.neighbours.put(direction, room);
	}

	/**
	 * Get next room with the direction.
	 * 
	 * @param direction
	 *            Get next room from the direction entered. If the direction
	 *            doesn't exist, return null.
	 */
	@Override
	public Room getNextRoom(String direction) {
		if (!isPossibleDirection(direction))
			return null;
		return this.neighbours.get(direction);
	}

	/**
	 * Check if there's a room from the direction entered.
	 * 
	 * @param direction
	 *            The direction needs to be checked.
	 */
	@Override
	public boolean isPossibleDirection(String direction) {
		return this.neighbours.containsKey(direction);
	}

	/**
	 * Try to go to next room. If it's impossible to go, return null, else
	 * return the next room.
	 * 
	 * @param command
	 *            A command begin with "Go" end with a direction(Such as
	 *            "Go north", "Go south").
	 */
	@Override
	public Room go(String command) throws CantGoException {
		if (isPossibleDirection(command.substring(3))) {
			return getNextRoom(command.substring(3));
		} else
			throw new CantGoException("You can't go there.");
	}
}

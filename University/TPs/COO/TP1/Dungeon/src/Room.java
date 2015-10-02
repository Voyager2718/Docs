/** 
 * subclass of R 
*/
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Room extends R {
	protected Map<String, R> rooms = new HashMap<String, R>();

	public Room(String type, String description) {
		super(type, description);
	}
/** Stocks the 4 directions in a list
* @param : direction
* @return true if the list contains the available direction, false else
*/
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


/**checks if the direction exists, and if there is already a room by the direction wanted
* if not, a new room is added
*@param : direction
*@param : room
*/

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




/**checks if the direction gives as parameter is available, and if there is already in the list and return the room appropriate
* if not, return null
*@param : direction
*/

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

public interface Room {
	/**
	 * A function to add next room into the map.
	 * @param room Room that needs to be added.
	 * @param direction Add on this direction under form: "north", "west", etc.
	 */
	public void addNextRoom(Room room, String direction);

	/**
	 * A function to get next room on direction inputed. 
	 * @param direction check if there's a room on this direction.
	 * @return
	 */
	public Room getNextRoom(String direction);

	/**
	 * A function to check if there's a room on direction.
	 * @param direction Direction that needs to be checked.
	 * @return
	 */
	public boolean isPossibleDirection(String direction);

	/**
	 * Try to go another room, if possible, return the latest room, if not, throw CantGoException.
	 * @param command A command in this form: "go+" "+direction".
	 * @return if it's possible to go.
	 * @throws Exception If there's no room, throw CantGoException.
	 */
	public Room go(String command) throws Exception;

	/**
	 * Get type of room.
	 * @return return type of room.
	 */
	public String getType();

	/**
	 * Get condition of room.
	 * @return return condition of room.
	 */
	public String getCondition();

}

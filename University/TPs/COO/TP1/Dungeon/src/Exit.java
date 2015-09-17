public class Exit implements Room {
	protected String type;
	protected String condition;

	/**
	 * Exit should be the last room of the game, so there's not a map contains any rooms.
	 */
	public Exit() {
		this.type = "exit";
		this.condition = "normal";
	}

	public String getType() {
		return this.type;
	}

	public String getCondition() {
		return this.condition;
	}

	/**
	 * Exit should be the last room of the game, so don't need to do anything.
	 */
	@Override
	public Room go(String command) {
		return null;
	}

	/**
	 * Exit should be the last room of the game, so don't need to do anything.
	 */
	@Override
	public void addNextRoom(Room room, String direction) {
	}

	/**
	 * Exit should be the last room of the game, so don't need to do anything.
	 */
	@Override
	public Room getNextRoom(String direction) {
		return null;
	}

	/**
	 * Exit should be the last room of the game, so don't need to do anything.
	 */
	@Override
	public boolean isPossibleDirection(String direction) {
		return false;
	}
}

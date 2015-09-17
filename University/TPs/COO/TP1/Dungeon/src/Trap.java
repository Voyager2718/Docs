public class Trap implements Room {
	protected String type;
	protected String condition;
	
	/**
	 * Trap should be the last room of the game, so there's not a map contains any rooms.
	 */
	public Trap() {
		this.type = "trap";
		this.condition = "normal";
	}

	/**
	 * Trap should be the last room of the game, so don't need to do anything.
	 */
	@Override
	public void addNextRoom(Room room, String direction) {
	}

	/**
	 * Trap should be the last room of the game, so don't need to do anything.
	 */
	@Override
	public Room getNextRoom(String direction) {
		return null;
	}

	/**
	 * Trap should be the last room of the game, so don't need to do anything.
	 */
	@Override
	public boolean isPossibleDirection(String direction) {
		return false;
	}

	/**
	 * Trap should be the last room of the game, so don't need to do anything.
	 */
	@Override
	public Room go(String command) {
		return null;
	}
	
	/**
	 * Trap should be the last room of the game, so don't need to do anything.
	 */
	@Override
	public String getType() {
		return this.type;
	}

	/**
	 * Trap should be the last room of the game, so don't need to do anything.
	 */
	@Override
	public String getCondition() {
		return this.condition;
	}

}

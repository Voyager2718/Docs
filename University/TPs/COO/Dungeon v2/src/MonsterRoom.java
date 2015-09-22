public class MonsterRoom extends Room {
	protected boolean monster = true;

	public MonsterRoom(String type, String description) {
		super(type, description);
	}
	
	public Room changeRoom(String destination) {
		if (monster() == true) {
			System.out.println("Can't go " + destination + ", there is a monster");
			return this;
		} else if (destinations.containsKey(destination)) {
			return destinations.get(destination);
		}
		System.out.println("Can't go " + destination);
		return this;
	}
	
	public void fight() {
		System.out.println("You defeat the monster");
		this.monster = false;
	}

	public boolean monster() {
		return monster;
	}
}

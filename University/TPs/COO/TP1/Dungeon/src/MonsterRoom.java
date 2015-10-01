//Version 0.14
//Class version 0.10
public class MonsterRoom extends Room {
	private boolean killed = false;

	public MonsterRoom() {
		super("Monster", "This room have a monster! Go to kill it with sword.");
	}

	public void kill() {
		this.killed = true;
	}

	public boolean getMonsterKilled() {
		return this.killed;
	}
}

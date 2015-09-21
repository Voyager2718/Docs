
public class MonsterRoom extends Room {
	private boolean killed = false;

	public MonsterRoom() {
		super("Monster", "This room have a monster! Go to kill it with sword.");
	}

	public void kill() {
		this.killed = false;
	}

	public boolean getMonsterCondition() {
		return this.killed;
	}
}

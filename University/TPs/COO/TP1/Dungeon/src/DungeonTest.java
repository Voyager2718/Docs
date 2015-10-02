import static org.junit.Assert.*;
import org.junit.*;

public class DungeonTest {
	protected Dungeon dungeon;

	@Before
	public void createDungeon() {
		dungeon = new Dungeon();
	}

	@Test
	public void initialRoomIsEntrance() {
		assert(dungeon.entrance instanceof Entrance);
	}

	@Test
	public void gameNotFinishedAtBeginning() {
		assertFalse(dungeon.gameIsFinished());
	}

	@Test
	public void gameWonWhenGoingExit() {
		dungeon.currentRoom = new Exit();
		assertTrue(dungeon.gameIsWon());
	}

	@Test
	public void gameLostWhenGoingTrap() {
		dungeon.currentRoom = new Trap();
		assertTrue(dungeon.gameIsLost());
	}

	@Test
	public void gameLostWhenHPIsZero() {
		dungeon.health = 0;
		assertTrue(dungeon.gameIsLost());
	}
}

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Dungeon {
	protected Room currentRoom;
	protected final Scanner scanner = new Scanner(System.in);

	/**
	 * Use this.establishRoom() to construct the whole playing map.
	 */
	public Dungeon() {
		List<Room> rooms = new ArrayList<Room>();
		rooms = this.establishRoom();
		this.currentRoom = rooms.get(0);
	}

	/**
	 * Use this function to establish the whole playing map.
	 * @return
	 */
	public List<Room> establishRoom() {
		List<Room> rooms = new ArrayList<Room>();
		rooms.add(new Entrance());
		rooms.add(new NormalRoom());
		rooms.add(new Exit());
		rooms.get(0).addNextRoom(rooms.get(1), "north");
		rooms.get(1).addNextRoom(rooms.get(2), "west");
		return rooms;
	}

	/**
	 * Get the room which have user.
	 * @return
	 */
	public Room getCurrentRoom() {
		return this.currentRoom;
	}

	/**
	 * Start to play.
	 */
	public void start() {
		while (!gameIsFinished()) {
			System.out.println("You're in " + getCurrentRoom().getType());
			System.out.println("What do you want to do?");
			this.interpretCommand();
		}
		if (gameIsWon()) {
			System.out.println("You won!");
		} else {
			System.out.println("You lost!");
		}
	}

	/**
	 * Try to interpret the command that user enter.
	 */
	public void interpretCommand() {
		String command = scanner.nextLine();
		try {
			this.currentRoom = this.currentRoom.go(command);
		} catch (CantGoException e) {
			System.out.println(e.getMessage());
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	/**
	 * If this.currentRoom == Exit, then return true.
	 * @return
	 */
	public boolean gameIsWon() {
		return this.currentRoom instanceof Exit;
	}

	/**
	 * If this.currentRoom == Trap, then return true.
	 * @return
	 */
	public boolean gameIsLost() {
		return this.currentRoom instanceof Trap;
	}

	/**
	 * If this.currentRoom == Exit||this.currentRoom == Trap, then return true.
	 * Because there're only 2 result: Exit-Won, Trap-Lost.
	 * @return
	 */
	public boolean gameIsFinished() {
		return gameIsWon() || gameIsLost();
	}
}

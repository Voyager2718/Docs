import java.util.Scanner;

public class Dungeon {
	protected Room currentRoom;
	protected boolean gameIsFinished = false;
	protected final Scanner scanner = new Scanner(System.in);

	protected Room exit;
	protected Room trap;
	protected Room intersection;
	protected Room entrance;

	public Dungeon() {
		this.exit = new Room("exit", "");
		this.trap = new Room("trap", "");
		this.intersection = new MonsterRoom("intersection",
				"there is two doors : north and west");
		this.intersection.destinations.put("west", this.trap);
		this.intersection.destinations.put("north", this.exit);
		this.entrance = new Room("entrance",
				"there is a door in the north");
		this.entrance.destinations.put("north", this.intersection);
	}

	public boolean gameIsWon() {
		return currentRoom.getType().equals("exit");
	}

	public boolean gameIsLost() {
		return currentRoom.getType().equals("trap");
	}

	public boolean gameIsFinished() {
		return gameIsWon() || gameIsLost();
	}

	public void interpretCommand(String command) {
		if (command.equals("description")) {
			System.out.println(currentRoom.getDescription());
		} else if (command.equals("combattre")) {
			currentRoom.fight();
		} else if (command.substring(0, 3).equals("go ")) {
			currentRoom = currentRoom.changeRoom(command.substring(3));
		} else {
			System.out.println("I don't know what you mean.");
		}
	}

	public void start() {
		currentRoom = entrance;

		do {
			System.out.println("You are in " + currentRoom.getType());
			System.out.println("What do you want to do ?");
			System.out.print("> ");

			// Read a command from the user (stdin)
			String line = scanner.nextLine();
			interpretCommand(line);
		} while (!gameIsFinished());

		System.out.println("You are in " + currentRoom.getType());
		if (gameIsWon())
			System.out.println("You win !");
		else
			System.out.println("You lose !");
	}

	public static void main(String args[]) {
		Dungeon dungeon = new Dungeon();
		dungeon.start();
	}
}

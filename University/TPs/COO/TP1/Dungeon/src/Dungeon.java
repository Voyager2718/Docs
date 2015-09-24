import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Dungeon {
	protected List<Equipement> equipements = new ArrayList<Equipement>();
	protected R currentRoom = new Entrance();
	protected final Scanner scanner = new Scanner(System.in);

	// testing
	protected int health = 100;

	public void hurt() {
		this.health -= 10;
	}

	public void hurt(int hurt) {
		this.health -= hurt;
	}

	public void heal() {
		this.health += 10;
	}

	public void heal(int heal) {
		this.health += heal;
	}

	public int getHealth() {
		return this.health;
	}
	// end testing

	public Dungeon() {
		Exit e = new Exit();
		NormalRoom n = new NormalRoom();
		((Room) this.currentRoom).addRoom("north", n);
		((Room) n).addRoom("south", e);
	}

	public R getCurrentRoom() {
		return this.currentRoom;
	}

	public void setCurrentRoom(R room) {
		this.currentRoom = room;
	}

	public void interpretCommand() {
		String command = this.scanner.nextLine();
		if (command.substring(0, 3).equals("go ")) {// Case go+direction
			String direction = command.substring(3);
			if (this.getCurrentRoom() instanceof NormalRoom) {
				if (((Room) this.getCurrentRoom()).directionAvailable(direction))
					try {
						this.setCurrentRoom(((Room) this.getCurrentRoom()).getNextRoom(direction));
					} catch (CantGoException e) {
						System.out.println(e.getMessage());
					}
			} else if (this.getCurrentRoom() instanceof LockedRoom) {

			} else if (this.getCurrentRoom() instanceof MonsterRoom) {

			} else if (this.getCurrentRoom() instanceof TreasureRoom) {

			}
		} else if (command.substring(0, 4).equals("use ")) {

		} else if (command.equals("description")) {
			System.out.println(this.currentRoom.getDescription());
		} else {
			System.out.println("I don't know what you mean.");
		}
	}

	public boolean gameIsWon() {
		return this.currentRoom instanceof Exit;
	}

	public boolean gameIsLost() {
		return this.currentRoom instanceof Trap;
	}

	public boolean gameIsFinished() {
		return gameIsWon() || gameIsLost();
	}

	public void start() {
		while (!this.gameIsFinished()) {
			System.out.println("You are in " + getCurrentRoom().getType() + "Room.");
			System.out.println("What do you want to do?");
			System.out.print("> ");
			interpretCommand();
		}
		if (this.gameIsWon())
			System.out.println("You won��");
		if (this.gameIsLost())
			System.out.println("You lost!");
	}

	public static void main(String[] args) {
		Dungeon d = new Dungeon();
		d.start();
	}
}

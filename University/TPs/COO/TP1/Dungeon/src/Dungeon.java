import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Dungeon {
	protected List<Equipement> equipements = new ArrayList<Equipement>();
	protected R currentRoom;
	protected final Scanner scanner = new Scanner(System.in);

	public R getCurrentRoom() {
		return this.currentRoom;
	}

	public void interpretCommand(String command) {
		if (command.substring(0, 3) == "go ") {

		}
	}

	public static void main(String[] args) {

	}
}

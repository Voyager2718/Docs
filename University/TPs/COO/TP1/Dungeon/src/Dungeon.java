import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Dungeon {
	protected List<Equipement> equipements = new ArrayList<Equipement>();
	protected Entrance entrance = new Entrance();
	protected R currentRoom = entrance;
	protected final Scanner scanner = new Scanner(System.in);

	protected int health = 100;
	protected int money = 0;

	public void hurt() {
		this.health -= 10;
		if (this.getHealth() <= 0) {
			this.currentRoom = new Trap();
			System.out.println("You died. Game over.");
		}
	}

	public void hurt(int hurt) {
		this.health -= hurt;
		if (this.getHealth() <= 0) {
			this.currentRoom = new Trap();
			System.out.println("You died. Game over.");
		}
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

	public void earnMoney(int money) {
		this.money += money;
	}

	public int getMoney() {
		return this.money;
	}

	public Dungeon() {
		Exit e = new Exit();
		NormalRoom n0 = new NormalRoom();
		LockedRoom l1 = new LockedRoom();
		((Room) this.currentRoom).addRoom("north", n0);
		((Room) n0).addRoom("north", n1);
		((Room) n1).addRoom("south", n0);
		((Room) n1).addRoom("west", e);
		this.equipements.add(new Treasure("Gold", 500));
		this.equipements.add(new Potion());
		this.equipements.add(new Sword());
		this.equipements.add(new Key());
		this.equipements.add(new Treasure("Diamond", 5000));
	}

	public R getCurrentRoom() {
		return this.currentRoom;
	}

	public void setCurrentRoom(R room) {
		this.currentRoom = room;
	}

	public boolean useEquipement(String equipement) {
		equipement = equipement.toLowerCase();
		for (int i = 0; i < this.equipements.size(); i++) {
			if (equipement == "key")
				if (this.equipements.get(i) instanceof Key) {
					this.equipements.remove(i);
					return true;// If true, remove equipment successfully.
				}
			if (equipement == "potion")
				if (this.equipements.get(i) instanceof Key) {
					this.equipements.remove(i);
					return true;// If true, remove equipment successfully.
				}
			if (equipement == "sword")
				if (this.equipements.get(i) instanceof Key) {
					this.equipements.remove(i);
					return true;// If true, remove equipment successfully.
				}
			if (equipement == "treasure")
				if (this.equipements.get(i) instanceof Treasure) {
					this.equipements.remove(i);
					return true;// If true, remove equipment successfully.
				}
		}
		return false;
	}

	public void interpretCommand() {
		String command = this.scanner.nextLine();
		command = command.toLowerCase();
		if (command.substring(0, 3).equals("go ")) {// Case go+direction
			String direction = command.substring(3);
			if (this.getCurrentRoom() instanceof Room) {
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
			if (command.substring(4).equals("sword")) {
				if (this.currentRoom instanceof MonsterRoom) {
					if (useEquipement("sword")) {
						System.out.println("You have killed the monster!");
						((MonsterRoom) this.currentRoom).kill();
					} else {
						System.out.println(
								"You don't have a sword to kill monster. You was hurt and was sent back to the entrance.");
						this.hurt(45);
						this.currentRoom = this.entrance;
					}
				} else
					System.out.println("Don't use the sword without monsters! It's dangerous!");
			} else if (command.substring(4).equals("potion")) {
				if (useEquipement("potion")) {
					System.out.println("You have recovered 50 HP!");
				} else {
					System.out.println("You don't have any potion, try to get one. It's useful.");
				}
			} else if (command.substring(4).equals("key")) {
				if (useEquipement("key")) {
					if (this.currentRoom instanceof LockedRoom) {
						System.out.println("You have unlocked this room.");
						((LockedRoom) this.currentRoom).unlock();
					}
				} else {
					while (true) {
						System.out.println("You don't have any key.");
						System.out.println(
								"Suddenly, there's a elf appear. She said \"I have a key, but you have to give me a treasure, or you will me put to the entrance magically.");
						System.out.println("Would you like to give her a treasure randomly?\nYes/No");
						String command2 = this.scanner.nextLine();
						command2 = command2.toLowerCase();
						if (command2.equals("yes")) {
							if (this.useEquipement("treasure")) {
								System.out.println("You've got a key.");
								break;
							} else {
								System.out.println("The elf sent you back to entrance.");
								this.currentRoom = entrance;
								break;
							}
						} else if (command2.equals("no")) {
							System.out.println("The elf sent you back to entrance.");
							this.currentRoom = entrance;
							break;
						} else {
							System.out.println("I don't know what do you mean.");
						}
					}
				}
			}
		} else if (command.equals("description")) {
			System.out.println(this.currentRoom.getDescription());
		} else if (command.equals("equipements")) {
			this.getEquipementsValue();
		} else {
			System.out.println("I don't know what you mean.");
		}
	}

	public int getEquipementsValue() {
		int potions = 0, swords = 0, keys = 0, treasureValue = 0;
		for (int i = 0; i < this.equipements.size(); i++) {
			if (this.equipements.get(i) instanceof Sword)
				swords++;
			if (this.equipements.get(i) instanceof Key)
				keys++;
			if (this.equipements.get(i) instanceof Potion)
				potions++;
		}
		System.out.println("You have these:\n-------------------------");
		for (int i = 0; i < this.equipements.size(); i++) {
			if (this.equipements.get(i) instanceof Treasure) {
				System.out.println(((Treasure) this.equipements.get(i)).getName() + "     ��"
						+ ((Treasure) this.equipements.get(i)).getValue());
				treasureValue += ((Treasure) this.equipements.get(i)).getValue();
			}
		}
		System.out
				.println("Potions��" + potions + " Swords��" + swords + " Keys��" + keys + "\n-------------------------");
		return 100 * potions + swords * 1000 + keys * 50 + treasureValue;
	}

	public void printEquipements() {
		this.getEquipementsValue();
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
		if (this.gameIsWon()) {
			System.out.println("You won��\nWhat's more, according to your spectacular, you've got\n");

		}
		if (this.gameIsLost())
			System.out.println("You lost!");
	}

	public static void main(String[] args) {
		Dungeon d = new Dungeon();
		d.start();
	}
}


//Version 0.15
//Class version 0.26
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Dungeon {
	protected List<Equipment> equipments = new ArrayList<Equipment>();
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
		ButtonRoom n0 = new ButtonRoom();
		LockedRoom l1 = new LockedRoom();
		MonsterRoom m1 = new MonsterRoom();
		((Room) this.currentRoom).addRoom("north", m1);
		((Room) m1).addRoom("east", n0);
		((Room) n0).addRoom("north", l1);
		((Room) l1).addRoom("south", n0);
		((Room) l1).addRoom("west", e);
		this.equipments.add(new Treasure("Gold", 500));
		this.equipments.add(new Potion());
		this.equipments.add(new Potion());
		this.equipments.add(new Sword());
		this.equipments.add(new Sword());
		this.equipments.add(new Sword());
		this.equipments.add(new Key());
		this.equipments.add(new Treasure("Diamond", 5000));
	}

	public R getCurrentRoom() {
		return this.currentRoom;
	}

	public void setCurrentRoom(R room) {
		this.currentRoom = room;
	}

	public boolean useEquipement(String equipement) {
		equipement = equipement.toLowerCase();
		for (int i = 0; i < this.equipments.size(); i++) {
			if (equipement == "key")
				if (this.equipments.get(i) instanceof Key) {
					this.equipments.remove(i);
					return true;// If true, remove equipment successfully.
				}
			if (equipement == "potion")
				if (this.equipments.get(i) instanceof Key) {
					this.equipments.remove(i);
					return true;// If true, remove equipment successfully.
				}
			if (equipement == "sword")
				if (this.equipments.get(i) instanceof Key) {
					this.equipments.remove(i);
					return true;// If true, remove equipment successfully.
				}
			if (equipement == "treasure")
				if (this.equipments.get(i) instanceof Treasure) {
					this.equipments.remove(i);
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
			if (this.getCurrentRoom() instanceof NormalRoom || this.getCurrentRoom() instanceof Entrance) {
				if (((Room) this.getCurrentRoom()).directionAvailable(direction))
					try {
						if (this.getCurrentRoom() instanceof NormalRoom) {
							if (!((NormalRoom) this.currentRoom).found) {
								System.out.println(
										"Where's the exit? It may under the table or behind the picture.\nEnter \"search table\" or \"search picture\" to search the exit.");
								return;
							}
						}
						this.setCurrentRoom(((Room) this.getCurrentRoom()).getNextRoom(direction));
					} catch (CantGoException e) {
						System.out.println(e.getMessage());
					}
				else
					System.out.println("I don't know what you mean.");
			} else if (this.getCurrentRoom() instanceof LockedRoom) {
				if (((Room) this.getCurrentRoom()).directionAvailable(direction))
					try {
						if (!((LockedRoom) this.currentRoom).getLocked())
							this.setCurrentRoom(((Room) this.getCurrentRoom()).getNextRoom(direction));
						else
							System.out.println(
									"The exit of this room is locked. Try to enter \"use key\" to unlock this room.");
					} catch (CantGoException e) {
						System.out.println(e.getMessage());
					}
				else
					System.out.println("I don't know what you mean.");
			} else if (this.getCurrentRoom() instanceof MonsterRoom) {
				if (((Room) this.getCurrentRoom()).directionAvailable(direction))
					try {
						if (((MonsterRoom) this.currentRoom).getMonsterKilled())
							this.setCurrentRoom(((Room) this.getCurrentRoom()).getNextRoom(direction));
						else
							System.out.println(
									"This room have a monster lying on the exit. Try to enter \"use sword\" to kill it.");
					} catch (CantGoException e) {
						System.out.println(e.getMessage());
					}
				else
					System.out.println("I don't know what you mean.");
			} else if (this.getCurrentRoom() instanceof ButtonRoom) {
				if (((Room) this.getCurrentRoom()).directionAvailable(direction))
					try {
						while (true) {
							System.out.println(
									"A typing god appear, and said: You have to type these things! Or you can't go to the next room!");
							System.out.println("Things to type:\n" + ((ButtonRoom) this.currentRoom).getButtons());
							String toType = this.scanner.nextLine();
							if (((ButtonRoom) this.currentRoom).getButtons().equals(toType)) {
								System.out.println("The typing god allows you to go.");
								break;
							}
						}
						this.setCurrentRoom(((Room) this.getCurrentRoom()).getNextRoom(direction));

					} catch (CantGoException e) {
						System.out.println(e.getMessage());
					}
				else
					System.out.println("I don't know what you mean.");
			} else if (this.getCurrentRoom() instanceof TreasureRoom) {
				if (((Room) this.getCurrentRoom()).directionAvailable(direction))
					try {
						System.out.println("This room have plenty of treasures! Already put them into beg.");
						this.setCurrentRoom(((Room) this.getCurrentRoom()).getNextRoom(direction));

					} catch (CantGoException e) {
						System.out.println(e.getMessage());
					}
				else
					System.out.println("I don't know what you mean.");
			}
		} else if (command.substring(0, 4).equals("use "))

		{
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
								this.equipments.add(new Key());
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
		} else if (command.equals("description"))

		{
			System.out.println(this.currentRoom.getDescription());
		} else if (command.equals("equipments"))

		{
			this.getEquipmentsValue();
		} else if (command.equals("health"))

		{
			System.out.println("HP:" + this.getHealth());
		} else if (command.substring(0, 6).equals("search"))

		{
			if (!(this.currentRoom instanceof NormalRoom)) {
				System.out.println("The \"search\" command is just for normal room. ");
				return;
			}
			if (command.substring(7).equals("table")) {
				if (((NormalRoom) this.currentRoom).getPosition() == "table") {
					System.out.println("You found the exit!");
					((NormalRoom) this.currentRoom).found();
				} else
					System.out.println("Exit is not here.");
			} else if (command.substring(7).equals("picture")) {
				if (((NormalRoom) this.currentRoom).getPosition() == "picture") {
					System.out.println("You found the exit!");
					((NormalRoom) this.currentRoom).found();
				} else
					System.out.println("Exit is not here.");
			} else
				System.out.println("I don't know what you mean.");
		} else

		{
			System.out.println("I don't know what you mean.");
		}

	}

	public int getEquipmentsValue() {
		int potions = 0, swords = 0, keys = 0, treasureValue = 0;
		for (int i = 0; i < this.equipments.size(); i++) {
			if (this.equipments.get(i) instanceof Sword)
				swords++;
			if (this.equipments.get(i) instanceof Key)
				keys++;
			if (this.equipments.get(i) instanceof Potion)
				potions++;
		}
		System.out.println("You have these:\n-------------------------");
		for (int i = 0; i < this.equipments.size(); i++) {
			if (this.equipments.get(i) instanceof Treasure) {
				System.out.println(((Treasure) this.equipments.get(i)).getName() + "     ��"
						+ ((Treasure) this.equipments.get(i)).getValue());
				treasureValue += ((Treasure) this.equipments.get(i)).getValue();
			}
		}
		System.out
				.println("Potions��" + potions + " Swords��" + swords + " Keys��" + keys + "\n-------------------------");
		return 100 * potions + swords * 1000 + keys * 50 + treasureValue;
	}

	public void printEquipements() {
		this.getEquipmentsValue();
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
			if (this.currentRoom instanceof Entrance)
				System.out.println("You are in " + getCurrentRoom().getType() + ".");
			else
				System.out.println("You are in " + getCurrentRoom().getType() + " Room.");
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

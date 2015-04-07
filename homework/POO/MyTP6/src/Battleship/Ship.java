package Battleship;

public class Ship {
	private int HP;

	public Ship(int HP) {
		this.HP = HP;
	}

	public void hit() {
		this.HP--;
	}
	
	public void setHP(int HP){
		this.HP = HP;
	}

	public int getHP() {
		return this.HP;
	}

	public boolean isSunk() {
		return this.HP == 0;
	}
}

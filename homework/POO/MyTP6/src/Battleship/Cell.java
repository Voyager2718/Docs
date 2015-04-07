package Battleship;

public class Cell {
	private Ship ship;
	private boolean damaged;
	private boolean godMode;

	public Cell(Ship ship) {
		this.damaged = false;
		this.ship = ship;
	}

	public void hit() {
		if (godMode)
			return;
		this.damaged = true;
		this.ship.hit();
	}

	public boolean getDamage() {
		return this.damaged;
	}

	public Ship getShip() {
		return this.ship;
	}

	public void enableGodMode() {
		this.godMode = true;
	}
	
	public void disableGodMode(){
		this.godMode = false;
	}
}

package Battleship;

public class Sea {
	private int width, height;
	private Cell[][] cells;
	private boolean[][] touches;
	
	public int getWidth(){
		return this.width;
	}
	
	public int getHeight(){
		return this.height;
	}

	public Sea(int width, int height) {
		this.width = width;
		this.height = height;
		this.cells = new Cell[this.width][this.height];
		this.touches = new boolean[this.width][this.height];
	}
	
	public Cell getCell(int x, int y){
		return this.cells[x][y];
	}

	public void placeShip(Ship ship, Direction direction, Position position)
			throws Exception {
			if (direction == Direction.EAST) {
				try {
					for (int j = 0; j < ship.getHP(); j++)
						if (cells[position.getX() + j][position.getY()] != null)
							throw new IllegalStateException();
					for(int k = 0; k < ship.getHP(); k++){
						this.cells[position.getX() + k][position.getY()] = new Cell(
								ship);}
				} catch (IllegalStateException e) {
					throw e;
				}
				catch(ArrayIndexOutOfBoundsException e){
					throw e;
				}
			}
			if (direction == Direction.WEST) {
				try {
					for (int j = 0; j < ship.getHP(); j++)
						if (cells[position.getX() - j][position.getY()] != null)
							throw new IllegalStateException();
					for(int k = 0; k < ship.getHP(); k++){
						this.cells[position.getX() - k][position.getY()] = new Cell(
								ship);}
				} catch (IllegalStateException e) {
					throw e;
				}
				catch(ArrayIndexOutOfBoundsException e){
					throw e;
				}
			}
			if (direction == Direction.SOUTH) {
				try {
					for (int j = 0; j < ship.getHP(); j++)
						if (cells[position.getX()][position.getY() + j] != null)
							throw new IllegalStateException();
					for(int k = 0; k < ship.getHP(); k++){
						this.cells[position.getX()][position.getY() + k] = new Cell(
								ship);}
				} catch (IllegalStateException e) {
					throw e;
				}
				catch(ArrayIndexOutOfBoundsException e){
					throw e;
				}
			}
			if (direction == Direction.NORTH) {
				try {
					for (int j = 0; j < ship.getHP(); j++)
						if (cells[position.getX()][position.getY() - j] != null)
							throw new IllegalStateException();
					for(int k = 0; k < ship.getHP(); k++){
						this.cells[position.getX()][position.getY() - k] = new Cell(
								ship);}
				} catch (IllegalStateException e) {
					throw e;
				}
				catch(ArrayIndexOutOfBoundsException e){
					throw e;
				}
			}
			if (direction == Direction.NORTH_EAST) {
				try {
					for (int j = 0; j < ship.getHP(); j++)
						if (cells[position.getX() + j][position.getY() - j] != null)
							throw new IllegalStateException();
					for(int k = 0; k < ship.getHP(); k++){
						this.cells[position.getX() + k][position.getY() - k] = new Cell(
								ship);}
				} catch (IllegalStateException e) {
					throw e;
				}
				catch(ArrayIndexOutOfBoundsException e){
					throw e;
				}
			}
			if (direction == Direction.NORTH_WEST) {
				try {
					for (int j = 0; j < ship.getHP(); j++)
						if (cells[position.getX() - j][position.getY() - j] != null)
							throw new IllegalStateException();
					for(int k = 0; k < ship.getHP(); k++){
						this.cells[position.getX() - k][position.getY() - k] = new Cell(
								ship);}
				} catch (IllegalStateException e) {
					throw e;
				}
				catch(ArrayIndexOutOfBoundsException e){
					throw e;
				}
			}
			if (direction == Direction.SOUTH_EAST) {
				try {
					for (int j = 0; j < ship.getHP(); j++)
						if (cells[position.getX() + j][position.getY() + j] != null)
							throw new IllegalStateException();
					for(int k = 0; k < ship.getHP(); k++){
						this.cells[position.getX() + k][position.getY() + k] = new Cell(
								ship);}
				} catch (IllegalStateException e) {
					throw e;
				}
				catch(ArrayIndexOutOfBoundsException e){
					throw e;
				}
			}
			if (direction == Direction.SOUTH_WEST) {
				try {
					for (int j = 0; j < ship.getHP(); j++)
						if (cells[position.getX() - j][position.getY() + j] != null)
							throw new IllegalStateException();
					for(int k = 0; k < ship.getHP(); k++){
						this.cells[position.getX() - k][position.getY() + k] = new Cell(
								ship);}
				} catch (IllegalStateException e) {
					throw e;
				}
				catch(ArrayIndexOutOfBoundsException e){
					throw e;
				}
			}
	}
	
	public void printTouch(){
		for(int j = 0; j < this.height; j++){
			for(int i = 0; i < this.width; i++)
				System.out.print(this.touches[i][j]+" ");
			System.out.println();
		}
		System.out.println();
	}

	public Answer shoot(Position position) {
		this.touches[position.getX()][position.getY()] = true;
		Cell cell = cells[position.getX()][position.getY()];
		if (cell == null)
			return Answer.MISSED;
		Ship ship = cell.getShip();
		cell.hit();
		if (ship.isSunk()) {
			for (int i = 0; i < width; i++)
				for (int j = 0; j < height; j++)
					if (this.cells[i][j].getDamage() == false)
						return Answer.SUNK;
			return Answer.WIN;
		}
		return Answer.HIT;
	}
	
	public boolean getTouch(Position position){
		return this.touches[position.getX()][position.getY()];
	}
	
	public boolean getTouch(int x, int y){
		return this.touches[x][y];
	}

	public void Cheat(String CheatCode) {
		if (CheatCode.toLowerCase() == "EnGodMode".toLowerCase())
			for (int i = 0; i < width; i++)
				for (int j = 0; j < height; j++)
					this.cells[i][j].enableGodMode();
		else if (CheatCode.toLowerCase() == "DisGodMode".toLowerCase())
			for (int i = 0; i < width; i++)
				for (int j = 0; j < height; j++)
					this.cells[i][j].disableGodMode();
	}

}

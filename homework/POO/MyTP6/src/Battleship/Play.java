package Battleship;

public class Play {
	private final static int DEFAULT_MAX_SHIPS = 10;
	private final static int DEFAULT_WIDTH = 15;
	private final static int DEFAULT_HEIGHT = 10;

	private Sea sea1, sea2;
	private Ship[] ships;
	private int Winner = 0;
	
	/**
	 * Auto set.
	 */
	public Play() {
		this.ships = new Ship[DEFAULT_MAX_SHIPS];
		this.sea1 = new Sea(DEFAULT_WIDTH, DEFAULT_HEIGHT);
		this.sea2 = new Sea(DEFAULT_WIDTH, DEFAULT_HEIGHT);
		for (int i = 0; i < DEFAULT_MAX_SHIPS; i++) {
			this.ships[i] = new Ship(3);
		}
	}

	public Play(int MaximumShip, int SeaWidth, int SeaHeight, int shipLife) {
		this.ships = new Ship[MaximumShip];
		this.sea1 = new Sea(SeaWidth, SeaHeight);
		this.sea2 = new Sea(SeaWidth, SeaHeight);
		for (int i = 0; i < MaximumShip; i++) {
			this.ships[i] = new Ship(shipLife);
		}
	}
	
	public void setShipLife(int shipNum, int shipLife){
		this.ships[shipNum].setHP(shipLife);
	}

	public void showSea(int seaNumber, int playerNum) {
		if (playerNum == 1) {
			if (seaNumber == 1) {
				System.out.println("Sea 1 Player 1");
				for (int j = 0; j < sea1.getHeight(); j++) {
					for (int i = 0; i < sea1.getWidth(); i++) {
						if (sea1.getCell(i, j) != null) {
							if (sea1.getCell(i, j).getDamage())
								System.out.print(" * ");
							else
								System.out.print(" B ");
						} else {
							System.out.print(" ~ ");
						}
					}
					System.out.print("\n");
				}
			} 
			else if (seaNumber == 2) {
				System.out.println("Sea 2 Player 1");
				for (int j = 0; j < sea2.getHeight(); j++) {
					for (int i = 0; i < sea2.getWidth(); i++) {
						if (sea2.getCell(i, j) != null) {
							if(!sea2.getCell(i, j).getDamage()){
								System.out.print(" . ");
							}
							else
								System.out.print(" * ");
						}
						else
							if(sea2.getTouch(i,j)){
								System.out.print(" ~ ");
							}
							else
								System.out.print(" . ");
					}
					System.out.print("\n");
				}
			}

			else {
				System.out.println("Sea Number Error.");
			}
		} else if (playerNum == 2) {
			if (seaNumber == 1) {
				System.out.println("Sea 1 Player 2");
				for (int j = 0; j < sea1.getHeight(); j++) {
					for (int i = 0; i < sea1.getWidth(); i++) {
						if (sea1.getCell(i, j) != null) {
							if(!sea1.getCell(i, j).getDamage()){
								System.out.print(" . ");
							}
							else
								System.out.print(" * ");
						}
						else
							if(sea1.getTouch(i,j)){
								System.out.print(" ~ ");
							}
							else
								System.out.print(" . ");
					}
					System.out.print("\n");
				}
			} else if (seaNumber == 2) {
				System.out.println("Sea 2 Player 2");
				for (int j = 0; j < sea2.getHeight(); j++) {
					for (int i = 0; i < sea2.getWidth(); i++) {
						if (sea2.getCell(i, j) != null) {
							if (sea2.getCell(i, j).getDamage())
								System.out.print(" * ");
							else
								System.out.print(" B ");
						} else {
							System.out.print(" ~ ");
						}
					}
					System.out.print("\n");
				}
			}

			else {
				System.out.println("Sea Number Error.");
			}
		} else {
			System.out.println("Sea Number Error.");
		}
	}

	public Answer shootShip(int seaNumber, int x, int y)
			throws IllegalStateException {
		Position position = new Position(x, y);
		Answer ans = Answer.DEFALULT;
		if (seaNumber == 1) {
			ans = this.sea1.shoot(position);
			if (ans == Answer.WIN)
				this.Winner = 1;
		} 
		else if (seaNumber == 2) {
			ans = this.sea2.shoot(position);
			if (ans == Answer.WIN)
				this.Winner = 2;
		}
		return ans;
	}

	public void placeShip(int seaNumber, int shipNumber, Direction direction,
			int x, int y) {
		Position position = new Position(x, y);
		if (seaNumber == 1) {
			try {
				this.sea1.placeShip(ships[shipNumber], direction, position);
			} catch (IllegalStateException e) {
				System.out.println("Already have boat.");
			}
			catch(ArrayIndexOutOfBoundsException e){
				System.out.println("Out of range.");
			}
			catch (Exception e){
				
			}
		} else if (seaNumber == 2) {
			try {
				this.sea2.placeShip(ships[shipNumber], direction, position);
			} catch (IllegalStateException e) {
				System.out.println("Already have boat.");
			}
			catch(ArrayIndexOutOfBoundsException e){
				System.out.println("Out of range.");
			}
			catch (Exception e){
				
			}
		}
	}

	public int getWinner() {
		return this.Winner;
	}

	public String getWinnerString() {
		switch (this.Winner) {
		case 0:
			return "No Winner";
		case 1:
			return "Player1 Won";
		case 2:
			return "Player2 Won";
		default:
			return "Error";
		}
	}
	
	public void pT(int sea){
		switch(sea){
		case 1:sea1.printTouch();break;
		case 2:sea2.printTouch();break;
		}
	}
}

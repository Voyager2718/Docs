package Battleship;

public class main {
	/**
	 * Play -> 	initializer the game. There're 2 constructors in "Play". First one will initialize with a default setting.
	 * 			Second one have 4 parameter: Maximum ships(int)| Sea Width(int)| Sea Height(int)| Ships life(int).
	 * 			-showSea() is a function which is aimed at showing the battlefield.
	 * 				It have 2 parameter. 1st: Sea number(int), 2nd Player number.
	 * 			-shootShip() is used as shooting ships. It will return 1.WIN(shows that there's a winner) 2.MISSED(shows 
	 *				  that the shooting was missed) 3.HIT(Success) 4.SUNK(the ship which was shot has sunk)
	 *			-setShipLife() is a function for setting ship's life.(For those who need to custom each ship's life)
	 *			-placeShip() is a function for placing ships on a sea.
	 *			-getWinner() is a function to get the winner's number.
	 *			-getWinnerString() is a function to tell who's the winner by using String.
	 *			-pT() is a function to print if a cell was hit or not.
	 * @throws IOException 
	 * 
	 * 
	 */
	public static void main(String args[]){
		Play play = new Play();
		play.placeShip(1, 1, Direction.NORTH_EAST, 2, 8);
		play.placeShip(1, 1, Direction.NORTH, 10, 6);
		play.placeShip(2, 1, Direction.SOUTH_EAST, 0, 2);
		play.placeShip(2, 1, Direction.WEST, 8, 4);
		play.shootShip(2, 2, 2);
		play.shootShip(2, 8, 3);
		play.shootShip(2, 1, 3);
		play.shootShip(1, 4, 9);
		play.shootShip(1, 12, 3);
		play.shootShip(1, 10, 8);
		play.showSea(1, 1);
		play.showSea(1, 2);
		play.showSea(2, 2);
		play.showSea(2, 1);
	}
}

/** 
* Subclass of Room, a room which contains a treasure
*/


import java.util.ArrayList;
import java.util.List;

public class TreasureRoom extends Room {
	private List<Equipement> equipements = new ArrayList<Equipement>();

	public TreasureRoom(Equipement equipements) {
		super("Treasure", "This is a room with treasures.");
		this.equipements.add(equipements);
	}



	public TreasureRoom(List<Equipement> equipements) {
		super("Treasure", "This is a room with treasures.");
		this.equipements = equipements;
	}


/**
* @param: List<Equipement>
	List of equipements
* @return the appropriate equipement from the list
*/

	public List<Equipement> getEquipements() {
		return this.equipements;
	}
}

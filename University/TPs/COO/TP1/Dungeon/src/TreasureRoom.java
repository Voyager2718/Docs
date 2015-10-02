/** 
* Subclass of Room, a room which contains a treasure
*/

import java.util.ArrayList;
import java.util.List;

public class TreasureRoom extends Room {
	private List<Equipment> equipements = new ArrayList<Equipment>();

	public TreasureRoom(Equipment equipements) {
		super("Treasure", "This is a room with treasures.");
		this.equipements.add(equipements);
	}

	public TreasureRoom(List<Equipment> equipements) {
		super("Treasure", "This is a room with treasures.");
		this.equipements = equipements;
	}

	/**
	 * @param: List<Equipement>
	 *             List of equipments
	 * @return the appropriate equipment from the list
	 */

	public List<Equipment> getEquipements() {
		return this.equipements;
	}
}

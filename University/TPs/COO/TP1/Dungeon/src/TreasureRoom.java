import java.util.ArrayList;
import java.util.List;

public class TreasureRoom extends Room {
	private List<Equipment> equipments = new ArrayList<Equipment>();

	public TreasureRoom(Equipment equipements) {
		super("Treasure", "This is a room with treasures.");
		this.equipments.add(equipements);
	}

	public TreasureRoom(List<Equipment> equipements) {
		super("Treasure", "This is a room with treasures.");
		this.equipments = equipements;
	}

	public List<Equipment> getEquipements() {
		return this.equipments;
	}
}

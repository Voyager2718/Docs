
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

	public List<Equipement> getEquipements() {
		return this.equipements;
	}
}
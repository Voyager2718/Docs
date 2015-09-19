import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Room{
	String type;
	Map<String, Room> rooms = new HashMap<String, Room>();
	
	protected boolean directionAvailable(String direction) {
		List<String> dir = new ArrayList<String>();
		dir.add("east");
		dir.add("south");
		dir.add("west");
		dir.add("north");
		return dir.contains(direction);
	}
	
	public Room(String type){
		this.type = type;
	}
	
	public String getType(){
		return this.type;
	}
}
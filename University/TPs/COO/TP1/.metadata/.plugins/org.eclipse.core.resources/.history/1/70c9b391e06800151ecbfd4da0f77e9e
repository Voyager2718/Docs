/**  
 * LockedRoom Subclass of Room, a room which you have to unlock
*/
public class LockedRoom extends Room {
	private boolean locked = true;

	public LockedRoom() {
		super("Lock", "This room is locked, you have to find a key to unlock it.");
	}


	public void unlock() {
		this.locked = false;
	}

 
	public void lock() {
		this.locked = true;
	}


/** @return true if the room is locked, false else 
*/

	public boolean getLocked() {
		return this.locked;
	}
}

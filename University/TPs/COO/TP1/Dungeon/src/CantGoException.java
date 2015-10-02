/**
* subclass of Exception, serves to generate exceptions when user try to go somewhere that have no room
*/
public class CantGoException extends Exception {
	
	private static final long serialVersionUID = 1L;
	private String message;

	public CantGoException(String message) {
		this.message = message;
	}

	public String getMessage() {
		return this.message;
	}
}

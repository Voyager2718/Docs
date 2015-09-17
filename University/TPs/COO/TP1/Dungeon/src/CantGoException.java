
public class CantGoException extends Exception {
	/**
	 * If user try to go somewhere that have no room, throw this Exception.
	 */
	private static final long serialVersionUID = 1L;
	private String message;

	public CantGoException(String message) {
		this.message = message;
	}

	public String getMessage() {
		return this.message;
	}
}

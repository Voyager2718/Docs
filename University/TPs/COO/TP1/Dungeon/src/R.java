/**  
* Supper class, serves to give a description of the rooms and their types
*/
public class R {
	protected String type;
	protected String description;

	public R(String type, String description) {
		this.type = type;
		this.description = description;
	}

	public String getType() {
		return this.type;
	}

	protected String getDescription() {
		return this.description;
	}
}

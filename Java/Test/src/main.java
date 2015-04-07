class A{
	public int a;
	A(int a){
		this.a=a;
	}
}

public class main{
	public static void p(A a){
		System.out.println(a.a);
	}
	
	public static void main(String argv[]){
		for (int j = 0; j < 3; j++){
			System.out.println("j="+j);
			if (false)
				throw new IllegalStateException(
						"Already have ship.");System.out.println("j2="+j);}
	}
}
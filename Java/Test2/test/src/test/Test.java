package test;

class Father {
	public int a;
}

class Son extends Father {
	protected int b;

	public Son(int a_F, int a_S) {
		b = a_S;
		super.a = a_F;
	}

	public void p() {
		System.out.println(b + " " + super.a);
	}
}

public class Test {
	public static void main(String args[]) {
		(new Son(10, 20)).p();
	}
}

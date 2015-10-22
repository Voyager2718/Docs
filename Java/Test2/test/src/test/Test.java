package test;

abstract class Father {
	protected int a;

	public Father(int a) {
		this.a = a;
	}

	abstract public int getA();

	public float _getA() {
		return (float) a;
	}
}

class Son extends Father {
	public Son(int a) {
		super(a);
	}

	public int getSuperA() {
		return super.a;
	}

	public int getA() {
		return a;
	}
}

public class Test {
	public static void main(String args[]) {
		Son son = new Son(20);
		System.out.println(son.getA() + " " + son.getSuperA() + " " + son._getA());
	}
}
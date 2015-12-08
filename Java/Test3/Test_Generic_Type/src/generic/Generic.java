package generic;

class A<C> {
	public C a;

	public A() {

	}
}

class MyException extends Exception{
	
}

class B<C, D> extends A<D> {
	public C b;

	public B() {
		
	}
}

class C {
	public Integer i;

	public C() {
		this.i = new Integer(10);
	}
}

public class Generic {
	public static void main(String args[]) {
		B<Integer, Float> b = new B<Integer, Float>();
		System.out.println("b.b instanceof Integer: " + (b.b instanceof Integer));
		System.out.println("b.a instanceof Float: " + (b.a instanceof Float));
	}
}
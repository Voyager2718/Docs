package generic;

class A {
	public String f() {
		return g();
	}

	public String g() {
		return "A.g()";
	}
}

class B extends A {
	public String g() {
		return "B.g()";
	}
}

public class Generic {
	public static void main(String[] args) {
		A a = new B();
		B b = new B();
		System.out.println(a.f());
		System.out.println(b.f());
		System.out.println(((B)a).f());
		System.out.println(((A)b).f());
		//System.out.println( ((B)new A()).f() );
	}
}
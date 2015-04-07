import java.io.*;
import java.util.Date;
class A {

}

class B extends A {
	static int a;

	static void printhh() {
		System.out.print(a);
	}

	static void printa() {
		printhh();
	}
}

final class C extends B {
	void func1() {
		try {
			int a = 1 / 0;
		} catch (Exception e) {
			System.out.println(e);
			System.exit(0);
		}
	}
}

public class Test {
	public static void main(String args[]) {
		B b = new B();
		C c = new C();
		Date date = new Date();
		b.a = 10;
		c.a = 20;
		//c.func1();
		b.printa();
		System.out.println(date.toString());
		int a = 100;
		System.out.printf("a=%d.",a);
	}
}
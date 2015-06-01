package tests;

import java.util.*;

enum a {
	Mon
};

class B {
	public int a;
	public double b;

	public B() {
		this.a = 100;
	}

	public boolean equals(Object o) {
		if (o instanceof B) {
			B b = (B) o;
			return this.a == b.a;
		}
		return false;
	}

}

class A {
	public int a;
	public double b;

	public A() {
		this.a = 100;
	}
}

public class main {
	public static void main(String args[]) {
		/*
		 * Map<String, String> map = new HashMap<String, String>();
		 * map.put("123", "abc"); map.put("124", "bcd"); map.put("1924", "1");
		 * Iterator<String> iter = map.values().iterator(); while
		 * (iter.hasNext()) { System.out.println(iter.next()); }
		 * 
		 * for (String s : map.keySet()) System.out.println(s);
		 * 
		 * System.out.println(iter.hashCode());
		 * 
		 * B a = new B(), c = new B(); A b = new A(); b.a = 100;
		 * System.out.println(a.hashCode()); System.out.println(b.hashCode());
		 * System.out.println(c.hashCode());
		 * 
		 * String str0 = "123", str1 = "456", str2 = "123", str3 = new String(
		 * "123"); str1 = "123"; System.out.println(str0.hashCode() + " " +
		 * str1.hashCode() + " " + str2.hashCode() + " " + str3.hashCode());
		 * System.out.println(str1 == str3); System.out.println(map.toString());
		 */
		Map<String, String> map = new HashMap<String, String>();
		Map<String, String> map2 = new HashMap<String, String>();
		map.put("a", "aaa");
		map.put("b", "bbb");
		System.out.println(map.get("a"));
		System.out.println(map.toString());
		for (Map.Entry<String, String> entry : map.entrySet())
			System.out.println(entry.getKey());

		for (String key : map.keySet()) {

		}
		System.out.println(map.hashCode());

		List<String> list = new ArrayList<String>();
		list.add("value0");
		List<String> list2 = new ArrayList<String>();
		list2.addAll(list);
		map2.putAll(map);
		System.out.println(list2.toString());
		System.out.println(list.get(0));
		Iterator iter = list.iterator();
		while (iter.hasNext()) {
			System.out.println(iter.next());
		}
		for (String s : list)
			System.out.println(s);
		System.out.println(map.size());

		
	}
}
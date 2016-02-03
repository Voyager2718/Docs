#include <iostream>


using namespace std;

int main() {
	char *a[3] = { "abc", "def", "ghi" };
	cout << sizeof(a) << endl;
	cout << sizeof(&a) << endl;
	cout << sizeof(*&a) << endl;

	int b[] = { 4, 5 };
	system("pause");
	return 0;
}
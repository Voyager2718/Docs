#include<iostream>
#include<Windows.h>
using namespace std;

int main(void){
	int m = 1000;
	system("pause");
	while (true || m > 1){
		if (m < 1)
			break;
		try{
			double *a = new double[500000000 / m];
			for (int i = 0; i < 500000000 / m; i++)
				*(a + i) = i;
			free(a);
			m /= 1.05;
			cout << m << endl;
		}
		catch (bad_alloc ba){
			cerr << (500000000 / m) * sizeof(double) / 1024 / 1024 << endl;
			break;
		}
	}
	cerr << (500000000 / (m + 1)) * sizeof(double) / 1024 / 1024 << endl;
	system("pause");
	return 0;
}
#include<iostream>
using namespace std;
int main(void){
	int a[] = { 73, 50, 128, 170, 87, 108, 130, 74, 88, 139 };
	int b[] = { 30, 20, 60, 80, 40, 50, 60, 30, 40, 60 };
	double s_a = 0, moy_a = 0, s_b = 0, moy_b = 0;

	for (int i = 0; i < 10; i++){
		moy_a += a[i];
	}
	moy_a /= 10;
	for (int i = 0; i < 10; i++){
		s_a += (a[i] - moy_a)*(a[i] - moy_a);
	}

	for (int i = 0; i < 10; i++){
		moy_b += b[i];
	}
	moy_b /= 10;
	for (int i = 0; i < 10; i++){
		s_b += (b[i] - moy_b)*(b[i] - moy_b);
	}

	double cv = 0;
	for (int i = 0; i < 10; i++){
		cv += (a[i] - moy_a)*(b[i] - moy_b);
	}

	cout << "Moy x:" << moy_b << endl;
	cout << "Ecart x:" << sqrt(s_b / 10) << endl;
	cout << "Vari x:" << (s_b / 10) << endl;
	cout << endl;
	cout << "Moy y:" << moy_a << endl;
	cout << "Ecart y:" << sqrt(s_a / 10) << endl;
	cout << "Vari y:" << (s_a / 10) << endl;
	cout << endl;
	cout << "Covar:" << cv / 10 << endl;
	system("pause");
}
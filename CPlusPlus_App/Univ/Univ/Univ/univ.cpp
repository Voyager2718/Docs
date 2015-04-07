#include <iostream>

using namespace std;

class Complex{
public:
	Complex (){
		re = 0;
		im = 0;
	}

	Complex(int a, int b){
		re = a;
		im = b;
	}

	void printComplex(){
		printf("%d+%di",re,im);
	}

	void editComplex(int a, int b){
		re = a;
		im = b;
	}

private:
	int re, im;
};

int main(int argc, char* argv[])
{
	return 0;
}
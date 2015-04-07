int * func1(int *p){
	(*p)++;
	return p;
}

int* (*func2(int (*(*pf)(int*)),int *p))(int*) {
	cout<<*(pf(p))<<endl;
	return pf;
}//C++11之前的标准

auto func3(int (*(*pf)(int*)),int *p) -> int *(*)(int*) {
	cout<<*(pf(p))<<endl;
	return pf;
}//C++11标准

int main (int argc, char * argv[]){
	int (*(*pf)(int*)),a=10,*p=&a;
	pf=&func1;
	
	cout<<*(pf(p))<<endl;
	
	func3(pf,p);
	func2(pf,p);
	return 0;
}

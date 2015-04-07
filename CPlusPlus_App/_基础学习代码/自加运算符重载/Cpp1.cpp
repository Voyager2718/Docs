#include <iostream>
using namespace std;
class Test {
public:
	Test (long y,int d,int h,int m,int s):year(y),day(d),hour(h),min(m),sec(s){}
	Test operator ++(){
		if (sec>=59)
		{
			sec=0;
			++min;
		}
		if (min>59){
			min=0;
			++hour;
		}
		if (hour>23){
			hour=0;
			++day;
		}
		if (day>364){
			day=0;
			++year;
		}
		++sec;
		return *this;
	}
	void Output (){
		cout<<year<<":"<<day<<":"<<hour<<":"<<min<<":"<<sec<<endl;
	}
private:
	int day,hour,min,sec;
	long year;
};
void main(){
	Test a(0,0,0,0,0);
	for (;;)
	{
		++a;
		a.Output();
	}
}
		

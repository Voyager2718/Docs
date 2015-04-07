#include <iostream>
using namespace std;
template <typename T>
class Test{
public:
//	Test(T a,T b){
//		x=a;y=b;}
	T x;T y;
	T Max(T x,T y);
	T Min(T w,T z){
		return (w<z)? w:z;
	}
	friend a(Test&);
};
void f(){
	Test<float> b;
	cout<<"___________"<<b.x<<" "<<b.y<<endl;
}
template <class T>
T Test<T>::Max(T x,T y){
		return (x>y)? x:y;
}
int main(){
	Test <float> a;
	float b=35.5;
	cout<<a.Max(35,b)<<endl;
	f();
	return 0;
}
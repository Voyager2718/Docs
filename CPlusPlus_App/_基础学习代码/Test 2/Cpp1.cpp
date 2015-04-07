#include<iostream>
using namespace std;
template <class a>
a function(a a1,a a2,a a3){
	if (a2>a1) a1=a2;
	if (a3>a1) a1=a3;
	cout<<a1<<endl;
	return a1;
}
int main (){
	int a,b,c;
	cin>>a>>b>>c;
	cout<<"here"<<endl;
	function(a,b,c);
	float d,e,f;
	cin>>d>>e>>f;
	function(d,e,f);
	return 0;
}

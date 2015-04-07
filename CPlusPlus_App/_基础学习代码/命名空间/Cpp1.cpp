#include<iostream>
using namespace std;
namespace ns1{
	int a(){
		return 1;
	}
}
namespace ns2{
	namespace ns3{
		int a(){
			return 3;
		}
	}
	int a(){
		return 2;
	}
}
void main(){
	cout<<ns1::a()<<endl<<ns2::a()<<endl<<ns2::ns3::a()<<endl;
}
#include<string>
#include<iostream>
using namespace std;

class qrcode{
private:
	string str;
	char correction;

public:
	qrcode(string str);
	void setString(string str);
};

qrcode::qrcode(string str){
	this->setString(str);
}

void qrcode::setString(string str){
	this->str = str;
}
#include<iostream>
#include"inherit.h"

using std::cout;
using std::endl;

father::father(){
	this->a = 10;
}

void father::print(){
	cout << "father" << endl;
}

void father::printA(){
	cout << this->a << endl;
}

sonA::sonA(){
	this->a = 20;
}

void sonA::print(){
	cout << "sonA" << endl;
}

sonB::sonB(){
	this->a = 30;
}

void sonB::print(){
	cout << "sonB" << endl;
}

grandSon::grandSon() :sonA(), sonB(){
	this->sonA::a = 10;
}

void grandSon::print(){
	cout << "grandSon" << endl;
}
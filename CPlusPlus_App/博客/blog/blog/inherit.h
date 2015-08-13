#ifndef inherit_h
#define inherit_h

class father
{
public:
	father();
	virtual void print();
	void printA();
protected:
	int a;
};

class sonA : virtual public father
{
public:
	sonA();
	virtual void print();
};

class sonB : virtual public father
{
public:
	sonB();
	virtual void print();
};

class grandSon :virtual public sonA, virtual public sonB
{
public:
	grandSon();
	virtual void print();
};

#endif
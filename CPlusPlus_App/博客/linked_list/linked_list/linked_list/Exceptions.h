#include<string>
using std::string;

class Exception{
private:
	string message;
public:
	Exception(string message){
		this->message = string(message);
	}

	Exception(){}

	string getMessage(){
		return message;
	}
};

class IndexOutOfRangeException :public Exception{};
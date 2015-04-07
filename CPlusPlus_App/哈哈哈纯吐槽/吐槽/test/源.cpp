#include<iostream>
#include<string>
using namespace std;
class girl{
	/*程度、能力等等∈[0,100]*/
	/*纯调侃，女生勿怪*/
	/*亮点自寻*/
private:
	string 爱人;string 伴侣;string 备胎;string 性伴侣;string 孩子他爸;
	bool 做爱？;int 做过爱的人数;
	long 堕胎次数;bool 能怀孕;
	int 漂亮程度;long 存款;
	int 月薪;bool 房子;
	bool 车子;
public:
	girl(int 漂亮程度){
		爱人="帅哥";做爱？=false;
		做过爱的人数=0;堕胎次数=0;
		能怀孕=true;this->漂亮程度=漂亮程度;
		伴侣="";备胎="";性伴侣="";
	}
	~girl(){
		(int)漂亮程度=漂亮程度*0.2;
	}
	void setHusband(string 谁？,double 存款,long 月薪,
		bool 房子,bool 车子,int 忠诚度,int 性能力){
			int 参数=漂亮程度*漂亮程度;
			if (存款>10000000+1000*参数&&月薪>25000+5*参数&&
				房子==true&&车子==true&&性能力>75)
				伴侣=谁？;
			else if (月薪>50000+10*参数&&房子==true&&
				车子==true&&忠诚度>=90&&性能力>75)
				伴侣=谁？;
			else if (月薪>100000+20*参数&&
				车子==true&&忠诚度>=95&&性能力>75)
				伴侣=谁？;
			else if (做爱？==true&&做过爱的人数>20&&堕胎次数>=3&&
				能怀孕==true&&月薪>20000&&车子==true)
				伴侣=谁？;
			else if(做爱？==true&&做过爱的人数>20&&堕胎次数>=3&&
				能怀孕==false&&月薪>5000)
				伴侣=谁？;
			else
			{
				备胎=谁？;
				if (性能力>90)
					性伴侣=谁？;
			}
			if(孩子他爸!=备胎)
				伴侣=备胎;
	}
	void setLover(string 谁？,int 帅气程度,double 存款,
		long 月薪,bool 车子,int 性能力){
			if (帅气程度>80||
				(存款>5000000&&月薪>30000&&车子==true&&性能力>75))
				爱人=谁？;
			else
			{
				备胎=谁？;
				if (性能力>90)
					性伴侣=谁？;
			}
	}
};
int main(void){
	system("pause");
}
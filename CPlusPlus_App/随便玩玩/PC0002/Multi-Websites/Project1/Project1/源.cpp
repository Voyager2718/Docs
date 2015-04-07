#include<iostream>
#include<conio.h>
#include<Windows.h>
#define PW_Output temp
#define PW_Output2 "*"
#define PW_Encrypt 159-temp
//#define Times 100
#define Maximum 50
#define Error_Input "你的输入出错，请重新输入。"
#define Puts_Website "请输入你想计算的网站（不大于50个字符且区分大小写），按回车键结束。"
#define Puts_RacinePW "请输入你的根密码（不大于50个字符且区分大小写），按回车键结束。"
#define Puts_Result "这里是根据你输入的数据算出你在此网站的密码："
#define Puts_Begin "欢迎来到多网站计算器。本软件可以帮助你在只需要记住根密码的情况下在不同网站使用不同密码。"
#define StarTimes 75
#define StarOrWhat "*"
#define Puts_Thank "感谢你使用本软件"<<endl<<"如有任何意见或者建议，可以致信Voyager2718@Gmail.com寻求帮助"
using namespace std;
class Time{
public:
	double Count(char Get[]){
		double Times=0;
		for (int i0=0;i0<Maximum&&Get[i0]!='\0';i0++)
			Times=Times*((Get[i0]%11)+1)+1;
		for (;Times>1000000;)
			Times/=3;
		for (;Times<10000;)
			Times*=3;
		return Times;
	}
};
class Input{	//输入类
public:
	int GetPW(char &PW_in,int Type){		//检查输入数据之后赋值；若输入出错，返回false，不赋值
		char temp;
		temp=getch();
		if ((temp<33||temp>126)&&temp!=13){
			if (temp==0||temp==224)
				getch();
			return 0;
		}
		if (temp==13){
			return 1;
		}
		PW_in=PW_Encrypt;
		if (Type==1)
			cout<<PW_Output;
		else
			cout<<PW_Output2;
		return 2;
	}
};//GetPW(char&);→自动检查ASCII在33~126之间，并赋值（失败输出false）【回车自动不赋值返回1】{成功返回2}
class Generate:public Time{
public:
	void Generator(char PW_in[]){
		double Times=Count(PW_in);int howmany=0;
		for (;PW_in[howmany]!='\0';howmany++);
		for (int i0=0;i0<Times;i0++){
			char temp=PW_in[0];
			for (int i1=0;i1<Maximum&&PW_in[i1]!='\0';i1++){
				if (i1>=howmany)
					PW_in[i1]=temp;
				else
					PW_in[i1]=PW_in[i1+1];
				PW_in[i1+1]=PW_in[i1];
				int Remainder=0;
				Remainder=(PW_in[i1]%7+1);
				if (PW_in[i1]>=123)
					PW_in[i1]=33+Remainder;
				else
					PW_in[i1]+=Remainder;
			}
		}
	}
};
class Assign{
public:
	void Assignment(char Get[],int Type){
M1:
		Input A;
		//for (int i=0;i<Maximum;i++)
			//Get[i]='\0';
		int re=0;
		for (int i0=0;i0<Maximum;i0++){
			re=A.GetPW(Get[i0],Type);
			if (re==0){
				cout<<Error_Input<<endl;
				goto M1;
			}
			if (re==1)
				break;
		}
	}
};
void Print(int Type){
	if (Type==0)
		cout<<Puts_Begin<<endl;
	if (Type==1)
		cout<<Puts_Website<<endl;
	if (Type==2)
		cout<<Puts_RacinePW<<endl;
	if (Type==3)
		cout<<Puts_Result<<endl;
	if (Type==4)
		cout<<Puts_Thank<<endl;
	if (Type==99){
		for (int i=0;i<StarTimes;i++)
			cout<<StarOrWhat;
		cout<<endl;
	}
}
int main(){
	/*system("title Multi-Website Password Calculator v0.0.2.1010");
	char Website[Maximum+1]={'\0'},RacinePassword[Maximum+1]={'\0'},bell=7;
	Assign A;
	Generate A2,B2,T;
	Print(0);
	Print(99);
	Print(1);
	A.Assignment(Website,1);
	A2.Generator(Website);
	cout<<endl;
	Print(99);
	cout<<endl;
	Print(2);
	A.Assignment(RacinePassword,2);
	B2.Generator(RacinePassword);
	for (int i=0;i<Maximum&&(RacinePassword[i]!='\0');i++)
		RacinePassword[i]=(RacinePassword[i]+Website[i])/2;
	T.Generator(RacinePassword);
	cout<<endl;
	Print(3);
	cout<<RacinePassword<<endl<<endl;
	Print(4);
	cout<<endl;
	cout<<bell;
	Sleep(100);
	cout<<bell;*/
	Generate A;char a[3]={'\0'};
	A.Generator(a);
	system("pause");
	return 0;
}
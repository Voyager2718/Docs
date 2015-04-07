#define Error_Input "您的输入有误，请重新输入"
#define PW_Length 20
#define PW_Output temp
#define PW_Encrypt 159-temp
//退格是27
//||(temp=71)||(temp=79)||(temp=73)||(temp=81)||(temp=82)||(temp=75)||(temp=72)||(temp=80)||(temp=77)||(temp>=59&&temp<=68)
#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;
class Input{	//输入类
public:
	int GetPW(char &PW_in){		//检查输入数据之后赋值；若输入出错，返回false，不赋值
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
		cout<<PW_Output;
		return 2;
	}
};//GetPW(char&);→自动检查ASCII在33~126之间，并赋值（失败输出false）【回车自动不赋值返回1】{成功返回2}
class Password{
public:
	bool Valid(char PW_in[]){	//密码验证函数（输入的数组是真正密码）
		M1:		//错误循环
		Input Val_PW;
		char PW_temp[PW_Length+1]={'\0'};
		for (int i1=0;i1<PW_Length;i1++){	//对临时的数组进行赋值
			int Type=0;
			Type=Val_PW.GetPW(PW_temp[i1]);	
			if (Type==0){	//返回0证明出错
				cout<<Error_Input<<endl;
				goto M1;
			}
			if (Type==1){	//返回1证明输入了回车
				break;
			}
		}
		for (int i2=0;i2<PW_Length&&PW_temp[i2]!='\0';i2++){
			if (PW_temp[i2]!=PW_in[i2])
				return false;
		}
		return true;
	}
	bool SetPassword(char PW_in[]){		//密码设置函数（输入的数组是空数组）【注意 可能并不需要清空密码】
		M2:		//错误循环
		for (int i0=0;i0<PW_Length;i0++){
			PW_in[i0]='\0';
		}	//清空输入数组的全部内容
		Input Set_PW;
		for (int i1=0;i1<PW_Length;i1++){	//对输入的数组进行赋值
			int Type=0;
			Type=Set_PW.GetPW(PW_in[i1]);
			if (Type==0){	//返回0证明出错
				cout<<Error_Input<<endl;
				goto M2;
			}
			if (Type==1){	//返回1证明输入了回车
				return true;
			}
		}
		return true;
	}	  //输入一个空数组，然后等候被赋值。（返回值是false，输入出错）
};
int main(){
	system("title Management v0.0.1");
	Password A;
	char a[PW_Length+1]={'\0'};
	A.SetPassword(a);
	cout<<" "<<a<<endl;
	cout<<A.Valid(a)<<endl;
	cout<<" "<<a<<endl;
	system("pause");
	return 0;
}
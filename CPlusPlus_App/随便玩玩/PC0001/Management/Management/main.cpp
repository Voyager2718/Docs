#define Error_Input "����������������������"
#define PW_Length 20
#define PW_Output temp
#define PW_Encrypt 159-temp
//�˸���27
//||(temp=71)||(temp=79)||(temp=73)||(temp=81)||(temp=82)||(temp=75)||(temp=72)||(temp=80)||(temp=77)||(temp>=59&&temp<=68)
#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;
class Input{	//������
public:
	int GetPW(char &PW_in){		//�����������֮��ֵ���������������false������ֵ
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
};//GetPW(char&);���Զ����ASCII��33~126֮�䣬����ֵ��ʧ�����false�����س��Զ�����ֵ����1��{�ɹ�����2}
class Password{
public:
	bool Valid(char PW_in[]){	//������֤������������������������룩
		M1:		//����ѭ��
		Input Val_PW;
		char PW_temp[PW_Length+1]={'\0'};
		for (int i1=0;i1<PW_Length;i1++){	//����ʱ��������и�ֵ
			int Type=0;
			Type=Val_PW.GetPW(PW_temp[i1]);	
			if (Type==0){	//����0֤������
				cout<<Error_Input<<endl;
				goto M1;
			}
			if (Type==1){	//����1֤�������˻س�
				break;
			}
		}
		for (int i2=0;i2<PW_Length&&PW_temp[i2]!='\0';i2++){
			if (PW_temp[i2]!=PW_in[i2])
				return false;
		}
		return true;
	}
	bool SetPassword(char PW_in[]){		//�������ú���������������ǿ����飩��ע�� ���ܲ�����Ҫ������롿
		M2:		//����ѭ��
		for (int i0=0;i0<PW_Length;i0++){
			PW_in[i0]='\0';
		}	//������������ȫ������
		Input Set_PW;
		for (int i1=0;i1<PW_Length;i1++){	//�������������и�ֵ
			int Type=0;
			Type=Set_PW.GetPW(PW_in[i1]);
			if (Type==0){	//����0֤������
				cout<<Error_Input<<endl;
				goto M2;
			}
			if (Type==1){	//����1֤�������˻س�
				return true;
			}
		}
		return true;
	}	  //����һ�������飬Ȼ��Ⱥ򱻸�ֵ��������ֵ��false���������
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
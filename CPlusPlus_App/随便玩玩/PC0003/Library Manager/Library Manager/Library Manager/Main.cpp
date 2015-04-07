#define NameMaximum 200
#define HowManyTimes 100
#define BookMaximum 100
#define PeopleMaximum 100
#define BookQuantity 100
#define PeopleQuantity 100

#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<fstream>

using namespace std;
class Database{
private:
	struct Book{	//������ݿ�
		Book(){		//��ʼ��
			for(int i0=0;i0<NameMaximum;i0++)
				BookName[i0]='\0';
			for(int i1=0;i1<BookMaximum;i1++)
				InLib=0;
			for(int i2=0;i2<HowManyTimes;i2++)
				Time_Lent[i2]=0;
			for(int i3=0;i3<HowManyTimes;i3++)
				Time_Return[i3]='\0';
		}
		char BookName[NameMaximum];	//����
		bool InLib;	//�ڿ⣿
		long Time_Lent[HowManyTimes];	//���ʱ�� HowManyTimesΪ�ڼ���
		long Time_Return[HowManyTimes];	//�黹ʱ��
	};
	struct People{	//�˵����ݿ�
		People(){	//��ʼ��
			for(int i0=0;i0<NameMaximum;i0++)
				PeopleName[i0]='\0';
			for(int i1=0;i1<BookMaximum;i1++)
				BookNumber[i1]=0;
			for(int i2=0;i2<HowManyTimes;i2++)
				Time_Lent[i2]=0;
			for(int i3=0;i3<HowManyTimes;i3++)
				Time_Return[i3]='\0';
		}
		char PeopleName[NameMaximum];	//����
		int BookNumber[HowManyTimes];	//������һ����
		long Time_Lent[HowManyTimes];	//���ʱ��;
		long Time_Return[HowManyTimes];	//�黹ʱ��
	};
	struct Data{
		Book BookFiles[BookQuantity];People PeopleFiles[PeopleQuantity];//��������
	};
	Data DB;

public:
/////////////////////////////////////////////////
//�����Ƕ����ݿ�Ĳ���
/////////////////////////////////////////////////

	//�����Ƿ����ģ��
	bool PutBookName(char BookName[NameMaximum],int BookNumber){	//��������
		strcpy(DB.BookFiles[BookNumber].BookName,BookName);
		return 0;
	}
	bool PutBookInLib(bool InLib,int BookNumber){	//�����ڿ����
		DB.BookFiles[BookNumber].InLib=InLib;
		return 0;
	}
	bool PutBookTime_Lent(long Time_Lent,int BookNumber,int Time){	//������ʱ�� Time�ڼ��ν��飬BookNumber������һ��
		DB.BookFiles[BookNumber].Time_Lent[Time]=Time_Lent;
		return 0;
	}
	bool PutBookTime_Return(long Time_Return,int Time,int BookNumber){	//����黹ʱ�� Time�ڼ��ν��飬BookNumber������һ��
		DB.BookFiles[BookNumber].Time_Return[Time]=Time_Return;
		return 0;
	
	bool PutPeopleName(char PeopleName[NameMaximum],int PeopleNumber){	//�������� 
		strcpy(DB.PeopleFiles[PeopleNumber].PeopleName,PeopleName);
		return 0;
	}
	bool PutPeopleBook(int BookNumber,int Time,int PeopleNumber){ //���������Ŀ Time�ڼ��ν��飬BookNumber������һ����PeopleNumber˭�����
		DB.PeopleFiles[PeopleNumber].BookNumber[Time]=BookNumber;
		return 0;
	}
	bool PutPeopleTime_Lent(int BookNumber,int Time,int PeopleNumber,long Time_Lent){ //
		DB.PeopleFiles[PeopleNumber].Time_Lent[Time]=Time_Lent;
		return 0;
	}
	bool PutPeopleTime_Return(int BookNumber,int Time,int PeopleNumber,long Time_Return){ //
		DB.PeopleFiles[PeopleNumber].Time_Return[Time]=Time_Return;
		return 0;
	}

	//������ȡ����ģ��
	char* GetBookName(int BookNumber){	//��ȡ����
		char(*BookName)[NameMaximum];BookName=&DB.BookFiles[BookNumber].BookName;
		return *BookName;
	}
	char* GetPeopleName(int PeopleNumber){	//��ȡ����
		char(*PeopleName)[NameMaximum];PeopleName=&DB.BookFiles[PeopleNumber].BookName;
		return *PeopleName;
	}
	
	//IOģ��
	bool Save(){	//����
		ofstream Save("Lib.dat",ios::binary);
		Save.write((char*)&DB,sizeof(DB));
		return 0;
	}
	bool Load(){	//��ȡ
		ifstream Load("Lib.dat",ios::binary);
		Load.read((char*)&DB,sizeof(DB));
		return 0;
	}


};

//���Թ��ܢ١�
bool PutBookName(Database* DATA){
	char BookName[200];cin>>BookName;
	DATA->PutBookName(BookName,0);
	return 0;
}

int main(void){
	Database *DATA=new Database;
	cout<<"Entrez le nom de livre"<<endl;
	PutBookName(DATA);
	//DATA->Load();
	
	cout<<DATA->GetBookName(0)<<endl;
	DATA->Save();
	system("pause");
	return 0;
}
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
	struct Book{	//书的数据库
		Book(){		//初始化
			for(int i0=0;i0<NameMaximum;i0++)
				BookName[i0]='\0';
			for(int i1=0;i1<BookMaximum;i1++)
				InLib=0;
			for(int i2=0;i2<HowManyTimes;i2++)
				Time_Lent[i2]=0;
			for(int i3=0;i3<HowManyTimes;i3++)
				Time_Return[i3]='\0';
		}
		char BookName[NameMaximum];	//书名
		bool InLib;	//在库？
		long Time_Lent[HowManyTimes];	//借出时间 HowManyTimes为第几次
		long Time_Return[HowManyTimes];	//归还时间
	};
	struct People{	//人的数据库
		People(){	//初始化
			for(int i0=0;i0<NameMaximum;i0++)
				PeopleName[i0]='\0';
			for(int i1=0;i1<BookMaximum;i1++)
				BookNumber[i1]=0;
			for(int i2=0;i2<HowManyTimes;i2++)
				Time_Lent[i2]=0;
			for(int i3=0;i3<HowManyTimes;i3++)
				Time_Return[i3]='\0';
		}
		char PeopleName[NameMaximum];	//人名
		int BookNumber[HowManyTimes];	//借了哪一本书
		long Time_Lent[HowManyTimes];	//借出时间;
		long Time_Return[HowManyTimes];	//归还时间
	};
	struct Data{
		Book BookFiles[BookQuantity];People PeopleFiles[PeopleQuantity];//定义数据
	};
	Data DB;

public:
/////////////////////////////////////////////////
//以下是对数据库的操作
/////////////////////////////////////////////////

	//以下是放入的模块
	bool PutBookName(char BookName[NameMaximum],int BookNumber){	//放入书名
		strcpy(DB.BookFiles[BookNumber].BookName,BookName);
		return 0;
	}
	bool PutBookInLib(bool InLib,int BookNumber){	//放入在库与否
		DB.BookFiles[BookNumber].InLib=InLib;
		return 0;
	}
	bool PutBookTime_Lent(long Time_Lent,int BookNumber,int Time){	//放入借出时间 Time第几次借书，BookNumber借了哪一本
		DB.BookFiles[BookNumber].Time_Lent[Time]=Time_Lent;
		return 0;
	}
	bool PutBookTime_Return(long Time_Return,int Time,int BookNumber){	//放入归还时间 Time第几次借书，BookNumber借了哪一本
		DB.BookFiles[BookNumber].Time_Return[Time]=Time_Return;
		return 0;
	
	bool PutPeopleName(char PeopleName[NameMaximum],int PeopleNumber){	//放入人名 
		strcpy(DB.PeopleFiles[PeopleNumber].PeopleName,PeopleName);
		return 0;
	}
	bool PutPeopleBook(int BookNumber,int Time,int PeopleNumber){ //放入借书书目 Time第几次借书，BookNumber借了哪一本，PeopleNumber谁借的书
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

	//以下是取出的模块
	char* GetBookName(int BookNumber){	//读取书名
		char(*BookName)[NameMaximum];BookName=&DB.BookFiles[BookNumber].BookName;
		return *BookName;
	}
	char* GetPeopleName(int PeopleNumber){	//读取人名
		char(*PeopleName)[NameMaximum];PeopleName=&DB.BookFiles[PeopleNumber].BookName;
		return *PeopleName;
	}
	
	//IO模块
	bool Save(){	//保存
		ofstream Save("Lib.dat",ios::binary);
		Save.write((char*)&DB,sizeof(DB));
		return 0;
	}
	bool Load(){	//读取
		ifstream Load("Lib.dat",ios::binary);
		Load.read((char*)&DB,sizeof(DB));
		return 0;
	}


};

//测试功能①↓
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
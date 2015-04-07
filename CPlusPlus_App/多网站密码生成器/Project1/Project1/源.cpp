#include<iostream>
#define Times 50
using namespace std;
char Correct(char Input){ //更正数据
	for (bool i=false;i=false;){
		if ((Input<48||(Input>57&&Input<64)||(Input>90&&Input<97))&&Input!=35&&Input!=33){
			++Input;
			continue;
		}
		if (Input>122){
			--Input;
			continue;
		}
	}
	return Input;
}
char Check(char Input){ //检查数据
	if ((Input<48||(Input>57&&Input<65)||(Input>90&&Input<97)||Input>122)&&Input!=35&&Input!=33)
			return 1;
	return 0;
}
void Version(){
	cout<<"多网站密码生成器 Multi-Website Password Generator"<<endl;
	cout<<"版本号：0900a Version:0900a"<<endl;
}
class Generator{
public:
	char Generate(char Input){//输入的数必须符合规范;（加密数据）
		if (Input==35)
			return 35;
		if (Input<=57)
			return Input+55;
		if (Input==64)
			return 53;
		if (Input<=74)
			return Input-17;
		if (Input<=80)
			return Input+23;
		if (Input<=90)
			return Input+32;
		return 187-Input;
	}
	char Mix(char Input1,char Input2){//输入的数必须符合规范;（混合两个数据）
		char Mixed;
		Mixed=(Input1+Input2)/2;
		Mixed=Correct(Mixed);
		return Mixed;
	}
};
int main(){
	Version();
	char InputWWW[20],InputPW[20],Result[20];
	int Count;
	L1:
	cout<<"请输入网站域名（就是.com前面部分；仅支持数字，大小写字母和\"!\"）长度不应大于20位（大于20位的数据将被忽略）。"<<endl;
	cout<<"若数据不足20位，请在末尾输入\"#\"。"<<endl;
	for (int i=0;i<20;i++){
		cin>>InputWWW[i];
		if (((Check(InputWWW[i]))==1)){
			cout<<"输入错误，请重新输入。"<<endl;
			goto L1;
		}
		if (InputWWW[i]=='#'){
			if (i==0){
				cout<<"输入错误，请重新输入。"<<endl;
				goto L1;
			}
			break;
		}
	}
	L2:
	cout<<"请输入根密码（仅支持数字，大小写字母和\"!\"）长度不应大于20位（大于20位的数据将被忽略）。"<<endl;
	cout<<"若数据不足20位，请在末尾输入\"#\"。"<<endl;
	for (int i2=0;i2<20;i2++){
//		cout<<"i2 "<<i2<<endl;
		cin>>InputPW[i2];
		if (((Check(InputPW[i2]))==1)){
			cout<<"输入错误，请重新输入。"<<endl;
			goto L2;
		}
		if (InputPW[i2]=='#'){
			if (i2==0){
				cout<<"输入错误，请重新输入。"<<endl;
				goto L2;
			}
			break;
		}
		Count=i2+1;
	}
	for (int l2=0;l2<20;l2++){
//		cout<<"②InputPW "<<InputPW[l2]<<" InputWWW "<<InputWWW[l2]<<" Result "<<Result[l2]<<endl;
	}
	Generator Gen;
	for (int i3=0;i3<20;i3++){
		for (int i7=0;i7<Times;i7++){
			InputWWW[i3]=Gen.Generate(InputWWW[i3]);
		}
//		cout<<"③InputPW "<<InputPW[i3]<<" InputWWW "<<InputWWW[i3]<<" Result "<<Result[i3]<<endl;
	}
	for (int i4=0;i4<Count;i4++){
		for (int i8=0;i8<Times;i8++){
			InputPW[i4]=Gen.Generate(InputPW[i4]);
		}
//		cout<<"④InputPW "<<InputPW[i4]<<" InputWWW "<<InputWWW[i4]<<" Result "<<Result[i4]<<endl;
	}
	for (int i5=0;i5<Count;i5++){
		for (int i9=0;i9<Times;i9++){
			Result[i5]=Gen.Mix(InputWWW[i5],InputPW[i5]);
		}
//		cout<<"⑤InputPW "<<InputPW[i5]<<" InputWWW "<<InputWWW[i5]<<" Result "<<Result[i5]<<endl;
	}
	for (int i6=0;i6<Count;i6++){
		cout<<Result[i6];
	}
	cout<<endl;
	for (int l=0;l<20;l++){
//		cout<<"玖InputPW "<<InputPW[l]<<" InputWWW "<<InputWWW[l]<<" Result "<<Result[l]<<endl;
	}
	system("pause");
	return 0;
}
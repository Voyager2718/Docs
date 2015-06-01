#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<list>
#include<stack>

using namespace std;

void vectorTest(){
	/* ���� */
	vector<int> _vec;//declareһ��vector���ͱ���_vec

	vector<int> vec(10);//���Ǹ��Ƽ�ֱ��ָ����С���������Խ�ʡ�ڴ�����ʱ��

	/* ���롢ɾ����print���� */
	vec.push_back(10);//push����int��vec��
	vec.push_back(20);
	vec.push_back(30);

	vec = { 40, 50, 60 };//Ҳ���������ַ�ʽ���и�ֵ

	cout << vec.size() << endl;//��ʱvec��sizeΪ3

	vec.pop_back();//ɾ�����һ��int
	cout << vec.size() << endl;//��ʱvec��sizeΪ2

	cout << vec[0] << " " << vec.at(1) << endl;//print��vec��0�͵�1��element

	vec.clear();//���vector

	/* ׼��һ�� 0 1 2 3 4 5 6 7 8 9��vector */
	for (unsigned int i = 0; i < 10; i++){
		vec.push_back(i);
	}

	/* ����һ�� ɾ��vector���ض���ֵ�İ취*/
	for (vector<int>::iterator it = vec.begin(); it != vec.end();){
		if (*it == 4 || *it == 5)
			it = vec.erase(it); // erase()ֻ��ɾ��һ����iteratorָ���element
		else
			it++;//�������it++д��else�еĻ��������
	}

	/* Ҳ���԰�˳��ɾ��ĳһ�ض�element*/
	vec.erase(vec.begin() + 2);//ɾ����2��element����0��ʼ���㣩

	/* ������ɾ�������������element*/
	vec.erase(vec.begin() + 2, vec.begin() + 4);//ɾ���ӵ�2����4��element

	vec.resize(10);//��ʱ��vec�����ɵ�element�ᱻvector�Ĺ��캯������

	vec.resize(20, 99);//��ʱ��vec�����ɵ�element�ᱻ��99���

	vec.reserve(50);//���·�����50��λ�ڴ�

	/*
	����˵����ʹ��vector::resize(a)ʱ����a��capacityС���򲻻�ı�capacity��ֵ�����������·����ڴ棩��
	����capacity��������·����ڴ档��Ȼ�����a��������vector��element�٣����ɾ�������element����ʱcapacity��Ȼ���䣩��

	��vector::reserve(b)���ǵ�capacity��bС��ʱ�����·����ڴ棬��b���ʱ��ִ���κζ�����

	���⣬sizeָ����vector��ǰӵ�е�element��������capacityָ���ǵ�ǰ�ڴ���Է����vector��������
	�����������capacity������ٴη����ڴ棩
	*/

	cout << (vec.empty() ? "true" : "false") << endl;//vector::empty()����vector�Ƿ�Ϊ��

	vec.insert(vec.begin() + 4, 999);//�ڵ�4��element�����999

	vector<int> vec2 = { 1, 2, 3, 4, 5 };
	vec.swap(vec2);//��vec��vec2������Ԫ�ضԵ�����ȻҲ���������ԣ��磺capacity��size�ȵȣ�
	vec.swap(vec2);

	for (int val : vec)
		cout << val << " ";

	printf("\nsize = %d, capacity = %d, max_size = %d\n", vec.size(), vec.capacity(), vec.max_size());
}

void listTest(){
	/* ���� */
	list<int> lst;

	for (unsigned int i = 0; i < 10; i++)
		lst.push_front(i);

	lst.insert(lst.begin(), 100);

	for (list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		cout << *it << " ";
	cout << endl;
	lst.pop_front();
	cout << lst.front() << endl;
	printf("\nsize = %d, max_size = %d\n", lst.size(), lst.max_size());
}

void mapTest(){
	map<string, int> mp;
}

void decltypeTest(){

}

void lambdaTest(){

}

void testVoid(void *arr, int size){
	void *tmp;
	tmp = arr;
	//*arr = *(arr + size);
}

int main(int argc, char**args){
	//vectorTest();
	//listTest();
	/*char **arr = (char**)malloc(10 * sizeof(char*));
	for (int i = 0; i < 10; i++)
	{
	arr[i] = (char*)malloc(10 * sizeof(char));
	}
	arr[1] = "123123";
	cout << arr[1] << endl;
	cout << sizeof(char) << endl;*/

	system("pause");
}
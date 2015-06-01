#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<list>
#include<stack>

using namespace std;

void vectorTest(){
	/* 声明 */
	vector<int> _vec;//declare一个vector类型变量_vec

	vector<int> vec(10);//但是更推荐直接指定大小，这样可以节省内存分配的时间

	/* 插入、删除和print操作 */
	vec.push_back(10);//push三个int到vec中
	vec.push_back(20);
	vec.push_back(30);

	vec = { 40, 50, 60 };//也可以用这种方式进行赋值

	cout << vec.size() << endl;//此时vec的size为3

	vec.pop_back();//删除最后一个int
	cout << vec.size() << endl;//此时vec的size为2

	cout << vec[0] << " " << vec.at(1) << endl;//print出vec第0和第1号element

	vec.clear();//清空vector

	/* 准备一个 0 1 2 3 4 5 6 7 8 9的vector */
	for (unsigned int i = 0; i < 10; i++){
		vec.push_back(i);
	}

	/* 这是一种 删除vector中特定数值的办法*/
	for (vector<int>::iterator it = vec.begin(); it != vec.end();){
		if (*it == 4 || *it == 5)
			it = vec.erase(it); // erase()只能删除一个由iterator指向的element
		else
			it++;//如果不将it++写在else中的话，会产生
	}

	/* 也可以按顺序删除某一特定element*/
	vec.erase(vec.begin() + 2);//删除第2个element（从0开始计算）

	/* 还可以删除多个个连续的element*/
	vec.erase(vec.begin() + 2, vec.begin() + 4);//删除从第2到第4的element

	vec.resize(10);//这时候vec新生成的element会被vector的构造函数构造

	vec.resize(20, 99);//这时候vec新生成的element会被以99填充

	vec.reserve(50);//重新分配了50单位内存

	/*
	简单来说，当使用vector::resize(a)时，若a比capacity小，则不会改变capacity的值（即不会重新分配内存）。
	若比capacity大，则会重新分配内存。当然，如果a的数量比vector中element少，则会删除多余的element（此时capacity仍然不变）。

	而vector::reserve(b)则是当capacity比b小的时候重新分配内存，比b大的时候不执行任何动作。

	另外，size指的是vector当前拥有的element数量。而capacity指的是当前内存可以分配给vector的数量。
	（如果超出了capacity，则会再次分配内存）
	*/

	cout << (vec.empty() ? "true" : "false") << endl;//vector::empty()返回vector是否为空

	vec.insert(vec.begin() + 4, 999);//在第4个element后插入999

	vector<int> vec2 = { 1, 2, 3, 4, 5 };
	vec.swap(vec2);//将vec和vec2中所有元素对调（当然也包括其属性，如：capacity，size等等）
	vec.swap(vec2);

	for (int val : vec)
		cout << val << " ";

	printf("\nsize = %d, capacity = %d, max_size = %d\n", vec.size(), vec.capacity(), vec.max_size());
}

void listTest(){
	/* 声明 */
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
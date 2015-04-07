#include<stdio.h>
#include<string.h>
#include<math.h>

#define bool int
#define false 0
#define true 1

	//数组长度
#define ArrLength(s) (sizeof(s) / sizeof(s[0]))

	//数组复制
	void ArrCpy(double Destination[], double Origin[], int Size_of_Ori_arr){
		for(int i = 0 ; i < Size_of_Ori_arr ; i++)
			Destination[i] = Origin[i];
	}

	//取最大值
	double Max(double a,double b){
		return a>b?a:b;
	}

	//取最大值
	double MaxArr(double arr[],int Size_of_arr){
		double m = arr[0];
		for (int k = 0 ; k < Size_of_arr ; k++) m = Max(m,arr[k]);
		return m;
	}
	//取最小值
	double Min(double a,double b){
		return a<b?a:b;
	}

	//取最小值
	double MinArr(double arr[],int Size_of_arr){
		double m = arr[0];
		for (int k = 0 ; k < Size_of_arr ; k++) m = Min(m,arr[k]);
		return m;
	}

	//取平均值
	double Avg(double arr[],int Size_of_arr){
		double a =(double) arr[0];
		for( int i = 1; i < Size_of_arr; i++){
			a = a + arr[i];
		}
		return a/Size_of_arr;
	}

	//快速排序法
	void QuickSort(double Data[], int Left, int Right){//注意，Right是右界，不是大小。
		int i = Left, j = Right;
		double Pivot = Data[(Left+Right)/2];
		do{
			while (Data[i] < Pivot)
				i++;
			while (Data[j] > Pivot)
				j--;
			if ( i <= j ){
				double C = Data[i];
				Data[i] = Data[j];
				Data[j] = C;

				i++;
				j--;
			}
		}while ( i <= j );
		if(Left < j)
			QuickSort( Data, Left, j);
		if(i < Right)
			QuickSort( Data, i, Right);
	}

	//插入排序法
	void InsertionSort(double Data[], int Size_of_arr){
		int k, j, itemk, times = 0;
		for( k = 1; k < Size_of_arr; k++){
			itemk = Data[k];
			j = k - 1;
			while (j >= 0 && itemk < Data[j] )
			{
				Data[j+1] = Data[j];
				j--;
			}
			Data[j+1] = itemk;
		}
	}

	//选择排序法
	void SelectionSort(double Data[], int Size_of_arr){
		int  min;
		for(int i = 0 ; i < Size_of_arr - 1 ; i++){
			min = i;
			for (int j = i + 1 ; j < Size_of_arr ; j++)
				if( Data[j] < Data[min])
					min = j;
			if( min != i){
				double C = Data[min];
				Data[min] = Data[i];
				Data[i] = C;
			}
		}
	}

	//希尔排序
	void ShellSort(double Data[], int Size_of_arr){
		int i,j, gap;
		double temp;
		for( gap = Size_of_arr >>1 ; gap >0 ; gap >>= 1 ){
			for ( i = gap ; i < Size_of_arr ; i++){
				temp = Data[i];
				for (j = i - gap; j >= 0 && Data[j] > temp  ; j-= gap)
					Data[ j + gap ] = Data[j];
				Data[j + gap] = temp;
			}
		}
	}

	//归并排序
	void FusionSort(double Data[], int Size_of_arr){

	}

	//冒泡排序
	void BubbleSort(double Data[], int Size_of_arr){
		for( int i = 0; i < Size_of_arr ; i++)
			for( int j = 0; j < Size_of_arr - 1 ; j++)
				if ( Data[j] > Data[j+1]){
					double C = Data[j];
					Data[j] = Data[j+1];
					Data[j] = C;
				}
	}
 
	//数组倒序
	void InvArr(double Data[], int Size_of_arr){
		for( int i = 0; i < Size_of_arr / 2 ; i++){
			double C = Data[i];
			Data[i] = Data[Size_of_arr-1-i];
			Data[Size_of_arr-1-i] = C;
		}
	}

	//升序？
	bool IsAsc(double Data[], int Size_of_arr){
		for( int i = 0; i < Size_of_arr-1 ; i++)
			if(Data[i]>Data[i+1])
				goto False;
		if(false){
False:
			return false;
		}
		return true;
	}

	//降序？
	bool IsDes(double Data[], int Size_of_arr){
		for( int i = 0; i < Size_of_arr-1 ; i++)
			if(Data[i]<Data[i+1])
				goto False;
		if(false){
False:
			return false;
		}
		return true;
	}

	//打印数组
	void PrintArr(double arr[], int Size_of_arr){
		for (int i = 0 ; i < Size_of_arr ; i++)
			printf("%lf ",arr[i]);
		printf("\n");
	}

	//阶乘
	long long Fact(int Fact){
		long long result = 1;
		for(int i = 2 ; i <= Fact ; i++)
			result *= i;
		return result;
	}

	//二进制整数转十进制-string
	long ToDec(char Binary[], int Size){
		long Decimal = 0;
		for(unsigned int i = 0 ; i < Size ; i ++ ){
			if (Binary[i]=='1'){
				Decimal += (long)pow(2,Size-i);
			}
		}
		return Decimal/2;
	}

	//十进制整数转二进制

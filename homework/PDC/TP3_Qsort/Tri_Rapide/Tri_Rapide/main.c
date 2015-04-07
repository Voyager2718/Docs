#define TABSIZE 1000

#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
//#include<math.h>
//#include<fstream>
#pragma warning(disable:4996)

//#include<iostream>
//using namespace std;

void QuickSort(int[], int, int);
void swap(int*, int*);
int ConstruireTableaux(struct Nomine_s *);
int CompareNomineParDateDeNaissance(struct Nomine_s *, struct Nomine_s *);


struct Nomine_s{
	int date, domain, day, month, year;
	char name[100], nationality[100];
	int gender;//Org = 2, man = 1, woman = 0
};

void swap(int *a, int *b){
	int c = *a;
	*a = *b;
	*b = c;
}

void swap2(struct Nomine_s *n1, struct Nomine_s *n2){
	struct Nomine_s n3;
	n3.date = n1->date;
	n3.domain = n1->domain;
	n3.day = n1->day;
	n3.month = n1->month;
	n3.year = n1->year;
	strcpy(n3.name, n1->name);
	strcpy(n3.nationality, n1->nationality);
	n3.gender = n1->gender;

	n1->date = n2->date;
	n1->domain = n2->domain;
	n1->day = n2->day;
	n1->month = n2->month;
	n1->year = n2->year;
	strcpy(n1->name, n2->name);
	strcpy(n1->nationality, n2->nationality);
	n1->gender = n2->gender;

	n2->date = n3.date;
	n2->domain = n3.domain;
	n2->day = n3.day;
	n2->month = n3.month;
	n2->year = n3.year;
	strcpy(n2->name, n3.name);
	strcpy(n2->nationality, n3.nationality);
	n2->gender = n3.gender;
}

void quicksort_int(int *tab, unsigned int n){
	QuickSort(tab, 0, n - 1);
}

void QuickSort(int Data[], int Left, int Right){
	int i = Left, j = Right;
	int Pivot = Data[(Left + Right) / 2];
	do{
		while (Data[i] < Pivot)
			i++;
		while (Data[j] > Pivot)
			j--;
		if (i <= j){
			Data[i] ^= Data[j];
			Data[j] ^= Data[i];
			Data[i] ^= Data[j];
			i++;
			j--;
		}
	} while (i <= j);
	if (Left < j)
		QuickSort(Data, Left, j);
	if (i < Right)
		QuickSort(Data, i, Right);
}

void QuickSort2(struct Nomine_s Data[], int Left, int Right){
	int i = Left, j = Right;
	int Pivot = Data[(Left + Right) / 2].date;
	do{
		while (Data[i].date < Pivot)
			i++;
		while (Data[j].date > Pivot)
			j--;
		if (i <= j){
			struct Nomine_s*p1 = &Data[i], *p2 = &Data[j];
			swap2(p1, p2);
			i++;
			j--;
		}
	} while (i <= j);
	if (Left < j)
		QuickSort2(Data, Left, j);
	if (i < Right)
		QuickSort2(Data, i, Right);
}

int puis(int x, int y){
	int r = x;
	for (int i = 1; i < y; i++){
		r = x * r;
	}
	return r;
}

int CharToInt(char c[]){
	int a = 0;
	for (unsigned int i = 0; i < strlen(c); i++)
		a += (c[i] - 48) * puis(10, strlen(c) - i - 1);
	return a;
}

void CharSet0(char *c){
	for (unsigned int i = 0; i < strlen(c); i++)
		c[i] = '\0';
}

int ConstruireTableaux(struct Nomine_s* n){
	char ch, str[1010] = "";
	int q = 0, m = 0, z = 0;
	FILE *fp = NULL;
	fp = fopen("nobel.csv", "r");
	if (fp == NULL)
	{
		printf("Error\n");
		return -1;
	}
	while ((ch = getc(fp)) != EOF){
		if (ch != ','&&ch != '\n'){
			str[z++] = ch;
		}
		else if (ch == ',' || ch == '\n'){
			str[z] = '\0';
			z = 0;
			switch (m)
			{
			case 0:(n + q)->date = CharToInt(str); m++; str[0] = '\0'; break;
			case 1:(n + q)->domain = CharToInt(str); m++; str[0] = '\0'; break;
			case 2:strcpy((n + q)->name, str);  m++; str[0] = '\0'; break;
			case 3:(n + q)->day = CharToInt(str); m++; str[0] = '\0'; break;
			case 4:(n + q)->month = CharToInt(str); m++; str[0] = '\0'; break;
			case 5:(n + q)->year = CharToInt(str); m++; str[0] = '\0'; break;
			case 6:strcpy((n + q)->nationality, str); m++; str[0] = '\0'; break;
			case 7:(n + q)->gender = str[0] == 'M' ? 1 : str[0] == 'F' ? 0 : 2; m = 0; q++; CharSet0(str); break;
			default:break;
			}
		}
	}
	fclose(fp);
	fp = NULL;
	return q;
}

int CompareNomineParDateDeNaissance(struct Nomine_s *n1, struct Nomine_s *n2){
	if (n1->date == n2->date)
		return 0;
	if (n1->date > n2->date)
		return 1;
	return -1;
}

void quicksort(struct Nomine_s *base, int nelem, int size, int(*compar)(const void *, const void *)){
	QuickSort2(base, 0, nelem - 1);
}

int main(int argc, char*arcv[]){
	/*int i = 0;
	cout << n[i].date << " " << n[i].domain << " " << n[i].name << " " << n[i].day
	<< " " << n[i].month << " " << n[i].year << " " << n[i].nationality << " " << n[i].gender << endl;*/
	return 0;
}
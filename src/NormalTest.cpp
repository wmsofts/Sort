#include "qgsort.cpp"
#include<iostream>
using namespace std;

void printArr(int *arr,int len){
	for (int i = 0; i < len; ++i)
	{
		printf(" %d ", arr[i]);
	}
	printf("\n");
}

int main(){
	printf("******�Զ����Գ���******\n");
	printf("����˵��������׼��һ��10����ִ��ÿ��������������ԡ���Ҫ��ȡ�ļ���������һ������\n") ;
	printf("ÿ������ǰ��������׼������������Ա���ԡ�������̻���ʾ��\n") ;
	int len = 10; 
	//	int len = sizeof(arr) / sizeof(arr[0]); //���㳤�ȣ�ͨ�ü���  

	
	int arr1[] = {12,8,20,4,6,15,0,3,9,2};
	printf("\n�������������ǣ�");
	printArr(arr1,len); 
	printf("1.��������");
	insertSort(arr1,len);
	printArr(arr1,len); 
	
	int arr2[] = {22,17,12,50,6,18,10,32,9,92};
	printf("\n�������������ǣ�");
	printArr(arr2,len); 
	printf("2.�鲢����");
	int *p = new int[len];   //����һ����lenһ����Ŀռ䣬�����������õ����ݡ� 
    MergeSort(arr2, 0, len - 1, p);  
    delete[] p;  
	printArr(arr2,len); 
	
	int arr3[] = {10,10,1,2,61,5,25,3,9,4};
	printf("\n�������������ǣ�");
	printArr(arr3,len); 
	printf("3.�������򣨵ݹ飩");
	QuickSort_Recursion(arr3, 0, len-1);
	printArr(arr3,len); 
	
	int arr4[] = {21,12,0,32,14,85,41,23,11,2,1};
	printf("\n�������������ǣ�");
	printArr(arr4,len); 
	printf("4.�������򣨲��ݹ飩");
	QuickSort(arr4,len);
	printArr(arr4,len); 
	
	int arr5[] = {32,10,25,98,2,3,3,5,54,12};
	printf("\n�������������ǣ�");
	printArr(arr5,len); 
	printf("5.�������������ţ�");
	quickSort_partition(arr5, 0, len-1);
	printArr(arr5,len); 
	
	int arr6[] = {8,4,2,3,5,1,6,9,32,18,7};
	printf("\n�������������ǣ�");
	printArr(arr6,len); 
	printf("6.������������");
	RadixCountSort(arr6, len);
	printArr(arr6,len); 
	
	int arr7[] = {51,20,30,2,15,2,96,33,12,1};
	printf("\n�������������ǣ�");
	printArr(arr7,len); 
	printf("7.��������");
	CountSort(arr7, len);
	printArr(arr7,len); 
	
    printf("\n��ϡ���������\n");
	getchar();
	getchar();
	return 0;
}


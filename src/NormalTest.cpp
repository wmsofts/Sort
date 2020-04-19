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
	printf("******自动测试程序******\n");
	printf("附加说明：程序准备一组10个数执行每个函数的排序测试。若要读取文件测试在另一个程序。\n") ;
	printf("每次排序前都会重新准备无序随机数以便测试。这个过程会显示。\n") ;
	int len = 10; 
	//	int len = sizeof(arr) / sizeof(arr[0]); //计算长度，通用计算  

	
	int arr1[] = {12,8,20,4,6,15,0,3,9,2};
	printf("\n这组无序数据是：");
	printArr(arr1,len); 
	printf("1.插入排序");
	insertSort(arr1,len);
	printArr(arr1,len); 
	
	int arr2[] = {22,17,12,50,6,18,10,32,9,92};
	printf("\n这组无序数据是：");
	printArr(arr2,len); 
	printf("2.归并排序");
	int *p = new int[len];   //开辟一个跟len一样大的空间，用来存放排序好的数据。 
    MergeSort(arr2, 0, len - 1, p);  
    delete[] p;  
	printArr(arr2,len); 
	
	int arr3[] = {10,10,1,2,61,5,25,3,9,4};
	printf("\n这组无序数据是：");
	printArr(arr3,len); 
	printf("3.快速排序（递归）");
	QuickSort_Recursion(arr3, 0, len-1);
	printArr(arr3,len); 
	
	int arr4[] = {21,12,0,32,14,85,41,23,11,2,1};
	printf("\n这组无序数据是：");
	printArr(arr4,len); 
	printf("4.快速排序（不递归）");
	QuickSort(arr4,len);
	printArr(arr4,len); 
	
	int arr5[] = {32,10,25,98,2,3,3,5,54,12};
	printf("\n这组无序数据是：");
	printArr(arr5,len); 
	printf("5.快速排序（枢轴存放）");
	quickSort_partition(arr5, 0, len-1);
	printArr(arr5,len); 
	
	int arr6[] = {8,4,2,3,5,1,6,9,32,18,7};
	printf("\n这组无序数据是：");
	printArr(arr6,len); 
	printf("6.基数计数排序");
	RadixCountSort(arr6, len);
	printArr(arr6,len); 
	
	int arr7[] = {51,20,30,2,15,2,96,33,12,1};
	printf("\n这组无序数据是：");
	printArr(arr7,len); 
	printf("7.计数排序");
	CountSort(arr7, len);
	printArr(arr7,len); 
	
    printf("\n完毕。请检查结果。\n");
	getchar();
	getchar();
	return 0;
}


#include "qgsort.cpp"

void printArr(int *arr,int len){
	for (int i = 0; i < len; ++i)
	{
		printf(" %d ", arr[i]);
	}
	printf("\n");
}

int main(){
	printf("******颜色排序******\n");
	printf("为了方便，程序已经准备好数据(只含0，1，2元素)以供测试，无需输入。\n") ;
	int len = 10; 
	int arr[] = {0,2,1,1,2,1,2,1,2,0};
	printf("\n这组无序颜色数据是：");
	printArr(arr,len); 
	printf("颜色排序：");
	ColorSort(arr,len);
	printArr(arr,len); 
	printf("\n完毕。请检查结果。\n");
	getchar();
	return 0; 
} 

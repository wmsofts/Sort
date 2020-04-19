#include "qgsort.cpp"

void printArr(int *arr,int len){
	for (int i = 0; i < len; ++i)
	{
		printf(" %d ", arr[i]);
	}
	printf("\n");
}

int main(){
	printf("******在一个无序序列中找到第K大的数******\n");
	printf("为了方便，程序已经准备好数据以供测试，无需输入。\n") ;
   int arrNum[] = {10,13,2,0,7,3,5,15};
   int K; 
   printArr(arrNum,8);
   printf("要找到第K大的数。请输入K的值：");
   scanf("%d",&K); 
   int value = GetNumber(arrNum, 8, K);
   if(value == -1){
       printf("错误：没能找到这样的数。你可能输入错误。\n");
   }
   else{
       printf("这个数是：%d\n",value);
   }
	printf("\n完毕。\n");
	getchar();
	getchar();
	return 0; 
} 

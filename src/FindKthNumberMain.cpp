#include "qgsort.cpp"

void printArr(int *arr,int len){
	for (int i = 0; i < len; ++i)
	{
		printf(" %d ", arr[i]);
	}
	printf("\n");
}

int main(){
	printf("******��һ�������������ҵ���K�����******\n");
	printf("Ϊ�˷��㣬�����Ѿ�׼���������Թ����ԣ��������롣\n") ;
   int arrNum[] = {10,13,2,0,7,3,5,15};
   int K; 
   printArr(arrNum,8);
   printf("Ҫ�ҵ���K�������������K��ֵ��");
   scanf("%d",&K); 
   int value = GetNumber(arrNum, 8, K);
   if(value == -1){
       printf("����û���ҵ�����������������������\n");
   }
   else{
       printf("������ǣ�%d\n",value);
   }
	printf("\n��ϡ�\n");
	getchar();
	getchar();
	return 0; 
} 

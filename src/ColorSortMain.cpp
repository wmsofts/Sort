#include "qgsort.cpp"

void printArr(int *arr,int len){
	for (int i = 0; i < len; ++i)
	{
		printf(" %d ", arr[i]);
	}
	printf("\n");
}

int main(){
	printf("******��ɫ����******\n");
	printf("Ϊ�˷��㣬�����Ѿ�׼��������(ֻ��0��1��2Ԫ��)�Թ����ԣ��������롣\n") ;
	int len = 10; 
	int arr[] = {0,2,1,1,2,1,2,1,2,0};
	printf("\n����������ɫ�����ǣ�");
	printArr(arr,len); 
	printf("��ɫ����");
	ColorSort(arr,len);
	printArr(arr,len); 
	printf("\n��ϡ���������\n");
	getchar();
	return 0; 
} 

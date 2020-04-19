
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ��������
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int *a,int n);


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp);


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int *a,int begin,int end,int *temp);


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(int *a, int begin, int end);


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(int *a,int size);


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int Partition(int *a, int begin, int end);
void quickSort_partition(int *a,int begin,int end);  //ʵ�� 


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size
 */
void CountSort(int *a, int size);


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int *p, int n);
int findMaxNum(int *p, int n);
int getLoopTimes(int num);
void sort2(int *p, int n, int loop);

/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int *a,int size);


/**
 *  @name        : int GetNumber(int start,int end)
 *  @description : ��һ�������������ҵ���K��/С����
 */
int GetNumber(int *arrNum, int n, int k);
int Partition(int *arrNum, int l, int r); 
 
 
void swap(int *p,int *q); //�������� 

typedef struct Stack{   //ջ 
	int *data;
	int size;
	
}stack;
void InitStack(stack *s);
void PushStack(stack *s,int d);
void PopStack(stack *s);
int TopStack(stack *s);
int EmptyStack(stack *s);

int MiddleNumber(int *a, int begin, int end); //�м����Ļ�� 
int qs2(int *arr, int begin, int end);
#endif // QUEUE_H_INCLUDED

#include "../inc/qgsort.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "assert.h"
#include "math.h"
#include<iostream>
using namespace std;

//��������
void insertSort(int *a,int n){
	int end = 0;
    for (int i = 0; i < n-1; i++)
    {
        end = i;
        int temp = a[end+1];//��Ҫ���������ݽ��б���
        while (end >= 0 && a[end] > temp)
        {
            //������������ں�ǰ�������������ݽ��бȽ���С��
            //������end=-1,��ôҲ���Թ�Ϊ[end+1]=[-1+1]=tmp;
            a[end + 1] = a[end];//�������������ƶ�
            end--;
        }
        a[end + 1] = temp;
    }
} 

//�鲢���򣨺ϲ����飩
void MergeArray(int* a, int begin, int mid, int end, int*temp)
{
	int i = begin;
	int j = begin;
	int k = mid + 1;
	while (i <= mid && k <= end)
	{
		if (a[i] < a[k])
			temp[j++] = a[i++];
		else
			temp[j++] = a[k++];
	}
	while (i <= mid)
		temp[j++] = a[i++];
	while (k <= end)
		temp[j++] = a[k++];
	for (int i = 0; i <= end; i++)
		a[i] = temp[i];
}

 //�鲢����
void MergeSort(int* a, int begin, int end, int *temp)
{
	if (begin < end)
	{
		int mid = begin + (end - begin) / 2;
		MergeSort(a, begin, mid, temp);  //���� 
		MergeSort(a, mid + 1, end, temp); //����  
		MergeArray(a, begin, mid, end, temp);   //���ù鲢-�ϲ����� 
	}
}

//�������� 
void CountSort(int *a, int size){
	int i;
    int minValue = a[0];
    int maxValue = a[0];
    int range = 0;
    int* temp = 0;
    int count = 0;
    for (i = 0; i < size; i++)//�������ݵķ�ɢ�ռ�
    {
        if (a[i] < minValue){
            minValue = a[i];
        }
        if (a[i] > maxValue){
            maxValue = a[i];
        }
    }
    range = maxValue - minValue + 1;
    temp = (int*)malloc(sizeof(a[0])*size);//���븨���ռ�
    if (temp == 0)
        return;
    memset(temp, 0, sizeof(int)*range);//��ʼ��

    for (i = 0; i < size; i++)//ͳ��ÿ��Ԫ�س��ֵĴ���
    {
        temp[a[i] - minValue]++;
    }

    for(i=0;i<range;i++)//ͨ��ͳ��temp[];����Ԫ��
    {
        while (temp[i]--)
        {
            a[count++] = i + minValue;
        }
    }
    //free(temp);    //free�������������ˣ�ԭ��δ֪�� 
} 

//�������� 
void RadixCountSort(int *p, int n)
{
    //��ȡ�����е������
    int maxNum = findMaxNum(p, n);
    //��ȡ�������λ��������Ҳ���ٷ���Ĵ�����
    int loopTimes = getLoopTimes(maxNum);
    int i;
    //��ÿһλ����Ͱ����
    for(i = 1; i <= loopTimes; i++)
    {
        sort2(p, n, i);
    }
}
//��ȡ���ֵ�λ��
int getLoopTimes(int num)
{
    int count = 1;
    int temp = num / 10;
    while(temp != 0)
    {
        count++;
        temp = temp / 10;
    }
    return count;
}
//��ѯ�����е������
int findMaxNum(int *p, int n)
{
    int i;
    int max = 0;
    for(i = 0; i < n; i++)
    {
        if(*(p + i) > max)
        {
            max = *(p + i);
        }
    }
    return max;
}
//�����ַ��䵽���Ե�Ͱ�У�Ȼ����Ͱ��˳�����������
void sort2(int *p, int n, int loop)
{
    //����һ��Ͱ�˴���20��Ԥ��ĸ���ʵ��������޸�
    int buckets[10][20] = {};
    //��Ͱ��index�ĳ���
    //��798��λͰindex=(798/1)%10=8
    //ʮλͰindex=(798/10)%10=9
    //��λͰindex=(798/100)%10=7
    //tempNumΪ��ʽ�е�1��10��100
    int tempNum = (int)pow(10, loop - 1);
    int i, j;
    for(i = 0; i < n; i++)
    {
        int row_index = (*(p + i) / tempNum) % 10;
        for(j = 0; j < 20; j++)
        {
            if(buckets[row_index][j] == 0)
            {
                buckets[row_index][j] = *(p + i);
                break;
            }
        }
    }
    //��Ͱ�е��������ص�ԭ��������
    int k = 0;
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 20; j++)
        {
            if(buckets[i][j] != 0)
            {
                *(p + k) = buckets[i][j];
                buckets[i][j] = 0 ;
                k++;
            }
        }
    }
}

//��ɫ����
//ͳ��1��2���ֵĴ�����Ȼ���ٱ���һ�θ�ֵ��
 void ColorSort(int *a,int size){
    int i = 0, count1 = 0, count2 = 0, index = 0;
    for(i = 0; i < size; i++) {
    	//ͳ��1��2���ֵĴ���
        if(a[i] == 1)
            count1++;
        else if(a[i] == 2)
            count2++;
    }
    for(i = 0; i < size - count1 - count2; i++)
        a[index++] = 0;
    for(i = 0; i < count1; i++)
        a[index++] = 1;
    for(i = 0; i < count2; i++)
        a[index++] = 2;
}

/*��ɫ���򡪡��㷨2 
j��¼0�ĸ�����k��¼1�ĸ�������������ԭ�е����֡�
void sortColors2(int* a, int size) {
    int i = 0, j = 0, k = 0;
    int t = 0;
    for(i = 0; i < size; i++) {
        t = a[i];
        a[i] = 2;
        if(t < 2)
            a[k++] = 1;
        if(t == 0) 
            a[j++] = 0;
    }
}
*/

//��һ�������������ҵ���K��/С����
int Partition(int *arrNum, int l, int r){
	//���Ϸ����� 
	if(arrNum == NULL || l > r){
        return -1;
    }
    int mid = (l+r)>>1;
	swap(arrNum[mid], arrNum[r]);
	int leftSeqIndex = l;
	//ö������ 
	for(int i = l; i < r; i++){
	    if(arrNum[i] < arrNum[r]){
           if(i > leftSeqIndex){
		   		swap(arrNum[i], arrNum[leftSeqIndex]);
   		   }
   		   ++leftSeqIndex;
		}
    } 
    //��׼��������
	swap(arrNum[leftSeqIndex], arrNum[r]);
	return leftSeqIndex; 
}
 
//���k�����
int GetNumber(int *arrNum, int n, int k){
	//���-1��ʾ���Ϸ� 
	if(arrNum == NULL || n <= 0 || k <= 0 || k > n){
        return -1;
    }
    //��k������ȼ����ҵ�n-k+1С����
	k = n-k+1;
	int l = 0;
	int r = n-1;
	while(l <= r){
	    int index = Partition(arrNum, l, r);
		if(index+1 == k){ //�ҵ� 
            return arrNum[index];
        }
        else if(index+1 < k){ //���ұ�������
		    l = index+1; 
	    }
	    else{ //����������� 
	        r = index-1;
	    }
	}
} 

//���ţ��ݹ�棩 
void QuickSort_Recursion(int *a, int begin, int end){  //���ң�ǰ��ָ�� 
if (begin < end)
	{
		int mid = begin + (end - begin) / 2;
		swap(&a[mid], &a[end]);
		int j = begin;
		for (int i = begin; i < end; i++)
		{
			if (a[i] < a[end])
			{
				swap(&a[i], &a[j++]);
			}
		}
		swap(&a[j], &a[end]);
		QuickSort_Recursion(a, begin, j - 1);  //�ݹ���� 
		QuickSort_Recursion(a, j + 1, end);
	}
} 
void swap(int *p,int *q)  {
    int k; 
    k=*p;   
    *p=*q;  
    *q=k;
}

//�������������ţ�
int partition(int *a,int p,int r){
	int i=p-1;
	int temp;
	
	int x= (rand()%(r-p+1))+p; //��������� 
    temp=a[x];
    a[x]=a[r];
    a[r]=temp;
    
    for (int j=p ; j <r; ++j)
    {
      if (a[j]<=a[r])
      {
        i++;
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
      }
    }
    temp=a[i+1];
    a[i+1]=a[r];
	a[r]=temp; 
    return i+1;
  }
 
 //�������������ţ���ʵ�� 
void quickSort_partition(int *a,int begin,int end){
   if(begin<end){
      int q=partition(a,begin,end);
      quickSort_partition(a,begin,q-1);
      quickSort_partition(a,q+1,end);
    }
  }
 

//���ţ����ݹ�棩 ����ջ��֪ʶ 
void QuickSort(int *a,int size){
	stack s;
	int position;
	int left = 0;
	int right = 0;
	InitStack(&s);
	PushStack(&s, 0);
	PushStack(&s, size);
	while (!EmptyStack(&s))
	{
		right = TopStack(&s);
		PopStack(&s);
		left=TopStack(&s);
		PopStack(&s);
		position = qs2(a, left, right - 1);
		//�ȿ��Ż�׼��࣬���Ƚ������±���ջ
		if ((right - left) > position + 1)
		{
			PushStack(&s, position + 1);
			PushStack(&s, right - left);
		}
		if (position > 0)
		{
			PushStack(&s, 0);
			PushStack(&s, position);
		}
	}
}

void  InitStack(stack *s)
{
	int *data = (int*)malloc(20 * sizeof(int));
	if (data == NULL)
	{
		assert(0);
		return;
	}
	s->data = data;
	s->size = 0;
}
void PushStack(stack *s,int d)
{
	assert(s);
	if (s->size > 20)
	{
		return;
	}
	else
		s->data[s->size++] = d;
}
void PopStack(stack *s)
{
	assert(s);
	if (s->size == 0)
	{
		return;
	}
	else
		s->size--;
}
int TopStack(stack *s)
{
	assert(s);
	return s->data[s->size-1];
		
}
int EmptyStack(stack *s)
{
	assert(s);
	return s->size == 0;
}
int MiddleNumber(int *a, int begin, int end)
{
	int mid = begin + ((end - begin) >> 1);
	if (a[begin] > a[mid])
	{
		if (a[begin] > a[end])
		{
			if (a[mid] > a[end])
			{
				return mid;
			}
			else
				return end;
		}
		else
			return begin;
	}
	else
	{
		if (a[mid] > a[end])
		{
			if (a[begin] > a[end])
			{
				return begin;
			}
			else
			{
				return end;
			}
		}
		else
			return mid;
	}
	
}

//�ڿӷ� 
int qs2(int *a, int begin, int end)
{
	int index = MiddleNumber(a, begin, end);
	if (index != end)
	{
		swap(&a[index], &a[end]);
	}
	int key = a[end];
	int k = end;
	while (begin != end)
	{
		while (a[begin] <= key&&begin < end)
		{
			begin++;
		}
		if (begin != end)
		{
			a[end] = a[begin];
			end--;
		}
		while (a[end] >= key&&begin < end)
		{
			end--;
		}
		if (begin != end)
		{
			a[begin] = a[end];
			begin++;
		}
	}
	if (begin != k)
	{
		a[begin] = key;
	}
	return begin;
}

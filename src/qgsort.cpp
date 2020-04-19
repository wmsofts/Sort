#include "../inc/qgsort.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "assert.h"
#include "math.h"
#include<iostream>
using namespace std;

//插入排序
void insertSort(int *a,int n){
	int end = 0;
    for (int i = 0; i < n-1; i++)
    {
        end = i;
        int temp = a[end+1];//需要将插入数据进行保存
        while (end >= 0 && a[end] > temp)
        {
            //如果插入数据在和前面有序区间数据进行比较最小，
            //将会有end=-1,那么也可以归为[end+1]=[-1+1]=tmp;
            a[end + 1] = a[end];//将大的数据向后移动
            end--;
        }
        a[end + 1] = temp;
    }
} 

//归并排序（合并数组）
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

 //归并排序
void MergeSort(int* a, int begin, int end, int *temp)
{
	if (begin < end)
	{
		int mid = begin + (end - begin) / 2;
		MergeSort(a, begin, mid, temp);  //调用 
		MergeSort(a, mid + 1, end, temp); //调用  
		MergeArray(a, begin, mid, end, temp);   //调用归并-合并数组 
	}
}

//计数排序 
void CountSort(int *a, int size){
	int i;
    int minValue = a[0];
    int maxValue = a[0];
    int range = 0;
    int* temp = 0;
    int count = 0;
    for (i = 0; i < size; i++)//计算数据的分散空间
    {
        if (a[i] < minValue){
            minValue = a[i];
        }
        if (a[i] > maxValue){
            maxValue = a[i];
        }
    }
    range = maxValue - minValue + 1;
    temp = (int*)malloc(sizeof(a[0])*size);//申请辅助空间
    if (temp == 0)
        return;
    memset(temp, 0, sizeof(int)*range);//初始化

    for (i = 0; i < size; i++)//统计每个元素出现的次数
    {
        temp[a[i] - minValue]++;
    }

    for(i=0;i<range;i++)//通过统计temp[];回收元素
    {
        while (temp[i]--)
        {
            a[count++] = i + minValue;
        }
    }
    //free(temp);    //free发生概率性闪退，原因未知！ 
} 

//基数排序 
void RadixCountSort(int *p, int n)
{
    //获取数组中的最大数
    int maxNum = findMaxNum(p, n);
    //获取最大数的位数，次数也是再分配的次数。
    int loopTimes = getLoopTimes(maxNum);
    int i;
    //对每一位进行桶分配
    for(i = 1; i <= loopTimes; i++)
    {
        sort2(p, n, i);
    }
}
//获取数字的位数
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
//查询数组中的最大数
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
//将数字分配到各自的桶中，然后按照桶的顺序输出排序结果
void sort2(int *p, int n, int loop)
{
    //建立一组桶此处的20是预设的根据实际数情况修改
    int buckets[10][20] = {};
    //求桶的index的除数
    //如798个位桶index=(798/1)%10=8
    //十位桶index=(798/10)%10=9
    //百位桶index=(798/100)%10=7
    //tempNum为上式中的1、10、100
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
    //将桶中的数，倒回到原有数组中
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

//颜色排序
//统计1和2出现的次数，然后再遍历一次赋值。
 void ColorSort(int *a,int size){
    int i = 0, count1 = 0, count2 = 0, index = 0;
    for(i = 0; i < size; i++) {
    	//统计1和2出现的次数
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

/*颜色排序——算法2 
j记录0的个数，k记录1的个数，并覆盖上原有的数字。
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

//在一个无序序列中找到第K大/小的数
int Partition(int *arrNum, int l, int r){
	//不合法数据 
	if(arrNum == NULL || l > r){
        return -1;
    }
    int mid = (l+r)>>1;
	swap(arrNum[mid], arrNum[r]);
	int leftSeqIndex = l;
	//枚举区间 
	for(int i = l; i < r; i++){
	    if(arrNum[i] < arrNum[r]){
           if(i > leftSeqIndex){
		   		swap(arrNum[i], arrNum[leftSeqIndex]);
   		   }
   		   ++leftSeqIndex;
		}
    } 
    //基准交换回来
	swap(arrNum[leftSeqIndex], arrNum[r]);
	return leftSeqIndex; 
}
 
//求第k大的数
int GetNumber(int *arrNum, int n, int k){
	//输出-1表示不合法 
	if(arrNum == NULL || n <= 0 || k <= 0 || k > n){
        return -1;
    }
    //第k大的数等价于找第n-k+1小的数
	k = n-k+1;
	int l = 0;
	int r = n-1;
	while(l <= r){
	    int index = Partition(arrNum, l, r);
		if(index+1 == k){ //找到 
            return arrNum[index];
        }
        else if(index+1 < k){ //在右边序列找
		    l = index+1; 
	    }
	    else{ //在左边序列找 
	        r = index-1;
	    }
	}
} 

//快排（递归版） 
void QuickSort_Recursion(int *a, int begin, int end){  //左右（前后）指针 
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
		QuickSort_Recursion(a, begin, j - 1);  //递归调用 
		QuickSort_Recursion(a, j + 1, end);
	}
} 
void swap(int *p,int *q)  {
    int k; 
    k=*p;   
    *p=*q;  
    *q=k;
}

//快速排序（枢轴存放）
int partition(int *a,int p,int r){
	int i=p-1;
	int temp;
	
	int x= (rand()%(r-p+1))+p; //随机化枢轴 
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
 
 //快速排序（枢轴存放）的实现 
void quickSort_partition(int *a,int begin,int end){
   if(begin<end){
      int q=partition(a,begin,end);
      quickSort_partition(a,begin,q-1);
      quickSort_partition(a,q+1,end);
    }
  }
 

//快排（不递归版） 利用栈的知识 
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
		//先快排基准左侧，则先将后侧的下标入栈
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

//挖坑法 
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

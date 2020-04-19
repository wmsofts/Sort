#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "qgsort.cpp"
FILE *fin,*fout;
int a[100000];
int choice;
int main()
{
   int num;
   int count=0;
   int i;
    printf("******读文件测试排序******\n");
	printf("需要先运行数据生成程序生成数据，读入文件名data.txt,自动输出排序结果文件名out.txt\n\n") ;
	printf("1.插入排序 2.归并排序 3.快速排序（递归） 4.快速排序（不递归）\n");
	printf("5.快速排序（枢轴存放） 6.计数排序 \n");
	printf("\n请需要要测试的排序函数：");
	scanf("%d",&choice) ;

   fin=fopen("data.txt","r");
   fout=fopen("out.txt","wb");
   if(!fin || !fout) return 0;
   /*这里会自动转换的*/
   fscanf(fin,"%d",&num);
	
   while(!feof(fin))
   {
      a[count++]=num;
      fscanf(fin,"%d",&num);     
    }
    /*排序部分*/
    switch(choice){
    	case 1:{
    	printf("正在排序，请稍等……\n");
		clock_t start = clock();
		insertSort(a,count);
		clock_t diff = clock() - start;
		printf("插入排序用时：%dms\n",diff);
			break;
		}
		case 2:{
		int *p = new int[count];
		printf("正在排序，请稍等……\n");
		clock_t start = clock();
		MergeSort(a,0,count - 1,p);
		clock_t diff = clock() - start;
		printf("归并排序用时：%dms\n",diff);
		delete[] p; 
			break;
		}
    	case 3:{
    	printf("正在排序，请稍等……\n");
		clock_t start = clock();
		QuickSort_Recursion(a, 0, count-1);
		clock_t diff = clock() - start;
		printf("快排递归用时：%dms\n",diff);
			break;
		}
		case 4:{
		printf("正在排序，请稍等……\n");
		clock_t start = clock();
		QuickSort(a, count);
		clock_t diff = clock() - start;
		printf("快排不递归用时：%dms\n",diff);
			break;
		}
		case 5:{
		printf("正在排序，请稍等……\n");
		clock_t start = clock();
		quickSort_partition(a, 0, count-1);
		clock_t diff = clock() - start;
		printf("快排枢轴存放用时：%dms\n",diff);
			break;
		}
		case 6:{
		printf("正在排序，请稍等……\n");
		clock_t start = clock();
		CountSort(a,count);
		clock_t diff = clock() - start;
		printf("计数排序递归用时：%dms\n",diff);
			break;
		}
	/*	case 7:{
		printf("正在排序，请稍等……\n");
		clock_t start = clock();
		RadixCountSort(a,count);
		clock_t diff = clock() - start;
		printf("基数计数排序递归用时：%dms\n",diff);
			break;
		} */ 
		default:printf("输入错误。") ; 
	}
    
    
    for(i=0;i<count;i++)
    {
        fprintf(fout,"%d\n",a[i]);
    } 
    fclose(fin);
    fclose(fout);
    printf("完成。请查看输出的out.txt文档。\n\n");
    getchar(); 
    getchar();
	return 0;
    
}


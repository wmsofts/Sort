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
    printf("******���ļ���������******\n");
	printf("��Ҫ�������������ɳ����������ݣ������ļ���data.txt,�Զ�����������ļ���out.txt\n\n") ;
	printf("1.�������� 2.�鲢���� 3.�������򣨵ݹ飩 4.�������򣨲��ݹ飩\n");
	printf("5.�������������ţ� 6.�������� \n");
	printf("\n����ҪҪ���Ե���������");
	scanf("%d",&choice) ;

   fin=fopen("data.txt","r");
   fout=fopen("out.txt","wb");
   if(!fin || !fout) return 0;
   /*������Զ�ת����*/
   fscanf(fin,"%d",&num);
	
   while(!feof(fin))
   {
      a[count++]=num;
      fscanf(fin,"%d",&num);     
    }
    /*���򲿷�*/
    switch(choice){
    	case 1:{
    	printf("�����������Եȡ���\n");
		clock_t start = clock();
		insertSort(a,count);
		clock_t diff = clock() - start;
		printf("����������ʱ��%dms\n",diff);
			break;
		}
		case 2:{
		int *p = new int[count];
		printf("�����������Եȡ���\n");
		clock_t start = clock();
		MergeSort(a,0,count - 1,p);
		clock_t diff = clock() - start;
		printf("�鲢������ʱ��%dms\n",diff);
		delete[] p; 
			break;
		}
    	case 3:{
    	printf("�����������Եȡ���\n");
		clock_t start = clock();
		QuickSort_Recursion(a, 0, count-1);
		clock_t diff = clock() - start;
		printf("���ŵݹ���ʱ��%dms\n",diff);
			break;
		}
		case 4:{
		printf("�����������Եȡ���\n");
		clock_t start = clock();
		QuickSort(a, count);
		clock_t diff = clock() - start;
		printf("���Ų��ݹ���ʱ��%dms\n",diff);
			break;
		}
		case 5:{
		printf("�����������Եȡ���\n");
		clock_t start = clock();
		quickSort_partition(a, 0, count-1);
		clock_t diff = clock() - start;
		printf("������������ʱ��%dms\n",diff);
			break;
		}
		case 6:{
		printf("�����������Եȡ���\n");
		clock_t start = clock();
		CountSort(a,count);
		clock_t diff = clock() - start;
		printf("��������ݹ���ʱ��%dms\n",diff);
			break;
		}
	/*	case 7:{
		printf("�����������Եȡ���\n");
		clock_t start = clock();
		RadixCountSort(a,count);
		clock_t diff = clock() - start;
		printf("������������ݹ���ʱ��%dms\n",diff);
			break;
		} */ 
		default:printf("�������") ; 
	}
    
    
    for(i=0;i<count;i++)
    {
        fprintf(fout,"%d\n",a[i]);
    } 
    fclose(fin);
    fclose(fout);
    printf("��ɡ���鿴�����out.txt�ĵ���\n\n");
    getchar(); 
    getchar();
	return 0;
    
}


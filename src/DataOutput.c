#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int range;
int choiceSign;
int main(void){
	void Choose();
	int num;
	int i;
	FILE*fp;
	Choose();
	if(NULL==fopen("data.txt","w"))
	{
		printf("�ļ�����ʧ�ܣ�");
	}
	fp = fopen("data.txt","w"); 
	srand((int)time(NULL)); //������ʱ����Ϊ�������
	if(choiceSign != 4){
	for(i = 0;i < range;i++) 	{	
		num = rand();
		fprintf(fp,"%d\n",num);
	}
	}
	else {
	for(i = 0;i < 100000;i++) 	{	
		num = rand()%100;
		fprintf(fp,"%d\n",num);
	}
    }
	fclose(fp); //�ر��ļ� 
	printf("��ɣ�data.txt�Ѿ�������ϡ�\n");
	getch();
    return 0;
	}

void Choose(){
	int choice;
	printf("*****�����������ɳ���*****\n");
	printf("1.��������:10,000�������\n");
	printf("2.��������:50,000�������\n");
	printf("3.��������:100,000�������\n"); 
	printf("4.����С����\n");
	printf("**************************\n");
	printf("�����������Ŀ��");
	scanf("%d",&choice);
	while(choice < 1||choice >4){
		printf("����������������룺");
		scanf("%d",&choice) ;
	} 
	switch(choice){
		case 1:range = 10000;break;
		case 2:range = 50000;break;
		case 3:range = 100000;break;
		case 4:choiceSign = 4;break;
	}
	printf("�����������ݣ����Ժ򡭡�\n");
	
}   

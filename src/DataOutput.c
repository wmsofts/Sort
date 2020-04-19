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
		printf("文件操作失败！");
	}
	fp = fopen("data.txt","w"); 
	srand((int)time(NULL)); //以立即时间作为随机种子
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
	fclose(fp); //关闭文件 
	printf("完成：data.txt已经生成完毕。\n");
	getch();
    return 0;
	}

void Choose(){
	int choice;
	printf("*****测试数据生成程序*****\n");
	printf("1.大量数据:10,000个随机数\n");
	printf("2.大量数据:50,000个随机数\n");
	printf("3.大量数据:100,000个随机数\n"); 
	printf("4.大量小数组\n");
	printf("**************************\n");
	printf("请输入测试项目：");
	scanf("%d",&choice);
	while(choice < 1||choice >4){
		printf("输入错误！请重新输入：");
		scanf("%d",&choice) ;
	} 
	switch(choice){
		case 1:range = 10000;break;
		case 2:range = 50000;break;
		case 3:range = 100000;break;
		case 4:choiceSign = 4;break;
	}
	printf("正在生成数据，请稍候……\n");
	
}   

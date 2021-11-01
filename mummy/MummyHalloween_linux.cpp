#include<iostream>
#include<string.h>
#include<vector>
//#include<conio.h>
//#include<windows.h>
#include<cstdlib>
#include<ctime>
#include<unistd.h>
#include<stdio.h>

using namespace std;

long long thief[8]={1,5,20,100,250,1000,10000000,7000000000},guard[9]={0,0,0,1,2,5,5,10,50};
int life = 1,guard1,thief1,pyr;
long score = 0;

void print(char a[])
{
    int s=strlen(a);
    for(int i=0;i<s;i++)
    {
        printf("%c",a[i]);
        sleep(0.2);
    }
    
    system("stty -echo");
    getchar(); 
    system("stty echo");
    
    system("cls");
}
void fight(){
	guard1 = guard[rand()%9];
	thief1 = thief[rand()%8];
	printf("修建金字塔\n");
	pyr = rand()%5;
	int in;
	while(life){
		sleep(0.700);
		system("cls");
		if(guard1 < 0) guard1 = 0;
		printf("分数：%ld\n",score);
		printf("金字塔厚度：%d\n",pyr);
		printf("万圣鬼：%d  盗墓贼：%d\n",guard1,thief1);
		if(thief1 <= 0){
			printf("恭喜获得胜利！\n");
			sleep(0.500);
			printf("下一波即将开始！");
			score += 200;
			pyr += 2;
			thief1 = thief[rand()%8];
			sleep(0.500);
			system("cls");
		}
		if(pyr){
			printf("金字塔被攻破一层！\n");
			score += 20;
			pyr--;
			printf("1：召集万圣鬼	2：诅咒\n");
			scanf("%d",&in);
			if(in == 1) guard1 = guard1*2 + 2;
			else if(rand()%5 < 2){
				printf("诅咒生效\n");
				thief1/=2;
			}
			else printf("诅咒失败！\n");
			if(rand()%20 < 19){
				printf("鬼来了！\n");
			    thief1 -= (guard1 * 15);
				guard1 = min((0-thief1) / 10,0);
			}
			else{
				printf("鬼造反了！\n");
				pyr = 0;
			}
			if(thief1 <= 0) continue;
		}
		else{
			if(rand()%20 < 19){
				printf("鬼来了！\n");
			    thief1 -= (guard1 * 10);
				guard1 = min((0-thief1) / 10,0);
			}
			if(thief1 <= 0) continue;
			sleep(0.400);
			system("cls");
			system("color 0c");
			print("木乃伊已沦陷！");
			printf("最终分数：%ld\n",score);
			sleep(1.500);
			system("cls");
			print("GAME OVER！"); 
			sleep(0.500);
			return;
		}
		sleep(0.700);
		system("cls");
	}
}
void game(){
	srand(time(NULL));
	print("在古埃及，三千年前，你死了，并选了一个木乃伊。");
	int rmummy = rand()%5 + 1,smummy;
	printf("选一个木乃伊(1~5)\n");
	scanf("%d", &smummy);
	if(smummy==rmummy || smummy == 28){
		printf("规则的木乃伊！");
		sleep(0.600);
		system("cls");
		fight();
	}
	else{
		sleep(0.300);
		system("cls");
		system("color 0c");
		print("不规则木乃伊！");
		print("火化！");
		print("GAME OVER！"); 
		return;
	}
}

int main(){
	
	system("title 木乃伊万圣节版");
	print("龙家游戏公司出品：木乃伊（万圣节特别版）");
	game();
	return 0;
}

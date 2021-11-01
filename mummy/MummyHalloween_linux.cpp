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
	printf("Pyramid building ... \n");
	pyr = rand()%5;
	int in;
	while(life){
		sleep(0.700);
		system("cls");
		if(guard1 < 0) guard1 = 0;
		printf("Score：%ld\n",score);
		printf("Thickness of Pyramid"：%d\n",pyr);
		printf("Halloween Guard：%d  Theif：%d\n",guard1,thief1);
		if(thief1 <= 0){
			printf("You win！Congratulations!\n");
			sleep(0.500);
			printf("Next wave on the way！");
			score += 200;
			pyr += 2;
			thief1 = thief[rand()%8];
			sleep(0.500);
			system("cls");
		}
		if(pyr){
			printf("Pyramid one level clear and destroyed！\n");
			score += 20;
			pyr--;
			printf("1：Call for more Halloween Guards\t2：Curse\n");
			scanf("%d",&in);
			if(in == 1) guard1 = guard1*2 + 2;
			else if(rand()%5 < 2){
				printf("Curse effective!\n");
				thief1/=2;
			}
			else printf("Curse failed！\n");
			if(rand()%20 < 19){
				printf("Ghosts come！\n");
			    thief1 -= (guard1 * 15);
				guard1 = min((0-thief1) / 10,0);
			}
			else{
				printf("Ghosts rebel！\n");
				pyr = 0;
			}
			if(thief1 <= 0) continue;
		}
		else{
			if(rand()%20 < 19){
				printf("Ghosts come！\n");
			    thief1 -= (guard1 * 10);
				guard1 = min((0-thief1) / 10,0);
			}
			if(thief1 <= 0) continue;
			sleep(0.400);
			system("cls");
			system("color 0c");
			print("Mummy deteriorated!");
			printf("Final Score：%ld\n",score);
			sleep(1.500);
			system("cls");
			print("GAME OVER!"); 
			sleep(0.500);
			return;
		}
		sleep(0.700);
		system("cls");
	}
} 
void game(){
	srand(time(NULL));
	print("In ancient Egypt, 3000 years ago, you died, and ... selected a mummy.");
	int rmummy = rand()%5 + 1,smummy;
	printf("Select a mummy (1~5)\n");
	scanf("%d", &smummy);
	if(smummy==rmummy || smummy == 28){
		printf("You get a regular mummy! continue to start the fight game...");
		sleep(0.600);
		system("cls");
		fight();
	}
	else{
		sleep(0.300);
		system("cls");
		system("color 0c");
		print("Oh, no! You get an irregular mummy.");
		print("Burned!");
		print("GAME OVER!"); 
		return;
	}
}

int main(){
	
	system("title Mummy - Halloween Edition");
	print("Mummy - Special edition for Halloween 2021: created by Longmao");
	game();
	return 0;
}

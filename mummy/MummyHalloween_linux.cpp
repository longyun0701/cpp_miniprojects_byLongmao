#include<iostream>
#include<string.h>
#include<vector>
//#include<conio.h>
//#include<windows.h>
#include<cstdlib>
#include<ctime>
#include<unistd.h>
#include<stdio.h>

//using namespace std;

long long thief[8]={1,5,20,100,250,1000,10000000,7000000000},guard[9]={0,0,0,1,2,5,5,10,50};
int life = 1,guard1,thief1,pyr;
long score = 0;

void print(char const* a)
{
    int s=strlen(a); //.size()
	 
    for(int i=0;i<s;i++)
    {
        printf("%c",a[i]);
        usleep(10000);
    }
    
    system("stty -echo");
    getchar(); 
    system("stty echo");
    
    system("echo -e \033[2J");
}
void fight(){
	guard1 = guard[rand()%9];
	thief1 = thief[rand()%8];
	printf("Pyramid building ... \n");
	pyr = rand()%5;
	int in;
	while(life){
		usleep(20000);
		system("echo -e \033[2J");
		if(guard1 < 0) guard1 = 0;
		printf("Score：%ld\n",score);
		printf("Thickness of Pyramid: %d\n",pyr);
		printf("Halloween Guards：%d  Thieves：%d\n",guard1,thief1);
		if(thief1 <= 0){
			printf("You win！Congratulations!\n");
			usleep(17000);
			printf("Next wave on the way!");
			score += 200;
			pyr += 2;
			thief1 = thief[rand()%8];
			usleep(17000);
			system("echo -e \033[2J");
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
				guard1 = std::min((0-thief1) / 10,0);
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
				guard1 =std:: min((0-thief1) / 10,0);
			}
			if(thief1 <= 0) continue;
			usleep(13000);
			system("echo -e \033[2J");
			system("echo -e \033[31m");
			print("Mummy deteriotated!");
			printf("Final Score：%ld\n",score);
			usleep(50000);
			system("echo -e \033[2J");
			print("GAME OVER!"); 
			usleep(17000);
			return;
		}
		usleep(25000);
		system("echo -e \033[2J");
	}
} 
void game(){
	srand(time(NULL));
	print("In ancient Egypt, 3000 years ago, you died, and ... selected a MUMMY.");
	int rmummy = rand()%5 + 1, smummy;
	printf("Select a mummy (1~5)\n");
	scanf("%d", &smummy);
	if(smummy==rmummy || smummy == 28){
		printf("You get a regular mummy! continue to start the fight game...");
		usleep(20000);
		system("echo -e \033[2J");
		fight();
	}
	else{
		usleep(10000);
		system("echo -e \033[2J");
		system("echo -e \033[31m");
		print("Oh, no! You get an irregular mummy.");
		print("Burned!");
		print("GAME OVER!");
		system("echo -e \033[0m");
		return;
	}
}

int main(){
	
//	system("title Mummy - Halloween Edition");
	print("Mummy - Special edition for Halloween 2021: created by Longmao");
	game();
	return 0;
}

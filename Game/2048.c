#include <stdio.h>
#include <stdlib.h>     // for rand() and srand() and exit()
#include <time.h>       // for time()
#include <conio.h>      // for getch()
#include <windows.h>
//画面绘制
int game[4][4] = {0};
int empty = 15;
void check(void)
{
	for (int i = 0; i < 4; i++) {
         for (int j = 0; j < 4; j++) {
             if (game[i][j] == game[i][j + 1] || game[j][i] == game[j + 1][i])	return;
             else
             {
             	printf("Game Over!");
             	exit(0);
			 }
         }
     }
}
void up(void)//上 
{
	for(int i = 0;i<4;i++)
	{
		for(int j = 0;j<4;j++)
		{
			if(game[i][j]==0)	continue;
			else
			{
				for(int k = i+1;k<4;k++)
				{
					if(game[k][j]==0)	continue;
					else if(game[k][j]==game[i][j])
					{
						game[i][j]*=2;
						game[k][j]=0;
						i = k;
						empty++;
						break;
					}
					else	break;
				}
					for(int z = 3;z>0;z--)
						{
							if(game[z-1][j]==0)
							{
								game[z-1][j] = game[z][j];
								game[z][j] = 0;
							}
						}
			}
		}
	}
/*	for(int j = 0;j<4;j++)//将所有数字向上移动 
	{
		for(int i = 0;i<4;i++)
		{
			if(game[i][j]==0)	continue;
			else
			{
				for(int k = i;(i>0)&&(game[i-1][j]==0);k--)
				{
					game[k][j] = game[i][j];
					game[i][j] = 0;
				}
			}
		}
	}*/
}
void down(void)//下 
{
	for(int i = 3;i>-1;i--)
	{
		for(int j = 0;j<4;j++)
		{
			if(game[i][j]==0)	continue;
			else
			{
				for(int k = i-1;k>-1;k--)
				{
					if(game[k][j]==0) continue;
					else if(game[k][j]==game[i][j])
					{
						game[i][j]*=2;
						game[k][j] = 0;
						i = k;
						empty++;
						break;
					}
					else	break;
					}
				for(int z = 0;z<3;z++)
				{
					if(game[z+1][j]==0)
					{
						game[z+1][j]=game[z][j];
						game[z][j]=0;
					}
				}
				}
			}
		}
	}
void left(void)//左 
{
	for(int i =0;i<4;i++)
	{
		for(int j = 0;j<4;j++)
		{
			if(game[i][j]==0)	continue;
			else
			{
				for(int k = j-1;k>-1;k--)
				{
					if(game[i][k]==0)	continue;
					else if(game[i][k]==game[i][j])
					{
						game[i][j]*=2;
						game[i][k] = 0;
						j = k;
						empty++;
						break;
					}
					else	break;
				}
					for(int z = 3;z>0;z--)
					{
						if(game[i][z-1]==0)
						{
							game[i][z-1] = game[i][z];
							game[i][z] = 0;
						}
					}
					}
				}
			}
		}
void right(void)//右 
{
	for(int i = 0;i<4;i++)
	{
		for(int j = 0;j<4;j++)
		{
			if(game[i][j]==0)	continue;
			else
			{
				for(int k = j+1;k<4;k++)
				{
					if(game[i][k]==0)	continue;
					else if(game[i][k]==game[i][j])
					{
						game[i][j]*=2;
						game[i][k] = 0;
						j = k;
						empty++;
						break;
					}
					else	break;
					}
					for(int z = 0;z<3;z++)
					{
							if(game[i][z+1] == 0)
						{
							game[i][z+1] = game[i][z];
							game[i][z] = 0;
						}
					}
				}
			}
		}
	}
void start ()//初始化地图，使用当前时间作为种子随机填入2 
{
	srand(time(0));
	int a = rand() % 4,b = rand() % 4;
	game[a][b] = 2;
}
void draw ()
{
	int i = 0,j = 0;
	for(i = 0;i<4;i++)
	{
		for(j = 0;j<4;j++)//第一行 
		{
			printf("|     ");
		}
		printf("|\n");
		for(j = 0;j<4;j++)//第二行，此时需要填入数字 
		{
			if(game[i][j]==0)
			printf("|     ");
			else
			printf("|%5d",game[i][j]);
		}
		printf("|\n");
		for(j = 0;j<4;j++)//第三行，需要横线 
		{
			printf("|_____");
		}
		printf("|\n");
	}
	
 } 
 void 
addnumber(void) {
    int temp, number;
    int x, y;
    
    if(empty > 0) {     // 找出空格 
        srand(time(0));
        do {
            x = rand() % 4;
            y = rand() % 4;
        } while(game[x][y] != 0);
        
        number = rand();
        temp = number % 2;
    
        if(temp == 1) {  // 判断是生成数字2，还是数字4
            game[x][y] = 2;
            --empty;
        } 
        if(temp == 0) {
            game[x][y] = 4;
            --empty;
        }
    }

}
 void play()
 {
 	char input = getch();
 	switch(input)
 	{
 		case'W':
 		case'w':
 			up();
 			system("cls");
 			addnumber();
 			draw();
 			break;
 		case's':
 		case'S':
 			down();
 			system("cls");
 			addnumber();
 			draw();
 			break;
 		case'd':
 		case'D':
 			right();
 			system("cls");
 			addnumber();
 			draw();
 			break;
 		case'a':
 		case'A':
 			left();
 			system("cls");
 			addnumber();
 			draw();
			break;
		default:
			break;	
	 }
 }
int main()
{
	start();	
	draw();
	while(1)
	{
		play();
		if(empty==0)	check();
	}
}

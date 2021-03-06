#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define random(x) (rand()%x)
#define MAX_N 100
#define SIZE 8
#define STAT_POS_Y 128
#define STAT_POS_X 128
#define WIN_LENGTH 640
#define WIN_HEIGHT 640

#pragma comment(lib,"winmm.lib")//加载库用于播放音乐
//自定义数据类型
enum DIR
{
	UP = 72, RIGHT = 77, LEFT = 75, DOWN = 80, STOP = 32
};
enum FOODTYPE
{
	ORANGE = 0, WATERMELON, COOKIR, STONE, BASKETBALL,MAN
};
struct  Point
{
	int pos_x;
	int pos_y;
};
struct  Snack
{
	int n;//当前长度
	DIR dir;//蛇的方向
	struct Point point[MAX_N];//蛇的坐标
};
//全局变量声明
struct Snack snack;//蛇
int food_x;//食物坐标
int food_y;//食物坐标
FOODTYPE food;
int FAIL;//是否失败变量
IMAGE background;
IMAGE basketball; IMAGE orange; IMAGE watermelon; 
IMAGE cookie; IMAGE stone; IMAGE man;
//函数声明
int Start_Page(void);
void Initialize_snack(void);
void Draw_snack(void);
int Game(void);
void keypro(void);
void Draw_food(void);



int main()
{

	srand((int)time(0));
	initgraph(WIN_LENGTH, WIN_HEIGHT);
	int player_choose=Start_Page();
	if (player_choose==0)
	{
		//开始游戏
		Initialize_snack();
		Game();
	}
	if (player_choose==1)
	{
		return 0;//退出游戏
	}
	if (player_choose==2)
	{
		//关于
		cleardevice();
		IMAGE START;
		loadimage(&START, L"start.jpg", WIN_LENGTH, WIN_HEIGHT);
		putimage(0, 0, &START);
		settextcolor(RED);
		settextstyle(32, 0, L"黑体");
		setbkmode(TRANSPARENT);
		outtextxy(200, 200, L"制作人：乐乐");
		outtextxy(200, 250, L"制作时间：2019");
		outtextxy(200, 300, L"开源协议：BSD  ");
		outtextxy(200, 350, L"版本：1.0  ");

	}



	_getch();
	return 0;
}

int Start_Page()//开始界面
{
	setbkmode(TRANSPARENT); //字体背景为空
	IMAGE START;
	loadimage(&START, L"start.jpg",WIN_LENGTH,WIN_HEIGHT);//开始界面背景图片
	putimage(0, 0, &START);
	settextcolor(GREEN);
	settextstyle(32, 0, L"黑体");
	outtextxy(300, 440, L"开始游戏");
	settextcolor(RED);
	outtextxy(300, 500, L"退出游戏");
	outtextxy(300, 560, L"  关于  ");
	int key_value; //按键值
	int key = 0;//选项卡值
	do
	{
		key_value = _getch();
		if (key_value == 72)
		{
			key--;
			if (key == -1){ key++; }
		}
		if (key_value == 80)
		{
			key++;
			if (key == 3){ key--; }
		}
		switch (key)
		{
		case 0:
			settextcolor(GREEN);
			settextstyle(32, 0, L"黑体");
			outtextxy(300, 440, L"开始游戏");
			settextcolor(RED);
			outtextxy(300, 500, L"退出游戏");
			outtextxy(300, 560, L"  关于  ");
			break;
		case 1:
			settextcolor(RED);
			settextstyle(32, 0, L"黑体");
			outtextxy(300, 440, L"开始游戏");
			settextcolor(GREEN);
			outtextxy(300, 500, L"退出游戏");
			settextcolor(RED);
			outtextxy(300, 560, L"  关于  ");
			break;
		case 2:
			settextcolor(RED);
			settextstyle(32, 0, L"黑体");
			outtextxy(300, 440, L"开始游戏");
			outtextxy(300, 500, L"退出游戏");
			settextcolor(GREEN);
			outtextxy(300, 560, L"  关于  ");

		default:
			break;
		}

	} while (key_value != 13);
	return key;
}
void Initialize_snack()//初始化函数
{
	mciSendString(L"open music.mp3 alias music", 0, 0, 0);
	mciSendString(L"play music.mp3  repeat", 0, 0, 0);
	snack.n = 5;
	snack.dir = RIGHT;
	snack.point[0].pos_x = STAT_POS_X;
	snack.point[0].pos_y = STAT_POS_Y;
	snack.point[1].pos_x = STAT_POS_X - SIZE;
	snack.point[1].pos_y = STAT_POS_Y;
	snack.point[2].pos_x = STAT_POS_X - SIZE * 2;
	snack.point[2].pos_y = STAT_POS_Y;
	snack.point[3].pos_x = STAT_POS_X - SIZE * 3;
	snack.point[3].pos_y = STAT_POS_Y;
	snack.point[4].pos_x = STAT_POS_X - SIZE * 4;
	snack.point[4].pos_y = STAT_POS_Y;
	 food_x = WIN_LENGTH / 2;
	 food_y = WIN_HEIGHT / 2;

	//初始一个五节的蛇，食物坐标
	  food = ORANGE;
	 //初始食物，橘子
	 loadimage(&background, L"background.jpg", WIN_LENGTH, WIN_HEIGHT);
	 //游戏界面的背景图
	 loadimage(&orange, L"orange.jpg", 2 * SIZE + 1,2*SIZE+1);
	 loadimage(&stone, L"stone.jpg", 2 * SIZE + 1, 2 * SIZE + 1);
	 loadimage(&basketball, L"basketball.jpg", 2 * SIZE + 1, 2 * SIZE + 1);
	 loadimage(&watermelon, L"watermelon.jpg", 2 * SIZE + 1, 2 * SIZE + 1);
	 loadimage(&man, L"man.jpg", 5 * SIZE + 1, 5 * SIZE + 1);
	 loadimage(&cookie, L"cookie.jpg", 2 * SIZE + 1, 2 * SIZE + 1);
	 //食物贴图
}
void Draw_snack() //画出蛇
{
	
	
	for (int i = 0; i <snack.n; i++)
	{
		setfillcolor(RGB(random(256), random(256), random(256)));//色彩随机蛇
		fillcircle(snack.point[i].pos_x, snack.point[i].pos_y, SIZE / 2);
	}
	char node[3];
	_itoa_s(100-snack.n, node, 10);//将一个数按照十进制形式存入字符串中
	outtextxy(600, 60,node[0]);//显示剩余食物数
	outtextxy(620, 60, node[1]);
	if (snack.n%10==0)
	{
		settextcolor(RGB(random(255), random(255), random(255)));
		outtextxy(20, 60, L"按空格键暂停，方向键继续");
	}
}
int snack_move(DIR dir)//蛇的移动
{
	if (dir==STOP)
	{
		return 0;
	}
	struct Point temp;//蛇头坐标副本
	temp.pos_x = snack.point[0].pos_x;
	temp.pos_y = snack.point[0].pos_y;
	
		
	snack.point[1].pos_y = snack.point[0].pos_y;
	switch (dir)
	{
	case UP:
		snack.point[0].pos_y = snack.point[0].pos_y-SIZE/2;
		break;
	case RIGHT:
		snack.point[0].pos_x = snack.point[0].pos_x + SIZE/2;
		break;
	case LEFT:
		snack.point[0].pos_x = snack.point[0].pos_x - SIZE/2;
		break;
	case DOWN:
		snack.point[0].pos_y = snack.point[0].pos_y + SIZE/2;
		break;
	case STOP:Sleep(500);
	default:
		break;
	}
	for (int i = 1; i <snack.n; i++)
	{
		if (snack.point[i].pos_x == snack.point[0].pos_x&&snack.point[i].pos_y == snack.point[0].pos_y)
		{
			outtextxy(WIN_LENGTH / 2-20, WIN_HEIGHT / 2-20, L"你输了,咬到了自己");
			return 1;//表示吃到自己
			
		}
	}
	
	for (int i = snack.n-1; i >1; i--)//移动
	{
		snack.point[i].pos_x = snack.point[i - 1].pos_x;
		snack.point[i].pos_y = snack.point[i - 1].pos_y;

	}
	snack.point[1].pos_x = temp.pos_x;
	snack.point[1].pos_y = temp.pos_y;
	return 0;//没吃到自己
}
int Game()//游戏主界面
{
	while (1)
	{
		while (!_kbhit())
		{
			putimage(0, 0, &background);
			if (abs(food_x - snack.point[0].pos_x)<SIZE&&abs(food_y-snack.point[0].pos_y)<SIZE)//相对吃到食物
			{
				//(food_x == snack.point[0].pos_x&&food_y == snack.point[0].pos_y)绝对吃到食物
				food_x = SIZE*random(WIN_LENGTH / SIZE);
				food_y = SIZE*random(WIN_HEIGHT / SIZE);
				food = (FOODTYPE)random(6);
				snack.n++;
				if (snack.n == 100)//蛇达到最大长度
				{
					break;
				}
				//增加一节蛇
				if (snack.point[snack.n - 2].pos_x == snack.point[snack.n - 1].pos_x)
				{
					if (snack.point[snack.n - 2].pos_y > snack.point[snack.n - 1].pos_y)
					{
						snack.point[snack.n].pos_x = snack.point[snack.n - 1].pos_x;
						snack.point[snack.n].pos_y = snack.point[snack.n - 1].pos_y - SIZE;
					}
					else
					{
						snack.point[snack.n].pos_x = snack.point[snack.n - 1].pos_x;
						snack.point[snack.n].pos_y = snack.point[snack.n - 1].pos_y + SIZE;
					}
				}
				else
				{
					if (snack.point[snack.n - 2].pos_x > snack.point[snack.n - 1].pos_x)
					{
						snack.point[snack.n].pos_x = snack.point[snack.n - 1].pos_x - SIZE;
						snack.point[snack.n].pos_y = snack.point[snack.n - 1].pos_y;
					}
					else
					{
						snack.point[snack.n].pos_x = snack.point[snack.n - 1].pos_x + SIZE;
						snack.point[snack.n].pos_y = snack.point[snack.n - 1].pos_y;
					}
				}

			}


			FAIL = snack_move(snack.dir);
			if (FAIL)
			{
				return 0;
			}
			setfillcolor(GREEN);
			//fillcircle(food_x, food_y, SIZE);//画食物
			Draw_food();
			Draw_snack();
			if (snack.point[0].pos_x<0)break;
			if (snack.point[0].pos_y<0)break;
			if (snack.point[0].pos_x>WIN_LENGTH)break;
			if (snack.point[0].pos_y>WIN_HEIGHT)break;

			Sleep(50);
		}
		if (snack.n == 100)	break;
		if (snack.point[0].pos_x<0)break;
		if (snack.point[0].pos_y<0)break;
		if (snack.point[0].pos_x>WIN_LENGTH)break;
		if (snack.point[0].pos_y>WIN_HEIGHT)break;
		keypro();

	}
	if (snack.n != 100)
	{
		outtextxy(WIN_LENGTH / 2, WIN_HEIGHT / 2, L"你输了,撞墙死了");
	}
	else
	{
		outtextxy(WIN_LENGTH / 2, WIN_HEIGHT / 2, L"你赢了达到最大长度100");
	}

}
void keypro()
{
	
	DIR key = (DIR)_getch();
	switch (key)
	{
	case UP:
		if (snack.dir!=DOWN)
		snack.dir = UP;
		break;
	case RIGHT:
		if (snack.dir != LEFT)
		snack.dir = RIGHT;
		break;
	case LEFT:
		if (snack.dir != RIGHT)
		snack.dir = LEFT;
		break;
	case DOWN:
		if (snack.dir != UP)
		snack.dir = DOWN;
		break;
	case STOP:
		snack.dir = STOP;

	default:
		
		
		break;
	}
}
void Draw_food()
{
	//fillcircle(food_x, food_y, SIZE);//画食物
	int pos_x = food_x-SIZE;
	int pos_y = food_y-SIZE;

	
	switch (food)
	{
	case ORANGE:
		putimage(pos_x,pos_y, &orange);
		break;
	case WATERMELON:
		putimage(pos_x, pos_y, &watermelon);
		break;
	case COOKIR:
		putimage(pos_x, pos_y, &cookie);
		break;
	case STONE:
		putimage(pos_x, pos_y, &stone);
		break;
	case BASKETBALL:
		putimage(pos_x, pos_y, &basketball);
		break;
	case MAN:
		putimage(pos_x, pos_y, &man);
		break;
	default:
		break;
	}

}

//BUG 蛇纵向移动的时候，少一结显示，恢复横向移动正常
//BUG:偶尔/经常食物消失，游戏无法继续

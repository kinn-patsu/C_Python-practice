#include<stdio.h>
#include<math.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#pragma comment (lib,"winmm.lib")		//加声音的
enum MY
{
	width = 572,	//窗口宽度高度
	high = 807,
	bulletnum=10,	//子弹数量
	enemy=10	//敌机数量
};
struct plane		//飞机结构体
{
	int x;
	int y;
	int hp;			//血量
	int pt;			//得分
	bool live;		//是否存活，bool只有真假2个变量

}player,bullet[bulletnum];
struct enemyp
{
	int x;
	int y;
	bool live;
	int hp;
}enemy1[enemy], enemy2[4];

IMAGE biu[2];		//子弹
IMAGE bk;			//把图片加载进程序
IMAGE playerimg[2];		//保存玩家图片
IMAGE imgenemy[2][2];		//敌机图片	
void load()
{
	//加载图片
	loadimage(&bk, "./images/bk.jpg");//报错要改字符集

	loadimage(&playerimg[0], "./images/me1.png");//加载玩家
	loadimage(&playerimg[1], "./images/me2.png");

	loadimage(&biu[0], "./images/bullet1.png");
	loadimage(&biu[1], "./images/bullet2.png");

	loadimage(&imgenemy[0][0], "./images/enemy1.png");
	loadimage(&imgenemy[0][1], "./images/enemy1_1.png");
	loadimage(&imgenemy[1][0], "./images/enemy2.png");
	loadimage(&imgenemy[1][1], "./images/enemy2_1.png");

}
void gameinit()
{
	player.x = width / 2;	//初始化角色
	player.y = high - 100;
	player.hp = 50;
	player.live = true;
	player.pt = 0;

	for (int i = 0; i < bulletnum; i++)		//初始化子弹
	{
		bullet[i].x = 0;
		bullet[i].y = 0;
		bullet[i].live = false;
	}

	for (int i = 0; i < enemy; i++)
	{
		enemy1[i].live = false;
		enemy1[i].hp = 1;
	}
	for (int j = 0; j < 4; j++)
	{
		enemy2[j].live = false;
		enemy2[j].hp = 2;
	}
}
void gamedraw()
{
	load();
	putimage(0, 0, &bk);		//把背景图片贴到窗口
	if (player.live)
	{
		putimage(player.x, player.y, &playerimg[0], SRCPAINT);			//贴玩家
		putimage(player.x, player.y, &playerimg[1], SRCINVERT);
	}

	for (int i = 0; i < bulletnum; i++)
	{
		if (bullet[i].live)
		{
			putimage(bullet[i].x, bullet[i].y, &biu[0], SRCPAINT);
			putimage(bullet[i].x, bullet[i].y, &biu[1], SRCINVERT);
		}
	}

	for (int i = 0; i < enemy; i++)
	{
		if (enemy1[i].live)
		{
			putimage(enemy1[i].x, enemy1[i].y, &imgenemy[0][0], SRCPAINT);
			putimage(enemy1[i].x, enemy1[i].y, &imgenemy[0][1], SRCINVERT);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (enemy2[i].live)
		{
			putimage(enemy2[i].x, enemy2[i].y, &imgenemy[1][0], SRCPAINT);
			putimage(enemy2[i].x, enemy2[i].y, &imgenemy[1][1], SRCINVERT);
		}
	}
}		 //游戏绘制函数
void bulletmove()
{
	for (int i = 0; i < bulletnum; i++)
	{
		if (bullet[i].live)
		{
			bullet[i].y -= 10;
		}
	}
}
void creatbullet()
{
	if (player.live)
	{
		for (int i = 0; i < bulletnum; i++)
		{
			if (!bullet[i].live)
			{
				bullet[i].x = player.x + 25;
				bullet[i].y = player.y;
				bullet[i].live = true;
				break;
			}
		}
	}
	for (int i = 0; i < bulletnum; i++)
	{
		if (bullet[i].live&&bullet[i].y<0)
		{
			bullet[i].live = false;
			break;
		}
	}
}
void createnemy()
{
	for (int i = 0; i < enemy; i++)
	{
		if (!enemy1[i].live)
		{
			enemy1[i].live = true;
			enemy1[i].x = rand() % (width-40);
			enemy1[i].y = 0;
			break;
		}
	}
	for (int j=0;j < 4; j++)
	{
		if (!enemy2[j].live)
		{
			enemy2[j].live = true;
			enemy2[j].x = rand() % (width-80);
			enemy2[j].y = 0;
			break;
		}
	}

}
void enemymove()
{
	for (int i = 0; i < enemy; i++)
	{
		if (enemy1[i].live)
		{
			enemy1[i].y +=2;
			if (enemy1[i].y > high)
			{
				player.hp -= 2;
				enemy1[i].live = false;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (enemy2[i].live)
		{
			enemy2[i].y ++;
			if (enemy2[i].y > high)
			{
				player.hp -= 10;
				enemy2[i].live = false;
			}		
		}
	}
}
bool timer(unsigned int ms,int id)
{
	static DWORD t[10];
	if ((clock()-t[id])> ms)
	{
		t[id] = clock();
		return true;
	}
	return false;
}
void move(int speed)				//飞机移动
{
	/*
	//方法1,getch() 阻塞函数，和scanf一样，如果没有输入就会卡住程序，一直等待输入,这个并不是c的标志函数，要包含头文件<conio.h>
	if (_kbhit())			//kbhit的作用是取消阻塞
	{
char k = _getch();
	switch (k)
	{
	case'w':
	case'W':
		player.y -= speed;
		break;
	case's':
	case'S':
		player.y += speed;
		break;
	case'a':
	case'A':
		player.x -= speed;
		break;
	case'd':
	case'D':
		player.x += speed;
		break;
	}
	}
	*/
	//方法2windows函数 GetAsyncKeyState	如果要检测字母按键必须要用大写，这样大写小写都可以检测得到，小写不能被检测
	if (GetAsyncKeyState(VK_UP)|| GetAsyncKeyState('W'))
	{
		if (player.y > 0)	//这样小于0的时候就不会移动了
		{
			player.y -= speed;

		}
	}
	if (GetAsyncKeyState(VK_DOWN)|| GetAsyncKeyState('S'))
	{
		if(player.y<high-66)
		player.y += speed;
	}
	if (GetAsyncKeyState(VK_LEFT)|| GetAsyncKeyState('A'))
	{
		if(player.x+25>0)
		player.x -= speed;
	}
	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D'))
	{
		if(player.x-60<width-102)
		player.x += speed;
	}
	if (timer(200,1)&& GetAsyncKeyState(VK_SPACE))
	{
		creatbullet();
		mciSendString(_T("close biubiu"), NULL, 0, NULL);
		mciSendString("open \".\\images\\shoot.mp3\" alias biubiu", NULL, 0, NULL);
		mciSendString(_T("play biubiu"), NULL, 0, NULL);
	}
	/*static DWORD t1 = 0, t2 = 0;	//dword ,是double word的简称， 就是双字节的意思
	if (GetAsyncKeyState(VK_SPACE)&&t2-t1>300)
	{
		creatbullet();
		t1 = t2;
	}t2 = GetTickCount();*/			//实现延时，获取毫秒级数目它返回从操作系统启动到当前所经过的毫秒数，常常用来判断某个方法执行的时间
}
void hit1()				//实现打击后血量减少，血量为0消失
{
	for (int i = 0; i< enemy; i++)
	{
		if (!enemy1[i].live)
			continue;
		for (int k = 0; k < bulletnum; k++)
		{
			if (!bullet[k].live)
				continue;
			if (bullet[k].x > enemy1[i].x && bullet[k].x<enemy1[i].x + 57
				&& bullet[k].y>enemy1[i].y && bullet[k].y < enemy1[i].y + 43)
			{
				bullet[k].live = false;
				enemy1[i].hp--;
			}
		}
		if (enemy1[i].hp <= 0)
		{
			enemy1[i].live = false;
			enemy1[i].hp = 1;
			player.pt += 1;
		}
	}
}
void hit2()				//实现打击后血量减少，血量为0消失
{
	for (int m = 0; m < 4; m++)
	{
		if (!enemy2[m].live)
			continue;
		for (int k = 0; k < bulletnum; k++)
		{
			if (!bullet[k].live)
				continue;
			if (bullet[k].x > enemy2[m].x && bullet[k].x<enemy2[m].x + 84
				&& bullet[k].y>enemy2[m].y && bullet[k].y < enemy2[m].y + 128)
			{
				bullet[k].live = false;
				enemy2[m].hp--;
			}
		}
		if (enemy2[m].hp <= 0)
		{
			enemy2[m].live = false;
			enemy2[m].hp = 2;
			player.pt += 2;
		}
	}
}
void print()
{
	if (player.live)
	{
		char a[2][10];
		sprintf_s(a[0], sizeof(a[0]), _T("%d"), player.hp);		//sprintf把整形参数转为字符
		sprintf_s(a[1], sizeof(a[1]), _T("%d"), player.pt);
		settextcolor(BLACK);		//设置文字颜色
		setbkmode(TRANSPARENT);		//设置文字背景透明
		settextstyle(25, 0, "宋体");
		outtextxy(0, 750, "hp:");		//outtext只能显示字符
		outtextxy(200, 750, "point:");
		outtextxy(100, 750, a[0]);
		outtextxy(300, 750, a[1]);
	}
	else
	{
		char a[10];
		sprintf_s(a, sizeof(a), _T("%d"), player.pt);
		settextcolor(BLACK);
		setbkmode(TRANSPARENT);
		settextstyle(50, 0, "宋体");
		outtextxy(width / 2-200, high / 2, "游戏结束  point:");
		outtextxy(width / 2 , high / 2+50, a);
	}
}
void gameover()
{
	if (player.hp <= 0)
	{
		player.live = false;
	}
	/*for (int i = 0; i < enemy; i++)
	{
		if (enemy1[i].y > high - 10 && enemy1[i].live)
		{
			mciSendString(_T("close over"), 0, 0, 0);
			mciSendString("open \".\\images\\hl.mp3\" alias over", NULL, 0, NULL);
			mciSendString(_T("play over "), 0, 0, 0);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (enemy2[i].y > high - 10 && enemy2[i].live)
		{
			mciSendString(_T("close over"), 0, 0, 0);
			mciSendString("open \".\\images\\hl.mp3\" alias over", NULL, 0, NULL);
			mciSendString(_T("play over "), 0, 0, 0);
		}
	}*/
}


int main()
{
	//创建一个背景窗口,show可以调出图形同时调出控制台
	initgraph(width, high, SHOWCONSOLE);
	/*circle(50, 50, 50);//画空心原
	setfillcolor(GREEN);
	fillcircle(100, 100, 50);*/
	gameinit();
	mciSendString("open \".\\images\\bgm.mp3\" alias bgm", NULL, 0, NULL);
	mciSendString("open \".\\images\\shoot.mp3\" alias biubiu", NULL, 0, NULL);
	mciSendString("open \".\\images\\hl.mp3\" alias over", NULL, 0, NULL);
	mciSendString(_T("play bgm repeat"), NULL, 0, NULL);
	
	BeginBatchDraw();		//双缓冲绘图

	while (1)
	{
		if (timer(500,0)&&player.live)
		{
			createnemy();
		}
		enemymove();
		gamedraw();
		print();
		FlushBatchDraw();
		move(3); bulletmove(); hit1(); hit2();gameover();
	}
	EndBatchDraw();
	return 0;
}
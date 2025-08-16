#include<stdio.h>
#include<math.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#pragma comment (lib,"winmm.lib")		//��������
enum MY
{
	width = 572,	//���ڿ�ȸ߶�
	high = 807,
	bulletnum=10,	//�ӵ�����
	enemy=10	//�л�����
};
struct plane		//�ɻ��ṹ��
{
	int x;
	int y;
	int hp;			//Ѫ��
	int pt;			//�÷�
	bool live;		//�Ƿ��boolֻ�����2������

}player,bullet[bulletnum];
struct enemyp
{
	int x;
	int y;
	bool live;
	int hp;
}enemy1[enemy], enemy2[4];

IMAGE biu[2];		//�ӵ�
IMAGE bk;			//��ͼƬ���ؽ�����
IMAGE playerimg[2];		//�������ͼƬ
IMAGE imgenemy[2][2];		//�л�ͼƬ	
void load()
{
	//����ͼƬ
	loadimage(&bk, "./images/bk.jpg");//����Ҫ���ַ���

	loadimage(&playerimg[0], "./images/me1.png");//�������
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
	player.x = width / 2;	//��ʼ����ɫ
	player.y = high - 100;
	player.hp = 50;
	player.live = true;
	player.pt = 0;

	for (int i = 0; i < bulletnum; i++)		//��ʼ���ӵ�
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
	putimage(0, 0, &bk);		//�ѱ���ͼƬ��������
	if (player.live)
	{
		putimage(player.x, player.y, &playerimg[0], SRCPAINT);			//�����
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
}		 //��Ϸ���ƺ���
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
void move(int speed)				//�ɻ��ƶ�
{
	/*
	//����1,getch() ������������scanfһ�������û������ͻῨס����һֱ�ȴ�����,���������c�ı�־������Ҫ����ͷ�ļ�<conio.h>
	if (_kbhit())			//kbhit��������ȡ������
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
	//����2windows���� GetAsyncKeyState	���Ҫ�����ĸ��������Ҫ�ô�д��������дСд�����Լ��õ���Сд���ܱ����
	if (GetAsyncKeyState(VK_UP)|| GetAsyncKeyState('W'))
	{
		if (player.y > 0)	//����С��0��ʱ��Ͳ����ƶ���
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
	/*static DWORD t1 = 0, t2 = 0;	//dword ,��double word�ļ�ƣ� ����˫�ֽڵ���˼
	if (GetAsyncKeyState(VK_SPACE)&&t2-t1>300)
	{
		creatbullet();
		t1 = t2;
	}t2 = GetTickCount();*/			//ʵ����ʱ����ȡ���뼶��Ŀ�����شӲ���ϵͳ��������ǰ�������ĺ����������������ж�ĳ������ִ�е�ʱ��
}
void hit1()				//ʵ�ִ����Ѫ�����٣�Ѫ��Ϊ0��ʧ
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
void hit2()				//ʵ�ִ����Ѫ�����٣�Ѫ��Ϊ0��ʧ
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
		sprintf_s(a[0], sizeof(a[0]), _T("%d"), player.hp);		//sprintf�����β���תΪ�ַ�
		sprintf_s(a[1], sizeof(a[1]), _T("%d"), player.pt);
		settextcolor(BLACK);		//����������ɫ
		setbkmode(TRANSPARENT);		//�������ֱ���͸��
		settextstyle(25, 0, "����");
		outtextxy(0, 750, "hp:");		//outtextֻ����ʾ�ַ�
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
		settextstyle(50, 0, "����");
		outtextxy(width / 2-200, high / 2, "��Ϸ����  point:");
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
	//����һ����������,show���Ե���ͼ��ͬʱ��������̨
	initgraph(width, high, SHOWCONSOLE);
	/*circle(50, 50, 50);//������ԭ
	setfillcolor(GREEN);
	fillcircle(100, 100, 50);*/
	gameinit();
	mciSendString("open \".\\images\\bgm.mp3\" alias bgm", NULL, 0, NULL);
	mciSendString("open \".\\images\\shoot.mp3\" alias biubiu", NULL, 0, NULL);
	mciSendString("open \".\\images\\hl.mp3\" alias over", NULL, 0, NULL);
	mciSendString(_T("play bgm repeat"), NULL, 0, NULL);
	
	BeginBatchDraw();		//˫�����ͼ

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
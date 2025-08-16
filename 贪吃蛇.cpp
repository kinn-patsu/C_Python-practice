#include<stdio.h>
#include<math.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#pragma comment (lib,"winmm.lib")
typedef struct tcs
{
	int x;
	int y;
	struct tcs* next;
}tcs;
struct fruit
{
	int x;
	int y;
	bool live;
}fruit;
enum
{
	width = 800,
	high = 800
};



void shifang(tcs* head)
{
	free(head);
}
bool timer(unsigned int ms, int id)
{
	static DWORD t[10];
	if ((clock() - t[id]) > ms)
	{
		t[id] = clock();
		return true;
	}
	return false;
}
tcs* add(tcs* head)                //添加蛇蛇的尾巴
{
	tcs* p = (tcs*)malloc(sizeof(tcs));
	tcs* k = head, * j = head;
	while (k->next->next != NULL)
	{
		j = j->next;
		k = k->next;
	}
	k = k->next; k->next = p;
	if (j->x == k->x && j->y > k->y)
	{
		p->x = k->x;
		p->y = k->y - 10;
	}
	if (j->x == k->x && j->y < k->y)
	{
		p->x = k->x;
		p->y = k->y + 10;
	}
	if (j->x > k->x && j->y == k->y)
	{
		p->x = k->x - 10;
		p->y = k->y;
	}
	if (j->x < k->x && j->y == k->y)
	{
		p->x = k->x + 10;
		p->y = k->y;
	}
	p->next = NULL;
	return head;
}
tcs* playerinit()			//初始化蛇蛇
{

	tcs* head = (tcs*)malloc(1 * sizeof(tcs));
	tcs* head2 = (tcs*)malloc(1 * sizeof(tcs)); head2->next = NULL;
	head->x = 99; head->y = 100; head2->x = 98; head2->y = 100;
	head->next = head2;
	for (int i = 0; i < 8; i++)		//刚开始十个单位的长度
	{
		head = add(head);
	}
	return head;
}
void draw(tcs*head,bool*player)			//画出蛇蛇和果实
{
	

	settextcolor(BLACK);
	settextstyle(29, 0, "宋体");
	setbkmode(TRANSPARENT);

	//蛇
	
	if (*player == true)
	{
		outtextxy(head->x, head->y, "·");
	}
	//改变字体
	settextcolor(BLACK);
	settextstyle(30, 0, "宋体");
	setbkmode(TRANSPARENT);
	head = head->next;

	if (*player == true)
	{
		while (head != NULL)
		{
			outtextxy(head->x, head->y, "*");
			head = head->next;
		}
	}

	//果实
	if (fruit.live)
	{
		outtextxy(fruit.x, fruit.y, "+");
	}
	
}
void creatfruit()			//生产果实
{	
	if (fruit.live==false)
	{
		fruit.live = true;
		fruit.x = rand()%700;
		fruit.y = rand()%700;
	}
}
void eat(tcs*head, struct fruit *fruit)			//吃果实
{
	if(head->x<fruit->x+10&&head->x>fruit->x-10)
		if (head->y<fruit->y + 10 && head->y>fruit->y-10)
		{
			fruit->live = false;
			add(head); add(head); add(head); add(head);
		}
	
}
void move(tcs*head,int speed)		//控制移动
{
	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W'))
	{
		if (head->y > -3)
		{
			head->y -= speed;
		}
	}
	if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S'))
	{
		if (head->y < high-20)
			head->y += speed;
	}
	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A'))
	{
		if (head->x > -3)
			head->x -= speed;
	}
	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D'))
	{
		if (head->x  < width-20 )
			head->x += speed;
	}
	
}
void updateList(tcs* p)		//更新链表下一个元素为上一个元素，单链表：采用递归的方法    双向链表：从最后一个开始遍历更新
{
	if (p->next != NULL)
	{
		updateList(p->next);
		p->next->x = p->x;
		p->next->y = p->y;
	}
}
void initmove(tcs* head,int speed)			//让蛇蛇的头和身自己移动
{
	tcs* p = head->next;
	int x = head->x, y = head->y;

	if ((GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W')) || (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S')) || (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A')) || (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D')))
	{
		updateList(head);
		p->x = x; p->y = y;
	}
	else 
	{
		if (head->x > head->next->x)
			head->x += speed;
		if (head->x < head->next->x)
			head->x -= speed;
		if (head->y < head->next->y)
			head->y -= speed;
		if (head->y > head->next->y)
			head->y += speed;

		updateList(head);
		p->x = x; p->y = y;
	}
	
}
bool hasDuplicate(tcs* head)		//判断是否有x，y都相等的节点
{
	tcs* current = head;
	while (current != NULL) {
		tcs* runner = current->next;
		while (runner != NULL) {
			if (current->x == runner->x && current->y == runner->y) {
				return true;
			}
			runner = runner->next;
		}
		current = current->next;
	}
	return false;
}
void gameover(tcs*head,bool *player)		//游戏结束条件
{
	if ((head->x < -17 || head->x > width) || (head->y < -17 || head->y > high))		//碰到边界死
	{
		*player = false;
		fruit.live = false;
	}
		

	if (hasDuplicate(head))			//咬到自己就死
	{
		*player = false;
		fruit.live = false;
	}
}





int main()
{
	initgraph(width, high, SHOWCONSOLE);	//生成窗口并添加控制台
	
	tcs* head; head = playerinit();		//召唤蛇蛇
	bool a; bool* player = &a; *player = true; fruit.live = false;

	BeginBatchDraw();
	while (1)
	{
		setbkcolor(WHITE);		//设置背景颜色
		cleardevice();		//设置清屏函数才能显示背景颜色
		if (*player == true)
		{
			creatfruit();
		}
		draw(head,player);
		FlushBatchDraw();
		if (timer(50, 0)){
			initmove(head, 5);
		
			move(head, 5);}
		eat(head,&fruit);
		gameover(head, player);
		
	}
	EndBatchDraw();
	shifang(head);
}
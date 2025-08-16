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
tcs* add(tcs* head)                //������ߵ�β��
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
tcs* playerinit()			//��ʼ������
{

	tcs* head = (tcs*)malloc(1 * sizeof(tcs));
	tcs* head2 = (tcs*)malloc(1 * sizeof(tcs)); head2->next = NULL;
	head->x = 99; head->y = 100; head2->x = 98; head2->y = 100;
	head->next = head2;
	for (int i = 0; i < 8; i++)		//�տ�ʼʮ����λ�ĳ���
	{
		head = add(head);
	}
	return head;
}
void draw(tcs*head,bool*player)			//�������ߺ͹�ʵ
{
	

	settextcolor(BLACK);
	settextstyle(29, 0, "����");
	setbkmode(TRANSPARENT);

	//��
	
	if (*player == true)
	{
		outtextxy(head->x, head->y, "��");
	}
	//�ı�����
	settextcolor(BLACK);
	settextstyle(30, 0, "����");
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

	//��ʵ
	if (fruit.live)
	{
		outtextxy(fruit.x, fruit.y, "+");
	}
	
}
void creatfruit()			//������ʵ
{	
	if (fruit.live==false)
	{
		fruit.live = true;
		fruit.x = rand()%700;
		fruit.y = rand()%700;
	}
}
void eat(tcs*head, struct fruit *fruit)			//�Թ�ʵ
{
	if(head->x<fruit->x+10&&head->x>fruit->x-10)
		if (head->y<fruit->y + 10 && head->y>fruit->y-10)
		{
			fruit->live = false;
			add(head); add(head); add(head); add(head);
		}
	
}
void move(tcs*head,int speed)		//�����ƶ�
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
void updateList(tcs* p)		//����������һ��Ԫ��Ϊ��һ��Ԫ�أ����������õݹ�ķ���    ˫�����������һ����ʼ��������
{
	if (p->next != NULL)
	{
		updateList(p->next);
		p->next->x = p->x;
		p->next->y = p->y;
	}
}
void initmove(tcs* head,int speed)			//�����ߵ�ͷ�����Լ��ƶ�
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
bool hasDuplicate(tcs* head)		//�ж��Ƿ���x��y����ȵĽڵ�
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
void gameover(tcs*head,bool *player)		//��Ϸ��������
{
	if ((head->x < -17 || head->x > width) || (head->y < -17 || head->y > high))		//�����߽���
	{
		*player = false;
		fruit.live = false;
	}
		

	if (hasDuplicate(head))			//ҧ���Լ�����
	{
		*player = false;
		fruit.live = false;
	}
}





int main()
{
	initgraph(width, high, SHOWCONSOLE);	//���ɴ��ڲ���ӿ���̨
	
	tcs* head; head = playerinit();		//�ٻ�����
	bool a; bool* player = &a; *player = true; fruit.live = false;

	BeginBatchDraw();
	while (1)
	{
		setbkcolor(WHITE);		//���ñ�����ɫ
		cleardevice();		//������������������ʾ������ɫ
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
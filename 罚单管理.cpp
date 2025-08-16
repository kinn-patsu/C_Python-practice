#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define N 10

struct time
{
	int year;
	int month;
};
typedef struct fd
{
	char name[20];
	int car1;
	int car2;
	int jing_hao;
	int fd_hao;
	char type;
	struct time tt;
	int fangshi;
	int money;
	int zhuangtai;

}fd;
int init(fd a[])
{
	char c;
	printf("是否录入（y/n）?"); int i = 0;
	scanf_s(" %c", &c, 1);
	while (c == 'y')
	{
		printf("输入信息\n");
		printf("驾驶员姓名、车牌号、驾驶号、开单交警编号、处罚单号码、罚单类型（酒驾 a、醉驾 b、闯红灯 c、追尾 d、违章停车 e、擅行公交车道 f、限行日出行 g、遮挡污损车牌 h、无牌驾驶 i、无照驾驶 j）、处罚时间（年 月）、处罚方式（现场 0/非现场 1）、罚款金额、处理状态（未处理0、已处理1）\n");
		scanf_s(" %s %d %d %d %d %c %d %d %d %d %d", a[i].name, 20, &a[i].car1, &a[i].car2, &a[i].jing_hao, &a[i].fd_hao, &a[i].type, 1, &a[i].tt.year, &a[i].tt.month, &a[i].fangshi, &a[i].money, &a[i].zhuangtai);
		getchar();
		printf("是否录入（y/n）?");
		scanf_s("%c", &c, 1);
		i++;
	}
	return i;
}
void printfd(fd a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf(" %s %d %d %d %d %c %d %d %d %d %d\n", a[i].name, a[i].car1, a[i].car2, a[i].jing_hao, a[i].fd_hao, a[i].type, a[i].tt.year, a[i].tt.month, a[i].fangshi, a[i].money, a[i].zhuangtai);
	}
}
void change(fd a[], int n)
{
	fd temp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			if (a[i].jing_hao > a[j].jing_hao)
			{
				temp.car1 = a[i].car1;
				temp.car2 = a[i].car2;
				temp.fangshi = a[i].fangshi;
				temp.fd_hao = a[i].fd_hao;
				temp.jing_hao = a[i].jing_hao;
				temp.money = a[i].money;
				temp.tt.year = a[i].tt.year;
				temp.tt.month = a[i].tt.month;
				temp.type = a[i].type;
				temp.zhuangtai = a[i].zhuangtai;
				strcpy(temp.name, a[i].name);

				a[i].car1 = a[j].car1;
				a[i].car2 = a[j].car2;
				a[i].fangshi = a[j].fangshi;
				a[i].fd_hao = a[j].fd_hao;
				a[i].jing_hao = a[j].jing_hao;
				a[i].money = a[j].money;
				a[i].tt.year = a[j].tt.year;
				a[i].tt.month = a[j].tt.month;
				a[i].type = a[j].type;
				temp.zhuangtai = a[i].zhuangtai;
				strcpy(a[i].name, a[j].name);

				a[j].car1 = temp.car1;
				a[j].car2 = temp.car2;
				a[j].fangshi = temp.fangshi;
				a[j].fd_hao = temp.fd_hao;
				a[j].jing_hao = temp.jing_hao;
				a[j].money = temp.money;
				a[j].tt.year = temp.tt.year;
				a[j].tt.month = temp.tt.month;
				a[j].type = temp.type;
				temp.zhuangtai = a[i].zhuangtai;
				strcpy(a[j].name, temp.name);
			}
		}
	}
}
void findcar1(fd a[], int car1, int n)
{
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].car1 == car1)
		{
			flag = 1;
			printf("成功找到喵\n");
			printf("驾驶员姓名:%s\n车牌号:%d\n驾驶号:%d\n开单交警编号:%d\n处罚单号码:%d\n罚单类型:%c\n处罚时间：%d年%d月\n处罚方式(现场 0/非现场 1):%d\n罚款金额:%d\n处理状态(未处理0/已处理1):%d\n", a[i].name, a[i].car1, a[i].car2, a[i].jing_hao, a[i].fd_hao, a[i].type, a[i].tt.year, a[i].tt.month, a[i].fangshi, a[i].money, a[i].zhuangtai);
		}
	}
	if (flag == 0)
	{
		printf("没有找到喵\n");
	}
}
void findcar2(fd a[], int car2, int n)
{
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].car2 == car2)
		{
			flag = 1;
			printf("成功找到喵\n");
			printf("驾驶员姓名:%s\n车牌号:%d\n驾驶号:%d\n开单交警编号:%d\n处罚单号码:%d\n罚单类型:%c\n处罚时间：%d年%d月\n处罚方式(现场 0/非现场 1):%d\n罚款金额:%d\n处理状态(未处理0/已处理1):%d\n", a[i].name, a[i].car1, a[i].car2, a[i].jing_hao, a[i].fd_hao, a[i].type, a[i].tt.year, a[i].tt.month, a[i].fangshi, a[i].money, a[i].zhuangtai);
		}
	}
	if (flag == 0)
	{
		printf("没有找到喵\n");
	}
}
void findjing_hao(fd a[], int jing_hao, int n)
{
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].jing_hao == jing_hao)
		{
			flag = 1;
			printf("成功找到喵\n");
			printf("驾驶员姓名:%s\n车牌号:%d\n驾驶号:%d\n开单交警编号:%d\n处罚单号码:%d\n罚单类型:%c\n处罚时间：%d年%d月\n处罚方式(现场 0/非现场 1):%d\n罚款金额:%d\n处理状态(未处理0/已处理1):%d\n", a[i].name, a[i].car1, a[i].car2, a[i].jing_hao, a[i].fd_hao, a[i].type, a[i].tt.year, a[i].tt.month, a[i].fangshi, a[i].money, a[i].zhuangtai);
		}
	}
	if (flag == 0)
	{
		printf("没有找到喵\n");
	}
}
void findfd_hao(fd a[], int fd_hao, int n)
{
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].fd_hao == fd_hao)
		{
			flag = 1;
			printf("成功找到喵\n");
			printf("驾驶员姓名:%s\n车牌号:%d\n驾驶号:%d\n开单交警编号:%d\n处罚单号码:%d\n罚单类型:%c\n处罚时间：%d年%d月\n处罚方式(现场 0/非现场 1):%d\n罚款金额:%d\n处理状态(未处理0/已处理1):%d\n", a[i].name, a[i].car1, a[i].car2, a[i].jing_hao, a[i].fd_hao, a[i].type, a[i].tt.year, a[i].tt.month, a[i].fangshi, a[i].money, a[i].zhuangtai);
		}
	}
	if (flag == 0)
	{
		printf("没有找到喵\n");
	}
}
void findname(fd a[], char b[], int n)
{
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(a[i].name, b) == 0)
		{
			flag = 1;
			printf("成功找到喵\n");
			printf("驾驶员姓名:%s\n车牌号:%d\n驾驶号:%d\n开单交警编号:%d\n处罚单号码:%d\n罚单类型:%c\n处罚时间：%d年%d月\n处罚方式(现场 0/非现场 1):%d\n罚款金额:%d\n处理状态(未处理0/已处理1):%d\n", a[i].name, a[i].car1, a[i].car2, a[i].jing_hao, a[i].fd_hao, a[i].type, a[i].tt.year, a[i].tt.month, a[i].fangshi, a[i].money, a[i].zhuangtai);
		}
	}
	if (flag == 0)
	{
		printf("没有找到喵\n");
	}
}


void printtimetype(fd a[], int n, int time)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i].tt.year == time)
		{
			printf("成功找到喵\n");
			printf("驾驶员姓名:%s\n车牌号:%d\n驾驶号:%d\n开单交警编号:%d\n处罚单号码:%d\n罚单类型:%c\n处罚时间：%d年%d月\n处罚方式(现场 0/非现场 1):%d\n罚款金额:%d\n处理状态(未处理0/已处理1):%d\n", a[i].name, a[i].car1, a[i].car2, a[i].jing_hao, a[i].fd_hao, a[i].type, a[i].tt.year, a[i].tt.month, a[i].fangshi, a[i].money, a[i].zhuangtai);
		}
	}
}

void wfilea(fd a[], int n)
{
	FILE* fp;
	if ((fp = fopen("D:\\dome.txt", "a")) == NULL)
	{
		printf("failure");
		exit(0);
	}
	for (int i = 0; i < n; i++)
	{
		fprintf(fp, " %s %d %d %d %d %c %d %d %d %d %d\n", a[i].name, a[i].car1, a[i].car2, a[i].jing_hao, a[i].fd_hao, a[i].type, a[i].tt.year, a[i].tt.month, a[i].fangshi, a[i].money, a[i].zhuangtai);
	}
	fclose(fp);
}
void rfile(fd a[], int* num)
{
	FILE* fp;
	if ((fp = fopen("D:\\dome.txt", "r")) == NULL)	//以读的方式打开文件，判断打开文件是否成功
	{
		printf("failure");
		exit(0);
	}
	fscanf_s(fp, "%d", num);
	for (int i = 0; i < *num; i++)
	{
		fscanf_s(fp, " %s %d %d %d %d %c %d %d %d %d %d", a[i].name, 20, &a[i].car1, &a[i].car2, &a[i].jing_hao, &a[i].fd_hao, &a[i].type, 1, &a[i].tt.year, &a[i].tt.month, &a[i].fangshi, &a[i].money, &a[i].zhuangtai);
	}
	fclose(fp);
}
void xieru(fd a[], fd b[], int n, int p)
{
	FILE* fp;
	if ((fp = fopen("D:\\dome.txt", "w")) == NULL)
	{
		printf("failure");
		exit(0);
	}
	fprintf(fp, "%d\n", p + n);
	for (int i = 0; i < p; i++)
	{
		fprintf(fp, " %s %d %d %d %d %c %d %d %d %d %d\n", a[i].name, a[i].car1, a[i].car2, a[i].jing_hao, a[i].fd_hao, a[i].type, a[i].tt.year, a[i].tt.month, a[i].fangshi, a[i].money, a[i].zhuangtai);
	}
	for (int i = 0; i < n; i++)
	{
		fprintf(fp, " %s %d %d %d %d %c %d %d %d %d %d\n", b[i].name, b[i].car1, b[i].car2, b[i].jing_hao, b[i].fd_hao, b[i].type, b[i].tt.year, b[i].tt.month, b[i].fangshi, b[i].money, a[i].zhuangtai);
	}
	fclose(fp);
}
void shanchu_w(fd*a,int n)
{
	FILE* fp;
	if ((fp = fopen("D:\\dome.txt", "w")) == NULL)
	{
		printf("failure");
		exit(0);
	}fprintf(fp, "%d\n",n);
	for (int i = 0; i < n; i++)
	{
		fprintf(fp, " %s %d %d %d %d %c %d %d %d %d %d\n", a[i].name, a[i].car1, a[i].car2, a[i].jing_hao, a[i].fd_hao, a[i].type, a[i].tt.year, a[i].tt.month, a[i].fangshi, a[i].money, a[i].zhuangtai);
	}
	fclose(fp);
}

fd* shanchu(fd a[], int n, int w,int *p)
{
	int m = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].fd_hao != w)
		{
			m++;
		}
	}
	fd* b = (fd*)malloc(m * sizeof(fd));
	fd* start = b;
	for (int i = 0; i < n; i++)
	{
		if (a[i].fd_hao != w)
		{
			strcpy(b->name, a[i].name);
			b->car1 = a[i].car1;
			b->car2 = a[i].car2;
			b->fangshi = a[i].fangshi;
			b->fd_hao = a[i].fd_hao;
			b->jing_hao = a[i].jing_hao;
			b->money = a[i].money;
			b->tt.year = a[i].tt.year;
			b->tt.month = a[i].tt.month;
			b->type = a[i].type;
			b->zhuangtai = a[i].zhuangtai;
			*p += 1;
			b++;
		}
	}



	return start;
}
fd* live(fd a[], int n,int *p)
{
	int m = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].zhuangtai == 0)
		{
			m++;
		}
	}
	fd* b = (fd*)malloc(m*sizeof(fd));
	fd* start = b;
	printf("jb想逃单，\n");
	for (int i = 0; i < n; i++)
	{
		if (a[i].zhuangtai == 0)
		{
			strcpy(b->name, a[i].name);
			 b->car1=a[i].car1;
			 b->car2=a[i].car2;
			 b->fangshi=a[i].fangshi;
			 b->fd_hao=a[i].fd_hao;
			 b->jing_hao=a[i].jing_hao;
			 b->money=a[i].money;
			 b->tt.year=a[i].tt.year;
			 b->tt.month=a[i].tt.month;
			 b->type=a[i].type;
			 b->zhuangtai = a[i].zhuangtai;
			 *p+=1;
			 b++;
		}
	}
	return start;
}
int main()
{

	printf("输入密码:");
	int p; scanf_s("%d", &p);
	if (p == 123)			//密码是123
	{
		printf("登录成功，你就是交警是吧\n");
		printf("要实现什么功能,a/添加罚单,b/查找罚单,c/删除罚单,d/显示所有罚单e/显示指定驾驶员未处理罚单,f/统计不同类型罚单");
		char tick; scanf_s(" %c", &tick, 1);
		if (tick == 'a')
		{
			printf("输入你要添加的罚单\n");
			fd a[20]; int p; rfile(a, &p); fd b[N]; int n = init(b); xieru(a, b, n, p); fd c[20]; int all; rfile(c, &all); printfd(c, all);
		}
		if (tick == 'b')
		{
			fd c[20]; int all; rfile(c, &all);// printfd(c, all);
			printf("通过什么查询？（a/车牌号，b/人名，c/驾驶号，d/警号，e/罚单号）\n");
			char ty; scanf_s(" %c", &ty, 1); getchar();
			switch (ty)
			{


			case'a':
			{
				printf("输入车牌\n");
				int car1; scanf_s("%d", &car1);
				findcar1(c, car1, all);
				break;
			}
			case'b':
			{
				printf("输入人名\n");
				char name[20]; scanf_s(" %s", name, 20);
				findname(c, name, all);
				break;
			}
			case'c':
			{
				printf("驾驶号是什么？\n");
				int car2; scanf_s("%d", &car2);
				findcar2(c, car2, all);
				break;
			}
			case'd':
			{
				printf("警号拿来\n");
				int jing_hao; scanf_s("%d", &jing_hao);
				findjing_hao(c, jing_hao, all);
				break;
			}
			case'e':
			{
				printf("铁咩，罚单号？\n");
				int fd_hao; scanf_s("%d", &fd_hao);
				findfd_hao(c, fd_hao, all);
				break;
			}
			default:
			{
				printf("不看说明吗？\n");
				break;
			}
			}
			/*	printf("是否开出不同年月的罚单（y/n）\n");
				char time; scanf_s(" %c", &time, 1);
				if (time == 'y')
				{
					printf("什么时间捏？\n");
					int yui; scanf_s("%d", &yui);
					printtimetype(c, all, yui);
				}*/
		}
		if (tick == 'c')
		{
			fd c[20]; int all; rfile(c, &all); printfd(c, all);
			printf("删除什么罚单？罚单号拿来\n");
			int ksla; scanf_s("%d", &ksla);
			int p = 0; 
			fd*b=shanchu(c, all, ksla, &p);
			if (p == all)
			{
				printf("没有找到喵\n");
			}
			else
			{
				shanchu_w(b, p);
				for (int i = 0; i < p; i++)
				{
					printf(" %s %d %d %d %d %c %d %d %d %d %d\n", b->name, b->car1, b->car2, b->jing_hao, b->fd_hao, b->type, b->tt.year, b->tt.month, b->fangshi, b->money, b->zhuangtai);
					b++;
				}
			}		
		}
		if (tick == 'd')
		{
			printf("所有罚单信息:");
			fd c[20]; int all; rfile(c, &all); printfd(c, all);
		}
		if (tick == 'e')
		{
			fd c[20]; int all; rfile(c, &all);// printfd(c, all);
			printf("以下是想逃单的sb\n");
			int l = 0;
			fd* b = live(c, all, &l);
			fd* b2 = b; 
			for (int i = 0; i < l; i++)
			{
				printf(" %s %d %d %d %d %c %d %d %d %d %d\n", b->name, b->car1, b->car2, b->jing_hao, b->fd_hao, b->type, b->tt.year, b->tt.month, b->fangshi, b->money, b->zhuangtai);
				b++;
			}b = b2;
			printf("你想显示谁未处理的罚单\n");
			char name[20]; scanf_s(" %s", name, 20);
			for (int i = 0; i < l; i++)
			{
				if (strcmp(b->name, name) == 0)
				{
					printf(" %s %d %d %d %d %c %d %d %d %d %d\n",b->name, b->car1, b->car2, b->jing_hao, b->fd_hao, b->type, b->tt.year, b->tt.month, b->fangshi, b->money, b->zhuangtai);
				}
				b++;
			}
		}
		if (tick == 'f')
		{
			int a = 0, b = 0, c1 = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i1 = 0, j = 0, i = 0;	fd c2[20]; int all; rfile(c2, &all);
			for (i = 0; i < all; i++)
			{
				if (c2[i].type == 'a')
				{
					a++;
				}
				if (c2[i].type == 'b')
				{
					b++;
				}
				if (c2[i].type == 'c')
				{
					c1++;
				}
				if (c2[i].type == 'd')
					d++;
				if (c2[i].type == 'e')
					e++;
				if (c2[i].type == 'f')
					f++;
				if (c2[i].type == 'g')
					g++;
				if (c2[i].type == 'h')
					h++;
				if (c2[i].type == 'i')
					i1++;
				if (c2[i].type == 'j')
					j++;
			}
			printf("酒驾%d单    醉驾%d单    闯红灯%d单    追尾%d单    违章停车%d单    擅行公交车道%d单    限行日出行%d单    遮挡污损车牌%d单    无牌驾驶%d单    无照驾驶%d单    ", a, b, c1, d, e, f, g, h, i1, j);
		}
	}
	else
	{
		printf("不知道密码，那你就是用户了\n");
		fd c[20]; int all; rfile(c, &all); //printfd(c, all);
		printf("通过什么查询？（a/车牌号，b/驾驶号）\n");
		char ty; scanf_s(" %c", &ty, 1); getchar();
		switch (ty)
		{


		case'a':
		{
			printf("输入车牌\n");
			int car1; scanf_s("%d", &car1);
			findcar1(c, car1, all);
			break;
		}

		case'b':
		{
			printf("驾驶号是什么？\n");
			int car2; scanf_s("%d", &car2);
			findcar2(c, car2, all);
			break;
		}

		default:
		{
			printf("不看说明吗？\n");
			break;
		}
		}
	}

}
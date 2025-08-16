#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define N 20
/*typedef struct sc
{
    int data;
    struct sc* next;
}link;
link* append(link* head)                //函数功能，新建一个节点并添加到链表末尾，返回添加节点后的链表的头指针
{
    link* p, * pr = head;
    p = (link*)malloc(sizeof(link));    //p指向新建节点
    if (p == NULL)                      //若p申请内存失败，退出程序
    {
        printf("你jb内存不够啦");
        exit(1);
    }
    if (head == NULL)                   //若原链表为空表
        head = p;                       //将新建的节点p当作第一个节点
    else                                //若原链表为非空，则将新建的节点p放到末尾
    {
        while (pr->next != NULL)        //若未到表尾，则移动pr直到pr指向表尾
        {
            pr = pr->next;              //pr指向下一个节点
        }pr->next = p;                  //让原来表尾的空指针变为新建的节点p
    }
    int data;
    printf("Input node");
    scanf_s("%d", &data);               //输入节点p的数据
    p->data = data;                     //赋值到节点p
    p->next = NULL;                     //将p节点里面的指向下一个节点的指针变为空指针，意思是p为表尾
    return head;                        //返回添加节点p后的链表的头指针
}
void display(link* head)                //函数功能，显示链表中所有节点号，以及节点里的信息
{
    link* p = head;
    int j = 1;
    while (p != NULL)                   //若不是表尾，则循环打印节点信息
    {
        printf("  %d    %d\n", j, p->data);     //打印第j个节点的数据
        p = p->next;                    //让p指向下一个节点
        j++;
    }
}
link* ddelete(link* head, int nodedata)  //函数功能，从链表中删除一个节点，返回删除节点后的链表的第一个指针
{
    link* p = head, * pr = head;
    if (head == NULL)                   //若链表为空，则退出程序
    {
        printf("jb空表别来碰瓷");
        return head;
    }
    while (nodedata != p->data && p->next != NULL)         //寻找要删除的节点
    {
        pr = p;                         //用pr来保存p
        p = p->next;                    //p指向下一个节点
    }
    if (nodedata == p->data)            //若p
    {
        if (p == NULL)                  //若待删除的节点是第一个
        {
            head = p->next;             //让p指向第二个
        }
        else
        {
            pr->next = p->next;         //若不是，让前一个节点的指针等于下一个节点的指针
        }free(p);
    }
    else                                //找到表尾仍未找到要删除的节点
    {
        printf("not found\n");
    }
    return head;                        //返回删除节点后的链表的第一个指针
}
link* front(link* head, int node)
{
    link* p = head, * pr = head;
    if (head == NULL)
    {
        printf("jb空表，真下头，别来碰瓷行不行");
        exit(1);
    }
    while (node != p->data && p->next != NULL)
    {
        pr = p;
        p = p->next;
    }
    if (node == p->data)
    {
        link* k; k = (link*)malloc(sizeof(link));
        int data; scanf_s("%d", &data);
        if (k == NULL)                      //若p申请内存失败，退出程序
        {
            printf("你jb内存不够啦");
            exit(1);
        }
        if (p == head)                      //若为第一个节点
        {
            k->next = pr;                     //将新建节点k的next指向原来的head
            k->data = data;
            head = k;                         //将head指针更新为新的节点
        }
        else                                //若不是第一个节点
        {
            pr->next = k;                   //前面的指针指向k
            k->next = p;                    //k的next指针指向后一个，实现在pr和p之间添加节点
            k->data = data;
        }
    }
    return head;
}
link* behind(link* head, int node)          //函数功能，在一个节点后面添加一个节点
{
    link* p = head, * pr = head;
    link* k = (link*)malloc(sizeof(link));
    int data; scanf_s("%d", &data);
    if (k == NULL)                      //若k申请内存失败，退出程序
    {
        printf("你jb内存不够啦");
        exit(1);
    }
    if (head == NULL)
    {
        printf("jb空表,别来碰瓷");             //若是空表，将新建的节点k当作第一个节点
        head = k;
        k->data = data;
    }
    while (p->data!=node&&p->next!=NULL)               //找到要在后面添加节点的节点  ！！这里一定不能缺少判定p->next是不是空指针，因为没判断的话如果没找到node
    {
        pr = p;                         //pr记录p
        p = p->next;                    //p指向下一个节点
    }
    if (p->data == node)                    //若找到p为这个节点
    {
        if (p->next == NULL)                //如果p是最后一个节点,在表尾添加节点
        {
            p->next = k;                    //p的指针域指向新建节点
            k->data = data;
            k->next = NULL;                 //令k为最后一个节点  !!注意，这里由于是使用的malloc，所以k并没有被赋初始值，k->next没有被赋值，一定不能使用没有被赋值的指针
        }
        else                                //如果p不是最后一个节点
        {
            pr = p;                     
            p = p->next;                    //记录p后，将p后移，在2个中间添加节点k
            pr->next = k;
            k->next = p;
            k->data = data;
        }
           
    }
    else                                
    {
        printf("not found\n");
    }
    return head;                        //返回添加节点后的头指针
}
void shifang(link* head)                //函数功能，释放head指向的链表中所有节点占用的内存
{
    link* p = head, * pr = NULL;
    while (p != NULL)                   //若不是表尾，则释放内存
    {
        pr = p;                         //pr保存当前节点的指针
        p = p->next;                    //p指向下一个节点
        free(pr);                       //释放pr节点的内存，也就是原来p的内存
    }
}
int main()
{
    int i = 0;
    char c;
    link* head = NULL;              //链表头指针
    printf("a new node?(Y/N)");
    scanf_s("%c", &c, 1);
    while (c == 'Y' || c == 'y')
    {
        head = append(head);        //在链表末尾添加节点
        display(head);              //显示当前链表的各个信息
        printf("a new node?(Y/N)");
        getchar();
        scanf_s("%c", &c, 1);
        i++;
    }
    printf("%d new node have been apended\n", i);
    printf("删什么?");
    int x1; scanf_s("%d", &x1);
    head = ddelete(head, x1); display(head);
    printf("在什么前面加什么?");
    int x2; scanf_s("%d", &x2);
    head = front(head, x2); display(head);
    printf("在什么后面加什么?");
    int x3; scanf_s("%d", &x3);
    head = behind(head, x3);display(head);
    shifang(head);                  //释放所有动态分配的内存
}*/
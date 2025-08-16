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
link* append(link* head)                //�������ܣ��½�һ���ڵ㲢��ӵ�����ĩβ��������ӽڵ��������ͷָ��
{
    link* p, * pr = head;
    p = (link*)malloc(sizeof(link));    //pָ���½��ڵ�
    if (p == NULL)                      //��p�����ڴ�ʧ�ܣ��˳�����
    {
        printf("��jb�ڴ治����");
        exit(1);
    }
    if (head == NULL)                   //��ԭ����Ϊ�ձ�
        head = p;                       //���½��Ľڵ�p������һ���ڵ�
    else                                //��ԭ����Ϊ�ǿգ����½��Ľڵ�p�ŵ�ĩβ
    {
        while (pr->next != NULL)        //��δ����β�����ƶ�prֱ��prָ���β
        {
            pr = pr->next;              //prָ����һ���ڵ�
        }pr->next = p;                  //��ԭ����β�Ŀ�ָ���Ϊ�½��Ľڵ�p
    }
    int data;
    printf("Input node");
    scanf_s("%d", &data);               //����ڵ�p������
    p->data = data;                     //��ֵ���ڵ�p
    p->next = NULL;                     //��p�ڵ������ָ����һ���ڵ��ָ���Ϊ��ָ�룬��˼��pΪ��β
    return head;                        //������ӽڵ�p��������ͷָ��
}
void display(link* head)                //�������ܣ���ʾ���������нڵ�ţ��Լ��ڵ������Ϣ
{
    link* p = head;
    int j = 1;
    while (p != NULL)                   //�����Ǳ�β����ѭ����ӡ�ڵ���Ϣ
    {
        printf("  %d    %d\n", j, p->data);     //��ӡ��j���ڵ������
        p = p->next;                    //��pָ����һ���ڵ�
        j++;
    }
}
link* ddelete(link* head, int nodedata)  //�������ܣ���������ɾ��һ���ڵ㣬����ɾ���ڵ�������ĵ�һ��ָ��
{
    link* p = head, * pr = head;
    if (head == NULL)                   //������Ϊ�գ����˳�����
    {
        printf("jb�ձ��������");
        return head;
    }
    while (nodedata != p->data && p->next != NULL)         //Ѱ��Ҫɾ���Ľڵ�
    {
        pr = p;                         //��pr������p
        p = p->next;                    //pָ����һ���ڵ�
    }
    if (nodedata == p->data)            //��p
    {
        if (p == NULL)                  //����ɾ���Ľڵ��ǵ�һ��
        {
            head = p->next;             //��pָ��ڶ���
        }
        else
        {
            pr->next = p->next;         //�����ǣ���ǰһ���ڵ��ָ�������һ���ڵ��ָ��
        }free(p);
    }
    else                                //�ҵ���β��δ�ҵ�Ҫɾ���Ľڵ�
    {
        printf("not found\n");
    }
    return head;                        //����ɾ���ڵ�������ĵ�һ��ָ��
}
link* front(link* head, int node)
{
    link* p = head, * pr = head;
    if (head == NULL)
    {
        printf("jb�ձ�����ͷ�����������в���");
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
        if (k == NULL)                      //��p�����ڴ�ʧ�ܣ��˳�����
        {
            printf("��jb�ڴ治����");
            exit(1);
        }
        if (p == head)                      //��Ϊ��һ���ڵ�
        {
            k->next = pr;                     //���½��ڵ�k��nextָ��ԭ����head
            k->data = data;
            head = k;                         //��headָ�����Ϊ�µĽڵ�
        }
        else                                //�����ǵ�һ���ڵ�
        {
            pr->next = k;                   //ǰ���ָ��ָ��k
            k->next = p;                    //k��nextָ��ָ���һ����ʵ����pr��p֮����ӽڵ�
            k->data = data;
        }
    }
    return head;
}
link* behind(link* head, int node)          //�������ܣ���һ���ڵ�������һ���ڵ�
{
    link* p = head, * pr = head;
    link* k = (link*)malloc(sizeof(link));
    int data; scanf_s("%d", &data);
    if (k == NULL)                      //��k�����ڴ�ʧ�ܣ��˳�����
    {
        printf("��jb�ڴ治����");
        exit(1);
    }
    if (head == NULL)
    {
        printf("jb�ձ�,��������");             //���ǿձ����½��Ľڵ�k������һ���ڵ�
        head = k;
        k->data = data;
    }
    while (p->data!=node&&p->next!=NULL)               //�ҵ�Ҫ�ں�����ӽڵ�Ľڵ�  ��������һ������ȱ���ж�p->next�ǲ��ǿ�ָ�룬��Ϊû�жϵĻ����û�ҵ�node
    {
        pr = p;                         //pr��¼p
        p = p->next;                    //pָ����һ���ڵ�
    }
    if (p->data == node)                    //���ҵ�pΪ����ڵ�
    {
        if (p->next == NULL)                //���p�����һ���ڵ�,�ڱ�β��ӽڵ�
        {
            p->next = k;                    //p��ָ����ָ���½��ڵ�
            k->data = data;
            k->next = NULL;                 //��kΪ���һ���ڵ�  !!ע�⣬����������ʹ�õ�malloc������k��û�б�����ʼֵ��k->nextû�б���ֵ��һ������ʹ��û�б���ֵ��ָ��
        }
        else                                //���p�������һ���ڵ�
        {
            pr = p;                     
            p = p->next;                    //��¼p�󣬽�p���ƣ���2���м���ӽڵ�k
            pr->next = k;
            k->next = p;
            k->data = data;
        }
           
    }
    else                                
    {
        printf("not found\n");
    }
    return head;                        //������ӽڵ���ͷָ��
}
void shifang(link* head)                //�������ܣ��ͷ�headָ������������нڵ�ռ�õ��ڴ�
{
    link* p = head, * pr = NULL;
    while (p != NULL)                   //�����Ǳ�β�����ͷ��ڴ�
    {
        pr = p;                         //pr���浱ǰ�ڵ��ָ��
        p = p->next;                    //pָ����һ���ڵ�
        free(pr);                       //�ͷ�pr�ڵ���ڴ棬Ҳ����ԭ��p���ڴ�
    }
}
int main()
{
    int i = 0;
    char c;
    link* head = NULL;              //����ͷָ��
    printf("a new node?(Y/N)");
    scanf_s("%c", &c, 1);
    while (c == 'Y' || c == 'y')
    {
        head = append(head);        //������ĩβ��ӽڵ�
        display(head);              //��ʾ��ǰ����ĸ�����Ϣ
        printf("a new node?(Y/N)");
        getchar();
        scanf_s("%c", &c, 1);
        i++;
    }
    printf("%d new node have been apended\n", i);
    printf("ɾʲô?");
    int x1; scanf_s("%d", &x1);
    head = ddelete(head, x1); display(head);
    printf("��ʲôǰ���ʲô?");
    int x2; scanf_s("%d", &x2);
    head = front(head, x2); display(head);
    printf("��ʲô�����ʲô?");
    int x3; scanf_s("%d", &x3);
    head = behind(head, x3);display(head);
    shifang(head);                  //�ͷ����ж�̬������ڴ�
}*/
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int* p;
    int length;
    int ac;
}S, * pS;

void creat_s(pS s) {
    int a;
    printf("你想要存储多少个数据？\n");
    scanf_s("%d", &a);
    if (a <= 0) {
        printf("你不想存储数据！\n");
    }
    else {
        s->p = (int*)malloc(sizeof(int) * a);
        if (NULL == s->p) {
            printf("空间申请失败！\n");
        }
        else {
            s->length = a;
            s->ac = -1;
            printf("能够存储%d个元素的空间申请成功！\n", s->length);
        }
    }
}

void insert_s(pS s) {
    int a, b, c, d, e, i;
    a = s->length;
    b = s->ac;
    c = a - (b+1);
    if (a == 0) {
        printf("你还没有创建顺序表！\n");
    }
    else if (c == 0) {
        printf("此表已满！\n");
    }
    else {
        printf("这个顺序表长度为%d，你还可以存%d个数据，请输入数据这次想储存多少个数据？\n", a, c);
        scanf_s("%d", &d);
        if (d == 0) {
            printf("你不想存数据！\n");
        }
        else if (c < d) {
            printf("此顺序表空间不足！\n");
        }
        else {
            for (i = 0; i < d; i++) {
                printf("请输入第%d个元素：\n", i + 1);
                scanf_s("%d", &e);
                s->p[++(s->ac)] = e;
                printf("元素输入成功！\n");
            }
        }
    }
}

void display_s(pS s) {
    int a, b, i;
    a = s->length;
    b = s->ac;
    if (a == 0) {
        printf("你还没创建顺序表！\n");
    }
    else {
        if (b == -1) {
            printf("这是一个空表！\n");
        }
        else {
            printf("顺序表中数据是：\n");
            for (i = 0; i <= b; i++) {
                printf("%4d", s->p[i]);
            }
            printf("\n");
        }
    }
}

void zhijiecharupaixu(pS s) {
    printf("表中共%d个元素,采用直接插入排序\n", s->ac+1);
    for (int i = 0; i < s->ac; ++i)
    {
        int end = i;
        int temp = *(s->p + end + 1);
        while (end >= 0)
        {
            if (temp < *(s->p + end))
            {
                *(s->p + end + 1) = *(s->p + end);
                end--;
            }
            else
                break;
        }
        *(s->p + end + 1) = temp;
    }
    display_s(s);
}

void xuanzhepaixu(pS s){//用min max来交换，用开头a，结尾b做2边，a++ b--。来逼近
    int a = 0, b = s->ac;
    while (a < b)
    {
        int min = a;
        int max = b;
        for (int i = a; i <= b; i++)
        {
            if (*(s->p + i) < *(s->p + min))
                min = i;
            if (*(s->p + i) > *(s->p + max))
                max = i;
        }
        int temp1, temp2;
        temp1 = *(s->p + min); *(s->p + min) = *(s->p + a); *(s->p + a) = temp1;
        if (a == max)
            max = min;
        temp2 = *(s->p + max); *(s->p + max) = *(s->p + b); *(s->p + b) = temp2;
        ++a; --b;
    }
    printf("表中共%d个元素,采用选择排序\n", s->ac + 1);
    display_s(s);
}

void maopaopaixu(pS s) {
    int end = s->ac;
    int temp = 0;
    while (end)
    {
        int flag = 0;
        for (int i = 1; i < end; i++)
        {
            if (*(s->p + i - 1) > *(s->p + i))
            {
                temp = *(s->p + i);
                *(s->p + i) = *(s->p + i - 1);
                *(s->p + i - 1) = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
        end--;
    }
    printf("表中共%d个元素,采用冒泡排序\n", s->ac + 1);
    display_s(s);
}

void kuaisupaixu(pS s,int left,int right) {
    int key = left;
    while (left < right)
    {
        while (left < right && *(s->p + key) <= *(s->p + right))
            right--;
        while (left < right && *(s->p + key) >= *(s->p + left))
            left++;
    }
    if (left < right)
    {
        int temp1;
        temp1 = *(s->p + left); *(s->p + left) = *(s->p + right); *(s->p + right) = temp1;
    }
    int temp2;
    temp2 = *(s->p + key); *(s->p + key) = *(s->p + left); *(s->p + left) = temp2;
    printf("表中共%d个元素,采用快速排序\n", s->ac + 1);
    display_s(s);
}

int main()
{
    int a = 1;
    S s; s.length = 0;
    creat_s(&s);
    insert_s(&s);
    display_s(&s);
    printf("选择什么方法排序1~4\n");
    int c;
    scanf_s("%d", &c);
    switch (c)
    {
    case 1:
        zhijiecharupaixu(&s);
        break;
    case 2:
        xuanzhepaixu(&s);
        break;
    case 3:
        maopaopaixu(&s);
        break;
    case 4:
        kuaisupaixu(&s,0,s.ac);
        break;
    default:
        break;
    }
}
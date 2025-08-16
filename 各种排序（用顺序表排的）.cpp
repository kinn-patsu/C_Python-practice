#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int* p;
    int length;
    int ac;
}S, * pS;

void creat_s(pS s) {
    int a;
    printf("����Ҫ�洢���ٸ����ݣ�\n");
    scanf_s("%d", &a);
    if (a <= 0) {
        printf("�㲻��洢���ݣ�\n");
    }
    else {
        s->p = (int*)malloc(sizeof(int) * a);
        if (NULL == s->p) {
            printf("�ռ�����ʧ�ܣ�\n");
        }
        else {
            s->length = a;
            s->ac = -1;
            printf("�ܹ��洢%d��Ԫ�صĿռ�����ɹ���\n", s->length);
        }
    }
}

void insert_s(pS s) {
    int a, b, c, d, e, i;
    a = s->length;
    b = s->ac;
    c = a - (b+1);
    if (a == 0) {
        printf("�㻹û�д���˳���\n");
    }
    else if (c == 0) {
        printf("�˱�������\n");
    }
    else {
        printf("���˳�����Ϊ%d���㻹���Դ�%d�����ݣ���������������봢����ٸ����ݣ�\n", a, c);
        scanf_s("%d", &d);
        if (d == 0) {
            printf("�㲻������ݣ�\n");
        }
        else if (c < d) {
            printf("��˳���ռ䲻�㣡\n");
        }
        else {
            for (i = 0; i < d; i++) {
                printf("�������%d��Ԫ�أ�\n", i + 1);
                scanf_s("%d", &e);
                s->p[++(s->ac)] = e;
                printf("Ԫ������ɹ���\n");
            }
        }
    }
}

void display_s(pS s) {
    int a, b, i;
    a = s->length;
    b = s->ac;
    if (a == 0) {
        printf("�㻹û����˳���\n");
    }
    else {
        if (b == -1) {
            printf("����һ���ձ�\n");
        }
        else {
            printf("˳����������ǣ�\n");
            for (i = 0; i <= b; i++) {
                printf("%4d", s->p[i]);
            }
            printf("\n");
        }
    }
}

void zhijiecharupaixu(pS s) {
    printf("���й�%d��Ԫ��,����ֱ�Ӳ�������\n", s->ac+1);
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

void xuanzhepaixu(pS s){//��min max���������ÿ�ͷa����βb��2�ߣ�a++ b--�����ƽ�
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
    printf("���й�%d��Ԫ��,����ѡ������\n", s->ac + 1);
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
    printf("���й�%d��Ԫ��,����ð������\n", s->ac + 1);
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
    printf("���й�%d��Ԫ��,���ÿ�������\n", s->ac + 1);
    display_s(s);
}

int main()
{
    int a = 1;
    S s; s.length = 0;
    creat_s(&s);
    insert_s(&s);
    display_s(&s);
    printf("ѡ��ʲô��������1~4\n");
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
#include<stdio.h>
/*
// ˳�����--��������򷵻ز��ҵ���ֵ�����򷵻�0.
int SequentialSearch(int arr[], int len, int KeyData)
{
    // ��һ�ַ�����ÿ��ѭ�����ÿ����Ƿ�Խ��
    // int tmp = 0;
    // for (int i = 0; i < len; i++) {
    //   if (arr[i] == KeyData)
    //     return i;
    // }

    //�ڶ��ַ��� �Ż�
    int i;
    arr[0] = KeyData;  //����arr[0]Ϊ�ؼ���ֵ��Ҳ����"�ڱ�"
    i = len - 1;  // ѭ������β����ʼ
    while (arr[i] != KeyData) {
        i--;
    }

    return i;
}

void printf_arr(int arr[], int size) //��ӡ����
{
    int i = 0;
    for (; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main()
{
    int arr[] = { 90, 70, 34, 35, 26, 89, 56 };
    int len = sizeof(arr) / sizeof(arr[0]);

    printf("ԭ����:\n");
    printf_arr(arr, len);

    int retData = SequentialSearch(arr, len, arr[6]);
    printf("�ҵ�����[%d] ����Ϊ: %d\n", retData, arr[6]);

    return 0;
}*/

/*
* ���ֲ���
int binary_search(int key, int a[], int n)
{
    int left, right, mid;
    int count = 0, count1 = 0;

    left = 0;
    right = n - 1;
    while (left < right) {         //���ҷ�Χ��Ϊ0ʱִ��ѭ�������
        count++;                  //count��¼���Ҵ���
        mid = (left + right) / 2;     //���м�λ��
        printf("�� %d �β���, left : %d  right : %d  mid : %d\n", count, left, right, mid);
        if (key < a[mid])          //keyС���м�ֵʱ
            right = mid - 1;         //ȷ�����ӱ�Χ
        else if (key > a[mid])     //key �����м�ֵʱ
            left = mid + 1;    //ȷ�����ӱ�Χ
        else if (key == a[mid]) {  //��key�����м�ֵʱ��֤�����ҳɹ�
            printf("\n���ҳɹ�!\n\n���� %d ��!", count);    //������Ҵ�����������Ԫ���������е�λ��
            count1++;             //count1��¼���ҳɹ�����
            break;
        }
    }

    if (count1 == 0)    //�ж��Ƿ����ʧ��
        printf("����ʧ��!");    //����ʧ�����no found

    return mid;
}

void printf_arr(int arr[], int size) //��ӡ����
{
    int i = 0;
    for (; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main(void)
{
    int i, key, a[100], n;

    printf("����������ĳ��ȣ�\n");
    scanf_s("%d", &n);    //��������Ԫ�ظ���

    printf("����������Ԫ�أ�\n");
    for (i = 0; i < n; i++)
        scanf_s("%d", &a[i]);    //�����������е�����a��

    printf("\nԭ����:\n");
    printf_arr(a, n);

    printf("\n������������ҵ�Ԫ�أ�\n");
    scanf_s("%d", &key);    //����Ҫ���ҵĹؼ���

    int pos = binary_search(key, a, n);
    if (pos != -1)
        printf("\n�������е�%d �ҵ�Ԫ��:%d\n", pos+1, key);
    else
        printf("\nδ���������ҵ�Ԫ��: %d\n", key);

    return 0;
}*/

/*
*    �۰����
int Interpolation_search(int* a, int key, int n)  //��ֵ����
{
    int mid, low, high;
    int count = 0, count1 = 0;
    low = 0, high = n - 1;

    while (low <= high) {
        count++;
        mid = ((key - a[low]) * (high - low)) / (a[high] - a[low]) + low;
        printf("�� %d �β���, low : %d  high : %d  mid : %d\n", count, low, high, mid);
        if (a[mid] < key) {
            low = mid + 1;
        }
        else if (a[mid] == key) {
            printf("\n���ҳɹ�!\n\n���� %d ��!", count);    //������Ҵ�����������Ԫ���������е�λ��
            count1++;
            break;
        }
        else {
            high = mid - 1;
        }
    }

    if (count1 == 0)    //�ж��Ƿ����ʧ��
        printf("����ʧ��!");    //����ʧ�����no found

    return mid;
}

void printf_arr(int arr[], int size) //��ӡ����
{
    int i = 0;
    for (; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("\nԭ����:\n");
    printf_arr(arr, n);

    printf("������Ҫ���ҵ�����:\n");
    scanf_s("%d", &key);

    int pos = Interpolation_search(arr, key, n);
    if (pos != -1)
        printf("\n�������е�%d �ҵ�Ԫ��:%d\n", pos+1, key);
    else
        printf("\nδ���������ҵ�Ԫ��: %d\n", key);

    return 0;
}
*/
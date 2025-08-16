#include<stdio.h>
/*
// 顺序查找--如果发现则返回查找到的值，否则返回0.
int SequentialSearch(int arr[], int len, int KeyData)
{
    // 第一种方法：每次循环都得考虑是否越界
    // int tmp = 0;
    // for (int i = 0; i < len; i++) {
    //   if (arr[i] == KeyData)
    //     return i;
    // }

    //第二种方法 优化
    int i;
    arr[0] = KeyData;  //设置arr[0]为关键字值，也叫做"哨兵"
    i = len - 1;  // 循环数组尾部开始
    while (arr[i] != KeyData) {
        i--;
    }

    return i;
}

void printf_arr(int arr[], int size) //打印数组
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

    printf("原数据:\n");
    printf_arr(arr, len);

    int retData = SequentialSearch(arr, len, arr[6]);
    printf("找到数组[%d] 数据为: %d\n", retData, arr[6]);

    return 0;
}*/

/*
* 二分查找
int binary_search(int key, int a[], int n)
{
    int left, right, mid;
    int count = 0, count1 = 0;

    left = 0;
    right = n - 1;
    while (left < right) {         //査找范围不为0时执行循环体语句
        count++;                  //count记录査找次数
        mid = (left + right) / 2;     //求中间位置
        printf("第 %d 次查找, left : %d  right : %d  mid : %d\n", count, left, right, mid);
        if (key < a[mid])          //key小于中间值时
            right = mid - 1;         //确定左子表范围
        else if (key > a[mid])     //key 大于中间值时
            left = mid + 1;    //确定右子表范围
        else if (key == a[mid]) {  //当key等于中间值时，证明查找成功
            printf("\n查找成功!\n\n查找 %d 次!", count);    //输出査找次数及所査找元素在数组中的位置
            count1++;             //count1记录查找成功次数
            break;
        }
    }

    if (count1 == 0)    //判断是否查找失敗
        printf("查找失敗!");    //査找失敗输出no found

    return mid;
}

void printf_arr(int arr[], int size) //打印数组
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

    printf("请输入数组的长度：\n");
    scanf_s("%d", &n);    //输入数组元素个数

    printf("请输入数组元素：\n");
    for (i = 0; i < n; i++)
        scanf_s("%d", &a[i]);    //输入有序数列到数组a中

    printf("\n原数据:\n");
    printf_arr(a, n);

    printf("\n请输入你想查找的元素：\n");
    scanf_s("%d", &key);    //输入要查找的关键字

    int pos = binary_search(key, a, n);
    if (pos != -1)
        printf("\n在数组中第%d 找到元素:%d\n", pos+1, key);
    else
        printf("\n未在数组中找到元素: %d\n", key);

    return 0;
}*/

/*
*    折半查找
int Interpolation_search(int* a, int key, int n)  //插值查找
{
    int mid, low, high;
    int count = 0, count1 = 0;
    low = 0, high = n - 1;

    while (low <= high) {
        count++;
        mid = ((key - a[low]) * (high - low)) / (a[high] - a[low]) + low;
        printf("第 %d 次查找, low : %d  high : %d  mid : %d\n", count, low, high, mid);
        if (a[mid] < key) {
            low = mid + 1;
        }
        else if (a[mid] == key) {
            printf("\n查找成功!\n\n查找 %d 次!", count);    //输出査找次数及所査找元素在数组中的位置
            count1++;
            break;
        }
        else {
            high = mid - 1;
        }
    }

    if (count1 == 0)    //判断是否查找失敗
        printf("查找失敗!");    //査找失敗输出no found

    return mid;
}

void printf_arr(int arr[], int size) //打印数组
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

    printf("\n原数据:\n");
    printf_arr(arr, n);

    printf("请输入要查找的数字:\n");
    scanf_s("%d", &key);

    int pos = Interpolation_search(arr, key, n);
    if (pos != -1)
        printf("\n在数组中第%d 找到元素:%d\n", pos+1, key);
    else
        printf("\n未在数组中找到元素: %d\n", key);

    return 0;
}
*/
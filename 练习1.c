#include <stdio.h>
int main(void)
{
	int x = 153, b0 , b1 , b2 , sum;
	b2 = x / 100;
	double result1 = x / 100.0;
	double result2 = (double)x / 100;
                     //ǿ��ת��
#include<stdio.h>
	int main(void)
		; {
	int m = 5;
	printf("m / 2 = % d\n", m / 2);
	printf("(float)(m/2)=%f\n", (float)(m / 2));//��m/2�Ľ��ǿ��ת��
	printf("(float)m/2=%f\n", (float)m / 2);//��mǿ��ת���ٳ���2
	printf("m=%d\n", m);
}
#include <stdio.h> 
	void main()
	{
		double F, c;
		scanf_s("%lf", &F);
		c = 5.0 / 9 * (F - 32);
		printf("F = %.2f\nc = %.2f\n", F, c);
	}
	//ʹ��const��������Բ����pi��ȡֵΪ3.14159������̴Ӽ�������Բ�İ뾶r�����㲢���Բ���ܳ����������������ݱ�����λС���㡣
#include <stdio.h>
	int main(void)
	{
		const double pi = 3.14159;
		printf("Input r:");
		double r, circum, area;
		scanf_s("%lf", &r);
		circum = 2 * pi * r;
		area = pi * r * r;
		printf("printf WITHOUT width or precision specifications:\n");
		printf("circumference = %f, area = %f\n", circum, area);
		printf("printf WITH width and precision specifications:\n");
		printf("circumference = %7.2f, area = %7.2f\n", circum, area);
	}
	//���㲢���һ����λ�����ĸ�λ��ʮλ�Ͱ�λ����֮�͡�
//** �����ʽҪ��"%d" ��ʾ��Ϣ��"������һ����λ������"
//* *�����ʽҪ��"b2=%d, b1=%d, b0=%d, sum=%d\n"
//��������ʾ�����£�
//������һ����λ������153
//b2 = 1, b1 = 5, b0 = 3, sum = 9
#include <stdio.h>
	int main()
	{
		printf("������һ����λ������");
		int x, b0, b1, b2, sum;
		scanf_s("%d", &x);
		b0 = x % 10;
		b2 = x / 100;
		b1 = (x - b2 * 100) / 10;
		sum = b1 + b2 + b0;
		printf("b2=%d, b1=%d, b0=%d, sum=%d\n", b2, b1, b0, sum);
	}
	//дһ������Ӽ�����������������Ȼ����ʾ�����1�������Ե�2�����Ľ�������磬����123��12���������������ʽ���£�

//10 Remainder = 3
//------
//12 )   123
//��ʾ��ʹ��������������������ʹ��������������̡�

//* *�����ʽҪ��"%d%d" ��ʾ��Ϣ��"����������������"
//* *�����ʽҪ��
//"%13d Remainder = %d\n"    ��ע����һ�������̣��ڶ�������������
//"       ------\n"
//"%5d ) %5d"     ��ע����һ�����ǳ������ڶ������Ǳ�������

//��������ʾ����
//����������������4 8
//0 Remainder = 4
//------
//8 )     4Press any key to continue
#include <stdio.h>
	int main()
	{
		int a, b;
		printf("����������������");
		scanf_s("%d%d", &a, &b);
		printf("%13d Remainder = %d\n", a / b, a % b);
		printf("       ------\n");
		printf("%5d ) %5d", b, a);
	}
	//������ı���͸���֮�͡��������� money������ year �������� rate�����ݹ�ʽ�������ʱ�ı�Ϣ�ϼ�sum��˰ǰ�������ʱ����2λС����sum = money(1 + rate) ^ year(��ʾ����C����� ^ Ҫ��pow()�������㣬������¼)��
//* *****��ʾ��Ϣ��"Enter money:"
//* *****�����ʽ��"%d"
//* *****��ʾ��Ϣ��"Enter year:"
//* *****�����ʽ��"%d"
//* *****��ʾ��Ϣ�� "Enter rate:"
//* *****�����ʽ��"%lf"
//* *�����ʽҪ��"sum = %.2f\n"
#include<stdio.h>
#include<math.h>
	int main()
	{
		int money, year;
		double  rate, sum, x;
		printf("Enter money:");
		scanf_s("%d", &money);
		printf("Enter year:");
		scanf_s("%d", &year);
		printf("Enter rate:");
		scanf_s("%lf", &rate);
		x = pow(1 + rate, year);
		sum = x * money;
		printf("sum = %.2f\n", x * money);//%.2f�Ǳ���2λС��
	}
#include<stdio.h>
#include<math.h>
	void main()
	{
		int n;
		float m, x;//m����Ϊint����
		scanf_s("%f,%d", &m, &n);
		x = (float)pow(0.5, n);
		printf("Input length and days:");
		printf("length=%.5f\n", (float)m * x);//�˴�ǿ��ת������%.5f�Ǳ���5λС��
	}
	//дһ������Ӽ�����������������Ȼ����ʾ��1������ռ�ڶ��������İٷֱȣ�������С�����1λ����������5��40���������������£�
		//5 is 12.5 percent of 40

		//* *�����ʽҪ��"%d%d" ��ʾ��Ϣ��"����������������"
		//* *�����ʽҪ��"%d is %.1f percent of %d"
		//l��������ʾ����
		//����������������6 18
		//6 is 33.3 percent of 18
#include<stdio.h>
#include<math.h>
	void main()
	{
		int a, b;
		float x;
		scanf_s("%d%d", &a, &b);
		x = (float)a / (float)b * 100;//����������������ȥβ��ת��Ϊ����
		//��2��д����a/(float)b
		//�����ԣ�(float(a)/b)
		printf("����������������");
		printf("%d is %.1f percent of %d", a, x, b);
	}
#include<stdio.h>
#include<math.h>
	void main()
	{
		printf("Input a,b,c:");
		float a, b, c;
		float s, area;
		scanf_s("%f,%f,%f", &a, &b, &c);
		s = (a + b + c) / 2.0;
		area = sqrt(s * (s - a) * (s - b) * (s - c));
		if (a + b < c)     //if����{}��ʾ�����Ľ��
		{
			printf("Input error!");
		}
		if (a + b > c)//���÷ֺ�
		{
			printf("area=%.2f", area);
		}
	}
#include<stdio.h>//��̽�һλ����ת���������ַ�
#include<math.h>
	void main()
	{
		printf("please input an  integer:");
		int a;
		char x;
		scanf_s("%d", &a);
		x = a + 48;
		printf("integer %d is changed to charator \'%c\'", a, x);
	}
#include <stdio.h>
int main(void)
{
	int x = 153, b0 , b1 , b2 , sum;
	b2 = x / 100;
	double result1 = x / 100.0;
	double result2 = (double)x / 100;
                     //强制转换
#include<stdio.h>
	int main(void)
		; {
	int m = 5;
	printf("m / 2 = % d\n", m / 2);
	printf("(float)(m/2)=%f\n", (float)(m / 2));//对m/2的结果强制转换
	printf("(float)m/2=%f\n", (float)m / 2);//对m强制转换再除以2
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
	//使用const常量定义圆周率pi（取值为3.14159），编程从键盘输入圆的半径r，计算并输出圆的周长和面积。输出的数据保留两位小数点。
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
	//计算并输出一个三位整数的个位、十位和百位数字之和。
//** 输入格式要求："%d" 提示信息："请输入一个三位整数："
//* *输出格式要求："b2=%d, b1=%d, b0=%d, sum=%d\n"
//程序运行示例如下：
//请输入一个三位整数：153
//b2 = 1, b1 = 5, b0 = 3, sum = 9
#include <stdio.h>
	int main()
	{
		printf("请输入一个三位整数：");
		int x, b0, b1, b2, sum;
		scanf_s("%d", &x);
		b0 = x % 10;
		b2 = x / 100;
		b1 = (x - b2 * 100) / 10;
		sum = b1 + b2 + b0;
		printf("b2=%d, b1=%d, b0=%d, sum=%d\n", b2, b1, b0, sum);
	}
	//写一个程序从键盘输入两个整数，然后显示输出第1个数除以第2个数的结果。例如，输入123和12，程序的输出结果格式如下：

//10 Remainder = 3
//------
//12 )   123
//提示：使用求余运算符获得余数，使用整数除法获得商。

//* *输入格式要求："%d%d" 提示信息："请输入两个整数："
//* *输出格式要求：
//"%13d Remainder = %d\n"    （注：第一个数是商，第二个数是余数）
//"       ------\n"
//"%5d ) %5d"     （注：第一个数是除数，第二个数是被除数）

//程序运行示例：
//请输入两个整数：4 8
//0 Remainder = 4
//------
//8 )     4Press any key to continue
#include <stdio.h>
	int main()
	{
		int a, b;
		printf("请输入两个整数：");
		scanf_s("%d%d", &a, &b);
		printf("%13d Remainder = %d\n", a / b, a % b);
		printf("       ------\n");
		printf("%5d ) %5d", b, a);
	}
	//计算存款的本金和复利之和。输入存款金额 money、存期 year 和年利率 rate，根据公式计算存款到期时的本息合计sum（税前），输出时保留2位小数。sum = money(1 + rate) ^ year(提示：在C语言里， ^ 要用pow()函数计算，详见书后附录)。
//* *****提示信息："Enter money:"
//* *****输入格式："%d"
//* *****提示信息："Enter year:"
//* *****输入格式："%d"
//* *****提示信息： "Enter rate:"
//* *****输入格式："%lf"
//* *输出格式要求："sum = %.2f\n"
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
		printf("sum = %.2f\n", x * money);//%.2f是保留2位小数
	}
#include<stdio.h>
#include<math.h>
	void main()
	{
		int n;
		float m, x;//m不能为int类型
		scanf_s("%f,%d", &m, &n);
		x = (float)pow(0.5, n);
		printf("Input length and days:");
		printf("length=%.5f\n", (float)m * x);//此处强制转换，，%.5f是保留5位小数
	}
	//写一个程序从键盘输入两个整数，然后显示第1个整数占第二个整数的百分比，保留到小数点后1位。例如输入5和40，程序输出结果如下：
		//5 is 12.5 percent of 40

		//* *输入格式要求："%d%d" 提示信息："请输入两个整数："
		//* *输出格式要求："%d is %.1f percent of %d"
		//l程序运行示例：
		//请输入两个整数：6 18
		//6 is 33.3 percent of 18
#include<stdio.h>
#include<math.h>
	void main()
	{
		int a, b;
		float x;
		scanf_s("%d%d", &a, &b);
		x = (float)a / (float)b * 100;//整数除法运算结果先去尾再转换为浮点
		//第2种写法：a/(float)b
		//还可以：(float(a)/b)
		printf("请输入两个整数：");
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
		if (a + b < c)     //if句用{}表示成立的结果
		{
			printf("Input error!");
		}
		if (a + b > c)//不用分号
		{
			printf("area=%.2f", area);
		}
	}
#include<stdio.h>//编程将一位整数转换成数字字符
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
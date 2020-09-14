#include <stdio.h>
#include <string.h>
#include "Pointer.h"



int main()
{

	//reverse_array();
	//copy_array_by_pointer();
	//Pointer_01();
	//Pointer_03();
	//Pointer_04();
	//Pointer_05();
	//Pointer_06();
	//Pointer_07();

}

void reverse_array()
{
	int temp;
	int a[10] = { 11,12,13,14,15,16,17,18,19,20 };
	printf("the array is:\n");
	for (size_t i = 0; i < 10; i++)
	{
		printf("%5d", a[i]);
	}

	for (size_t j = 0; j < 5; j++)
	{
		temp = a[j];
		a[j] = a[9 - j];
		a[9 - j] = temp;
	}

	printf("\nNow the array is:\n");

	for (size_t i = 0; i < 10; i++)
	{
		printf("%5d", a[i]);
	}
}

void copy_array_by_pointer()
{
	int length=0;
	char str1[30], str2[30];
	char* p1, * p2;
	p1 = str1;
	p2 = str2;

	printf("please input string:\n");
	gets(str1);

	while (*p1 !='\0')
	{
		*p2 = *p1;
		p1++;
		p2++;
		length++;
	}
	*p2 = '\0';
	printf("%d\n", length);

	for (size_t i = 0; i < length; i++)
	{
		printf("%c", str2[i]);
	}
}
/********************************
Funtion: Input three int, Output in ascending order
Method: Pointer
*******************************/
void Pointer_01()
{
	int n1, n2, n3;
	int* p1, *p2, *p3;
	printf("Please input three number\n");
	scanf_s("%d,%d,%d", &n1, &n2, &n3); //input
	printf("%5d, %5d, %5d \n", n1, n2, n3);

	p1 = &n1;
	p2 = &n2;
	p3 = &n3;
	
	if (n1>n2)
	{
		Pointer_01_swap(p1, p2);
	}

	if (n1 > n3)
	{
		Pointer_01_swap(p1, p3);
	}

	if (n2 > n3)
	{
		Pointer_01_swap(p2, p3);
	}

	printf("%5d, %5d, %5d", n1, n2, n3);
}
void Pointer_01_swap(int *p1, int *p2)
{
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

/********************************
Funtion: Input three string, Output in ascending order
Method: Pointer
*******************************/
void Pointer_02_method_01()
{
	char str1[30];
	char str2[30];
	char str3[30];

	printf("please input 3 strings \n");
	gets(str1);
	gets(str2);
	gets(str3);
	if (strcmp(str1, str2) > 0)
	{
		Pointer_02_method_swap(str1, str2);
	}
	if (strcmp(str1, str3) > 0)
	{
		Pointer_02_method_swap(str1, str3);
	}
	if (strcmp(str2, str3) > 0)
	{
		Pointer_02_method_swap(str2, str2);
	}
	printf("Now the order is:\n");
	puts(str1);
	puts(str2);
	puts(str3);
}
void Pointer_02_method_swap(char *p1, char *p2)
{
	char p[30];
	strcpy_s(p, 30, p1);
	strcpy_s(p1, 30, p2);
	strcpy_s(p2, 30, p);
}

/********************************
Funtion: Input 10 number, ��С�ĺ͵�һ�����������ĺ����һ������
Method: Pointer
*******************************/
void Pointer_03()
{
	int number[10];
	input_number(number);
	max_min_number(number);
	output_number(number);
}
void input_number(int *number)
{
	printf("please inout 10 numbers\n");
	for (size_t i = 0; i < 10; i++)
	{
		scanf_s("%d", number+i);
	}
}
void max_min_number(int* number)
{
	int* max, * min, * p, temp;
	max = min = number;
	for ( p = number+1; p < number+10; p++)
	{
		if (*p > * max)
		{
			max = p;
		}
		else if (*p < *min)
		{
			min = p;
		}
	}
	temp = number[0];
	number[0] = *min;
	*min = temp;

	if (max == number)
	{
		max = min;  //��ʱ�������ԭ����С����λ����
	}
	temp = number[9];
	number[9] = *max;
	*max = temp;
}
void output_number(int* number)
{
	int* p;
	for (p = number; p <number+ 10; p++)
	{
		printf("%d ", *p);
	}
	printf("\n");
}

/********************************
Funtion: ��n��������ʹǰ�����˳�����m��λ�ã����m���������ǰ��m����
Method: Pointer
*******************************/
void Pointer_04()
{
	int number[30], n, m;

	printf("Ҫ������ٸ�����<30��\n");
	scanf_s("%d", &n);
	// 01 input n ����
	Pointer_04_input(number, n);
	// 02 ����Ҫ�ƶ�����λ =m
	printf("Ҫ�ƶ���λ��=");
	scanf_s("%d", &m);
	// 03 �ƶ�����
	Pointer_04_move(number, n, m);
	// 04 �������
	Pointer_04_output_number(number, n);
}
void Pointer_04_input(int* number, int n)
{
	int i;

	printf("������%d������\n", n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", number+i);
	}
}
void Pointer_04_move(int* number, int n, int m)
{
	int* p, temp;
	for (size_t i = 0; i < m; i++)
	{
		temp = number[n-1];  //��ʱ������һλ��ֵ
		for (p = number+n-1; p > number; p--)
		{
			*p = *(p - 1);
		}
		*number = temp; //֮ǰ������һλ��ֵ������λ
	}
}
void Pointer_04_output_number(int* number, int n)
{
	int* p;
	printf("���ڵĽ���ǣ�\n");
	for (p = number; p < number + n; p++)
	{
		printf("%d ", *p);
	}
	printf("\n");
}

/********************************
Funtion: ��n����Χ��һȦ��˳���źš��ӵ�1���˿�ʼ������1~3�����������Ǳ���3�����˳�Ȧ�ӣ����������������ԭ���ڵڼ���λ
Method: Pointer
*******************************/
void Pointer_05()
{
	int n, m, *p, num[50];
	int k=0, i =0 ;

	printf("input number of person: n = ");
	scanf_s("%d", &n);
	p = num;
	for ( i = 0; i < n; i++)
	{
		*(p + i) = i+1;  // ��1��ʼ��ÿ���˱��
	}
	i = 0;
	m = 0;
	k = 0;
	while (m<n-1)
	{
		if (*(p+i) !=0)
		{
			k++;   // k ������1-3����, ֻ���㲻Ϊ0�ģ�Ϊ0���Ѿ��˳���
		}
		else
		{
			// do nothing
		}
		if (k ==3)
		{
			k = 0;
			*(p + i) = 0;
			m++; // m = �˳�������
		}
		i++;
		if (i == n) { i =0; }
	}

	// ��ʼ����һ��������������ģ�������µģ�=0
	while (*p==0)
	{
		p++;
	}

	printf("The last on is No. %d \n", *p);
}


/********************************
Funtion: ��һ���ַ����ĳ���
Method: Pointer
*******************************/
void Pointer_06()
{
	int len;
	char str[30];
	printf("Please input a string: ");
	gets(str);
	len = Pointer_06_lengh(str);
	printf("The length of string is %d .\n", len);
}
int  Pointer_06_lengh(char *p)
{
	int n;
	n = 0;
	while (*p!='\0')
	{
		n++;
		p++;
	}
	return n;
}


/********************************
Funtion: ��һ���ַ���������n���ַ�
                ��дһ�������������ַ����д�m���ַ���ʼ�������ַ����Ƴ�Ϊ����һ���ַ���
Method: Pointer
*******************************/
void Pointer_07()
{
	int m;
	char str1[20], str2[20];
	printf("Please input strings \n");
	gets_s(str1, 20);

	printf("which character do you want begin to copy? \n");
	scanf_s("%d", &m);
	getchar();

	if (strlen(str1) < m)
	{
		printf("input error ! \n");
	}
	else
	{
		Pointer_07_copychar(str1, str2, m);
		printf("result is \n");
		puts(str2);
	}
}
void Pointer_07_copychar(char * p1, char *p2, int m)
{
	int n;
	n = 0;

	while (n<m-1)
	{
		p1++;
		n++;
	}

	while (*p1 !='\0')
	{
		*p2 = *p1;
		p2++;
		p1++;
	}
	*p2 = '\0';
}

void Pointer_08()
{
	int upper = 0;
}

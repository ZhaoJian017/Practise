#include<iostream>
using namespace std;


int main()
{
	void fun(int *p);
	int a = 10;

	fun(&a);

	cout << a << "" << endl;
	return 0;

}

void fun(int *p)
{
	*p = 5 * (*p);
}

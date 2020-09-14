#include <iostream>
using namespace std;

class CCircle
{
public:
	CCircle(int r);
	~CCircle();
	void DisplayArea(void);

private:
	float CalculateArea(void);
	int m_radius;
	int m_color;

};

CCircle::CCircle(int r)
{
	m_radius = r;
}

CCircle::~CCircle()
{
}

void CCircle::DisplayArea(void)
{
	float fArea;
	fArea = CalculateArea();
	cout<<"The area of the cricle is : " << fArea << endl;
}

float CCircle::CalculateArea(void)
{
	float f;
	f = 3.14 * m_radius * m_radius;
	return f;
}
void main()
{
	CCircle MyCircle(10);
	MyCircle.DisplayArea();
}
#include <stdio.h>

class MathCalc
{
private:
	static const double pie;

public :
	MathCalc() { }
	void DoCalc(double r) {
		printf("반지름이 %.2f인 원의 둘레 = %.2f\n", r, r * 2 * pie);
	}
	
};
const double MathCalc::pie = 3.1416;
int main()
{
	MathCalc r;
	r.DoCalc(5);
}
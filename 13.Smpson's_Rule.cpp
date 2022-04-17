#include<iostream>
#include<cmath>
using namespace std;
class Simpson{
public:
	// function
	float func(float x) {
		return (1/(1 + x));
	}
	float integrate(double lb, double ub, int interval) {
		double h = (ub + lb) / interval;
		double sum = func(lb) + func(ub);
		double oddSum = 0, evenSum = 0;
		for(int i = 1; i < interval; i = i + 2){
			oddSum = oddSum + func(lb + i * h);
		}
		for(int j = 2; j < interval; j = j +2){
			evenSum =  evenSum + func(lb + j * h);
		}
		sum = sum + 4 * oddSum + 2 * evenSum;

		double integration = sum * (h / 3);
		cout << "Integration Result is " << integration;
	}
};
main() {
	float result, lowLim, upLim;
	double lb = 0, ub = 1;
	int interval = 10;
	Simpson myObj;
	myObj.integrate(lb, ub, interval);
}

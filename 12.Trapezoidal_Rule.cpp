#include <bits/stdc++.h>
using namespace std;
class Trapezoidal{
public:
	double func(double x){
		return 1 / (1 + x);
	}

	void trapezoidal(double lb, double ub, int interval){
		double h = (ub - lb) / interval;
		//cout << h;
		double integral = func(lb) + func(ub);
		for(int i = 1; i <= interval - 1; i++){
			integral = integral + 2 * (func(lb + h * i));
		}
		integral = integral * (h / 2);
		cout << integral;
	}
};
int main(){
	double lb = 0, ub = 1;
	int interval = 10;
	Trapezoidal myObj;
	myObj.trapezoidal(lb, ub, interval);
}

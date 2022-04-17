#include <bits/stdc++.h>
using namespace std;
#define e 0.0000001
class SecantMethod{
public:
	double solution(double x){
		return 3*x - cos(x) - 1;
	}

	void secant(double x0, double x1){
		if(solution(x0) * solution(x1) >= 0){
			cout << "there is no solution between " << x0 << " and " << x1 << endl;
		}
		double root , h = ((x1 - x0) / (solution(x1) - solution(x0))) * solution(x1);
		while(abs(h) >= e){
			h = ((x1 - x0) / (solution(x1) - solution(x0))) * solution(x1);
			root = x0 - h;
			double x2 = x1 - h;
			x0 = x1;
			x1 = x2;
		}
		cout << "Root is: " << root << endl;
	}
};

int main(){
	SecantMethod myObj;
	myObj.secant(-100, 100);
	return 0;
}

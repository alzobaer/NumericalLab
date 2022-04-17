#include<bits/stdc++.h>
using namespace std;
#define e 0.0001
class Newton_Raphson{
public:
	double solution(double x){
		//return x*x*x - x*x + 2;
		return 3*x - cos(x) - 1;
	}
	double derivative(double x){
		return 3 + sin(x);
	}

	void newtonRaphson(double a, double b){
		double c = (a + b) / 2;
		//cout << c;
		if(solution(a) * solution(b) >= 0){
			cout << "Root is not available between " << a << " and " << b << endl;
			return;
		}

		double h = solution(c) / derivative(c);
		while(abs(h) >= e){
			h = solution(c) / derivative(c);
			c = c - h;
		}
		cout << "Root is: " << c << endl;
	}
};

int main(){
	Newton_Raphson myObject;
	myObject.newtonRaphson(100, -200);
	return 0;
}

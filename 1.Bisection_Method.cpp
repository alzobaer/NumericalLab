#include<bits/stdc++.h>
using namespace std;
#define e 0.000001
class Bisection{
public:
	double solution(double x){
		//return x*x*x - x*x + 2;
		return 3*x - cos(x) - 1;
	}
	void bisection(double a, double b){
		if(solution(a) * solution(b) >= 0){
			cout << "There is no solution between " << a << " and " << b << endl;
			return;
		}
		double c;
		while(abs(b - a) >= e){
			c = (a + b) / 2;
			if(solution(c) == 0){
				break;
			}
			else if(solution(a) * solution(c) < 0){
				b = c;
			}
			else{
				a = c;
			}
		}
		cout << "Root is " << c << endl;
	}
};
int main(){
	Bisection myObj;
	myObj.bisection(100, -100);
	return 0;
}

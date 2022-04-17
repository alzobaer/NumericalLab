#include <bits/stdc++.h>
using namespace std;
#define MaxIter 1000000
class FalsePosition{
public:
	double solution(double x){
		//return x*x*x - x*x + 2;
		return 3*x - cos(x) - 1 ;
	}
	void falseposition(double a, double b){
		if(solution(a) * solution(b) >= 0){
			cout << "there is no solution between " << a << " and " << b << endl;
			return;
		}
		else{
			double c = a;

			for(int i = 0; i < MaxIter; i++){
				c = (a*solution(b) - b*solution(a)) / ((solution(b) - solution(a)));
				//cout << c;
				if(solution(c) == 0.0){
					break;
				}
				else if(solution(a) * solution(c) < 0){
					b = c;
				}
				else
					a = c;
			}
			cout << "Root is " << c << endl;
		}
	}
};

int main(){
	FalsePosition myObj;
	myObj.falseposition(100, -10);
	return 0;
}

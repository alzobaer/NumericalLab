#include <bits/stdc++.h>
using namespace std;
class LagrangeInterpolation{
public:
	void lagrangeinterpolation(double x[], double y[], int n){
		double multi, result = 0;
		//value the interpolate at
		double value = 2;
		for(int i = 0; i < n; i ++){
			multi = 1;
			for(int j = 0; j < n; j ++){
				if(i != j){
					multi = multi * ((value - x[j])/(x[i] - x[j]));
				}
			}

			result = result + y[i] * multi;

		}
		cout << "\n value at " << value << " is " << result << endl;
	}
};

int main(){
	int n = 4;
	double x[n] = {0, 1, 3, 4};
	double y[n] = {-12, 0, 12, 24};
	LagrangeInterpolation myObj;
	myObj.lagrangeinterpolation(x, y, n);
}

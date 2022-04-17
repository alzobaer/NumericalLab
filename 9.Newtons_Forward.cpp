#include <bits/stdc++.h>
using namespace std;
class NewtonForward{
public:
	double u_calculate(double u, int n){
		double temp = u;
		for(int i = 1; i < n; i++){
			temp = temp * (u - i);
		}
		return temp;
	}
	double factorial(int n){
		int f = 1;
		for(int i = 2; i <= n; i++){
			f = f * i;
		}
		return f;
	}

	void newtonforward(){
		int n = 5;
		double x[] = {1891, 1901, 1911, 1921, 1931};
		double y[n][n];
		y[0][0] = 98752;
		y[1][0] = 132285;
		y[2][0] = 168076;
		y[3][0] = 195690;
		y[4][0] = 246050;
		//calculating the forward differences table
		for(int i = 1; i < n; i ++){
			for(int j = 0; j < n - i; j ++){
				y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
			}
		}
		// displaying the forward differences table
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n - i; j++){
				cout << y[i][j] << "\t" ;
			}
			cout << endl;
		}

		//value the interpolate at
		double value = 1905;

		// initializing u and sum
		double u, sum;
		u = (value - x[0]) / (x[1] - x[0]);
		sum = y[0][0];
		for(int i = 1; i < n; i++){
			sum = sum + (u_calculate(u, i) * y[0][i]) / factorial(i);
		}

		cout << "\n Value at " << value << " is " << sum << endl;
	}
};
int main(){
	NewtonForward myObj;
	myObj.newtonforward();
}

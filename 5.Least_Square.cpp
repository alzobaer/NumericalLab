#include<bits/stdc++.h>
using namespace std;
class LeastSquare{
public:
	void leastsquare(double x[], double y[], int n){
		double xsum = 0, ysum = 0, xysum = 0, x2sum = 0;
		for(int i = 0; i < n; i ++){
			xsum = xsum + x[i];
			ysum = ysum + y[i];
			xysum = xysum + x[i] * y[i];
			x2sum = x2sum + x[i] * x[i];
		}

		double a1 = ((xsum*ysum - n*xysum) / (xsum*xsum - n * x2sum));
		double a0 = ((xsum*xysum - ysum*x2sum) / (xsum*xsum - n * x2sum));
		cout << setprecision(5) << "y = " << a1 << "x " << a0 << endl;
	}

};

int main(){
	double x[10] = {0, 2, 5, 7}, y[10] = {-1, 5, 12, 20};
	int n = 4;

	LeastSquare myObj;
	myObj.leastsquare(x, y, n);
	return 0;
}

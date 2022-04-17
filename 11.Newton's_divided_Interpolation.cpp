#include<bits/stdc++.h>
using namespace std;
class NewtonDivided{
public:
	void newtondivided(double x[], double y[][10], int n) {
		//creating divided difference table
		for(int i = 1; i < n; i++){
			for(int j = 0; j < n - i; j++){
				y[j][i] = (y[j + 1][i - 1] - y[j][i - 1]) / (x[j + i] - x[j]);
			}
		}
		//displaying the forward differences table
		cout << " forward differences table" << endl;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n - i; j++){
				cout << setprecision(5) << y[i][j] << "\t";
			}
			cout << endl;
		}
	}
	double prod(double x[], double value, int i){
		double p = 1;
		for(int j = 0; j < i; j++){
			p = p * (value - x[j]);
		}
		return p;
	}
	double applyFormulla(double value, double x[], double y[][10], int n){
		double sum = y[0][0];
		//cout << n;
		for(int i = 1; i < n; i++){
			//cout << "In loop "  << endl;
			sum = sum + (prod(x, value, i) * y[0][i]);
		}
		cout << "\nvalue at " << value << " = " << sum << endl;
	}
};
int main(){
	int n = 4;
	double x[] = {35, 35.5, 39.5, 40.5};
	//double y[] = {1175, 1280, 2180, 2420};
	double y[10][10];
		y[0][0] = 1175;
		y[1][0] = 1280;
		y[2][0] = 2180;
		y[3][0] = 2420;
	NewtonDivided myObj;
	myObj.newtondivided(x, y, n);
	//cout << endl << y[0][2];
	// value to be interpolated
	double value = 40;
	myObj.applyFormulla(value, x, y, n);
}

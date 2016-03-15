#include <iostream>
#include <cmath>	
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;
const double PI = 3.14159265358979323846;

double fxfunction(double xx, int N, vector<double> x, vector<double> y) {
	double fx = 0.0;
	for (int i = 0; i <= N; i++) {
		double tmp = 1.0;
		for (int j = 0; j <= N; j++) {
			if (j != i) {
				tmp *= (xx - x[j]) / (x[i] - x[j]);
			}
		}
		fx += tmp * y[i];
	}
	return fx;
}
double fx3(int i, int N) {
	return  -5.0 + 10.0 * i / N;
}
double fx2(int i, int N) {
	return -5.0 * cos((2*i + 1)* PI / (2*N + 2));
}
double fx(double x) {
	return 1.0 / (1.0 + x * x);
}
int main() {
	ofstream fout("C:/Users/KangQi/Desktop/result.txt");
	int count = 0;
	int N = 5;
	fout << "第一组节点误差：" << endl;

	while (count < 4) {
		vector<double> x,y;
		x.resize(N + 1);
		y.resize(N + 1);
		for (int i = 0; i <= N; i++) {
			x[i] = fx3(i, N);
			y[i] = fx(x[i]);
		}
		double max = 0;
		for (int j = 0; j <= 500; j++) {
			double yj = -5.0 + 10.0 * j / 500;
			double current = fabs(fxfunction(yj, N, x, y) - fx(yj));
			if (current > max)
				max = current;
		}
		fout <<setiosflags(ios::fixed) << setprecision(15) << scientific << "N = " << N << '\t' << max << endl;
		N = N * 2;
		count++;
		
		
	}
	count = 0;
	N = 5;
	fout << "第二组节点误差：" << endl;
	while (count < 4) {
		vector<double> x, y;
		x.resize(N + 1);
		y.resize(N + 1);
		for (int i = 0; i <= N; i++) {
			x[i] = fx2(i, N);
			y[i] = fx(x[i]);
		}
		double max = 0;
		for (int j = 0; j <= 500; j++) {
			double yj = -5.0 + 10.0 * j / 500;
			double current = fabs(fxfunction(yj, N, x, y) - fx(yj));
			if (current > max)
				max = current;
		}
		fout << setiosflags(ios::fixed) << setprecision(15) << scientific << "N = " << N << '\t' << max << endl;
		N = N * 2;
		count++;


	}
	fout.close();
	return 0;
}
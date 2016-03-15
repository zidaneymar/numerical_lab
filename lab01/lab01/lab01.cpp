// lab01.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;
double calculate(double x) {
	double result = 0;
	for (int k = 1; ; k++) {
		double current = 1 / (k * (k + x));
		if (current > 0.000000000000000001) {
			result += current;
		}
		else {
			return result;
		}
	}
}
int main(){
	ofstream fout("c:/users/kangQi/desktop/szjs lab/result.txt");
	double x[7] = { 0.0, 0.5, 1.0, sqrt(2), 10.0, 100.0, 300.0 };
	for (int i = 0; i < 7; i++) {
		fout  << setiosflags(ios::fixed) << setprecision(2)<< scientific <<  x[i];
		fout << setiosflags(ios::fixed) << setprecision(12) << scientific << '\t' << calculate(x[i]) <<endl;
	}
	fout.close();
    return  0;
}


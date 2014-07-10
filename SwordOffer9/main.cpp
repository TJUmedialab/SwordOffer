#include <iostream>
#include <algorithm>
using namespace std;

int getF(int n){
	if ( n == 0 ){
		return 0;
	} else if ( n == 1){
		return 1;
	}
	else {
		double temp = pow(5, 0.5);
		double m_result = (1.0 / temp)*(pow((1.0 + temp) / 2, n) - pow((1.0 - temp) / 2, n));
		return round(m_result);
	}

	pow((int)2, n);
}
int main(int argc, char* argv[])
{
	int k = 0;
	while (cin >> k && k != -1) {
		cout << getF(k) << endl;
	}
	return 0;
}
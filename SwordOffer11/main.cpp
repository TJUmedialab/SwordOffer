// integer power of a read number

#include <iostream>
#include <assert.h>
#include <fstream>
using namespace std;

bool p_InvalidResult;

double getPowerCore(double p_base, int p_power){
	if ( p_power == 0 ){
		return 1;
	} else if ( p_power == 1 ){
		return p_base;
	}
	double halfPower = getPowerCore(p_base, p_power>>1);
	if ( p_power & 0x1 == 0){
		return halfPower*halfPower;
	}
	else {
		return halfPower*halfPower*p_base;
	}
}

bool doubleEqual(double a, double b){
	return ((a - b)<0.00001) && ((a - b)>-0.00001);
}

double getPower(double p_base, int p_pow){
	p_InvalidResult = false;
	if (doubleEqual(p_base, 0) && p_pow < 0){
		p_InvalidResult = true;
		return 0;
	}

	double m_result = 0;
	if (p_pow >= 0){
		m_result = getPowerCore(p_base, p_pow);
	}
	else
	{
		m_result = 1.0 / getPowerCore(p_base, -p_pow);
	}
	return m_result;
}

int main(int argc, char* argv[])
{
	double m_base = 0;
	int m_pow = 0;
	ifstream inFile("data.txt");
	double m_result;
	while( inFile>>m_base>>m_pow ) {
		m_result = getPower(m_base, m_pow);
		if (p_InvalidResult){
			cerr << "Invalid result\n";
		}
		else{
			cout << m_result << endl;
		}
	}
	return 0;
}
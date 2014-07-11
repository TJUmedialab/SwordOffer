// number of 1s in a binary number
#include <iostream>
#include <assert.h>
using namespace std;

int getOnes(int i){
	int count = 0;
	while ( i != 0) {
		count++;
		i = i&(i - 1);
	}
	return count;
}

int main(int argc, char* argv[])
{
	int n;
	while ( cin>> n && n != 0 ) {
		cout << getOnes(n) << endl;
	}
	return 0;
}
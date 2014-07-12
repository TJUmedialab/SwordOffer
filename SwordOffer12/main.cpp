// output from 1 to 999...999
#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

vector<char > num_array;
vector<char > num_char = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

void outputArray(){
	bool firstZero = true;
	assert(num_array.size() > 0);
	for (int i = 0; i < num_array.size(); i ++) {
		if ( num_array[i] != '0' ){
			firstZero = false;
		}
		if ( !firstZero ){
			cout << num_array[i];
		}
	}
	if (!firstZero){
		cout << endl;
	}
	
}

void circleOutputs(int bits, int index ){
	if ( index == bits ){
		outputArray();
		return;
	}
	for (int i = 0; i < 10; i ++) {
		num_array[index] = num_char[i];
		circleOutputs(bits, index + 1);
	}
}

int main(int argc, char* argv[])
{
	int bits = 0;
	while (cin >> bits&&bits != 0){
		if ( bits < 0 ){
			cerr << "the input number must be a >1 number\n";
			continue;
		}
		int t = bits;
		while (t--) {
			num_array.push_back('0');
		}
		circleOutputs(bits, 0);
		num_array.clear();
	}
}
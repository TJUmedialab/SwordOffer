// odd is the front part, even is the second part

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

bool myComp(int a){
	return (a % 2) ? true : false;
}

void mySwap(int& a, int& b){
	a = a^b;
	b = a^b;
	a = a^b;
}

void mySort(vector<int>& m_array){
	for (int fromIndex = 0, toIndex = m_array.size() - 1;
		toIndex - fromIndex >= 1; ) {
		if (myComp(m_array[fromIndex])){
			mySwap(m_array[fromIndex], m_array[toIndex]);
			toIndex--;
		}
		else {
			fromIndex++;
		}
	}
}

int main(int argc, char* argv[])
{
	vector<int> number_array;
	int k, input_number;
	ifstream inFile("data.txt");
	while (inFile >> k && k > 0) {
		for (int i = 0; i < k; i ++) {
			inFile >> input_number;
			number_array.push_back(input_number);
		}
		mySort(number_array);
		for (int i = 0; i < k; i++) {
			cout << number_array[i] << ' ';
		}
		cout << endl;
		number_array.clear();
	}
	inFile.close();
	return 0;
}
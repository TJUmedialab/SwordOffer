#include <iostream>
#include <assert.h>
#include <vector>
#include <fstream>
using namespace std;

template <typename T>
T seqDetect(vector<T>& m_array, int begin, int end) {
	T mid = m_array[begin];
	while (begin < end) {
		if (m_array[begin] < mid){
			mid = m_array[begin];
		}
		begin++;
	}
	return mid;
}

template <typename T>
T getMin(vector<T>& m_array){
	if ( m_array.size() <= 0){
		cerr << "the size is not big enough\n";
		return -1;
	}

	int start = 0, end = m_array.size() - 1;
	int mid = 0;
	while (m_array[end] <= m_array[start]) {
		if ( end - start == 1 ){
			mid = end;
			break;
		}

		mid = (start + end) / 2;
		if (m_array[mid] == m_array[end] && m_array[mid] == m_array[start]){
			return seqDetect(m_array, start, end);
		}

		if (m_array[mid] >= m_array[start]){
			start = mid;
		}
		else if (m_array[mid] <= m_array[end]){
			end = mid;
		}
	}

	return m_array[mid];
}

int main(int argc, char* argv[])
{
	int n;
	vector<int> d_array;
	int temp;
	ifstream dataFile("data.txt");
	while (dataFile >> n && n != 0) {
		for (int i = 0; i < n; i ++) {
			dataFile >> temp;
			d_array.push_back(temp);
		}
		temp = getMin(d_array);
		cout << temp << endl;
		d_array.clear();
	}
	dataFile.close();
	return 0;
}
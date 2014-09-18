// print a matrix in a circle sequence

#include <iostream>
#include <vector>
using namespace std;

void circlePrint(vector<vector<int>> arr){
	int len = arr.size();
	int begin_idx = 0;
	int i, j;
	while ( len > 1 ) {
		i = begin_idx;
		for (j = begin_idx; j < begin_idx+len; j++) {
			cout << arr[i][j] << ' ';
		}
		j = begin_idx + len - 1;
		for (i = begin_idx + 1; i < begin_idx+len; i++) {
			cout << arr[i][j] << ' ';
		}
		i = begin_idx + len - 1;
		for (j = begin_idx + len - 2; j >= begin_idx; j --) {
			cout << arr[i][j] << ' ';
		}
		j = begin_idx;
		for (i = begin_idx + len - 2; i > begin_idx; i--) {
			cout << arr[i][j] << ' ';
		}
		len -= 2;
		begin_idx += 1;
	}
	if ( len == 1 ) {
		cout << arr[begin_idx][begin_idx];
	}
	cout << endl;
}

int main()
{
	vector<vector<int>> mat;
	int k = 0;
	while ( cin >> k && k > 0) {
		mat.clear();
		mat.resize(k);
		for (int i = 0; i < k; i++) {
			mat[i].resize(k);
			for (int j = 0; j < k; j++) {
				mat[i][j] = (i+1)*(j+1);
				cout << mat[i][j] << ' ';
			}
			cout << endl;
		}
		circlePrint(mat);
	}
	return 0;
}
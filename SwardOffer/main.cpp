#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	char *str = new char[10000];
	cin.getline(str, 10000, '\n');
	int oldlength = strlen(str);
	int count = 0; 
	for (int i = 0; i < oldlength; i++) {
		if (str[i] == ' '){
			count++;
		}
	}
	int newlength = oldlength+2*count;
	str[newlength] = '\0';
	for (int i = oldlength-1; i >= 0; i --) {
		if (str[i] != ' ') {
			str[i + count * 2] = str[i];
		}
		else {
			str[i + count * 2 - 2] = '%';
			str[i + count * 2 - 1] = '2';
			str[i + count * 2] = '0';
			count--;
		}
	}
	cout << str << endl;
	return 0;
}
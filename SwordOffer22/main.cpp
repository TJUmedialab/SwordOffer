// given a stack input array, check whether another array is a valid array of output
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> stack_a;

bool checkValid(vector<int> a, vector<int> b){
    while ( stack_a.size() > 0 ) {
		stack_a.pop();
    }

    if (a.size() == 0 && b.size() == 0) {
        return true;
    }
    if (a.size()!=b.size()) {
        return false;
    }
	int i, j;
    for ( i = 0, j = 0 ; i < a.size() && j < b.size();  ){
        while(i < a.size()){
			if (a[i] != b[j]) {
				stack_a.push(a[i]);
				i++;
			}
			else {
				i++;
				break;
			}
            
        }
        j ++;
        while(stack_a.size() > 0 && stack_a.top() == b[j]){
            stack_a.pop();
            j++;
        }
    }
	if ( i == j && i == a.size() ) {
		return true;
	}
	else {
		return false;
	}
}

int main()
{
    vector<int> input_array;
    vector<int> output1;
    vector<int> output2;
    for (int i = 0 ; i < 5; i ++){
        input_array.push_back(i+1);
		output1.push_back(5 - i);
    }

	output2.push_back(4);
	output2.push_back(5);
	output2.push_back(3);
	output2.push_back(1);
	output2.push_back(2);

    if (checkValid(input_array, output1)) {
        cout << "output1 is valid!\n";
    } else {
        cout << "output1 is not valid!\n";
    }

    if (checkValid(input_array, output2)) {
        cout << "output2 is valid!\n";
    } else {
        cout << "output2 is not valid!\n";
    }

    return 0;
}

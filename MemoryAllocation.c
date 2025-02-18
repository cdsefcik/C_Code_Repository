#include<iostream>

using namespace std;

/*
* Calculate the number of zeros in a number.
* Provides an example of programming with recursion. 
*/

int countZeros(int n) {
	//base case
	if (n == 0) {
		return 0;
	}

	//recursive case
	int smallAns = countZeros(n / 10);

	//calculation
	int last_digit = n % 10;
	if (last_digit == 0) {
		return 1 + smallAns;
	}
	else {
		return smallAns;
	}
    
}


int main() {

	    int a;
		cout << "Enter the number: ";
		cin >> a;
		
		cout << countZeros(a);

		return 0;

}

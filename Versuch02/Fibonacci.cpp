//============================================================================
// Name        : Fibonacci.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

/* Formel:
 * f(0)=0
 * f(1)=1
 * f(x)= f(n-2) + f(n-1)
 */

int fibonacci(int n){

		if (n==0)
		return 0;
		else if (n==1)
		return 1;
		else
		return fibonacci(n-1) + fibonacci(n-2);
}


int main() {
	int n;
	for (n=0; n<26; n++){

		std::cout << fibonacci(n) <<std::endl;
	}

	return 0;
}


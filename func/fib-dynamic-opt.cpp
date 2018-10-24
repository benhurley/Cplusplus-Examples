// Benjamin Hurley
// fib-dynamic-opt.cpp

/*
    This program simulates fib with an optimized dynamic programming approach.

    When analyzing the approach in fib-dynamic.cpp, we can notice that
    cashed computations stored in the array (i) are only referenced for the 
    following two fib computations (fib[i+1] and fib[i+2]). This means
    we dont need to waste the extra space, and can use temp ints instead.

    Also in this version, once the double cannot be expressed as an integer,
    it is estimated as an exponent. 

    Runtime: O(n).

*/

#include <iostream>

using namespace std;

double fib(int);

int main() {

    unsigned int num = 0;
    long double fibNum = 0;
    cout << "Enter digit of fib you would like: ";
    cin >> num;

    fibNum = fib(num);

    cout << "Fibonacci at position " << num << " is " << fibNum << endl;

    return 0;
}

double fib(int n) {
    if (n == 0 || n == 1) return n;
    else {
        double a = 0;
        double b = 1;
        double temp = 0;

        for (int i = 2; i < n; ++i) {
            temp = b + a;
            a = b;
            b = temp;
        }
       return (a + b);
    }
}
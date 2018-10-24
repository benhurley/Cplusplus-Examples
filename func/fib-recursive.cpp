// Benjamin Hurley
// fib-recursive.cpp

/*
    This program computs the nth number of fib through a traditional, recursive algorithm.

    This version is the least optimized, with a slow runtime and wasted space due to continuous
    recursive calls filling stack space.

    Also in this version, once the double cannot be expressed as an integer,
    it is estimated as an exponent.

    Runtime: O(2^n). (Actually around O(1.6^n) specifically because right
    subtree is never as large as the left subtree, but 0(2^n) upperbound
    is also correct).
*/

#include <iostream>

using namespace std;

double fib(int);

int main() {

    unsigned int num = 0;
    long double fibNum = 0;
    cout << "Enter the digit of fib you would like to solve for: ";
    cin >> num;

    fibNum = fib(num);

    cout << "Fibonacci at position " << num << " is " << fibNum << endl;

    return 0;
}

double fib(int n) {
    if (n == 0 || n == 1) return n;
    else return (fib(n-1) + fib(n-2));
}
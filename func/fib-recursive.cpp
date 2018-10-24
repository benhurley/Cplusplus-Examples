// Benjamin Hurley
// fib-recursive.cpp

/*
    This program computs the nth number of fib through a traditional, recursive algorithm.

    This version is the least optimized, with a slow runtime and wasted space due to continuous
    recursive calls filling stack space.

    Runtime: ~ O(2^n). Actually around O(1.6^n) specifically because right
    subtree is never as large as the left subtree, but 0(2^n) upperbound
    is also correct.
*/

#include <iostream>

using namespace std;

int fib(int);

int main() {

    int num = 0;
    long int fibNum = 0;
    cout << "Enter digit of fib you would like: ";
    cin >> num;

    fibNum = fib(num);

    cout << "Fib of " << num << " is " << fibNum << endl;

    return 0;
}

int fib(int n) {
    if (n == 0 || n == 1) return n;
    else return (fib(n-1) + fib(n-2));
}
// Benjamin Hurley
// fib-memoization.cpp

/*
    This program computs the nth number of fib through a traditional, recursive algorithm.

    This version includes an array to store previously-computed values, making this version
    much faster than the traditional.

    This version is capped at 46 to make sure int doesnt overflow.

    Runtime: O(n).
*/

#include <iostream>

using namespace std;

int fib(int, int[]);

int main() {

    unsigned int num = 0;
    long int fibNum = 0;
    cout << "Enter the digit of fib you would like to solve for (0-46): ";
    cin >> num;

    if (num > 46) {
        cout << "Too big for example, int will overload" << endl;
        return 0;
    }

    int * fibStore = new int[num+1];

    // fill store with zeros
    for (int i = 0; i < num+1; ++i) {
        fibStore[i] = 0;
    }

    fibNum = fib(num, fibStore);

    cout << "Fibonacci at position " << num << " is " << fibNum << endl;

    return 0;
}

int fib(int n, int fibStore[]) {
    if (n == 0 || n == 1) return n;
    else {
        if (fibStore[n] == 0) {
            fibStore[n] = (fib(n-1, fibStore) + fib(n-2, fibStore));
        }
        return fibStore[n];
    }
}
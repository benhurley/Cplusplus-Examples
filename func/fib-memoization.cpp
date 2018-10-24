// Benjamin Hurley
// fib-memoization.cpp

/*
    This program computs the nth number of fib through a traditional, recursive algorithm.

    This version includes an array to store previously-computed values, making this version
    much faster than the traditional.

    Runtime: O(n).
*/

#include <iostream>

using namespace std;

int fib(int, int[]);

int main() {

    int num = 0;
    long int fibNum = 0;
    cout << "Enter digit of fib you would like (0-46): ";
    cin >> num;

    if (num > 46) {
        cout << "Too big for example, int will overload" << endl;
        return 0;
    }
    else if (num < 0) {
        cout << "Needs to be a positive integer" << endl;
        return 0;
    }

    int * fibStore = new int[num+1];

    // fill store with zeros
    for (int i = 0; i < num+1; ++i) {
        fibStore[i] = 0;
    }

    fibNum = fib(num, fibStore);

    cout << "Fib of " << num << " is " << fibNum << endl;

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
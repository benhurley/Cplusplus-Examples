// Benjamin Hurley
// fib-dynamic-opt.cpp

/*
    This program simulates fib with an optimized dynamic programming approach.

    When analyzing the approach in fib-dynamic.cpp, we can notice that
    cashed computations stored in the array (i) are only referenced for the 
    following two fib computations (fib[i+1] and fib[i+2]). This means
    we dont need to waste the extra space, and can use temp ints instead.

    Runtime: O(n).

*/

#include <iostream>

using namespace std;

int fib(int);

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

    fibNum = fib(num);

    cout << "Fib of " << num << " is " << fibNum << endl;

    return 0;
}

int fib(int n) {
    if (n == 0 || n == 1) return n;
    else {
        int a = 0;
        int b = 1;
        int temp = 0;

        for (int i = 2; i < n; ++i) {
            temp = b + a;
            a = b;
            b = temp;
        }
       return (a + b);
    }
}
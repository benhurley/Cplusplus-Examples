// Benjamin Hurley
// fib-memoization.cpp

/*
    This program simulates fib with a dynamic programming approach.

    Instead of the traditional top-down approach, we will use a 
    bottom-up solution. We will compute smaller values of fib and
    store them for caching until we reach out desired solution.

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

    fibNum = fib(num, fibStore);

    cout << "Fib of " << num << " is " << fibNum << endl;

    return 0;
}

int fib(int n, int fibStore[]) {
    if (n == 0 || n == 1) return n;
    else {
        fibStore[0] = 0;
        fibStore[1] = 1;
        for (int i = 2; i < n; ++i) {
           fibStore[i] = (fibStore[i-1] + fibStore[i-2]);
        }
       return (fibStore[n-1] + fibStore[n-2]);
    }
}
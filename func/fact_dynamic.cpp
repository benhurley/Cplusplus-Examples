// Benjamin Hurley
// fact_dynamic.cpp

/*
    This program will compute the factorial of a number using
    a dynamic programming approach.

    Time complexity: O(n)
*/

#include <iostream>

using namespace std;

int Factorial(unsigned int, int*);

int main() {
    unsigned int num = 0;

    cout << "Enter number you want to compute Factorial for (1-30): ";
    cin >> num;

    if (num > 30) {
        cout << "Too Big" << endl;
        return 0;
    }

    int * factStore = new int[num+1];

    int res = Factorial(num, factStore);
    cout << "Factorial of " << num << " is " << res << endl;

    return 0;
}

int Factorial(unsigned int n, int * factStore) {

    if (n == 0) return 0;
    else if (n ==1) return 1;
    else {
        factStore[1] = 1;

        for (int i = 2; i <= n; ++i) {
            factStore[i] = i * factStore[i-1];
        }
    }
    return factStore[n];
}
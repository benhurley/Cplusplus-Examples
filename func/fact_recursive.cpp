// Benjamin Hurley
// fact_recursive.cpp

/*
    This program will compute the factorial of a number using recursion.

    Time complexity: O(n)
*/

#include <iostream>

using namespace std;

int Factorial(unsigned int);

int main() {

    unsigned int num = 0;

    cout << "Enter number you want to compute Factorial for: ";
    cin >> num;

    if (num > 30) {
        cout << "Too Big" << endl;
        return 0;
    }
    
    int res = Factorial(num);
    cout << "Factorial of " << num << " is " << res << endl;

    return 0;
}

int Factorial(unsigned int n) {

    if (n == 1 || n == 0) return n;

    n = n * Factorial(n-1);

    return n;
}
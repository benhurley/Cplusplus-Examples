// Benjamin Hurley
// fib-sublinear.cpp

/*
    This program uses the math library to solve for fib directly 
    with a sublinear equation.

    Note: This version of fib begins with fib[0] = 1, so results
    will differ from other versions of my examples.
    
    Runtime: According to an MIT article, you can achieve O(e^n) runtime,
    but given the algorithm uses doubles, the results are approximated once
    expressed as an exponent. 

    link: http://courses.csail.mit.edu/6.01/spring07/lectures/lecture4.pdf

    ... still cool though regardless
*/

#include <iostream>
#include <math.h>

using namespace std;

double binet(int n);

int main() {

    unsigned int num = 0;
    long double fibNum = 0;
    cout << "Enter the digit of fib you would like to solve for: ";
    cin >> num;

    fibNum = binet(num);

    cout << "Fibonacci at position " << num << " is " << fibNum << endl;

    return 0;
}

double binet(int n)
{
    static const double phi = (1 + sqrt(5))*0.5;
    double fib = (pow(phi,n) - pow(1-phi,n))/sqrt(5);
    return round(fib);
}
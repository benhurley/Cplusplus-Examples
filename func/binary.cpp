// Benjamin Hurley
// binary.cpp

/*
    In this program, we will compute the binary complement of a number
*/

#include <iostream>

using namespace std;

int Comp(int);

 int main() {
    int a = 0;

    int ans = Comp(a);
    cout << "The binary complement of " << a << " is " << ans << endl;
    return 0;
 }

 int Comp(int a) {
    if (!a) return 1;
    
    int i = 1;

    while (i <= a) {
        a ^= i;
        i = i << 1;
    }

    return a;
 }
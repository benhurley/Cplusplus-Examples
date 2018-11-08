// Benjamin Hurley
// hamming.cpp

/*
    This program calculates the hamming distance (the number of bits
    that differ) between two numbers and hamming weight (number of 
    bits turned on) in a digit.
 */

#include <iostream>

using namespace std;

int Ham_Dist(int, int);
int Ham_Weight(int);

int main() {
    int a = 7;
    int b = 18;

    int dist = Ham_Dist(a, b);
    int weight1 = Ham_Weight(a);
    int weight2 = Ham_Weight(b);

    cout << "Hamming distance between " << a << " and " << b << " is: " << dist << endl;
    cout << "Hamming weight of " << a << " is: " << weight1 << endl;  
    cout << "Hamming weight of " << b << " is: " << weight2 << endl;

    return 0;
}

int Ham_Dist(int a, int b) {
    // Use xor to find bits that differ between a and b, store as 1
    int h = a ^ b;
    return h;
}

int Ham_Weight(int a) {
    // loop through bits in a to check for 1's
    int count = 0;

    while (a) {
        (a &= a-1);
        count++;
    }
    return count;
}

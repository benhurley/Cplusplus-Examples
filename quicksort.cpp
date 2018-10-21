// Benjamin Hurley
// quicksort.cpp

#include <iostream>
#include <vector>

using namespace std;

void quicksort(vector<int>&, int, int);
void swap(vector<int>&, int, int);
void Print(vector<int>&);

int main() {
    // For this example, we will use a vector and
    // populate it with random numbers each time

    vector<int> vec;
    const int count = 20;
    srand (time(NULL));

    // fill vector with random numbers 1-100
    for (int i = 0; i < count; i++) {
        vec.push_back(rand() % 100 + 1);
    }

    cout << endl << "Quick Sort Example" << endl;
    cout << endl << "Printing unsorted list: ";
    Print(vec);

    quicksort(vec, 0, count-1);

    cout << endl << "Printing sorted list: ";
    Print(vec);
    cout << endl <<endl;

    return 0;
}

void quicksort(vector<int> &vec, int low, int high) {
    int i = low;
    int j = high;

    // pick pivot in middle to increase chances of beating O(n^2)
    int pivot = vec[low + (high - low) / 2];

    while (i < high || j > low) {
        while (vec[i] < pivot)
            i++;
        while (vec[j] > pivot)
            j--;

        if (i <= j) {
            swap(vec, i, j);
            i++;
            j--;
        }
        else {
            if (i < high)
                quicksort(vec, i, high);
            if (j > low)
                quicksort(vec, low, j);
            return;
        }
    }
}

void swap(vector<int>& vec, int i, int j) { 
    int temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;

}

void Print(vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
}

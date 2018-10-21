// Benjamin Hurley
// mergesort.cpp

#include <iostream>

using namespace std;

void mergeSort(int[], int, int);
void merge(int[], int, int, int);
void printArray(int[], int);

int main() 
{ 
    // For this example, we will use an array and
    // populate it with random numbers each time

    const int count = 20;
    srand (time(NULL));

    // example array
    int arr[count];

    // even though we know the size already, we can
    // practice solving for the size
    int arr_size = sizeof(arr)/sizeof(arr[0]); 

    // fill array with random numbers 1-100
    for (int i = 0; i < count; i++) {
        arr[i] = (rand() % 100 + 1);
    }
  
    cout << "Given unosrted array is: "; 
    printArray(arr, arr_size); 
  
    mergeSort(arr, 0, arr_size - 1); 
  
    cout << "Sorted array is: "; 
    printArray(arr, arr_size); 

    return 0; 
} 

// Step 1 of 2: Break in half and sort halves.
void mergeSort(int arr[], int left, int right) 
{ 
    if (left < right) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int mid = left + (right - left)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, left, mid); 
        mergeSort(arr, mid + 1, right); 
  
        // Merge them together
        merge(arr, left, mid, right); 
    } 
} 

// Step 2 of 2: Merge sorted halves back together
void merge(int arr[], int left, int mid, int right) 
{ 
    int i, j, k; 
    int n1 = mid - left + 1; 
    int n2 =  right - mid; 
  
    // create temp arrays
    int L[n1], R[n2]; 

    // copy data into temp arrays
   for (i = 0; i < n1; i++) 
        L[i] = arr[left + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[mid + 1+ j]; 
  
    // Merge the temp arrays back into the original array
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = left; // Initial index of merged subarray 

    // merge lowest of two into originial array
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    // Copy the remaining elements of L[] (if any) 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    // Copy the remaining elements of R[] (if any)
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void printArray(int arr[], int size) 
{ 
    for (int i = 0; i < size; i++) 
        cout << arr[i] << " ";
    cout << endl;
} 
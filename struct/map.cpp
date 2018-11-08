#include <iostream>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

void consolidate(string*, int, map<string, int>&);

int main() {

    /*
        This example uses a map to parse input and place into seperate buckets.
        The number of occurences of each are counted and stored as values to a particular string (key).

        Also included random numbers after the cloud type (comma separated) to practice string splicing
        with stringstream for added complexity.

    */

    map<string, int> myMap;
    map<string, int>::iterator itr;

    int size = 10;
    string logs[size];  // this initialization compiles, if an initialization like below is attempted, compile fails
                        // because there is a chance at compile time that logs isnt initialized to size

    string temp[] = { "aws,1", "azure,6", "aws,4", "aws,9", "red hat,2", "azure,2", "gcp,5", "aws,9", "azure,5", "red hat,1" };
    
    // copy items into other array of strings
    for (int i = 0; i < size; ++i) {
        logs[i] = temp[i];
    }

    consolidate(logs, size, myMap);

    // print contents of map
    cout << "Elements in myMap:" << endl;

    for (itr = myMap.begin(); itr != myMap.end(); itr++) {
        cout << itr->first << " " << itr->second << endl;
    }

    return 0;
}

void consolidate(string * logs, int size, map<string, int>& myMap) {
    map<string, int>::iterator itr;

    for (int i = 0; i < size; ++i) {
         // save each string as a stringstream
         stringstream ss(logs[i]);

         string build = "";
         char c;

         // while iterating through the stringstream, check for commas
         while (ss >> c) {
            if (c == ',') break; // if we wanted to continue after, ss.peek() and ss.ignore() would skip
            else build += c;
         }

         // search for the key in the map
         itr = myMap.find(build);

         // if never reached the end, must have found it.
         if (itr !=myMap.end()) {
             // found it
             itr->second++;
         }
         else {
             // add to map
             myMap[build] = 1;
         }

    }

}
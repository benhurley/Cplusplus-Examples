#include <iostream>
#include <map>
#include <vector>

using namespace std;

void consolidate(vector<string>, map<string, int>&);
map<string, int>::iterator itr;

int main() {

    /*
		*** C++11 needed for this vector initialization ***
        This example uses a map to parse input and place into seperate buckets.
        The number of occurences of each are counted and stored as values to a particular string (key).

        Estimated runtime: O(n + m) including print to console.
    */

    map<string, int> myMap;

    vector<string> logs{ "aws", "azure", "aws", "aws", "red hat", "azure", "gcp", "aws", "azure", "red hat" };

    consolidate(logs, myMap);

    // print contents of map
    cout << "Elements in myMap:" << '\n';
    for (itr = myMap.begin(); itr != myMap.end(); itr++) {
        cout << itr->first << " " << itr->second << endl;
    }

    return 0;
}

void consolidate(vector<string> logs, map<string, int>& myMap) {
    map<string, int>::iterator itr;

    for (int i = 0; i < logs.size(); ++i) {
         itr = myMap.find(logs[i]);

         if (itr !=myMap.end()) {
             // found it
             itr->second++;
         }
         else {
             // add to map
             myMap[logs[i]] = 1;
         }

    }

}
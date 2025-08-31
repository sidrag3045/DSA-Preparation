// Finding a unique number where all the numbers are repeated twice except for one N = 2*m + 1, m no's are repeated twice and one no is unique
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// One way to do this is by using a hash map
int findUnique1(vector<int> &arr){
    // Create a frequency map of type <int,int> where first int is the element and second int is its count
    unordered_map<int, int> freq;
    for (int num : arr) {
        // for each num, increment its count in the frequency map
        freq[num]++;
    }

    // Another loop to find the unique element
    // For each value in the freq map, we check if its count is 1 and if yes then we return the element
    for (auto it : freq) {
        if (it.second == 1) {
            return it.first;
        }
    }
    return -1;  // If no unique element is found
}

// Another way to find the unique element is by using bit manipulation (XOR)
// Property of XOR => a ^ a = 0 and a ^ 0 = a
// the above property means that if we XOR all the numbers, the duplicates will cancel each other out and give 0 and when we finally XOR with the unique number, we will get that number

int findUnique2(vector<int> &arr) {
    // Using XOR to find the unique element
    // We first initialize a variable unique to 0
    int unique = 0;
    for (int num : arr) {
        unique ^= num;
    }
    return unique;
}

int main() {
    vector<int> arr = {1, 2, 3, 2, 1};

    cout << "Unique element using frequency map: " << findUnique1(arr) << endl;
    cout << "Unique element using XOR: " << findUnique2(arr) << endl;

    return 0;
}


// Given an array of numbers, check whether the given array is sorted or not in the non-decreasing order. Return true if sorted else return false.

#include <iostream>
#include <vector>
using namespace std;

bool isSorted(vector<int> &arr) {
    int n = arr.size();
    // just traversing the array and checking if at any point the current element is less than the previous element, then we need to return false else if it comes out of the loop then we return true
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 4};
    if (isSorted(arr)) {
        cout << "Array is sorted." << endl;
    } else {
        cout << "Array is not sorted." << endl;
    }
    return 0;
}

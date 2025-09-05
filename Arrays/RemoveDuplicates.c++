// Given an array which is sorted, remove all the duplicates from the array in (in-place manner).

#include <iostream>
#include <vector>
#include <set>
using namespace std;


// Here brute force approach could be to use a set data structure and store only unique elements in it and then copy them back to the original array. But this would require extra space and also would not be in-place.
// Time complexity: O(n log n) due to set insertion, Space complexity: O(n) due to set storage.
// void removeDuplicates(vector<int> &arr) {
//     set<int> uniqueElements;
//     for (int i = 0; i < arr.size(); i++) {
//         uniqueElements.insert(arr[i]);
//     }
//     arr.clear();
//     for (int num : uniqueElements) {
//         arr.push_back(num);
//     }
// }

// Optimal approach: Since the array is sorted, we can use two pointers to remove duplicates in-place.
void removeDuplicates(vector<int> &arr) {
    if (arr.empty()) return;

    int writeIndex = 1; // Index to write the next unique element
    // Our pointer i starts from the second element and this pointer will traverse the entire array to look for unique elements, whenever this i pointer finds a unique element, we write it at the writeIndex and increment the writeIndex.
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] != arr[i - 1]) { // If current element is different from the previous one
            arr[writeIndex] = arr[i]; // Write it at the writeIndex
            writeIndex++;
        }
    }
    arr.resize(writeIndex); // Resize the array to keep only unique elements
}


void printArray(vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 1, 2, 2, 3, 4, 4, 5};
    cout << "Original array: ";
    printArray(arr);

    removeDuplicates(arr);
    cout << "Array after removing duplicates: ";
    printArray(arr);
    return 0;
}
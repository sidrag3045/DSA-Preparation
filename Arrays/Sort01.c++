// Sorting 0's and 1's in an array
// Here brute force approach is to count the number of 0's and 1's and then fill the array accordingly. This takes O(n) time and O(1) space.
// Another approach is to use two pointers, one starting from the beginning and the other from the end. We swap the elements if the left pointer is at 1 and the right pointer is at 0. This also takes O(n) time and O(1) space.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sort01(vector<int> &arr){
    int left = 0;
    int right = arr.size() - 1;

    while(left < right){
        // ideal position for 0 ==> shift left pointer forward
        if(arr[left] == 0){
            left++;
        }
        // ideal position for 1 ==> shift right pointer backward
        else if(arr[right] == 1){
            right--;
        }
        // swapping condition
        else{
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

void printArray(vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {0, 1, 0, 1, 0, 1, 0, 1};
    cout << "Original array: ";
    printArray(arr);
    sort01(arr);
    cout << "Sorted array: ";
    printArray(arr);
    return 0;
}
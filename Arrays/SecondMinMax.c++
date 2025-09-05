// Given an array, we need to find the second largest and second smallest elements in the array.

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// 1. Brute force approach is to sort the array and then traverse the array to find the second largest and second smallest elements. We check for duplicates while traversing with condition if the current element is not equal to the previous element then we can consider it as a valid second largest or second smallest element.
// This approach takes O(n log n) time due to sorting.

// int secondLargest(vector<int> &arr){
//     int n = arr.size();
//     if(n < 2) return -1; // Not enough elements for second largest

//     sort(arr.begin(), arr.end());
//     for(int i = n - 2; i >= 0; i--){
//         if(arr[i] != arr[n - 1]){
//             return arr[i];
//         }
//     }
//     return -1; // All elements are the same
// }

// int secondSmallest(vector<int> &arr){
//     int n = arr.size();
//     if(n < 2) return -1; // Not enough elements for second smallest

//     sort(arr.begin(), arr.end());
//     for(int i = 1; i < n; i++){
//         if(arr[i] != arr[0]){
//             return arr[i];
//         }
//     }
//     return -1; // All elements are the same
// }

// =================================================================================================


// 2. Better approach is to traverse the array twice, once to find the largest and smallest elements and then again to find the second largest and second smallest elements by taking their value to be INT_MIN and INT_MAX respectively and finally comparing their values with the largest and smallest elements found in the first traversal. This approach takes O(2*n) time and O(1) space.

// int secondLargest(vector<int> &arr) {
//     int n = arr.size();
//     if (n < 2) return -1; // Not enough elements for second largest

//     int largest = INT_MIN;
//     int secondLargest = INT_MIN;

//     // First traversal to find the largest element
//     for (int i = 0; i < n; i++) {
//         if (arr[i] > largest) {
//             largest = arr[i];
//         }
//     }

//     // Second traversal to find the second largest element
//     for (int i = 0; i < n; i++) {
//         if (arr[i] > secondLargest && arr[i] != largest) {
//             secondLargest = arr[i];
//         }
//     }

//     return (secondLargest == INT_MIN) ? -1 : secondLargest;
// }

// int secondSmallest(vector<int> &arr) {
//     int n = arr.size();
//     if (n < 2) return -1; // Not enough elements for second smallest

//     int smallest = INT_MAX;
//     int secondSmallest = INT_MAX;

//     // First traversal to find the smallest element
//     for (int i = 0; i < n; i++) {
//         if (arr[i] < smallest) {
//             smallest = arr[i];
//         }
//     }

//     // Second traversal to find the second smallest element
//     for (int i = 0; i < n; i++) {
//         if (arr[i] < secondSmallest && arr[i] != smallest) {
//             secondSmallest = arr[i];
//         }
//     }

//     return (secondSmallest == INT_MAX) ? -1 : secondSmallest;
// }

// =================================================================================================

// 3. Optimal approach is to traverse the array only once and keep track of the largest, second largest, smallest and second smallest elements in a single traversal. This approach takes O(n) time and O(1) space.


int secondLargest(vector<int> &arr) {
    int n = arr.size();
    if (n < 2) return -1; // Not enough elements for second largest

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    return (secondLargest == INT_MIN) ? -1 : secondLargest;
}

int secondSmallest(vector<int> &arr) {
    int n = arr.size();
    if (n < 2) return -1; // Not enough elements for second smallest

    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }
    }

    return (secondSmallest == INT_MAX) ? -1 : secondSmallest;
}

// =================================================================================================


int main() {
    vector<int> arr = {12, 35, 1, 10, 34, 1};
    cout << "Second Largest: " << secondLargest(arr) << endl;
    cout << "Second Smallest: " << secondSmallest(arr) << endl;
    return 0;
}
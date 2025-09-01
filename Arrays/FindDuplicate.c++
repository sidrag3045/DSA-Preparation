// Finding duplicate in an array
// Given the condition that all other elements repeat only once and N numbers are in the range from 1 to N-1, where exactly one element is repeated
// Example: N = 5, then elements in array are from 1 to 4 and any of them is repeated twice.
// arr = {1, 2, 3, 4, 2} => 2 is the duplicate
#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int> &arr, int n) {
    int ans = 0;
    // firstly what we do here is that we run a loop on array to XOR all elements in one answer variable
    for (int i = 0; i < n; i++) {
        ans = ans ^ arr[i];
    }
    // then we run a loop from 1 to n-1 and XOR all those elements with the answer variable
    // this will cancel out all elements that are not duplicated
    // E.g., for arr = {1, 2, 3, 4, 2} and n = 5, we will XOR 1, 2, 3, 4 and we know that a^0 = a and a^a = 0, so all the even occurrences will be cancelled out and we will be left with duplicate element.
    for (int i = 1; i < n; i++) {
        ans = ans ^ i;
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 2};
    int n = arr.size();

    int ans = 0;
    ans = findDuplicate(arr, n);
    cout << "The duplicate element is: " << ans << endl;
    return 0;
}


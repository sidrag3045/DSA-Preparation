// Finding unique element in an array where all numbers are repeated k times except one, N = k*m + 1, m no's are repeated
#include <iostream>
#include <vector>

using namespace std;

// We cant use XOR in this case because XOR only works when every element is repeated even times
// We will be using Bit Manipulation technique here to find the bit sets at each position from 0->31

int findUnique(vector<int> &arr, int k){
    int n = arr.size();
    int ans = 0;

    // Iterate over each bit position
    for (int i = 0; i < 32; i++) {
        int sum = 0;
        // Check each number in the array
        for (int j = 0; j < n; j++) {
            // If the ith bit is set, increment sum
            if (arr[j] & (1 << i)) {
                sum++;
            }
        }
        // If sum is not a multiple of k, then the unique number has the ith bit set
        if (sum % k != 0) {
            ans |= (1 << i);
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 4, 2, 3, 3, 1, 1, 3, 2, 4, 4, 5};
    int k = 3;  // Number of times each element is repeated
    cout << "Unique element is: " << findUnique(arr, k) << endl;

    return 0;
}

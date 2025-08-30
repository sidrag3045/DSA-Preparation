#include <iostream>
#include <limits.h>
#include <algorithm>
#include <vector>
using namespace std;

// Traditional approach for finding minimum
int findMinTraditional(const vector<int>& arr) {
    int mini = INT_MAX;
    for (int val : arr) {
        if (val < mini) {
            mini = val;
        }
    }
    return mini;
}

// Traditional approach for finding maximum
int findMaxTraditional(const vector<int>& arr) {
    int maxi = INT_MIN;
    for (int val : arr) {
        if (val > maxi) {
            maxi = val;
        }
    }
    return maxi;
}

// Using algorithm library min function
int findMinAlgo(const vector<int>& arr) {
    int mini = INT_MAX;
    for (int val : arr) {
        mini = min(mini, val);
    }
    return mini;
}

// Using algorithm library max function
int findMaxAlgo(const vector<int>& arr) {
    int maxi = INT_MIN;
    for (int val : arr) {
        maxi = max(maxi, val);
    }
    return maxi;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Using traditional approach
    // int mini = findMinTraditional(arr);
    // int maxi = findMaxTraditional(arr);

    // Using algorithm library functions
    int mini = findMinAlgo(arr);
    int maxi = findMaxAlgo(arr);

    cout << "Minimum element: " << mini << endl;
    cout << "Maximum element: " << maxi << endl;
    return 0;
}

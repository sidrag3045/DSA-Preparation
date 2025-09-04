// Generate a triplet from the array elements such that their sum is equal to the target sum
// OR
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.
// now when we were solving the 2-sum probem, were able to do it in O(n) time complexity, but the only problem was that we were still using O(n) space complexity.
// We could have used 2 pointer approach there if the array was sorted, but since it was not sorted we had to use a set to store the elements we have seen so far.
// but the brute force approach here for 3-sum is O(n^3) and we can reduce it to O(n^2) using the 2 pointer approach if the array is sorted as O(nlogn) is the time complexity of sorting the array which is less than O(n^2).
// so the overall time complexity will be O(n^2) and space complexity will be O(1) if we don't consider the space required for sorting the array.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> tripletSum(vector<int> &arr, int targetSum) {
    sort(arr.begin(), arr.end());
    int n = arr.size();

    vector<vector<int>> result;

    // optimisation check
    // if number of elements in the array is less than 3, we cannot form a triplet
    if (n < 3) {
        return {};
    }

    // traversing the array, fixing one element and finding the other two elements using 2 pointer approach
    for(int i=0; i<n-2; i++){
        int low = i+1;
        int high = n-1;

        // we can skip the duplicate elements to avoid duplicate triplets in the result as for any particular element we have searched completely in our rest of the array for the other two elements, so if we encounter the same element again, we will end up getting the same triplet again.
        if(i > 0 && arr[i] == arr[i-1]) {
            continue; // skip duplicate elements to avoid duplicate triplets
        }

        // 2 pointer approach
        while(low < high){
            int currSum = arr[i] + arr[low] + arr[high];
            vector<int> tempResult;
            if(currSum == targetSum){
                tempResult.push_back(i);
                tempResult.push_back(low);
                tempResult.push_back(high);
                result.push_back(tempResult);
                // move the pointers to find other possible triplets
                low++;
                high--;
            } else if (currSum < targetSum) {
                low++;
            } else {
                high--;
            }
        }
    }
    return result;
}


int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int targetSum = 15;
    vector<vector<int>> result = tripletSum(arr, targetSum);
    if (!result.empty()) {
        cout << "Triplet found : "<< endl;
        for (const auto& triplet : result) {
            cout << "(" << arr[triplet[0]] << ", " << arr[triplet[1]] << ", " << arr[triplet[2]] << ") " << endl;
        }
        cout << endl;
    } else {
        cout << "No triplet found" << endl;
    }

    return 0;
}
// Pair Sum Problem to find all pairs in an array that sum to a target value
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<pair<int, int>> findAllPairs(vector<int> &arr, int target) {
    unordered_map<int, int> numMap;
    // in case if you dont want duplicate pairs, then use set of pairs instead of vector of pairs
    vector<pair<int, int>> result;

    for (int i = 0; i < arr.size(); i++) {
        int complement = target - arr[i];
        if (numMap.find(complement) != numMap.end()) {
            // If found, add the pair to the result
            // Instead of returning the single pair, we add it to the result vector
            pair<int, int> newPair = {numMap[complement], i};
            if (newPair.first > newPair.second) {
                swap(newPair.first, newPair.second);
            }
            result.push_back(newPair);
        }
        numMap[arr[i]] = i;
    }
    sort(result.begin(), result.end());
    return result;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 9, 13, 10, 11, 11};
    int target = 14;

    vector<pair<int, int>> pairs = findAllPairs(arr, target);
    for (const auto &p : pairs) {
        // to show all pair values
        // cout << "Pair found: (" << arr[p.first] << ", " << arr[p.second] << ")" << endl;
        // to show their indices
        cout << "Indices: (" << p.first << ", " << p.second << ")" << endl;
    }

    return 0;
}
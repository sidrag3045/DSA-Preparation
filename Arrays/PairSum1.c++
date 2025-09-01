// Solution to find a pair of elements from the array such that their sum is equal to the target sum, return only one suc pair

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> pairSum(vector<int> &arr, int size, int target){
    // Create a hash map to store the elements and their respective indices
    unordered_map<int, int> hashMap;
    // Loop through the array
    for(int i=0; i<size; i++){
        // finding the complement element 
        int complement = target - arr[i];
        // Check if the complement exists in the hash map already
        // find function searches through the entire hashmap, and returns the iterator on the key if found, and it goes on till hashMap.end() which is the end of the hashmap ( one past the last element )
        if(hashMap.find(complement) != hashMap.end()){
            // If found, return the indices of the pair
            return {hashMap[complement], i};
        }
        // If not found, add the current element and its index to the hash map
        hashMap[arr[i]] = i;
    }
    return {-1, -1};
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int target = 9;
    int n = arr.size();

    vector<int> result = pairSum(arr, n, target);

    if (result[0] != -1 && result[1] != -1) {
        cout << "Pair found: (" << result[0] << ", " << result[1] << ")" << endl;
    } else {
        cout << "No pair found" << endl;
    }

    return 0;
}
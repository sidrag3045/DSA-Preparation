#include <iostream>
#include <vector>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    // array to store result
        vector<int> result;
        // looping through the array to mark visited elements
        for (int i = 0; i < nums.size(); ++i) {
            // what we do here is we take the value at current index and convert it to index by subtracting 1 and then we mark that value as visited by negating it
            int index = abs(nums[i]) - 1; // Converting value to 0-based index
            // if the value is already negative, it means we've seen this index before
            if (nums[index] < 0) {
                // pushing the absolute value of the current element in the result array
                result.push_back(abs(nums[i])); // Already visited → duplicate
            } else {
                nums[index] = -nums[index]; // Marking as visited
            }
        }
        return result;
    }

int main() {
    vector<int> arr = {4, 3, 2, 7, 8, 2, 3, 1, 7, 8};
    vector<int> duplicates = findDuplicates(arr);
    cout << "Duplicate elements are: ";
    for (int num : duplicates) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
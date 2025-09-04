// Sorting array of 0s, 1s and 2s
#include <iostream>
#include <vector>
using namespace std;

void sort012(vector<int>& nums) {
    // Dutch National Flag Algo
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;
    // Intuition is to sort the numbers in such a way that we consider only a part of our array to be unsorted, like we consider our array looks like 0 0 0 ... 1 1 1 ... [ Unsorted Part ] ... 2 2 2

    // We call the range where all are 0's to be 0 -> low - 1
    // Range for 1's to be low -> mid - 1
    // Range for unsorted to be mid -> high
    // Range for 2's to be high + 1 -> n - 1

    // Initially we assume everything lies in unsorted part
    while(mid <= high){
        // Condition for 0 to be shifted in the correct range
        if(nums[mid] == 0){
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        // Condition for 1 to be shifted in the correct range
        else if(nums[mid] == 1){
            mid++;
        }
        // Condition for 2 to be shifted in the correct range
        else if(nums[mid] == 2){
            swap(nums[high],nums[mid]);
            high--;
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
    vector<int> arr = {2, 0, 1, 2, 0, 1, 2};
    cout<<"Original array: ";
    printArray(arr);
    sort012(arr);
    cout<<"Sorted array: ";
    printArray(arr);
    return 0;
}
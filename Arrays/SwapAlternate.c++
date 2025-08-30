#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int> &arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

void swapAlternate(vector<int> &arr, int n){
    for(int i=0; i < n-1; i += 2){
        swap(arr[i], arr[i+1]);
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();

    // Before swapping
    cout << "Array before swapping: ";
    printArray(arr, n);
    cout << endl;

    // Swapping alternate elements
    swapAlternate(arr, n);

    // After swapping
    cout << "Array after swapping: ";
    printArray(arr, n);
    cout << endl;

    return 0;
}
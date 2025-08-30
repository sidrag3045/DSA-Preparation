#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> &arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

void reverseArray(vector<int> &arr, int n){
    int s = 0;
    int e = n - 1;
    // using 2 pointers approach
    while(s <= e){
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int n = arr.size();
    // printing before reversing
    cout << "Array before reversing: ";
    printArray(arr, n);
    cout << endl;
    // reversing the array
    reverseArray(arr, n);
    // printing after reversing
    cout << "Array after reversing: ";
    printArray(arr, n);
    cout << endl;

    return 0;
}
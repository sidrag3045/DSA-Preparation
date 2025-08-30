#include <iostream>
#include <vector>
using namespace std;

int arraySum(vector<int> &arr){
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {

    vector<int> arr = {1, 2, 3, 4, 5};
    
    int sum = arraySum(arr);
    
    cout << "Sum of array elements: " << sum << endl;
    return 0;

}
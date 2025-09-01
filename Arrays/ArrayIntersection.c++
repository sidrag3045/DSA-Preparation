// Solution to find intersection (common elements) of two arrays given that both the arrays are sorted
#include <iostream>
#include <vector>

using namespace std;

vector<int> findIntersection(vector<int> &arr1, int size1, vector<int> &arr2, int size2){
    // taking 2 starting pointers pointing at each array
    int i = 0, j = 0;
    // vector to store intersection elements
    vector<int> intersection;
    // looping through both arrays
    while(i<size1 && j<size2){
        // if both elements are equal, add to intersection and move both pointers forward
        if(arr1[i] == arr2[j]){
            intersection.push_back(arr1[i]);
            i++;
            j++;
        }
        // if element in arr1 is smaller, move pointer in arr1
        else if(arr1[i] < arr2[j]){
            i++;
        }
        // if element in arr2 is smaller, move pointer in arr2
        else{
            j++;
        }
    }
    return intersection;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {4, 5, 6, 7, 8};

    int size1 = arr1.size();
    int size2 = arr2.size();

    vector<int> intersection = findIntersection(arr1, size1, arr2, size2);

    cout << "Intersection elements are: ";
    for (int num : intersection) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
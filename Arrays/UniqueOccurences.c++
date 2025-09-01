// We have to find if in an array, the number of occurences of each element is unique or not.
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool uniqueOccurences(vector<int> &arr){
    // firstly we are taking a hashmap to stire the frequency of each element of the array
    unordered_map<int, int> freq;
    for(int i=0; i<arr.size(); i++){
        freq[arr[i]]++;
    }
    // now we will take a set to store the frequency of each element
    unordered_set<int> uniqueFreq;
    for(auto it: freq){
        uniqueFreq.insert(it.second);
    }
    // if the size of the set is equal to the size of the map, it means all frequencies are unique
    return (uniqueFreq.size() == freq.size());
}

int main() {

    vector<int> arr = {1, 2, 2, 1, 1, 3};
    bool result = false;
    result = uniqueOccurences(arr);
    if(result){
        cout<<"All elements have unique occurrences."<<endl;
    }
    else{
        cout<<"Elements have duplicate occurrences."<<endl;
    }
    
    
    // Your code here
    return 0;
}
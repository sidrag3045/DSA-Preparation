// Solution to find if an integer is a power of 2
#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    // In this way, we are checking if n has exactly one bit set in its binary representation, then the number is a power of 2, and we can check it by subtracting 1 from the original number which makes all the bits after the rightmost set bit 1 and the rightmost set bit 0 and doing a bitwise AND with the original number will lead to result 0 if it is a power of 2.
    return (n & (n - 1)) == 0;
}

int main() {
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;

    if (isPowerOfTwo(num)) {
        cout << num << " is a power of 2." << endl;
    } else {
        cout << num << " is not a power of 2." << endl;
    }

    return 0;
}

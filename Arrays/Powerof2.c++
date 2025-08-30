// Solution to find if an integer is a power of 2
#include <iostream>
using namespace std;

bool isPowerOfTwo1(int n) {
    if (n <= 0) return false;
    // In this way, we are checking if n has exactly one bit set in its binary representation, then the number is a power of 2, and we can check it by subtracting 1 from the original number which makes all the bits after the rightmost set bit 1 and the rightmost set bit 0 and doing a bitwise AND with the original number will lead to result 0 if it is a power of 2.
    return (n & (n - 1)) == 0;
}

// We can also solve it recursively using the below logic 
bool isPowerOfTwo2(int n) {
    // base condition
    if (n == 1) return true;

    // If n is not positive or odd, it's not a power of 2
    if (n < 1 || n % 2 != 0) return false;

    // Recursive case ( we just divide n by 2 in each call)
    return isPowerOfTwo2(n / 2);
}


int main() {
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;

    if (isPowerOfTwo2(num)) {
        cout << num << " is a power of 2." << endl;
    } else {
        cout << num << " is not a power of 2." << endl;
    }

    return 0;
}

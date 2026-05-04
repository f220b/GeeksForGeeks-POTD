class Solution {
public:
    bool isBinaryPalindrome(int n) {
        unsigned int original = n;
        unsigned int reversed = 0;
        unsigned int temp = n;

        while (temp > 0) {
            reversed <<= 1;
            reversed |= (temp & 1);
            temp >>= 1;
        }

        return original == reversed;
    }
};
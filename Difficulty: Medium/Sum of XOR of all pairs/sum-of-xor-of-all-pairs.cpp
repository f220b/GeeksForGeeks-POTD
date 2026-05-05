class Solution {
public:
    long long sumXOR(std::vector<int> &arr) {
        long long total_sum = 0;
        int n = arr.size();
        
        // Iterate through each bit position from 0 to 31
        for (int i = 0; i < 32; i++) {
            long long count_zero = 0;
            long long count_one = 0;
            
            for (int j = 0; j < n; j++) {
                // Check if the i-th bit is set
                if ((arr[j] >> i) & 1) {
                    count_one++;
                } else {
                    count_zero++;
                }
            }
            
            // The number of pairs with the i-th bit set in their XOR
            long long pairs_with_bit = count_zero * count_one;
            
            // Add the contribution of the i-th bit to the total sum
            total_sum += pairs_with_bit * (1LL << i);
        }
        
        return total_sum;
    }
};
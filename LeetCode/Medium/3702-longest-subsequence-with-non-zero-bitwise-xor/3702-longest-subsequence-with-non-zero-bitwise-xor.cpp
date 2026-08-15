class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total_xor = 0;
        int non_zero_count = 0;
        int n = nums.size();
        
        for (int num : nums) {
            total_xor ^= num;
            if (num != 0) {
                non_zero_count++;
            }
        }
        if (non_zero_count == 0) {
            return 0;
        }
        if (total_xor != 0) {
            return n;
        }
        return n - 1;
    }
};
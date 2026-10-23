class Solution {
public:
    int sortPermutation(vector<int>& nums) {
         int ans = -1;
        bool is_sorted = true;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i) {
                is_sorted = false;
                ans &= nums[i];
            }
        }

        return is_sorted ? 0 : std::max(ans, 0);
    }
};
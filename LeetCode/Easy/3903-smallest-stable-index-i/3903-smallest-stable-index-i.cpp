class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int max_left = INT_MIN;
        int right = n - 1, min_right = nums[n - 1];

        for (int i = 0; i < n; ++i) {
            max_left = std::max(max_left, nums[i]);
            if (right < i) {
                right = n - 1;
                min_right = nums[n - 1];
            }
            while (right > i) {
                if (nums[right] < min_right) min_right = nums[right];
                right--;
            }
            min_right = std::min(min_right, nums[i]); 
            if (max_left - min_right <= k) {
                return i;
            }
        }
        return -1;
    }
};
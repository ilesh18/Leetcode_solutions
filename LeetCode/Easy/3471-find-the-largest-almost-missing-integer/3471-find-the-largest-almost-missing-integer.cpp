class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == n) {
            int max_val = -1;
            for (int x : nums) max_val = max(max_val, x);
            return max_val;
        }
        if (k == 1) {
            int count[51] = {0};
            for (int x : nums) count[x]++;
            int ans = -1;
            for (int x = 0; x <= 50; x++) {
                if (count[x] == 1) ans = x;
            }
            return ans;
        }
        int count[51] = {0};
        for (int x : nums) count[x]++;
        
        int ans = -1;
        if (count[nums[0]] == 1) ans = max(ans, nums[0]);
        if (count[nums[n - 1]] == 1) ans = max(ans, nums[n - 1]);
        return ans;
    }
};

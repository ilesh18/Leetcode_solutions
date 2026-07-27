class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        int max_val = INT_MIN;
        int ans= INT_MIN;
        for(int j=k; j<n;++j){
            max_val = max(max_val, nums[j - k]);
            ans = max(ans, max_val + nums[j]);
        }
        return ans;
        }
};
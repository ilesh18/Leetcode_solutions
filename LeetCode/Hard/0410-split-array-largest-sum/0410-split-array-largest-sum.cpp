class Solution {
public:
    bool isValid(vector<int>& nums, int n, int k, int maxAllowedSum) {
        int subarrays = 1;
        int currentSum = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] > maxAllowedSum) {
                return false;
            }
            if (currentSum + nums[i] <= maxAllowedSum) {
                currentSum += nums[i];
            } else {
                subarrays++;
                currentSum = nums[i];
            } 
        }      
        return subarrays <= k;
    }
     
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        for (int num : nums) {
            left = max(left, num);
            right += num;
        }
        
        int ans = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (isValid(nums, n, k, mid)) {
                ans = mid;      
                right = mid - 1;  
            } else {
                left = mid + 1;  
            }
        }
        
        return ans;
    }
};
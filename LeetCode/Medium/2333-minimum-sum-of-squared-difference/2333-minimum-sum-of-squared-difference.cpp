class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        
        const int MAX_DIFF = 100000;
        vector<long long> diff_count(MAX_DIFF + 1, 0);
        long long total_diff = 0;
        
        for (int i = 0; i < n; ++i) {
            int diff = abs(nums1[i] - nums2[i]);
            diff_count[diff]++;
            total_diff += diff;
        }
        
        if (total_diff <= k) {
            return 0;
        }
        
        for (int d = MAX_DIFF; d > 0; --d) {
            if (diff_count[d] == 0) continue;
            
            long long take = min(diff_count[d], k);
            
            diff_count[d] -= take;
            diff_count[d - 1] += take;
            k -= take;
            
            if (k == 0) break;
        }
        
        long long min_squared_sum = 0;
        for (long long d = 1; d <= MAX_DIFF; ++d) {
            if (diff_count[d] > 0) {
                min_squared_sum += diff_count[d] * d * d;
            }
        }
        
        return min_squared_sum;
    }
};
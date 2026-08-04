class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
            if (nums.empty()) return {};

        int minel = *std::min_element(nums.begin(), nums.end());
        int maxel = *std::max_element(nums.begin(), nums.end());
        vector<bool> exists(maxel - minel + 1, false);
        
        for (int i : nums) {
            exists[i - minel] = true;
        }
        
        std::vector<int> ans;
        for (int i = 0; i < exists.size(); ++i) {
            if (!exists[i]) {
                ans.push_back(i + minel);
            }
        }
        
        return ans;
    }

};
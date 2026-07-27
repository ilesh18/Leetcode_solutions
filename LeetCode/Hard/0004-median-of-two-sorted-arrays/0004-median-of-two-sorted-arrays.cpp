class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        for(int i = 0; i < nums1.size(); i++){
            merged.push_back(nums1[i]);
        }
        for(int j = 0; j < nums2.size(); j++){
            merged.push_back(nums2[j]);
        }
        for(int i = 0; i < merged.size()-1; i++){
            for(int j = 0; j < merged.size()-i-1; j++){
                if(merged[j] > merged[j+1]) {
                    int temp = merged[j];
                    merged[j] = merged[j+1];
                    merged[j+1] = temp;
                }
            }
        }
        int n = merged.size();
        if(n % 2 == 0){
            return (merged[n/2] + merged[n/2 - 1]) / 2.0;
        } else {
            return merged[n/2];
        }
    }
};
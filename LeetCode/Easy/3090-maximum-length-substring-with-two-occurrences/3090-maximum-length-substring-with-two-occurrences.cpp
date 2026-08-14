class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left = 0, max_len = 0;
        int count[26] = {0};
        
        for (int right = 0; right < s.length(); ++right) {
            count[s[right] - 'a']++;
            while (count[s[right] - 'a'] > 2) {
                count[s[left] - 'a']--;
                left++;
            }
            
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};
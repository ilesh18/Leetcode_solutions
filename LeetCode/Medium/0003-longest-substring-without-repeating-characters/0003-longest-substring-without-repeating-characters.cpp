class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int maxCount = 0;

        for(int i = 0; i < s.length(); i++) {

            bool seen[256] = {false};
            int count = 0;

            for(int j = i; j < s.length(); j++) {

                if(seen[s[j]]) {
                    break;
                }

                seen[s[j]] = true;
                count++;

                if(count > maxCount) {
                    maxCount = count;
                }
            }
        }

        return maxCount;
    }
};

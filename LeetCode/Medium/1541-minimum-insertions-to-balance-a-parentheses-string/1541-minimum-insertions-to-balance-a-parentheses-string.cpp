class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;   // Total number of insertions needed
        int open = 0;  // Count of unmatched opening parentheses '('
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                open++;
            } else {
                if (i + 1 < s.length() && s[i + 1] == ')') {
                    i++;
                } else {
                    ans++; 
                }
                if (open > 0) {
                    open--;
                } else {
                    ans++; 
                }
            }
        }
        ans += open * 2;
        
        return ans;
    }
};
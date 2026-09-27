class Solution {
public:
    string reverseParentheses(string s) {
        vector<std::string> st;
        string current = "";
        
        for (char c : s) {
            if (c == '(') {
                st.push_back(current);
                current = "";
            } else if (c == ')') {
                std::reverse(current.begin(), current.end());
                if (!st.empty()) {
                    current = st.back() + current;
                    st.pop_back();
                }
            } else {
                current += c;
            }
        }
        return current;
    }
};
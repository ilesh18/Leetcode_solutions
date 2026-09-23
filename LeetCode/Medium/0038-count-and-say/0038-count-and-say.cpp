class Solution {
public:
    string countAndSay(int n) {
        string current = "1";
        for (int i = 1; i < n; ++i) {
            std::string next_str = "";
            int len = current.length();
            
            for (int j = 0; j < len; ) {
                int count = 0;
                char digit = current[j];
                while (j < len && current[j] == digit) {
                    count++;
                    j++;
                }
                next_str += std::to_string(count) + digit;
            }
            
            current = next_str;
        }
        
        return current;
    }
};
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        queue<string> q{{s}};
        unordered_set<string> visited{s};
        bool found = false;

        auto isValid = [](const string& str) {
            int count = 0;
            for (char c : str) {
                if (c == '(') count++;
                if (c == ')') { if (--count < 0) return false; }
            }
            return count == 0;
        };

        while (!q.empty()) {
            string curr = q.front(); q.pop();
            if (isValid(curr)) { ans.push_back(curr); found = true; }
            if (found) continue;

            for (int i = 0; i < curr.length(); ++i) {
                if (curr[i] != '(' && curr[i] != ')') continue;
                string next = curr.substr(0, i) + curr.substr(i + 1);
                if (visited.insert(next).second) q.push(next);
            }
        }
        return ans;
    }
};
struct Element {
    string str;
    int open;
    int close;
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        stack<Element> stack;
        

        stack.push({"(", 1,0});
        while (!stack.empty()) {
            Element curr = stack.top();
            stack.pop();
            if (curr.str.length() == n * 2) {
                result.push_back(curr.str);
                continue;
            }

            if (curr.close < curr.open){
                stack.push({curr.str + ")", curr.open, curr.close + 1});
            }

            if (curr.open < n) {
                stack.push({curr.str + "(", curr.open + 1, curr.close});                
            }

            
        }

        return result;
    }
};

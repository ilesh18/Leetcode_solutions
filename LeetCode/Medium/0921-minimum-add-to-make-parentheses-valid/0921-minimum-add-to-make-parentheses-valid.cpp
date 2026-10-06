class Solution {
public:
    int minAddToMakeValid(string s) {
        int openCount = 0; 
        int moves = 0;    

        for (char c : s) {
            if (c == '(') {
                openCount++;
            } else {
                if (openCount == 0) {
                    moves++;
                } else {
                    openCount--; 
                }
            }
        }
        return moves + openCount;
    }
};
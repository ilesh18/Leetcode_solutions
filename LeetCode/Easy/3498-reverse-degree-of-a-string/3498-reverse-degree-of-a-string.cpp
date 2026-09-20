class Solution {
public:
    int reverseDegree(string s) {
        int totalDegree = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            int alphabetPos = 26 - (s[i] - 'a');
            int stringPos = i + 1;
            totalDegree += alphabetPos * stringPos;
        }
        
        return totalDegree;
    }
};
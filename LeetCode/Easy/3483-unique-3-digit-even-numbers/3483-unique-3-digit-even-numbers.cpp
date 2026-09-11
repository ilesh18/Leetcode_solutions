class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int count[10] = {0};
        for (int d : digits) {
            count[d]++;
        }
        
        int resultCount = 0;
        for (int i = 100; i <= 998; i += 2) {
            int d1 = i / 100;        
            int d2 = (i / 10) % 10;   
            int d3 = i % 10;       
            int current_req[10] = {0};
            current_req[d1]++;
            current_req[d2]++;
            current_req[d3]++;
            if (count[d1] >= current_req[d1] && 
                count[d2] >= current_req[d2] && 
                count[d3] >= current_req[d3]) {
                resultCount++;
            }
        }
        
        return resultCount;
    }
};
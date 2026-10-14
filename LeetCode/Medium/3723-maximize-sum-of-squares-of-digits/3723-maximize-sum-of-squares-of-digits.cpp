class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) {
            return "";
        }
        
        string result = "";
        result.reserve(num);
        int count_9 = sum / 9;
        int remainder = sum % 9;
        result.append(count_9, '9');
        if (remainder > 0) {
            result.push_back('0' + remainder);
        }
        int current_len = result.length();
        if (current_len < num) {
            result.append(num - current_len, '0');
        }
        
        return result;
    }
};
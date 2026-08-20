class Solution {
public:
    bool isFreqSame(int freq1[], int freq2[]) {
        for(int i = 0; i < 26; i++) {
            if(freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true; 
    }

    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        int freq[26] = {0};
        int windFreq[26] = {0};

        for(int i = 0; i < s1.length(); i++) {
            freq[s1[i] - 'a']++;
            windFreq[s2[i] - 'a']++;
        }

        if(isFreqSame(freq, windFreq)) return true;

        for(int i = s1.length(); i < s2.length(); i++) {
            windFreq[s2[i] - 'a']++;               
            windFreq[s2[i - s1.length()] - 'a']--;    

            if(isFreqSame(freq, windFreq)) return true;
        }

        return false;
    }
};

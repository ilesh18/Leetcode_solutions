class Solution { 
public: 
    bool checkDivisibility(int n) { 
        if (n <= 0) return false;

        int original_n = n;
        int pro = 1; 
        int add = 0; 

        while (n > 0) { 
            int digit = n % 10;
   
            pro *= digit; 
  
            add += digit; 
            n /= 10; 
        } 

        return (original_n % (add + pro) == 0); 
    } 
};

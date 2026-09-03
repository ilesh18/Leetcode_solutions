class Solution {
public:
    int reverse(int x) {
        long long int rem=0;
        long long int num=0;
        int flag=0;
        while(x!=0){
            rem=x%10;

            if(num>INT_MAX/10 || num<INT_MIN/10)
                return 0;

            if(rem != 0 || flag==1){
                num=num*10+rem;
                flag=1;
            }
            x/=10;
        }
        return num;
    }
};
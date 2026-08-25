class Solution {
public:
    int divide(int dividend, int divisor) {
        if( dividend == divisor){
            return 1;
        }
        bool sign = true;
        if( divisor>= 0 && dividend < 0 ) sign = false;
        if( divisor<=0 && dividend > 0) sign = false;
        long  n = abs((long long)dividend);
        long  d = abs((long long)divisor);
        long long quotient = 0;
        while( n >=d){
            int cnt = 0;
            while( n>= ( d<< ( cnt+1))){
                cnt +=1;
            }
            quotient += 1LL<<cnt;
            n-= ( d<<cnt);
        }
        if( quotient == ( 1LL<<31) && sign){
            return INT_MAX;
        }
        if( quotient == ( 1LL<<31) && ! sign){
            return INT_MIN;
        }
        return sign ? quotient : -quotient;
    }
};
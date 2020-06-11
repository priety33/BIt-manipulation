class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};
/*
    If temp=rev⋅10+poptemp = temp=rev⋅10+pop causes overflow, then it must be that rev≥INTMAX/10
    If rev>INTMAX/10, then temp=rev⋅10+pop is guaranteed to overflow.
    If rev==INTMAX/10, then temp=rev⋅10+pop will overflow if and only if pop>7
*/

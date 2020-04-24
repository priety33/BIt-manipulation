/*
1) Find position of Most Significant Bit (MSB) in both numbers.
2) If positions of MSB are different, then result is 0.
3) If positions are same. Let positions be msb_p.
……a) We add 2msb_p to result.
……b) We subtract 2msb_p from x and y,
……c) Repeat steps 1, 2 and 3 for new values of x and y.
*/

class Solution {
public:
    
    int msb_pos(long long a)
    {
        int pos=-1;
        while(a)
        {
            a= a>>1;
            pos++;
        }
        return pos;
    }
    
    int rangeBitwiseAnd(int m, int n) {
        if(m==n) return m;
        long long ans=0;
        int msb1= msb_pos(m);
        int msb2= msb_pos(n);
        while(msb1==msb2)
        {
            msb1= 1<<msb1;
            ans+= msb1;
            m=m-msb1;
            n=n-msb1;
            msb1= msb_pos(m);
            msb2= msb_pos(n);
        }
        return ans;
    }
};

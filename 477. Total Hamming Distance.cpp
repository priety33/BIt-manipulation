/*
For all number a1, a2, a3,..., a(n), if there are p numbers have 0 as LSB (put in set M), and q numbers have 1 for LSB (put in set N).

There are 2 situations:

Situation 1. If the 2 number in a pair both comes from M (or N), the total will get 0.

Situation 2. If the 1 number in a pair comes from M, the other comes from N, the total will get 1.

Since Situation 1 will add NOTHING to the total, we only need to think about Situation 2

How many pairs are there in Situation 2?

We choose 1 number from M (p possibilities), and 1 number from N (q possibilities).

The total possibilities is p × q = pq, which means

    The total Hamming distance will get pq from LSB.

If we remove the LSB of all numbers (right logical shift), the same idea can be used again and again until all numbers becomes zero

2.4 Time complexity

In each loop, we need to visit all numbers in nums to calculate how many numbers has 0 (or 1) as LSB.

If the biggest number in nums[] is K, the total number of loop is [logK] + 1.

So, the total time complexity of this approach is O(n).
*/

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int size = nums.size();
        if(size < 2) return 0;
        int ans = 0;
        int *zeroOne = new int[2];
        while(true)
        {
            int zeroCount = 0;
            zeroOne[0] = 0;
            zeroOne[1] = 0;
            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i] == 0) zeroCount++;
                zeroOne[nums[i] % 2]++;
                nums[i] = nums[i] >> 1;
            }
            ans += zeroOne[0] * zeroOne[1];
            if(zeroCount == nums.size()) return ans;
        }
        return ans;
    }
};

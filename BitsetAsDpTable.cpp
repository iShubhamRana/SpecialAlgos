/*
We can actually use a bitset some times instead of DP table , altough the space complexity remains same , as bitset maybe implmented using an array inside c++ but
the approach really speeds up the code.

explaination:
For eg in ques: https://leetcode.com/problems/partition-equal-subset-sum/
we had to tell the sum achievable.
The normal approach was pretty useful although the optimised approaches have same complexity , there was a new idea behind them.

My idea was for each i , we will check if the sum is achievable , But there can be another approach. For every i we just keep updating the all the sums which are avcievable
. Actually the idea in both the approaches is same but from a diffeent perspective

My DP implementation is this:
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(begin(nums), end(nums), 0), halfSum = totalSum / 2;
        if(totalSum & 1) return false;
        bool dp[halfSum+1]; memset(dp, false, sizeof dp);
        dp[0] = true;                              // 0 sum is always achievable
        for(int num : nums) 
            for(int j = halfSum; j >= num; j--)    // essential to start right to left
                if(dp[j - num])                    // if j - num was previously achievable
                    dp[j] = true;                  // we can add num to it and make j achievable as well
            
        return dp[halfSum];
    }
};

Bitset approach : explaination

/*
Suppose current dp = 1011
This means sums 0, 1 and 3 are possible to achieve.
Let the next number we get: num = 5. 
Now we can achieve (0, 1 & 3) which were already possible and (5, 6, 8) which are new sum after adding 'num=5' to previous sums

1. 'dp << num': This operation will add num to every bit .
                         3 2 1 0                                8 7 6 5 4 3 2 1 0                     
                So, dp = 1 0 1 1 will be transformed to  dp  =  1 0 1 1 0 0 0 0 0   (after 5 shifts to left)
			    Note that new dp now denotes 5, 6, 8 which are the new sums possible.
			    We will combine it with previous sums using '|' operation
				
                      8 7 6 5 4 3 2 1 0
2. 'dp | dp << num' = 1 0 1 1 0 1 0 1 1

And now we have every possible sum after combining new num with previous possible sums.
*/


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(begin(nums), end(nums), 0), halfSum = totalSum / 2;
        if(totalSum & 1) return false;
        bitset<10001> dp(1);       // 0 is always achievable => dp[0] = 1
        for(int num : nums) 
            dp = dp | dp << num;
        return dp[halfSum];
    }
};


*** See we are actually not using a dp table but bit positions to represent which all sums are possible . If the sum was smaller we could have acutally done it using 
  just a number. But seeing this approach is just another level for me .

*/

# 题目大意
给一个数组，从中选出一个连续的子数组，使得它们的和是最大的。

# 分析
动态规划经典问题，用一个一维数组来保存所有的截止到当前下标的子数组的最大和。dp[i]表示从左到右截止到当前位置i的子数组的最大和，初始dp[i] =nums[i]，如果dp[i-1]加上当前的nums[i]比nums[i]大，则更新dp[i] = dp[i-1]+nums[i]，否则不更新。状态转移方程为：
dp[i] = max(dp[i-1]+nums[i],num[i])。
终于有一道1a的题目了。哭~~~

#实现
```
int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp[n+1];
        int ans = nums[0];
        for(int i = 0;i<n;i++){
            dp[i] = nums[i];
            if(i !=0){
                dp[i] = max(dp[i-1]+nums[i],nums[i]);
            }
            if(dp[i] > ans)
                ans = dp[i];
        }
        return ans;
    }
```
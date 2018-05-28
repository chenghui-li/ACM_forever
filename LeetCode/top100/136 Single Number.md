# 题目
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
# 分析
使用按位异或的思想，异或满足相同为0，相异为1。所以数组中的所有数字按位异或运算后的结果就是那个只出现一次的数字。

# 实现
```
int singleNumber(vector<int>& nums) {
        
        int temp = nums[0];
        for(int i = 1;i<nums.size();i++)
            temp = temp^nums[i];
        return temp;
    }
```
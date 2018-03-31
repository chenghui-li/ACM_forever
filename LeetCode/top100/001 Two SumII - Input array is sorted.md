# 题目
给一个从小到大排好序的数组和一个目标值，从中找出两个数使得其和等于目标值。返回下标

# 分析
可以和Two Sum那个题目一样使用hash映射，也可以使用类似二分查找的思路。复杂度都是O(n)。

这里主要说下二分的思路：设两个指针i指向数组头和j指向尾，算出当前i和j位置的元素和，如果大于目标值，则j前移一位，如果小于目标值，i后移一位。
# 实现
```
vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size()-1;
        vector<int> ans;
        while(1){
            if(numbers[i]+numbers[j] > target)
                --j;
            else if(numbers[i]+numbers[j] < target)
                ++i;
            else{
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
        }
        return ans;
    }
```
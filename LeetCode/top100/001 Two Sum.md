# 题目
给一个数组，和一个目标值。从数组中找两个数使得他两的值的和等于目标值。返回这两个数的下标。

# 分析
O(n^2)的想法就不说了。说下O(n)的想法。
使用hash映射，从左向右遍历数组，设一个临时变量NumToFind，它等于目标值减去当前位置的值，表示对于当前位置的值，需要凑成目标值的另一个值。如果这个值在hash表中，则说明前面有过这个值，将下标返回即可，如果没有则将当前位置的值插入到hash表中。
O(n)的复杂度完全是沾了hash的O(1)查找的光O(∩\_∩)O

#实现
```
vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int,int> hash;
        for(int i = 0;i<nums.size();i++){
            int numToFind = target - nums[i];
            if(hash.find(numToFind) != hash.end()){
                ans.push_back(i);
                ans.push_back(hash[numToFind]);
                break;
            }
            hash[nums[i]] = i;
        }
        return ans;
}
```
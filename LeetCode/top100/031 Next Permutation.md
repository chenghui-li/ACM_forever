# 题目大意
给一个序列，求这个序列的排列的下一个序列，如果该序列是降序的，则直接翻转输出
# 分析
讨论区看到的，是一种奇妙的算法，步骤如下：
1. 遍历该序列，找到最后一个满足nums[k] < nums[k+1]的下标k，如果这个下标不存在，则说明序列是降序排列，直接翻转。
2. 下标l从k+1位置开始，找到最后一个满足nums[l]>nums[k]的l。
3. 交换nums[k]和nums[l]。
4. 将nums[k+1]到nums.end()翻转。

# 实现
```
void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int k = -1,l = -1;
        for(int i = 0;i<len-1;i++){
            if(nums[i]<nums[i+1])
                k = i;
        }
        if(k == -1){
            reverse(nums.begin(),nums.end());
        }
        else{
        	for(int i = k+1;i<len;i++){
        	    if(nums[i]>nums[k]){
       	         l = i;
      		    }
      	  	}
       	    swap(nums[k],nums[l]);
       	    vector<int>::iterator ite = nums.begin()+k+1;
       	    reverse(ite,nums.end());
        }
    }
```
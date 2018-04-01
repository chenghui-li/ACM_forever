# 题目
给一个可能翻转过的数组，原来是从小到大有序。现在要求从中找出最小的元素。
# 分析
二分的思想，头指针尾指针指向第一个后最后一个元素。去中间位置mid的元素，如果mid处的元素大于最后一个元素，则说明最小的元素在mid的后面，头指针后移mid+1。否则说明最小的元素在mid前面，尾指针前移到mid。

# 实现（左闭右开）
```
int findMin(vector<int>& nums) {
	int len = nums.size();
	int first = 0;
	int second = len-1;
	while(first < second){
		int mid = (first + second)/2;
		if(nums[mid] > nums[second])
			first = mid+1;
		else
			second = mid;
	}
	return nums[first];
}
```
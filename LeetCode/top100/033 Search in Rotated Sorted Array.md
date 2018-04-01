# 题目
给一个数组，其原来是从小到大有序的，但是现在将前面的一部分截取放到后面，比如：3 4 5 6 1 2。现在给一个目标数target，要求从数组中找到该数并返回下标，如果没有找到则返回-1。

# 分析
从前向后遍历肯定是可以的，O(n)的复杂度，但是可以用二分更快，可以O(logn)
首先头指针尾依次指向第一个元素和最后一个元素，找他们两中间位置的指针mid
如果该位置的指针的数字大于尾指针的数字，则说明翻转了小于一半个数的数字，再来判定target的值和mid处的值，尾指针三者的关系，如果target大于mid处的值，或者小于等于尾指针处的值，则说明target在数组的后半部分，头指针前移到mid+1处，否则说明在前半部分，尾指针前移到mid处。

如果mid处的值小于尾指针的值，则说明翻转的个数大于一半，此时如果target处的值大于mid处的值并且还不大于尾指针位置的值，则说明在后半部分，否则在前半部分。

# 实现
```
int search(vector<int>& nums, int target) {
	int len = nums.size();
	int first = 0;
	int second = len-1;
	while(first<second){    //左闭右开
		int mid = (first+second)/2;
		if(nums[mid] > nums[second]){
			if(target > nums[mid] || target <= nums[second])
				first = mid+1;
			else
				second = mid;
		}
		else{
			if(target >nums[mid] && target <=nums[second]){
				first = mid+1;
			}
			else
				second = mid;
		}
	}
	if(len == 0 || (first == second) && target != nums[first])
		return -1;
	return first;
}
```
# 题目
给定一个非负整数组成的非空数组，给整数加一。
可以假设整数不包含任何前导零，除了数字0本身。
最高位数字存放在列表的首位。
# 分析
可以按照数学思维从后向前依次运算，涉及到可能最后的结果比原来的长，比如[9,9]->[1,0,0]，所以可以先将原数组翻转，然后从前向后遍历，这样可以在后面push_back，再将结果翻转就是最后的答案，这是时间换空间。

也可以空间换时间，重新申请一个vector，将原数组从后向前遍历，一次插入新数组，将最后结果翻转就是答案。

看了下别人的代码，思路是：将原数组从后向前遍历，如果某个位置的数小于9，则直接加一就可以退出了，否则将其变成0。最后将第一个数置1，最后面push_back(0)。
# 实现
```
vector<int> plusOne(vector<int>& digits) {
        int temp = 0;
        reverse(digits.begin(),digits.end());
        int len = digits.size();
        for(int i = 0;i<len;i++){
            if(i == 0){
                digits[i] += 1;
                
            }
            digits[i] = digits[i]+temp;
            if(digits[i] >9){
                temp = 1;
                digits[i] = digits[i]%10;
            }else
                temp = 0;
        }
        if(temp)
            digits.push_back(temp);
        reverse(digits.begin(),digits.end());
        return digits;
    }
```
法二
```
vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        for(int i = len;i--;digits[i] = 0){
            if(digits[i]++ < 9){
                return digits;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
```
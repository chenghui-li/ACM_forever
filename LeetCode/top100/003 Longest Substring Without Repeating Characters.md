# 题目
给一个字符串，求其中的最长不重复的子串的长度

# 分析
第一遍做的时候用的O(n^2)的复杂度。naive！！！后来看了大牛的O(n)的方法，学习了。
设一个start标志，表示最长不重复子串的起始位置。然后映射一下每个字符最近出现的位置，如果已经出现过了，则更新start到出现过的位置之后一个位置，每次更新，求一下当前最大的长度，应为当前位置减起点位置加1。

# 实现
```
int lengthOfLongestSubstring(string s) {
        int num[200];
        memset(num,-1,sizeof(num));
        int maxlen = 0;
        int start = 0;
        for(int i = 0;i<s.size();i++){
            if(num[s[i]] >= start)
                start = num[s[i]]+1;
            num[s[i]] = i;
            maxlen = max(maxlen,i-start+1);
        }
        return maxlen;
    }
```
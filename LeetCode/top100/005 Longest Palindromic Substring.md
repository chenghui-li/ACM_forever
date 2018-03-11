# 题目大意
给一个字符串，找出其中的最长回文子串
# 分析
可以再声明一个字符串，用于存放指定字符串的逆序，用KMP算法比较两个字符串，记录起点以及最大匹配长度。

也可以使用区间动态规划，设`dp[j][k]`表示起点为j，终点为k的字符串是不是回文串，是则用1表示，不是用0表示。用i枚举字符串长度，状态转移方程为：
```
k = j+i;
dp[j][k] = (s[j] == s[k])&&(i<=2 || dp[j+1][k-1])
```
记录每次遍历的最长回文子串
# 实现
```
string longestPalindrome(string s) {
        int len = s.size();
        bool dp[1002][1002];
        string maxS ;   //最长回文子串
        int maxlen = 0;
        memset(dp,0,sizeof(dp));
        for(int i = 0;i<len;i++){    //长度枚举
            for(int j = 0;j<len-i;j++){    //起点枚举
                int k = j+i;    //终点
                if(s[j] == s[k] && (i<=2 || dp[j+1][k-1])){
                    dp[j][k] = true;
                    if(k-j+1>maxlen){
                        maxlen = k-j+1;
                        maxS = s.substr(j,maxlen);
                    }
                }
            }
        }
        return maxS;
    }
```
# 题目大意
给一个字符串包含'(', ')', '{', '}', '[' 和 ']'。判断是不是括号匹配。像[]{}(),{([])},([]{})都属于匹配，像[(]),[都不属于。

# 分析
可以用一个栈来保存所有的左括号，遇从左遍历字符串，遇到左括号就压栈，否则，如果栈空则不匹配，不空则取栈顶元素并出栈，判断与当前右括号是否匹配。可以说只要想到用栈就非常简单了，如果想不到，那就有点gg。

# 实现
```
bool AreYouOk(string s){
	if(s.size()%2)
		return false;
	stack<char> st;
	for(int i = 0;i<s.size();i++){
		if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
        }
        else{
        	if(st.empty())
        		return false;
        	char p = st.top();
        	st.pop();
        	if(s[i] == ')' && p != '(' || s[i] == ']' && p!='[' || s[i] == '}' && p != '{')
                return false;
        }
	}
	retur st.empty();
}
```
# 题目
给一个都是数字的字符串，要求输出它们对应电话按键的英文组合。比如
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

# 分析
使用队列，将每个按键对应的英文存入vector，然后遍历输入的数字，将队列首元素弹出，将其遍历到的数字对应的英文组合，然后存入队列。其实
# 实现

```
vector<string> letterCombinations(string digits) {
        vector<string > myv[12];
        myv[2].push_back("a");
        myv[2].push_back("b");
        myv[2].push_back("c");
        myv[3].push_back("d");
        myv[3].push_back("e");
        myv[3].push_back("f");
        myv[4].push_back("g");
        myv[4].push_back("h");
        myv[4].push_back("i");
        myv[5].push_back("j");
        myv[5].push_back("k");
        myv[5].push_back("l");
        myv[6].push_back("m");
        myv[6].push_back("n");
        myv[6].push_back("o");
        myv[7].push_back("p");
        myv[7].push_back("q");
        myv[7].push_back("r");
        myv[7].push_back("s");
        myv[8].push_back("t");
        myv[8].push_back("u");
        myv[8].push_back("v");
        myv[9].push_back("w");
        myv[9].push_back("x");
        myv[9].push_back("y");
        myv[9].push_back("z");
        myv[0].push_back(" ");
        queue<string> myq;
        vector<string> ans;
        int num = digits[0] - '0';
        if(num <0 || num >9){
            return ans;
        }
        for(int i = 0;i<myv[num].size();i++){
            myq.push(myv[num][i]);
        }
        for(int i =1;i< digits.size();i++){
            int num = digits[i] - '0';
            int all = myq.size();
            for(int j = 0;j<all;j++){
                string get = myq.front();
                myq.pop();
                for(int k = 0;k<myv[num].size();k++){
                    string get2 = get+myv[num][k];
                    myq.push(get2);
                }
            }
        }
        while(!myq.empty()){
            ans.push_back(myq.front());
            myq.pop();
        }
        return ans;
    }
```
其实不用我这样添加vector的！\-\_\-\|\|。
直接`vector<string> myv = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}`
但是这里就有一个坑点，从myv中取出的每个元素都是string，但是从这个元素里遍历的时候，每个取出的都是char。因为queue声明为string类型的，如果直接添加会编译错误，所以要用一个零时空string相加以下，类型就转换为string了
```
vector<string> letterCombinations(string digits) {
        vector<string> myv = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        queue<string> myq;
        vector<string> ans;
        
        
        int num = digits[0] - '0';
        if(num <0 || num >9){
            return ans;
        }
        string s;
        string ms= myv[num];
        s = "";
        for(int i = 0;i<ms.size();i++){
            string s = "";   //用于将char转为string
            s+=ms[i];
            myq.push(s);
        }
        for(int i =1;i< digits.size();i++){
            int num = digits[i] - '0';
            ms = myv[num];
            int all = myq.size();
            for(int j = 0;j<all;j++){
                string get = myq.front();
                myq.pop();
                for(int k = 0;k<ms.size();k++){
                    string get2 = get+ms[k];
                    myq.push(get2);
                }
            }
        }
        while(!myq.empty()){
            ans.push_back(myq.front());
            myq.pop();
        }
        return ans;
    }
```
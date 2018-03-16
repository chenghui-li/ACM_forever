# 题目
给一棵二叉树，求这课树的最大深度。

# 分析
发现我这个脑子有点问题丫。。。居然想的是深度优先搜索，而且发现我想不到递归。。。汗

可以用递归的方法，也可以用迭代，递归直接返回左子树和右子树的最大深度+1即可，迭代则进行层序遍历，最后维护的level就是最大深度。

# 实现
```
//递归。这也太简单了哇........................
int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
}
```

```
//迭代
int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        queue<TreeNode *>q;
        q.push(root);
        int level = 0;      //层数
        int evernum = 1;    //记录当前层剩余结点个数
        int nextnum = 0;    //记录下一层的几点个数
        while(!q.empty()){
            TreeNode *work = q.front();
            q.pop();
            if(work->left){
                q.push(work->left);
                nextnum++;
            }
                
            if(work->right){
                q.push(work->right);
                nextnum++;
            }
            if(--evernum == 0){
                level++;
                evernum = nextnum;
                nextnum = 0;
            }
            
                
        }
        return level;
    }
```
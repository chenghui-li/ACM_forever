# 题目
给一棵二叉树，求这棵树是不是镜像对称的。

# 分析
我一开始想的设两个指针，然后深度优先搜索，然后，就想不下去了。。。
google后，学习下大佬们的想法
设定两个指针，分别指向根的左右结点，如果其中一个为空，另一个不空，则返回false。否则，判断两个结点的值是否相等，不相等返回false。然后继续判断左节点的左孩子和右节点的右孩子，以及左节点的右孩子和右节点的左孩子。
可以递归，也可以迭代。

# 实现
```
//迭代
bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> myq1;
        queue<TreeNode*> myq2;
        if(root == nullptr)
            return true;
        TreeNode *node1 = nullptr;
        TreeNode *node2 = nullptr;
        myq1.push(root->left);
        myq2.push(root->right);
        while(!myq1.empty() && !myq2.empty()){
            node1 = myq1.front();
            node2 = myq2.front();
            myq1.pop();
            myq2.pop();
            if(node1 && !node2 || !node1 && node2)
                return false;
            
            if(node1 && node2){
                if(node1->val != node2->val)
                     return false;
                 myq1.push(node1->left);
                 myq2.push(node2->right);
                 myq1.push(node1->right);
                 myq2.push(node2->left);
            }
           
        }
        return true;
}
```

```
//递归
	bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        return isSymmetric(root->left,root->right);
    }
    bool isSymmetric(TreeNode* left,TreeNode *right){
        if(left && !right || !left && right )
            return false;
        if(!left && !right)
            return true;
        if(left->val != right ->val)
            return false;
        return isSymmetric(left->left,right->right) && isSymmetric(left->right,right->left);
    }

```
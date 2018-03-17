# 题目大意
给一个有k个有序链表的vector，请将这k个链表从小到大排成一个链表。

# 分析
由于前面的将两个链表合并的题目的阴影，马上想到类似的方法，但是，就想不下去了。。。

解：用优先队列啊亲，将每个链表的第一个结点都加入到优先队列中，然后就是队列的判空循环了，由于每次都是弹出最小的，所以只需要把最小的结点的下一个节点添加到队列中就可以了。
注意优先队列的自定义优先级的写法！
# 实现

```
struct cmp{
    bool operator()(ListNode *a,ListNode *b){
        return a->val > b->val;
    }
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return nullptr;
        }
        int len = lists.size();
        ListNode *head,*cur,*curne;
        head = cur = curne = nullptr;
        priority_queue<ListNode *,vector<ListNode *>, cmp > pq;
        for(int i = 0;i<len;i++){
            if(lists[i])
               pq.push(lists[i]);
        }
        if(!pq.empty()){
            head = pq.top();
            pq.pop();
            if(head->next){
                pq.push(head->next);
            }
            cur = head;
        }
        while(!pq.empty()){
            cur->next = pq.top();
            pq.pop();
            cur = cur->next;
            if(cur->next)
                pq.push(cur->next);
        }
        return head;
    }
```	
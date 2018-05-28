# 题目
Given a linked list, determine if it has a cycle in it.
# 分析
使用快慢指针，一个一次移动两步，一个一次移动一步，如果最后它们相遇，则说明有环，否则无环。
# 实现
```
bool hasCycle(ListNode *head) {
        if(head == nullptr)
            return false;
        ListNode *fi,*se;
        fi = se = head;
        while(fi != nullptr && se != nullptr && se->next != nullptr){
            fi = fi->next;
            se = se->next->next;
            if(fi == se)
                return true;
        }
        return false;
    }
```
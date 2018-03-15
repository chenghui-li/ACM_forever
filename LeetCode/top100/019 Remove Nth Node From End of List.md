# 题目
给一个链表和一个整数n，要求删除倒数第n个结点后，输出该链表
# 分析
和剑指offer上的一个题很像，书上是返回倒数第n个结点。这个是删除后输出新链表。
思路一样，设两个指针指向head结点，让第一个指针先移动，并同时用一个整数计数这是第几个结点，当计数器等于n时，说明此时second指针指向的就是倒数第n个结点，当计数器大于n时，second也向后移动，直到第一个指针指向最后一个结点时，second指向的是要删除的结点。注意移动时应该记录一下second 前面的一个结点，用于最后的删除。
**注意坑点：**
1. 只有一个结点时，直接返回nullptr
2. n比链表长度大时，不删除，直接返回head

# 实现
```
ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr || n <= 0)
            return nullptr;
        ListNode *first,*second;
        first = second = head;
        ListNode *secondpre = nullptr;
        int nth = 1;
        while(first->next != nullptr){
            first = first->next;
            nth++;
            if(nth > n){
                secondpre = second;
                second = second->next;
                
            }
        }
        if(nth < n){
            return head;
        }
        if(secondpre == nullptr){   //删除头结点
            head = head->next;
        }else{
            secondpre->next = second->next;
            free(second);
        }
        return head;
    }
```
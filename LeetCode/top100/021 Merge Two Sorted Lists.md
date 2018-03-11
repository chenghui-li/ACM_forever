# 题目大意
给两个从小到大排好序的链表，要求将两个链表从小到大归并成一个链表

# 分析
第一反应，创建一个新链表，将每个节点从小到大插入。naive！！！直接将两个链表的节点连起来就好了！！！空间复杂度只有O(1)。
还有就是new的使用不太熟练，太菜啊啊啊啊。

# 实现
```
struct ListNode{
	int val;
	struct ListNode *next;
	ListNode(int x):val(x),next(nullptr){}
};

ListNode *MergeList(ListNode *l1,ListNode *l2){
	if(l1 == nullptr && l2 == nullptr){
		return nullptr;
	}
	ListNode *head = new ListNode(0);
	ListNode *ans = head;
	ListNode *p1 = l1,p2 = l2;
	while(p1 != nullptr &&  p2!=nullptr){
		if(p1->val <=p2->val){
			ans ->next - p1;
			p1 = p1->next;
		}
		else{
			ans ->next = p2;
			p2 = p2->next
		}
		ans = ans ->next;
	}
	while(p1 != nullptr){
		ans ->next = p1;
		p1 = p1->next;
		ans = ans ->next;
	}
	while(p2 != nullptr){
		ans ->next = p2;
		p2 = p2->next;
		ans = ans ->next;
	}
	return head ->next;
}
```
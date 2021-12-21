#include <iostream>
#include <map>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* init(int a[]) {
	ListNode *n = new ListNode(a[0]);
	n->next = new ListNode(a[1]);
	n->next->next = new ListNode(a[2]);
	return n;
}

int main()
{
	int a1[] = {2, 4, 3};
	int a2[] = {5, 6, 4};
	ListNode *l1, *l2;
	l1 = init(a1);
	l2 = init(a2);

	ListNode *l1_curr = l1;
	ListNode *l2_curr = l2;
	ListNode *ans = new ListNode();
	ListNode *ans_curr = ans;

	int sum = 0;
	while (l1_curr != nullptr && l2_curr != nullptr) {
		sum = l1_curr->val + l2_curr->val;
		ans_curr->val += sum % 10;

		if ((l1_curr->next != nullptr && l2_curr->next != nullptr) || sum / 10 == 1)
		ans_curr->next = new ListNode(sum/10);

		ans_curr = ans_curr->next;
		l1_curr = l1_curr->next;
		l2_curr = l2_curr->next;
	}

	cout << ans->val << " " << ans->next->val << " " << ans->next->next->val;
}

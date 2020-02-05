#if 0
struct ListNode {
	*int val;
	*struct ListNode* next;
	*ListNode(int x) :
		*val(x), next(NULL) {
		*
	}
	*
};
*/
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		std::stack<int>node;
		vector<int>outnode;
		while (head != NULL)
		{
			node.push(head->val);
			head = head->next;
		}
		while (!node.empty())
		{
			outnode.push_back(node.top());
			node.pop();
		}
		return outnode;
	}
};
#endif
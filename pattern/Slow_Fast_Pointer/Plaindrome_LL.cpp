
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (head->next == nullptr)
        {
            return true;
        }

        // vector<int> ans;
        // ListNode* temp = head;
        // while (temp) {
        //     ans.push_back(temp->val);
        //     temp = temp->next;
        // }
        // int i = 0;
        // int j = ans.size() - 1;
        // while (i <= j) {
        //     if (ans[i] != ans[j]) {
        //         return false;
        //     }
        //     i++;
        //     j--;
        // }
        // return true;

        ListNode *fast = head;
        ListNode *slow = head;

        // 1. Find middle
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse the second half of the linked list
        ListNode *prev = nullptr;
        ListNode *curr = slow;
        while (curr)
        {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // 3. Compare the halves
        ListNode *temp = head;
        while (prev)
        {
            if (temp->val != prev->val)
            {
                return false;
            }
            temp = temp->next;
            prev = prev->next;
        }

        return true;
    }
};
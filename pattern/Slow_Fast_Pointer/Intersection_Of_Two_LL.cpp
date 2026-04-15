
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *A = headA;
        ListNode *B = headB;
        while (A->next && B->next)
        {
            if (A == B)
            {
                return A;
            }
            A = A->next;
            B = B->next;
        }
        if (A->next == nullptr)
        {
            int blen = 0;
            while (B->next)
            {
                blen++;
                B = B->next;
            }
            while (blen--)
            {
                headB = headB->next;
            }
        }
        if (B->next == nullptr)
        {
            int alen = 0;
            while (A->next)
            {
                alen++;
                A = A->next;
            }
            while (alen--)
            {
                headA = headA->next;
            }
        }
        A = headA;
        B = headB;
        while (A != B)
        {
            A = A->next;
            B = B->next;
        }
        return A;
    }
};
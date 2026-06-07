class Solution {
public:
    int helper(ListNode* l1, ListNode* l2){
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int carry = 0;
        ListNode* prev = nullptr;

        while(t1 != nullptr && t2 != nullptr){
            t1->val = t1->val + t2->val + carry;

            if(t1->val < 10){
                carry = 0;
            }
            else{
                carry = 1;
                t1->val = t1->val - 10;
            }

            prev = t1;
            t1 = t1->next;
            t2 = t2->next;
        }

        if(t1 != nullptr){
            while(t1 != nullptr){
                t1->val = t1->val + carry;

                if(t1->val < 10){
                    carry = 0;
                }
                else{
                    carry = 1;
                    t1->val = t1->val - 10;
                }

                prev = t1;
                t1 = t1->next;
            }
        }

        if(t2 != nullptr){
            prev->next = t2;

            while(t2 != nullptr){
                t2->val = t2->val + carry;

                if(t2->val < 10){
                    carry = 0;
                }
                else{
                    carry = 1;
                    t2->val = t2->val - 10;
                }

                prev = t2;
                t2 = t2->next;
            }
        }

        return carry;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = helper(l1, l2);

        if(carry == 1){
            ListNode* t = l1;
            while(t->next != nullptr){
                t = t->next;
            }
            t->next = new ListNode(1);
        }

        return l1;
    }
};
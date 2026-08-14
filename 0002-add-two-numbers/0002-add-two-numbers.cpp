class Solution {
    public: 
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
        {
            ListNode* x1 = l1;
            ListNode* x2 = l2;
            ListNode* dummy = new ListNode();
            ListNode* curr = dummy;
            int mem = 0;
            while(x1!=nullptr || x2!=nullptr || mem!=0)
            {
                int x = (x1 != nullptr) ? x1->val : 0;
                int y = (x2 != nullptr) ? x2->val : 0;
                
                int sum = mem + x + y;
                mem = sum / 10; // Cập nhật biến nhớ cho lượt sau
                
                // Tạo nút mới lưu chữ số ở hàng hiện tại (sum % 10)
                curr->next = new ListNode(sum % 10);
                curr = curr->next;
                
                // Dịch chuyển con trỏ l1 và l2 nếu chưa tới cuối
                if (x1 != nullptr) x1 = x1->next;
                if (x2 != nullptr) x2 = x2->next;
            }
            ListNode* head = dummy->next;
            delete dummy;
            return head;
        } 
    };
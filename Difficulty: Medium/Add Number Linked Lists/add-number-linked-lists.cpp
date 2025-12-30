class Solution {
public:
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    Node* addTwoLists(Node* head1, Node* head2) {
        head1 = reverse(head1);
        head2 = reverse(head2);

        int carry = 0;
        Node* dummy = new Node(0);
        Node* tail = dummy;

        while (head1 || head2 || carry) {
            int sum = carry;
            if (head1) {
                sum += head1->data;
                head1 = head1->next;
            }
            if (head2) {
                sum += head2->data;
                head2 = head2->next;
            }
            carry = sum / 10;
            tail->next = new Node(sum % 10);
            tail = tail->next;
        }

        Node* result = reverse(dummy->next);

        while (result && result->data == 0 && result->next)
            result = result->next;

        return result;
    }
};

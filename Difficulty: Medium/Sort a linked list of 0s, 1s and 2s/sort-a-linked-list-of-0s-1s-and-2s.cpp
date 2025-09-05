class Solution {
  public:
    Node* segregate(Node* head) {
        Node* zeroHead = new Node(0);
        Node* oneHead = new Node(0);
        Node* twoHead = new Node(0);

        Node *zero = zeroHead, *one = oneHead, *two = twoHead;
        Node* curr = head;

        while (curr != nullptr) {
            if (curr->data == 0) {
                zero->next = curr;
                zero = zero->next;
            } else if (curr->data == 1) {
                one->next = curr;
                one = one->next;
            } else {
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }

        zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
        one->next = twoHead->next;
        two->next = nullptr;

        Node* newHead = zeroHead->next;
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        return newHead;
    }
};
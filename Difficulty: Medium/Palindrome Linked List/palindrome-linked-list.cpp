class Solution {
  public:
    Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        while (curr != NULL) {
            Node* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    bool isPalindrome(Node *head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* secondHalf = reverseList(slow->next);
        Node* firstHalf = head;
        Node* tempSecond = secondHalf;

        while (tempSecond != NULL) {
            if (firstHalf->data != tempSecond->data) {
                return false;
            }
            firstHalf = firstHalf->next;
            tempSecond = tempSecond->next;
        }

        return true;
    }
};
/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int helper(Node* slow){
        Node* t = slow->next;
        int count = 1;
        while(t != slow){
            count++;
            t = t->next;
        }
        return count;
    }
    int lengthOfLoop(Node *head) {
        Node *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return helper(slow);
        }
        return 0;
    }
};
//GFG POTD solution for 06 September
//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
         int len = getLength(head);
        Node* origH = nullptr;
        Node* origT = nullptr;
        Node* tmpH = nullptr;
        Node* tmpT = nullptr;
        Node* curr = head;

        while (len > 0) {
            int j = k;
            j = std::min(j, len);
            while (j > 0) {
                Node* nex = curr->next;
                if (tmpH == nullptr) {
                    tmpH = curr;
                    tmpT = curr;
                } else {
                    curr->next = tmpH;
                    tmpH = curr;
                }
                curr = nex;
                j--;
                len--;
            }

            if (origH == nullptr) {
                origH = tmpH;
                origT = tmpT;
            } else {
                origT->next = tmpH;
                origT = tmpT;
            }

            tmpH = nullptr;
            tmpT = nullptr;
        }

        if (origT != nullptr) {
            origT->next = nullptr;
        }

        return origH;
    }

    int getLength(Node* head) {
        int len = 0;
        while (head != nullptr) {
            len++;
            head = head->next;
        }
        return len;
    }
};


//{ Driver Code Starts.

/* Driver program to test above function*/
int main(void) {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends
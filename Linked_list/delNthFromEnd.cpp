#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// remove nth node from end
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* slow = head;
    ListNode* fast = head;

    // move fast n steps ahead
    for(int i = 0; i < n; i++) {
        fast = fast->next;
    }

    // if we need to delete head
    if(fast == NULL) {
        return head->next;
    }

    // move both pointers
    while(fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // delete node
    slow->next = slow->next->next;

    return head;
}

// helper: create linked list
ListNode* createList(vector<int>& arr) {
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;

    for(int i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }

    return head;
}

// helper: print linked list
void printList(ListNode* head) {
    ListNode* curr = head;
    while(curr != NULL) {
        cout << curr->val << " -> ";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

// main function
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = 2;

    ListNode* head = createList(arr);

    cout << "Original List:" << endl;
    printList(head);

    head = removeNthFromEnd(head, n);

    cout << "After Removing Nth Node From End:" << endl;
    printList(head);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int data;
    ListNode* next;

    ListNode(int d){
        this ->data = d;
        this ->next = NULL;
    }

};

void reorderList(ListNode* head) {
    if (head == NULL || head->next == NULL) return;

    //Find middle
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    //now slow point to middle, so we have to reverse after the mid which is slow->next

    //Reverse second half
    ListNode* curr = slow->next;
    ListNode* prev = NULL;
    while (curr != NULL) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    //prev is the LL which is reversed

    // Merge
    ListNode* first = head;
    slow->next = NULL; //to break the list in two LL
    ListNode* second = prev;

    while (second != NULL) {
        //store next nodes of each LL
        ListNode* next1 = first->next;
        ListNode* next2 = second->next;

        first->next = second;   // attach from second list
        second->next = next1;   // reconnect back to first

        //Move pointers forward
        first = next1;
        second = next2;
    }
}

// Print list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List:\n";
    printList(head);

    reorderList(head);

    cout << "Reordered List:\n";
    printList(head);

    return 0;
}

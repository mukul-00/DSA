#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
   
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
};

// //Approach 1: Using Length (Brute Force)

// int getLength(Node* head){
//     int len = 0;
//     while(head != NULL){
//         len++;
//         head = head->next;
//     }
//     return len;
// }

// Node *findMiddle(Node *head) {
    
//     int len = getLength(head);
//     int ans = len / 2;

//     Node* temp = head;
//     int cnt = 0;

//     while(cnt < ans){
//         temp = temp->next;
//         cnt++;
//     }

//     return temp;
// }
//--------------------------------------------------

//Approach 2: Fast & Slow Pointer (Optimal)
Node* getMiddle(Node* head){

    // if node is empty or have 1 node
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* slow = head;           // ek baar aage badega
    Node* fast = head->next;     // 2 baar badega aage

    while(fast != NULL){
        fast = fast->next;

        if(fast != NULL)
            fast = fast->next;

        slow = slow->next;
    }

    return slow;
}

Node *findMiddle(Node *head) {
    return getMiddle(head);
}


int main() {

    // creating linked list: 10 -> 20 -> 30 -> 40 -> 50
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    Node* middle = findMiddle(head);

    cout << "Middle element: " << middle->data << endl;

    return 0;
}
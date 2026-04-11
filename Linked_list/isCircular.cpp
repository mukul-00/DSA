#include<bits/stdc++.h>
#include <cstddef>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d ) {
        this-> data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

bool isCircularList(Node* head){
    //empty list
    if(head == NULL){
        return true;
    }

    //non-empty list
    Node* temp = head -> next;
    while(temp != NULL && temp != head){
        temp = temp -> next;
    }
    if(temp == head){
        return true;
    }
    else{
        return false;
    }
}


int main() {
    // --------- Create nodes ----------
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    // --------- Link nodes (circular) ----------
    first->next = second;
    second->next = third;
    third->next = first;   // makes it circular

    // --------- Test ----------
    if(isCircularList(first)) {
        cout << "List is Circular" << endl;
    } else {
        cout << "List is NOT Circular" << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int x){
        this -> data = x;
        this -> next = NULL;
    }
};

Node* KReverse(Node* head, int k){

    // base case
    if(head == NULL){
        return NULL;
    }

    // step 1 : reverse first k Nodes
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    int count = 0;

    while(curr != NULL && count < k){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // step 2 : let recursion handle the rest
    if(next != NULL){
        head -> next = KReverse(next, k);
    }

    // step 3 : return a head of reversed list
    return prev;
}
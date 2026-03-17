#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    //constructor
    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }

    //destructor
    ~Node(){
        int value = this -> data;
        if(this -> next != NULL){
            delete next;
            next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }

};

void print(Node* tail){

    if(tail == NULL) return;

    Node* temp = tail -> next; //head

    do{
        cout << temp->data << " ";
        temp = temp->next;
    }
    while(temp != tail->next);

    cout << endl;
}

//insert node of data d after element
void insertNode(Node* &tail, int element, int d){

    //empty list
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode; //for circular l.l
    }
    else{
        // non- empty list
        // assuming element is present in the list
        Node* curr = tail;

        while(curr->data != element){
            curr = curr -> next;
        }
        //element found -> curr
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}

void deleteNode(Node* &tail, int value){

    //empty list
    if(tail == NULL){
        cout << "List is empty, Please check again" << endl;
        return;
    }
    else{
        //Non-empty

        //assuming that value is present in the list
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value){
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = curr -> next;
        if(tail == curr){
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
}

int main(){

    Node* tail = NULL;

    //when list is empty 
    insertNode(tail, 5, 3);
    print(tail);

    deleteNode(tail, 3);
    print(tail);

    return 0;
}






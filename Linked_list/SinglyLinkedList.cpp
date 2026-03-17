//https://chatgpt.com/s/t_69a48f1566ec8191ba1df26e1b7b163f

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next; 

    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    //https://chatgpt.com/s/t_69a596f8b1c481918a7e16f6b20475e5
    //destructor 
    ~Node(){
        int value = this -> data;
        //memory free
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};

void print(Node* &head){
    Node* temp = head;
    
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

// Step1: create node
// Step2: new -> next = head
// Step3: head = new
void insertAtHead(Node* &head, int d){

    // new node create
    Node *temp = new Node(d);
    temp -> next = head;
    head = temp;
}

// Step1: create node
// Step2: tail -> next = new
// Step3: tail = new
void insertAtTail(Node* &tail, int d){

    //new node created
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head, int position, int d){

    if(position == 1){
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < position - 1){
        temp = temp -> next;
        cnt++;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;
}

//https://chatgpt.com/s/t_69a597121ed88191af2f9da88c7032ad
void deleteNode(int position, Node* &head){

    // deleting first or start node
    if(position == 1){
        Node* temp = head;
        head = head -> next;

        //memory free for start node
        temp -> next = NULL;
        delete temp;
    }
    else{
        // deleting any middle node or last node 
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        prev -> next = curr -> next;
        
        curr -> next = NULL;
        delete curr;
    }
}

//-------------------main----------------------
int main(){

    // created a new node
    Node* node1 = new Node(10);
    //cout << node1 -> data << endl;
    //cout << node1 -> next << endl;

    //head pointer ro node1
    Node* head = node1;
    //tail pointer ro node1
    Node* tail = node1;

    cout << "original : " << endl;
    print(head);
    cout << endl;
    // output = 10

    cout << "For insert at head : " << endl ;
    insertAtHead(head, 12);
    print(head);
    insertAtHead(head, 15);
    print(head);
    cout << endl;
    // output = 15 12 10

    cout << "for insert at tail : " << endl;
    insertAtTail(tail, 11);
    print(head);
    insertAtTail(tail, 9);
    print(head);
    cout << endl;
    // output = 15 12 10 11 9

    cout << "Insert elememt at certain position : " << endl;
    insertAtPosition(head, 3, 22);
    print(head);
    cout<<endl;
    // output = 15 12 22 10 11 9

    cout << "Delete element : " << endl;
    deleteNode(1, head);
    print(head);
    cout<<endl;
    //output = memory is free for node with data 15
             //12 22 10 11 9 

    return 0;
}
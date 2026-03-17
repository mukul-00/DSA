//https://chatgpt.com/s/t_69a7ffb784e88191a49a4614415e17ff (explanation)
 
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

// insert node at position
Node* insertAtPosition(Node* tail, int data, int pos) {

    Node* newNode = new Node(data);

    // case 1: empty list
    if(tail == NULL) {

        if(pos != 1) {
            cout << "Invalid position\n";
            return tail;
        }

        //apne hi new node ko circular bna diya
        tail = newNode;
        newNode->next = newNode;
        return tail;
    }

    Node* curr = tail->next; // head

    int count = 1;

    // move to (pos-1)
    while(count < pos - 1) {

        curr = curr->next;
        count++;

        //means pos mili nhi
        if(curr == tail->next) {
            cout << "Invalid position\n";
            return tail;
        }
    }
    // curr ko pos mil gye hai (before the element where it need to be inserted)

    // insert node
    newNode->next = curr->next;
    curr->next = newNode;

    // update last if inserted at end
    if(curr == tail)
        tail = newNode;

    return tail;
}

// print circular linked list
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


int main() {

    Node* tail = NULL;

    tail = insertAtPosition(tail, 10, 1);
    tail = insertAtPosition(tail, 20, 2);
    tail = insertAtPosition(tail, 30, 3);
    tail = insertAtPosition(tail, 40, 4);

    cout << "List: ";
    print(tail);

    cout << "After inserting 25 at position 3:\n";
    tail = insertAtPosition(tail, 25, 3);

    print(tail);

}
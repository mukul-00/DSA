#include <iostream>
using namespace std;

class TwoStack {
	int *arr;
    int top1;
    int top2;
    int size;
public:

    // Constructor: initialize both stacks
    TwoStack(int s) {
        this -> size = s;
        top1 = -1;     // stack 1 starts from left
        top2 = s;      // stack 2 starts from right
        arr = new int[s];
    }
    
    // Push in stack 1 (left to right)
    void push1(int num) {
        if(top2 - top1 > 1 ) {   // check space available
            top1++;
            arr[top1] = num;
        } 
    }

    // Push in stack 2 (right to left)
    void push2(int num) {
         if(top2 - top1 > 1 ) {  // check space available
            top2--;
            arr[top2] = num;
        } 
    }

    // Pop from stack 1
    int pop1() {
		if( top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        return -1;  // underflow
    }

    // Pop from stack 2
    int pop2() {
		if( top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        return -1;  // underflow
    }
};


int main() {

    TwoStack ts(6);

    ts.push1(10);
    ts.push1(20);
    ts.push1(30);

    ts.push2(100);
    ts.push2(200);
    ts.push2(300);

    cout << ts.pop1() << endl;  // 30
    cout << ts.pop2() << endl;  // 300
    cout << ts.pop1() << endl;  // 20
    cout << ts.pop2() << endl;  // 200

    return 0;
}

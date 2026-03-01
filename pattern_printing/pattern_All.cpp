#include <iostream>
using namespace std;

void pattern1(int n){
    for (int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout << "* ";
        }
        cout << endl;
    }
}
void pattern2(int n){
    for (int i = 1; i <= n; i++){
        for(int j = 1; j <= n - i + 1; j++){
            cout << j << " ";
        }
        cout << endl;
    }
}
void pattern7(int n){
    // for rows
    for (int i = 0; i < n; i++){
        // for spaces in patter
        for (int j = 0; j < n - i - 1; j++){
            cout << " ";
        }

        // for stars
        for (int j = 0; j < 2 * i + 1; j++){
            cout << "*";
        }
        // for spaces again in patter (no need for this loop again {just for practice}but in some complex patter it will be handy)
        for (int j = 0; j < n - i - 1; j++){
            cout << " ";
        }
        cout << endl;
    }
}
void pattern8(int n){
    // for rows
    for (int i = 0; i < n; i++){
        // for spaces in patter
        for (int j = 0; j < i; j++){
            cout << " ";
        }

        // for stars
        for (int j = 0; j < 2 * n - (2*i+ 1); j++){
            cout << "*";
        }
        // for spaces again in patter (no need for this loop again {just for practice}but in some complex patter it will be handy)
        for (int j = 0; j < n - i - 1; j++){
            cout << " ";
        }
        cout << endl;
    }
}
void pattern9(int n){
    // for upper half pyramid
    // for rows
    for (int i = 0; i < n; i++){
        //for space 
        for (int j = 0; j < n - i - 1; j++){
            cout << " ";
        }
        // for stars
        for (int j = 0; j < 2*i + 1; j++){
            cout << "*";
        }
        cout << endl;
    }

    // for lower half pyramid
    for (int i = 0; i < n; i++){
        // for spaces 
        for (int j = 0; j < i; j++){
            cout << " ";
        }
        // for stars
        for (int j = 0; j < 2*n-(2*i+1); j++){
            cout << "*";
        }
        cout << endl;
    }
}
void pattern10(int n){
    // for rows (how many line it should be print{ex - 9} upto 2n-1)
    for(int i = 1; i <= 2*n-1; i++){
        // for stars
        if (i > n){
            for(int j = 1; j <= 2*n - i; j++){
                cout << "*";
            }
            cout << endl;
        }
        else{
            for(int j = 1; j <= i; j++){
            cout << "*";
            }
            cout << endl;
        }
    }
}
void pattern11(int n){
    int star = 1;
    for(int i = 0; i<=n; i++){
        if(i % 2 == 0) //this will print 1 if each is even 
            star = 1;
        else
            star = 0;

        for (int j = 0; j <= i; j++){ 
            cout << star;
            star = 1 - star; // this is for reversing the 0 or 1 in columns
        }
        cout << endl;
    }
}
void pattern12(int n){
    for(int i = 1; i <= n; i++){
        //numbers
        for(int j = 1; j<=i; j++){
            cout << j;
        }

        //spaces
        for (int j = 1; j <= 2*(n - i); j++){
            cout << " ";
        }

        //numbers
        for(int j = i; j >= 1; j--){
            cout << j;
        }
        cout << endl;
    }
}
void pattern13(int n){
    int num = 1;
    for (int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout << num << " ";
            num = num + 1;
        }
        cout << endl;
    }
}
void pattern14(int n){
    for(int i = 0; i < n; i++){
        for (char ch = 'A'; ch <= 'A' + i; ch++ ){
            cout << ch << " ";
        }
        cout << endl;
    }
}
void pattern15(int n){
    for (int i = 0; i < n; i++){
        for (char ch = 'A'; ch <= 'A' + (n - i - 1); ch ++){
            cout << ch << " ";
        }
        cout << endl;
    }
}
void pattern16 (int n){
    for (int i = 0; i <= n; i++){
        char ch = 'A' + i;
        for(int j = 0; j <= i; j++){
            cout << ch << " ";
        }
        cout << endl;
    }
}
void pattern17 (int n){
    for(int i = 0; i < n; i++){
        //for space
        for(int j = 0; j < n-i-1; j++){
            cout << " ";
        }
        // for chars
        char ch = 'A';
        int breakpoint = (2*i+1)/2;
        for (int j = 0; j < 2 * i + 1; j++){
            cout << ch;
            if (j <= breakpoint) ch++;
            else ch--;
        }

        //for spaces
        for (int j = 0; j < n-i-1; j++){
            cout << " ";
        }
        cout << endl;
    }
}


int main(){
    int t;
    cout << "How many times you want to print your pattern's : ";
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cout << "Enter the number : ";
        cin >> n;
        pattern17(n);  
    }
}

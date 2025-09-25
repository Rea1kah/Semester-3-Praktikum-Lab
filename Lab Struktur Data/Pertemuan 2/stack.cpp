#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> s;
    int input;

    // Input berhenti kalau bukan angka
    while(cin >> input){
        s.push(input);
    }
    
    do {
        cout << s.top() << " ";
        s.pop();
    }while(s.size() != 0);
    cout << endl;

    return 0;
}
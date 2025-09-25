#include <iostream>
#include <stack>
using namespace std;

struct node {
    int datanya;
    node *next;
};

node *top = NULL;

void push(int nilainya){
    node *node_baru = new node;
    node_baru -> datanya = nilainya;
    node_baru -> next = top;
    top = node_baru;
}

void pop(){
    if(top == NULL){
        cout << "Stacknya masih kosong lek!\n";
        return;
    }
    node *sementara = top;
    cout << "Elemen yang di-pop : " << sementara -> datanya << endl;
    top = top -> next;
    delete sementara;
}

void cetak_stack(){
    node *sementara = top;
    cout << "\nIsi Stack\n";
    cout << "=========\n";
    while(sementara != NULL){
        cout << sementara -> datanya << " ";
        sementara = sementara-> next;
    }
    cout << "\n\n";
}

int main(){
    push(20);
    push(16);
    push(8);

    cetak_stack();

    pop();

    cetak_stack();

    return 0;
}
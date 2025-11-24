#include <iostream>
using namespace std;
#define MAX 5

int stack[MAX];
int top = -1; //awalnya kosong

// push
void push (int value){
    if (top == MAX){
        cout<<"Stack Penuh"<<endl;
    }
    else{
        top++;
        stack[top] = value;
        cout<< value << " Ditambahakan dalam stack \n";
    }
}

// pop
void pop(){
    if (top == -1){
        cout<<"Stack Kosong!"<<endl;
    }
    else {
        cout<<stack[top] <<" keluar dari stack\n";
        top--;
    }
}

// nampilin stack
void display(){
    if (top == -1){
        cout<<"Stack Kosong!"<<endl;
    }
    else {
        cout<<"isi stack: ";
        for (int i = top; i>=0;i--){
            cout<<stack[i] << " ";
        }
        cout<<endl;
    }
}




int main (){
    for (int i=10; i<=50; i+=10){
        push(i);
    }
    cout<<endl;
    for (int i = 0; i <= 5; i++ ){
        display();
        pop();
        cout<<endl;
    }

    return 0;
}
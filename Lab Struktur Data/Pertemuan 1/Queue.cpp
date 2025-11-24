#include <iostream>
using namespace std;

#define MAX 6

int queue[MAX];
int front = -1;
int rear = -1;

// enqueue
void enqueue(int value){
    if (rear == MAX -1){
        cout<<"Queue Penuh! \n";
    }
    else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = value;
        cout<< value <<" masuk ke queue.\n";
    }
}

// dequeue
void dequeue(){
    if (front == -1 || front > rear){
        cout<<"Queue kosong! \n";
    }
    else {
        cout<<queue[front]<<" keluar dari queue. \n";
        front++;
    }
}

// nampilin isi
void display(){
    if (front == -1 || front > rear){
        cout<<"Queue kosong! \n";
    }
    else {
        cout<<"isi queue: ";
        for (int i=front;i<rear;i++){
            cout<<queue[i]<< " ";
        }
        cout<<endl;
    }
    
}

int main (){
    for (int i = 1;i<=5;i++){
        enqueue(i);

    }

    display();
    enqueue(6);

    display();
    dequeue();
    display();
}
#include <iostream>
using namespace std;

// Deklarasi struktur node
struct node
{
    int nilai;
    node *next;
};

node *head = NULL;
node *tail = NULL;

// Insert Front
void insertFirst(int n){
    node *newNode = new node;
    newNode -> nilai = n;
    newNode -> next = NULL;

    if(head == NULL){
        head = newNode;
        tail = head;
    }else{
        newNode -> next = head;
        head = newNode;
    }
}

// Insert Last
void insertLast(int n){
    node *newNode = new node;
    newNode -> nilai = n;
    newNode -> next = NULL;

    if(head == NULL){
        head = newNode;
        tail = head;
    }else{
        tail -> next = newNode;
        tail = newNode;
    }
}

// Insert setelah nilai tertentu
void insertAfter(int n, int check){
    if(head == NULL){
        cout << "LIST NYA KOSONG BANG!, INSERT DI DEPAN DULU!";
        return;
    }

    node *newNode = new node;
    newNode -> nilai = n;
    newNode -> next = NULL;

    node *p = head;
    while(p != NULL && p -> nilai != check){
        p = p -> next;
    }

    if(p == NULL){
        cout << "Node dengan nilai " << check << " Tidak Ditemukan!" << endl;
        delete newNode;
    }else{
        newNode -> next = p -> next;
        p -> next = newNode;

        if(p == tail){
            tail == newNode;
        }
    }
}

// Cetak isi Linked List
void cetakList(){
    node *temp = head;
    cout << "Isi Linked List\n";
    cout << "===============\n";
    while(temp != NULL){
        cout << temp -> nilai << " -> ";
        temp = temp -> next;
    }
    cout << "NULL\n";
}

int main(){
    insertFirst(10);
    insertLast(20);
    insertLast(30);
    insertAfter(25,20);
    insertFirst(5);

    cetakList();
    return 0;
}
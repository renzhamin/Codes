#include <bits/stdc++.h>
using namespace std;

struct Node{
public:
    int value;
    Node *next;
    Node(){
        next = NULL;
    }
    Node(int key){
        value = key;
        next = NULL;
    }
}*head,*tail;


void insert_front(int key){
    Node *new_node = new Node(key);
    if(head == NULL){
        head = new_node;
        tail = new_node;
        return;
    }
    new_node->next = head;
    head = new_node;
}

void insert_back(int key){
    if(head == NULL) {
        insert_front(key);
        return;
    }
    Node *new_node = new Node(key);
    tail->next = new_node;
    tail=new_node;
}

void insert_after_node(int key, int v){
    Node *cur = head;
    while(cur!= NULL && cur->value != v){
        cur = cur->next;
    }
    if(cur == NULL) {
        cout<<"Node not found\n";
        return;
    }
    Node *new_node = new Node(key);
    new_node->next = cur->next;
    cur->next = new_node;
    if(new_node->next == NULL) 
        tail = new_node;

}
void update_node(int key, int v){
    Node *temp = head;
    while(temp!= NULL && temp->value != v){
        temp = temp->next;
    }
    if(temp == NULL) {
        cout<<"Node not found\n";
        return;
    }
    temp->value = key;
}

void remove_by_value(int v){
    Node *temp = head;
    Node *prevNode = temp;
    if(temp->value == v){
        head = temp->next;
        delete(temp);
        return;
    }

    while(temp!= NULL && temp->value != v){
        prevNode = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        cout<<"Not Found\n";
        return;
    }
    prevNode->next = temp->next;
    delete(temp);
    if(prevNode->next == NULL) 
        tail = prevNode;
}

void remove_end(){
    if(head == NULL) {
        cout<<"No nodes in the list";
        return;
    }
    Node *temp = head;
    Node *prev = temp;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    tail = prev;
    delete(temp);
}

void printAll(){
    cout<<"\n";
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->value<<" ";
        temp= temp->next;
    }
    cout<<"\n";
}

bool menu(){
    printf("1.Insert at front\n2.Insert at back\n3.Insert after node\n4.update node\n5.remove node\n6.remove last node\n7.show the list\n8.exit\n");

    int option, key, v;
    cin >> option;
    switch (option){
    case 1:
        cout<<"Enter value : ";
        cin >> key;
        insert_front(key);
        break;
    case 2:
        cout<<"Enter value : ";
        cin >> key;
        insert_back(key);
        break;
    case 3:
        cout<<"Enter value : ";
        cin >> key;
        cout<<"Enter new node value : ";
        cin >> v;
        insert_after_node(key, v);
        break;
    case 4:
        cout<<"Enter value : ";
        cin >> key;
        cout<<"Enter new value : ";
        cin >> v;
        update_node(key, v);
        break;
    case 5:
        cout<<"Enter value: ";
        cin >> v;
        remove_by_value(v);
        break;
    case 6:
        remove_end();
        break;
    case 7:
        printAll();
        break;    
    case 8:
        return 0;
    default:
        cout<<"invalid input"<<"\n";
    }
    return 1;
}

int main(){
    while(menu());
}

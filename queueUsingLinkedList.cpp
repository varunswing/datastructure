#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

Node* front = NULL;
Node* rear = NULL;
Node* temp;

void Insert(){
    int val;
    cout << "Enter the element to insert:" << endl;
    cin >> val;
    if(rear == NULL){
        rear = (Node *)malloc(sizeof(Node));
        rear->data = val;
        rear->next = NULL;
        front = rear;
    }else{
        temp = (Node *)malloc(sizeof(Node));
        temp->data = val;
        rear->next = temp;
        temp->next = NULL;
        rear = temp;
    }
}

void Delete(){
    temp = front;
    if(front == NULL){
        cout<<"Underflow.";

    }else if(temp != NULL){
        cout << "Element deleted is:" << front->data << endl; 
        temp = temp->next;
        free(front);
        front = temp;
    }else{
        cout << "Element deleted is:" << front->data << endl;
        free(front);
        front = NULL;
        rear = NULL;
    }
}

void Display(){
    if((front == NULL) && (rear == NULL)){
        cout <<"Queue is empty."<<endl;

    }else{
        cout <<"Elements of queue are:" <<endl;
        temp = front;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
}

int main(){
    int ch;
    cout<< "1. Insert element in queue: "<<endl;
    cout<< "2. Delete element in queue: "<<endl;
    cout<< "3. Display elements of queue: "<<endl;
    cout<< "4. Exit"<<endl;
    do{
        cout <<"Enter your choice: "<<endl;
        cin >> ch;
        switch(ch){
            case 1: Insert();
                break;
            case 2: Delete();   
                break;
            case 3: Display();
                break;
            case 4: cout << "Program ended.";
                break;
            default: cout<<"Invalid choice.";
        }
    }while(ch != 4);
    return 0;
}
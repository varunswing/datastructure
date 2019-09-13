#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct node{
    int val;
    struct node* next;
}NODE;

NODE* head = NULL;
NODE* temp = NULL;
NODE* node = NULL;
NODE* temp1 = NULL;
NODE* temp2 = NULL;

void printList(NODE* head){
    node = head;
    while(node){
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
    return;
}

int main(){
    int n, val, pos;
    cout << "Enter the no. of nodes you want to create: " << endl;
    cin >> n;
    for(int i=1; i<=n; i++){
        cout << "Enter the integer: " << endl;
        cin >> val;
        if(!head){
            head = (NODE*)malloc(sizeof(NODE*));
            head->val = val;
            head->next = NULL;
            temp = head;
        }else{
            node = (NODE*)malloc(sizeof(NODE*));
            node->val = val;
            node->next = NULL;
            temp->next = node;
            temp = node;
        }
    }
    printList(head);

    int choice;
    cout << "Enter your choice:  "<< endl;
    cout << "1.To delete at beginning "<< endl;
    cout << "2.To delete at end "<< endl;
    cout << "3.To delete at any position"<< endl;
    cin >> choice;

    if(choice == 1){
        head = head->next;
        cout << "Linked list after deleting first element is:."<< endl;
        printList(head);
    }if(choice == 2){
        temp1 = (NODE*)malloc(sizeof(NODE*));
        temp1 = head;
        for(int i=1; i<n-1; i++){
            temp1 = temp1->next;
        }
        temp1->next = NULL;
        cout << "Linked list after deleting last element is:."<< endl;
        printList(head);
    }if(choice == 3){
        cout << "Enter the position: " << endl;
        cin >> pos;
        if(pos <= 0 || pos > n+1){
            cout << "Position entered is invalid!, Please enter a valid position.";
        }if(pos == 1){
            head = head->next;
            cout << "Linked list after deleting element at position " << pos << " is:"<< endl;
            printList(head);
        }else{
            temp2 = (NODE*)malloc(sizeof(NODE*));
            node = (NODE*)malloc(sizeof(NODE*));
            temp2 = head;
            for(int i=1; i<pos-1; i++){
                temp2 = temp2->next;
            }
            temp = temp2->next;
            temp2->next = temp->next;
            temp = temp->next;
            cout << "Linked list after deleting element at position " << pos << " is:"<< endl;
            printList(head);
        }
    }
    return 0;
}
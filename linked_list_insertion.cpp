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
    cout << "1.To insert at beginning "<< endl;
    cout << "2.To insert at end "<< endl;
    cout << "3.To insert at any position"<< endl;
    cin >> choice;

    if(choice == 1){
        cout << "Enter the integer: " << endl;
        cin >> val;
        temp1 = (NODE*)malloc(sizeof(NODE*));
        temp1->val = val;
        temp1->next = head;
        head = temp1;
        printList(head);
    }if(choice == 2){
        cout << "Enter the integer: " << endl;
        cin >> val;
        temp2 = (NODE*)malloc(sizeof(NODE*));
        node = (NODE*)malloc(sizeof(NODE*));
        temp2->val = val;
        temp2->next = NULL;
        temp->next = temp2;
        temp = temp2;
        printList(head);
    }if(choice == 3){
        cout << "Enter the position: " << endl;
        cin >> pos;
        if(pos <= 0 || pos > n+1){
            cout << "Position entered is invalid!, Please enter a valid position.";
        }if(pos == 1){
            cout << "Enter the integer: " << endl;
            cin >> val;
            temp1 = (NODE*)malloc(sizeof(NODE*));
            temp1->val = val;
            temp1->next = head;
            head = temp1;
            printList(head);
        }else{
            cout << "Enter the integer: " << endl;
            cin >> val;
            temp2 = (NODE*)malloc(sizeof(NODE*));
            node = (NODE*)malloc(sizeof(NODE*));
            temp2 = head;
            for(int i=1; i<pos-1; i++){
                temp2 = temp2->next;
            }
            node->val = val;
            temp = temp2->next;
            temp2->next = node;
            node->next = temp;
            printList(head);
        }
    }
    return 0;
}
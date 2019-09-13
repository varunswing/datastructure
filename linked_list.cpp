#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct node{
    int val;
    struct node* next;
}NODE;

NODE* head = NULL;
NODE* node = NULL;
NODE* temp = NULL;

void printList(NODE* head){
    node = head;
    while(head){
        cout << node->val << " ";
        node = node->next;
    }
    cout<<endl;
    return;
}

int main(){
    int val;
    cout << "Enter an integer value:" << endl;
    cin >> val;

    while(val != -1){
        if(!head){
            head = ((NODE*)malloc(sizeof(NODE*)));
            head->val = val;
            head->next = NULL;
            temp = head;
        }
        else{
            node = ((NODE*)malloc(sizeof(NODE*)));
            node->val = val;
            node->next = NULL;
            temp->next = node;
            temp = node;
        }
        cout << "Enter an integer value:" << endl;
        cin >> val;
    }
    printList(head);
    return 0;
}
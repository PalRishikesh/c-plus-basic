#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// void displayNode(Node* head){
//     Node* temp = head;
//     // Checking current current node is empty or not
//     while(temp != NULL){
//         cout<<temp->data<<" ";
//         temp = temp->next;
//     }    
//     cout<<"NULL"<<endl;
// }

void insertAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* currentNode = head;
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
    
}

void displayNode(Node* head){
    Node* currentNode  = head;
    while (currentNode!= NULL)
    {
        cout<<currentNode->data<<" ";
        currentNode = currentNode->next;
    }
    cout<<"NULL"<<endl;
}
// Iterative way
void reverseNode(Node* &head){
    Node* prevPtr = NULL;
    Node* currentPtr = head;
    Node* nextPtr = NULL;
    while (currentPtr!= NULL)
    {
        nextPtr = currentPtr->next;
        currentPtr->next = prevPtr;
        // Moving 1 node forward
        prevPtr = currentPtr;
        currentPtr = nextPtr;
    }
    // Making head to currrent point that is currently assing to prevPtr
    head = prevPtr;
    
}



Node* recursiveReverse(Node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* newHead = recursiveReverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

// Recursive way
int main(){
     Node* currentHead = NULL;
    insertAtTail(currentHead,11);
    insertAtTail(currentHead,12);
    insertAtTail(currentHead,13);
    insertAtTail(currentHead,14);
    displayNode(currentHead);
    // Node* revHead = reverseNodePtr(currentHead);
    Node* revHead = recursiveReverse(currentHead);

    displayNode(revHead);


    return 0;
}
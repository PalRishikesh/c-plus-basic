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

void displayNode(Node* head){
    Node* temp = head;
    // Checking current current node is empty or not
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }    
    cout<<"NULL"<<endl;
}

void insertAtTail(Node* &head,int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    // Cheking current next is present or not
    Node* currentNode = head;
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
    
}

void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    Node* currentNode = head;
    newNode->next = currentNode;
    head = newNode;
}

void insertAtPosition(Node* &head, int position, int data){
    Node* newNode = new Node(data);
    Node* currentNode = head;
    int count = 1;
    
    while (count < (position-1))
    {
        currentNode = currentNode->next;
        count++;
    }
    newNode->next = currentNode->next;
    currentNode->next = newNode;
    
}

bool searchNode(Node* head, int value){
    Node* currentNode = head;
    while(currentNode != NULL){
        if (currentNode->data == value)
        {
            return true;
        }
        currentNode = currentNode->next; 
    }
    return false;
}
bool searchNodeValue(Node* head, int value){
    Node* currentNode  = head;
    bool isPresent = false;
    while (currentNode != NULL)
    {
        if(currentNode->data == value){
            isPresent = true;
        }
        currentNode = currentNode->next;
    }
    return isPresent;
}

void deleteSamplesNode(Node* &head, int nodeNumber){
    Node* prevePtr = NULL;
    Node* currentPtr = head;
    int counter = 1;
    while (counter < nodeNumber)
    {
        prevePtr = currentPtr;
        currentPtr = currentPtr->next;
        counter++;
    }
    prevePtr->next = currentPtr->next;
    currentPtr->next = NULL;
    
}

void deleteNodeByValue(Node* &head, int value){
    if(head == NULL){
        return;
    }
    if(head->next == NULL){
        deleteAtHead(head);
        return;
    }
    Node* tempNode = head;
    // Till we get node value (before it own value i.e previous node)
    while (tempNode->next->data != value)
    {
        tempNode = tempNode->next;
    }
    Node* toDelte = tempNode->next;
    // Assing previous node next value to current next value
    tempNode->next = tempNode->next->next;
    delete toDelte;
    
}
void deleteAtHead(Node* &head){
    Node* deleteNode = head;
    head = head->next;
    delete deleteNode;
}
int main(){
    Node* currentHead = NULL;
    insertAtTail(currentHead,11);
    insertAtTail(currentHead,12);
    displayNode(currentHead);
    insertAtHead(currentHead,10);
    insertAtHead(currentHead,9);
    displayNode(currentHead);
    insertAtPosition(currentHead,1,20);
    displayNode(currentHead);

    cout<<searchNodeValue(currentHead,0);
    cout<<endl;
    // deleteSamplesNode(currentHead,2);
    // deleteNodeByValue(currentHead,9);
    deleteAtHead(currentHead);
    displayNode(currentHead);

    return 0;
}
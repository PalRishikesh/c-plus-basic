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

void insertNodeAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* tempNode = head;
    while (tempNode->next != NULL)
    {
        tempNode = tempNode->next;
    }
    tempNode->next = newNode;
}
void displayNode(Node* head){
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    

}
int main(){
    // Node* NodeHead = new Node(10);
    Node* NodeHead = NULL;
    insertNodeAtTail(NodeHead,11);
    insertNodeAtTail(NodeHead,12);
    displayNode(NodeHead);
    return 0;
}

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void dispalyNode(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << " << NULL " << endl;
}

void insertNodeAtHead(Node *&head, int data)
{
    Node *newNode = new Node(data);
    Node *currentHead = head;
    newNode->next = currentHead;
    if (currentHead != NULL)
    {
        currentHead->prev = newNode;
    }
    head = newNode;
}

void insertNodeAtTail(Node* &head, int data)
{
    Node *newNode = new Node(data);
    Node *currentHead = head;
    if (currentHead == NULL)
    {
        insertNodeAtHead(head, data);
        return;
    }
    while (currentHead->next != NULL)
    {
        currentHead = currentHead->next;
    }
    currentHead->next = newNode;
}

void deleteAtHead(Node* &head){
    Node* currnetNode = head;
    head = currnetNode->next; // Or head = head->next;
    currnetNode->next->prev = NULL;
    currnetNode->next = NULL;
    delete currnetNode;
    // Easy way
    // head = head->next;
    // head->prev = NULL
    // delete currentNode;

    
}

void deleteNodeAtPosition(Node* &head, int position)
{
    Node *currentNode = head;
    int count = 1;
    if(position == 1){
        deleteAtHead(head);
        return;
    }
    while (currentNode->next != NULL && count != position)
    {
        currentNode = currentNode->next;
        count++;
    }
    currentNode->prev->next = currentNode->next;
    if (currentNode->next != NULL)
    {
        currentNode->next->prev = currentNode->prev;
    }
    delete currentNode;
}
int main()
{
    // Node* head = new Node(1);
    Node *head = NULL;
    insertNodeAtTail(head, 1);
    insertNodeAtTail(head, 2);
    insertNodeAtHead(head, 0);
    dispalyNode(head);
    deleteNodeAtPosition(head, 1);
    dispalyNode(head);

    return 0;
}
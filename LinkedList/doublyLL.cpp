#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node(){
        int value = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<" memeory free from data "<<value<<endl;
    }
};

void printNode(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int nodeLength(Node *&head)
{
    int length = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

void insertAtHead(Node *&tail, Node *&head, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        // New node next address to old node
        temp->next = head;
        // Old Node previous address to new Node
        head->prev = temp;
        // Move head to new node
        head = temp;
    }
}

void insertAtTail(Node *&tail, Node *&head, int data)
{
    if (tail == NULL)
    {
        Node *newNode = new Node(data);
        tail = newNode;
        head = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        // Old node next address is new node
        tail->next = newNode;
        // New node previous is old tail value
        newNode->prev = tail;
        // Moving new node to tail
        tail = newNode;
    }
}

void insertAtPosition(Node *&tail, Node *&head, int position, int data)
{
    if (position == 1)
    {
        insertAtHead(tail, head , data);
        return;
    }
    // Taking first node as head pointer
    Node *currentHead = head;
    int cnt = 1;

    // Traveling till desire location reached
    while (cnt < position - 1)
    {
        currentHead = currentHead->next;
        cnt++;
    }
    // Inserting at last Position
    if (currentHead->next == NULL)
    {
        insertAtTail(tail, head, data);
        return;
    }
    // Create new node with data
    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = currentHead->next;
    currentHead->next->prev = nodeToInsert;
    currentHead->next = nodeToInsert;
    nodeToInsert->prev = currentHead;
}

void deleteNodePosition(int position, Node *&head, Node *&tails)
{
    // Deleting first position
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;

        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
            // Deleting last node
            if (curr->next == NULL)
            {
                tails = prev;
            }
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;


        delete curr;
    }
}
int main()
{
    // Node* node1 = new Node(13);
    // Node* head = node1;
    // Node* tail = node1;
    // If there is no data at all
    Node* head = NULL;
    Node* tail = NULL;
    // printNode(head);
    // cout<<nodeLength(head);
    insertAtHead(tail, head, 12);
    insertAtHead(tail, head, 11);
    insertAtHead(tail, head, 10);
    printNode(head);
    insertAtTail(tail,head,14);
    printNode(head);
    insertAtPosition(tail, head, 1, 55);
    printNode(head);
    deleteNodePosition(5,head, tail);
    printNode(head);
    return 0;
}
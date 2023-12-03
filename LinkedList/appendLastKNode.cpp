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


void insertNodeAtTail(Node* &head, int data)
{
    Node *newNode = new Node(data);
    Node *currentHead = head;
    
    while (currentHead->next != NULL)
    {
        currentHead = currentHead->next;
    }
    currentHead->next = newNode;
}

int nodeLength(Node* head){
    Node* currentNode = head;
    int length = 0;
    while (currentNode != NULL)
    {
        currentNode = currentNode->next;
        length++;

    }
    return length;
    
}

Node* kNodeAppend(Node* &head, int k){
    int length = nodeLength(head);
    Node* tail = head;
    Node* newTail;
    Node* newHead;

    int count = 1;
    // If k size is greater ne lenght
    k = k%length;
    while (tail->next != NULL)
    {
        if(count == length-k){
            newTail = tail;
        }
        if(count == length - k +1){
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }
    newTail->next = NULL;
    tail->next = head;
    return newHead;

    

}
int main()
{
    Node* head = new Node(1);
    insertNodeAtTail(head, 2);
    insertNodeAtTail(head, 3);
    insertNodeAtTail(head, 4);
    insertNodeAtTail(head, 5);
    insertNodeAtTail(head, 6);
    insertNodeAtTail(head, 7);
    dispalyNode(head);
    int lenght = nodeLength(head);
    cout<<" Length is "<<lenght<<endl;
    Node* newList = kNodeAppend(head,3);
    dispalyNode(newList);



    return 0;
}
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // Construction
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    // Destructor
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            // delete next;
            this->next = NULL;
        }
        cout << "Memory is free with node with data " << value << endl;
    }
};

void insertAtHead(Node *&tial, Node *&head, int data)
{

    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tial = temp;
    }
    else
    {
        // (We have taken references (&) so that it does not create copy, make changes in original linked list)
        // Creating new Node with inserting data
        Node *temp = new Node(data);
        // Assingin new node next address of head  previous value
        temp->next = head;
        // Remove head from previous node and put on the new node
        head = temp; // Making new Node its first value, because of head value assing to first as head alway refer start
    }
}

void insertAtTail(Node *&tail, Node *&head, int data)
{
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        // Point old next address  to new node
        tail->next = temp;
        // Tail alway point to last node
        // Assing new node to tail with these two option
        // tail = tail->next; OR
        tail = temp; // Assing new value node to tail
    }
}

void insertAtPosition(Node *&tail, Node *&head, int position, int data)
{
    if (position == 1)
    {
        insertAtHead(tail, head, data);
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
    }
    // Create new node with data
    Node *nodeToInsert = new Node(data);
    // Assing new node next with current next (so that next value pointer changed from current to new node)
    nodeToInsert->next = currentHead->next;
    // Making previous next to current new node
    currentHead->next = nodeToInsert;
}

void deleteNodePosition(int position, Node *&head, Node *&tails)
{
    // Deleting first position
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // Free memory
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
        prev->next = curr->next;
        // Deleting
        curr->next = NULL;
        delete curr;
    }
}
void deleteNodeWithValue(int value, Node *&head, Node *&tails)
{
    // Deleting first position
    // if (position == 1)
    // {
    //     Node *temp = head;
    //     head = head->next;
    //     // Free memory
    //     temp->next = NULL;
    //     delete temp;
    // }
    // else
    // {
    // Node *curr = head;
    // Node *prev = NULL;
    // int cnt = 1;
    // while (cnt < position)
    // {
    //     prev = curr;
    //     curr = curr->next;
    //     cnt++;
    //     // Deleting last node
    //     if (curr->next == NULL)
    //     {
    //         tails = prev;
    //     }
    // }
    // prev->next = curr->next;
    // curr->next = NULL;
    // delete curr;
    // }

    Node *temp = head;
    int cnt = 1;
    while (temp != NULL)
    {
        if (temp->data != value)
        {
            cnt++;
        }
    }
    cout << " Found value at position: " << cnt << endl;
}

void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Creating new node
    // Node *node1 = new Node(10);
    // Head pointed to node1
    // Node *head = node1;
    // Node *tails = node1;
    Node *head = NULL;
    Node *tails = NULL;
    print(head);
    insertAtTail(tails,head, 9);
    // print(head);
    insertAtHead(tails, head, 12);
    // print(head);

    insertAtHead(tails,head, 15);
    print(head);

    insertAtPosition(tails, head, 4, 11);
    print(head);
    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tails->data << endl;
    // deleteNodePosition(1, head, tails);
    print(head);
    // cout << "Head: " << head->data << endl;
    // cout << "Tail: " << tails->data << endl;
    // deleteNodeWithValue(15, head, tails);
    return 0;
}
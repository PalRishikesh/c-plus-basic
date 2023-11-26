#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << " memeory free from data " << value << endl;
    }
};

void insertNode(Node *&tail, int element, int data)
{
    // Empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // Assuming tjhat the lement is present in the list
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }

        Node *newNode = new Node(data);
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

void printNode(Node *tail)
{
    Node *temp = tail;
    if(tail == NULL){
        cout<<" List is empty"<<endl;
    }
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
        // } while (temp->next != temp); This is also work fine
    } while (tail != temp);
    cout << endl;
}

void deleteNode(Node* &tail, int value){
    if(tail == NULL){
        cout<<" List is empty, Please check again"<<endl;
        return;
    }
    else{
        Node* prev = tail;
        Node* curr = prev->next;

        while(curr->data != value){
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        curr->next = NULL;
        // If 1 Node is ther
        if(curr == prev){
            tail = NULL;
        }
        // >=2 Node linked list
        if(tail == curr){
            tail = prev;
        }
        delete curr;

    }
}
int main()
{

    Node *tail = NULL;

    insertNode(tail, 1, 13);
    // printNode(tail);
    // insertNode(tail, 13, 14);
    printNode(tail);

    // insertNode(tail, 14, 16);
    // printNode(tail);
    //  insertNode(tail, 13, 133);
    // printNode(tail);

    deleteNode(tail,13);
    printNode(tail);

    return 0;
}
#include<iostream>
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



// class Node{
//     public:
//     int data;
//     Node* next;

//     Node(int value){
//         data = value;
//         next = NULL;
//     }
// };

void insertAtTail(Node* &head, int value){
    Node* newNode = new Node(value);
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
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    
}

int main(){

    Node* head = NULL;
    insertAtTail(head,4);
    insertAtTail(head,5);
    displayNode(head);

    return 0;

}
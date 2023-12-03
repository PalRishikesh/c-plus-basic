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

// Making intersection 
void intersectionNode(Node* &head1, Node* &head2, int pos){
    Node* temp1 = head1;
    Node* temp2 = head2;
    pos--;
    while (pos--)
    {
        temp1 = temp1->next;         
    }
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
    

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

int intersection(Node* &head1, Node* &head2){
    int l1 = nodeLength(head1);
    int l2 = nodeLength(head2);
    int d=0;
    Node* ptr1;
    Node* ptr2;
    if(l1 > l2){
        d = l1-l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else{
        d = l2-l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    // Just to skip the no. of uncommon node (intially node)
    while (d)
    {
        ptr1 = ptr1->next;
        if(ptr1 == NULL){
            return -1;
        }
        d--;
    }

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if(ptr1 == ptr2){
            return ptr2->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}

int main()
{
    Node* head = new Node(1);
    Node* head2 = new Node(10);
    insertNodeAtTail(head, 2);
    insertNodeAtTail(head, 3);
    insertNodeAtTail(head, 4);
    insertNodeAtTail(head, 5);
    insertNodeAtTail(head, 6);
    insertNodeAtTail(head2, 12);
    dispalyNode(head);
    intersectionNode(head, head2,2);
    int inserSectValue = intersection(head, head2);
    cout<<"Value is "<<inserSectValue<<endl;



    return 0;
}
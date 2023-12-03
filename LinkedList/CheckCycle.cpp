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

//Or
Node* reverseNodePtr(Node* &head){
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
   return prevPtr;
    
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
Node* reverseK(Node* &head, int k){
    Node* prevPtr = NULL;
    Node* currentPtr = head;
    Node* nextPtr;
    int count = 0;
    while (currentPtr != NULL && count < k)
    {
        nextPtr = currentPtr->next;
        currentPtr->next = prevPtr;
        prevPtr = currentPtr;
        currentPtr = nextPtr;
        count++;
    }
    if(currentPtr != NULL){
        head->next = reverseK(nextPtr,k);
    }
    return prevPtr;

}

bool detectCycle(Node* &head){
    Node* slow = head;
    Node* fast = head;

    while (fast!=NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            return true;
        }
    }
    return false;
    
}

void makeCycle(Node* &head, int pos){
    Node* temp = head;
    Node* startNode;
    int count=1;
    while (temp->next != NULL)
    {
        if(count == pos){
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

void removeCycle(Node* &head){
    Node* slow = head;
    Node* fast = head;
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);
    
    fast = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
    
}
int main(){
     Node* currentHead = NULL;
    insertAtTail(currentHead,11);
    insertAtTail(currentHead,12);
    insertAtTail(currentHead,13);
    insertAtTail(currentHead,14);
    displayNode(currentHead);
    // Node* revHead = reverseNodePtr(currentHead);
    // Node* revHead = recursiveReverse(currentHead);
    Node* revHead = reverseK(currentHead,2);
makeCycle(currentHead,2);
    // displayNode(revHead);
    bool returnCycle = detectCycle(currentHead);
    cout<<" Cyclce: "<<returnCycle;
    removeCycle(currentHead);
    bool returnCycle2 = detectCycle(currentHead);
    cout<<endl<<" Cyclce 2: "<<returnCycle2;


    return 0;
}
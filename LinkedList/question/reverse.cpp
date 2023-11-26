//https://www.codingninjas.com/studio/problems/reverse-the-singly-linked-list_799897?source=youtube&campaign=Lovebabbarcodestudio_24thJan&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio_24thJan&leftPanelTabValue=SOLUTION


  if (head == NULL || head->next == NULL) {
    return head;
  }
  LinkedListNode *prev = NULL;
  LinkedListNode *curr = head;
  LinkedListNode *forward = NULL;
  while (curr != NULL) {
    forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
  }
  return prev;
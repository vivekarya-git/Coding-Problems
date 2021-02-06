/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

Node * merge(Node *l, Node *r) {
    Node *s = NULL;
    Node *head = NULL;

    while ( l != NULL && r != NULL ) {
        if ( l->data <= r->data ) {
            if (s != NULL) {
                s->next = l;
            } else {
                head = l;
            }
            s = l;
            l = l->next;
            s->next = r;
        } else {
            if ( s != NULL ) {
                s->next = r;
            } else {
                head = r;
            }
            s = r;
            r = r->next;
            s->next = l;
        }
    }
    
    if ( l != NULL ) {
        s = l;
    } else if ( r != NULL) {
        s = r;
    }

    return head;
}

void splitList(Node *head, Node **l, Node **r) {
    Node *slow = head;
    Node *fast = head->next;
    
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *l = head;
    *r = slow->next;
    slow->next = NULL;
    return;
}

/* Function to mergesort the linked list
   It should return head of the modified list  */
Node* mergeSort(Node* head) {
    // your code here
    Node *l = NULL;
    Node *r = NULL;
    if ( head == NULL || head->next == NULL ) {
        return head;
    }

    splitList(head, &l, &r);
    l = mergeSort(l);
    r = mergeSort(r);
    head = merge(l, r);
    
    return head;
}

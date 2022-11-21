#include <bits/stdc++.h>
#include <inttypes.h>
using namespace std;

class Node {
	public:
    	int data;
    	Node* link;
};

Node* XOR (Node *a, Node *b) {
	return (Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}

void insertBeginning(Node **head_ref, int data) {
	Node *new_node = new Node();
	new_node->data = data;

	new_node->link = *head_ref;

	if (*head_ref != NULL)
	{
		(*head_ref)->link = XOR(new_node, (*head_ref)->link);
	}

	*head_ref = new_node;
}

void insertEnd(Node **head_ref, int data) {
	Node *new_node = new Node();
	new_node->data = data;

	Node *curr = *head_ref;
	Node *prev = NULL;
	Node *next = XOR(prev, curr->link);

	if (*head_ref != NULL)
	{
		while(next != NULL){
			prev = curr;
			curr = next;
			next = XOR (prev, curr->link);
		}

	new_node->link = XOR(curr, NULL);
	curr->link = XOR(curr->link, new_node);

	}else{
		new_node->link = NULL;
		*head_ref = new_node;

	}
}
/*
 void insertPos(Node **head_ref, int data){
    Node *new_node = new Node();
	new_node->data = data;

    Node *curr = *head_ref;
    Node *prev = NULL;
    Node *next = XOR(prev, curr->link);

    if(*head_ref != NULL){
        while(next != NULL){
            prev = curr;
            curr = next;
            next = XOR(prev, curr->link);
        }

    }

}
*/

Node* delete_end(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = XOR(prev, curr->link);
    if(head == NULL){
        return NULL;

    }
    while (next != NULL) {
        prev = curr;
        curr = next;
        next = XOR(prev, curr->link);
    }
    if(prev != NULL){
        prev->link = XOR(prev->link, curr);
    }
    delete curr;
    return head;
}

Node* delete_begin(Node *head)
{
    if(head == NULL){
        return NULL;
    }
    Node *temp = XOR(head->link,NULL);
    temp->link = XOR(head, temp->link);
    delete head;
    return temp;
}

void printList (Node *head) {
	Node *curr = head;
	Node *prev = NULL;
	Node *next;

	cout << "\nLinked List: ";

	while (curr != NULL) {
		cout<<curr->data<<" ";

		next = XOR (prev, curr->link);

		prev = curr;
		curr = next;
	}
	cout<<endl;
}

int main () {
	Node *head = NULL;
	int d = 0;
	int w = 0;
	while(true) {
    	cout << "Enter the number and -1 to stop: ";
    	cin >> d;
    	if (d == -1)
    	    break;
    	cout<< "Enter 1:beginning <> 2:end: ";
    	cin >> w;
    	if (w == 1)
    	    insertBeginning(&head, d);
    	if (w == 2)
    	    insertEnd(&head, d);
        //if (w == 3)
        //    insertPos(&head, d);
        printList(head);
        cout<<endl;
	}

	printList(head);

	Node* head1 = head;
	cout<<"\nAfter deleting the last node from list ";
	head1 = delete_end(head1);
	printList(head1);
	cout<<"\nAfter deleting the first node from list ";
	head1 = delete_begin(head1);
	printList(head1);


	return 0;
}

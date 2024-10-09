#include <iostream>

using namespace std;

typedef struct Node {
	int data;
	Node *next;
} Node;

void appendNode(int data, Node **head);
void displayList(Node *head);

int main() {
	Node *head = NULL;
	appendNode(1, &head);
	appendNode(2, &head);
	appendNode(3, &head);
	appendNode(4, &head);


	displayList(head);
}

void appendNode(int data, Node **head) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	if (*head != NULL) {
		Node *temp = *head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
	} else {
		*head = newNode;
	}
}

void displayList(Node *head) {
	Node *temp = head;
	if (temp != NULL) {
		cout << "{";
		while (temp != NULL) {
			cout << temp->data << " --> ";
			if (temp->next == NULL) cout << "END";
			temp = temp->next;
		}
		cout << "}";
	} else {
		cout << "The list is empty";
	}
}

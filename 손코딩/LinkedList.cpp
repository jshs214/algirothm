#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* head, * tail;

// ù��° ��� �߰�
void addFrontNode(int n) {
	Node* temp = new Node;
	temp->data = n;

	if (head == NULL) {
		head = temp;
		tail = temp;
	}
	else {
		temp->next = head;
		head = temp;
	}

}
// ������ ��� �߰�
void addNode(int n) {
	Node* temp = new Node;
	temp->data = n;
	temp->next = NULL;
	
	if (head == NULL) {
		head = temp;
		tail = temp;
	}
	else {
		tail->next = temp;
		tail = temp;
	}


}
//��� ����
void insertNode(Node* prevNode, int n) {
	Node* temp = new Node;
	temp->data = n;

	temp->next = prevNode->next;
	prevNode->next = temp;

}
//node ����
void deleteNode(Node* prevNode) {
	Node* temp = prevNode->next;
	prevNode->next = temp->next;

	delete temp;
}

void Print(Node* head) {
	if (head == NULL) {
		cout << "\n";
	}
	else {
		cout << head->data << " ";
		Print(head->next);
	}
}


int main() {
	addNode(4);
	addNode(5);
	addNode(6);

	addFrontNode(1);

	deleteNode(head->next);

	Print(head);
	


	return 0;
}
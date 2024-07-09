#include <iostream>

using namespace std;

// DINH NGHIA NODE
struct Node {
	int data;
	Node *next;
};

// KHOI TAO DANH SACH RONG
void init(Node *&head) {
	head = NULL;
}


// TAO 1 NODE MOI
Node *createNode(int x) {
	Node *p = new Node;
	p->data = x;
	p->next = NULL;
	return p;
}

// KIEM TRA DANH SACH RONG
bool isEmpty(Node *head) {
	if (head==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void free() {

}


void addFirst(Node *&head, int val) {
	Node *p = createNode(val);
	p->next = head;
	head = p;
}

void xuat(Node *head) {
	Node * flag = head;
	while (flag!=NULL)
	{
		cout << flag->data << "\t";
		flag = flag->next;
	}
}

Node* searchNode(Node *head, int x) {
	Node *p = head;
	while (p->next!=NULL && p->data!=x)
	{
		p = p->next;
	}
	return p;
}

void delNode(Node *head) {
	Node *p = head;

}

int main() {
	Node *head;
	init(head);
	addFirst(head, 10);
	addFirst(head, 20);
	xuat(head);
	cout << endl;
	Node *search = searchNode(head, 20);
	cout << "Vi tri cua 20: " << search << endl;
	return 0;
}
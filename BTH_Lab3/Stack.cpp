#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
};




struct Stack {
	Node *head;
};

void init(Stack &s) {
	s.head = NULL;
}

bool isEmpty(Stack s) {
	return (s.head == NULL);
}

Node* createNode(int data) {
	Node* p = new Node;
	if (p==NULL)
	{
		return NULL;
	}
	p->data = data;
	p->next = NULL;
	return p;
}

void pushStack(Stack &s, int val) {
	Node* p = createNode(val);
	p->next = s.head;
	s.head = p;
}

void free(Node*& head) {
	while (head!=NULL)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

void popStack(Stack& s) {
	Node* temp = s.head;
	s.head = temp->next;
	temp->next = NULL;
	delete temp;
}

void output(Stack s) {
	if (!isEmpty(s))
	{
		Node* temp = s.head;
		while (temp!=NULL)
		{
			cout << temp->data << "\t";
			temp = temp->next;
		}
	}
}

void xuatDauStack(Stack s) {
	if (!isEmpty(s))
	{
		cout << s.head->data;
	}
	else
	{
		cout << "Stack rong!\n";
	}
}


/* =====================CHUYEN CO SO===================== */
void chuyen_he(Stack& s, int val) {
	while (val!=0)
	{
		int x = val % 2;
		pushStack(s, x);
		val /= 2;
	}
	output(s);
}


void menu() {
	int chon;
	Stack s, s1;
	init(s);
	init(s1);
	pushStack(s, 10);
	pushStack(s, 20);
	pushStack(s, 30);
	cout << "Xuat cac phan tu trong Stack:\n";
	output(s);
	do
	{
		cout << "\n\t\t==============MENU=================\n";
		cout << "1. Chi hien thi phan tu dau trong Stack\n";
		cout << "2. Xoa phan tu trong Stack\n";
		cout << "3. Hien thi cac phan tu trong Stack\n";
		cout << "0. Ket  thuc\n";
		cout << "\n\t\t===============END=================\n";
		cout << "Nhap lua chon ban muon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			xuatDauStack(s);
			break;
		case 2:
			popStack(s);
			output(s);
			break;
		case 3:
			output(s);
			break;
		case 4:
			chuyen_he(s1, 10);
			break;
		}
	} while (chon!=0);
}

int main() {
	menu();
	
	system("pause");
	return 0;
}

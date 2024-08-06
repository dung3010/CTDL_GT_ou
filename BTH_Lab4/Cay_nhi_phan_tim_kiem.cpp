#include <iostream>

using namespace std;

// Khai bao cau truc cay
struct Node {
	int info;
	Node *left;
	Node *right;
};

//Tao cay rong
void init(Node *&root) {
	root = NULL;
}

//Them phan tu vao cay
void them(Node *&root, int x) {
	if (root==NULL)
	{
		root = new Node;
		root->info = x;
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		if (root->info==x)
		{
			return;
		}
		else if (root->info > x)
		{
			return them(root->left, x);
		}
		else
		{
			return them(root->right, x);
		}
	}
}

// duyet cay 
void duyet_LNR(Node* root) {
	if (root != NULL)
	{
		duyet_LNR(root->left);
		cout << root->info << "\t";
		duyet_LNR(root->right);
	}
}



// Tim kiem trong cay
Node* search(Node* root, int x) {
	if (root != NULL)
	{
		if (root->info == x)
		{
			return root;
		}
		else
		{
			if (root->info > x)
			{
				return search(root->left, x);
			}
			else
			{
				return search(root->right, x);
			}
		}
	}
}



//Xoa phan tu trong cay
void del_2con(Node*&root, Node*&root_right) {
	if (root_right->left != NULL)
	{
		del_2con(root, root_right->left);
	}
	else
	{
		root->info = root_right->info;
		root = root_right;
		root_right = root_right->right;
	}
}

void del(Node*&root, int x) {
	if (root == NULL)
	{
		return;
	}
	if (root->info > x)
	{
		return del(root->left, x);
	}
	else if (root->info < x)
	{
		return del(root->right, x);
	}
	else
	{
		Node *p = root;
		if (root->left == NULL)
		{
			root = root->right;
		}
		else if (root->right == NULL)
		{
			root = root->left;
		}
		else
		{
			del_2con(p, root->right);
		}
		delete p;
	}
}



// Tinh tong gia tri cac nut tren cay
int sum_Cay(Node* root) {
	if (root == NULL)
	{
		return 0;
	}
	return sum_Cay(root->left) + sum_Cay(root->right) + root->info;
}

// Tim gia tri lon nhat va nho nhat tren cay
int max(Node* root) {
	if (root != NULL)
	{
		if (root->right == NULL)
		{
			return root->info;
		}
		return max(root->right);
	}
}

int min(Node* root) {
	if (root != NULL)
	{
		if (root->left == NULL)
		{
			return root->info;
		}
		return min(root->left);
	}
}

// Dem so luong cac nut tren cay
int count_Node(Node* root) {
	if (root == NULL)
	{
		return 0;
	}
	return count_Node(root->left) + count_Node(root->right) + 1;
}


int main() {
	Node* root;
	init(root);
	them(root, 4);
	them(root, 9);
	them(root, 2);
	them(root, 12);
	them(root, 10);
	them(root, 1);
	them(root, 3);
	them(root, 6);
	them(root, 5);
	them(root, 7);
	duyet_LNR(root);
	cout << endl << search(root, 9) << endl;
	cout << "Tong cac phan tu cua cay la: " << sum_Cay(root) << endl;

	cout << "Gia tri lon nhat trong mang la: " << max(root) << endl;
	cout << "Gia tri nho nhat trong mang la: " << min(root) << endl;
	cout << "So cac nut tren cay la: " << count_Node(root) << endl;
	del(root, 4);
	duyet_LNR(root);
	system("pause");
	return 0;
}

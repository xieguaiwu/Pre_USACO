#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *ptr;
};

int main() {
	Node n1, n2, n3;
	n1 = {10, &n2};
	n2 = {20, &n3};
	n3 = {30, &n1};
	Node *shit = &n1;
	cout << "Linked List Traversal: ";
	for (int i = 0; i < 3; ++i) {
		cout << shit -> data << " ";
		shit = shit -> ptr;
	}
}

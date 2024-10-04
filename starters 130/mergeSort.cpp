#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *next, *prev;
	Node(int x) {
		data = x;
		next = prev = NULL;
	}
};

struct Node* merge(struct Node* node1, struct Node* node2) {
	struct Node* ptr;
	while(node1 && node2) {
		ptr = node1;
		if(node1->data <= node2->data) {
			node1 = node1->next;
		} else {
			struct Node* tmp = node2->next;
			node2->next = node1;
			if(node1->prev) {
				node1->prev->next = node2;
				node2->prev = node1->prev;
			}
			node1->prev = node2; 
			node2 = tmp;
			if(node2) node2->prev = NULL;
		}
	}
	if(node2 != NULL) {
		node2->prev = ptr;
		ptr->next = node2;
	}
	while(ptr->prev) {
		ptr = ptr->prev;	
	}
	return ptr;
}

struct Node* mergeSort(struct Node* node, int len) {
	if(len == 1) return node;
	struct Node *node2 = node;
	for(int i = 1; i <= len/2; i++) {
		node2 = node2->next;
	}
	node2->prev->next = NULL;
	node2->prev = NULL;
	node = mergeSort(node, len/2);
	node2 = mergeSort(node2, len-len/2);
	node = merge(node, node2);
	return node;
}

struct Node* sortDoubly(struct Node *head) {
	int len = 0;
	struct Node* temp = head;
	while(temp) {
		len++;
		temp = temp->next;
	}
	mergeSort(head, len);
}

int main() {
	struct Node *n1 = new Node(1);
	struct Node *n2 = new Node(2);
	struct Node *n3 = new Node(3);
	struct Node *n4 = new Node(5);
	struct Node *n5 = new Node(4);
	n5->next = n4;
	n4->prev = n5;
	n4->next = n3;
	n3->prev = n4;
	n3->next = n2;
	n2->prev = n3;
	n2->next = n1;
	n1->prev = n2;
	struct Node* head = sortDoubly(n5);
	struct Node* tmp = head, *last;
	while(tmp) {
		last = tmp;
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
	while(last) {
		cout << last->data << " ";
		last = last->prev;
	}
}




























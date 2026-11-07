#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	
	Node(int val) {
		data = val;
		next = NULL;
	}
};

class Circular {
	Node* head;
	Node* tail;
public:
	Circular () {
		head = NULL;
		tail = NULL;
	}
	
	void insert_end(int val) {
		Node* newNode = new Node(val);
		if(head == NULL) {
			head = newNode;
			tail = newNode;
			newNode->next = head;
			return;
		}

		tail->next = newNode;
		tail = newNode;
		tail->next = head;
	}
	
	void insert_head (int val) {
		Node* newNode = new Node(val);
		if(head == NULL) {
			head = newNode;
			tail = newNode;
			newNode->next = head;
			return;
		}
		tail->next = newNode;
		newNode->next = head;
		head = newNode;
	}
	
	void insert_pos (int pos, int val) {
		Node* newNode = new Node(val);
		Node* curr;
		Node* pre;
		if(pos == 0) {
			insert_head(val);
			return;
		}
		curr = head;
		pre = NULL;
		for(int i=0; i<pos; i++) {
			pre = curr;
			curr = curr->next;
		}
		pre->next = newNode;
		newNode->next = curr;
	} 
	
	void delete_pos (int pos) {
		Node* curr = head;
		Node* pre = NULL;
		for(int i=0; i<pos; i++) {
			pre = curr;
			curr = curr->next;
		}
		pre->next = curr->next;
		delete curr;
	}
	
	void display() {
		Node* temp = head;
		if(head == NULL) {
			return;
		}
		while(temp->next != head) {
			cout << temp->data << "->";
			temp = temp->next; 
		}
		cout << temp->data << "->HEAD";
	}
	
};

int main() {
	Circular c;
	c.insert_end(4);
	c.insert_end(5);
	c.insert_end(6);
	
	c.insert_head(1);
	c.insert_head(2);
	
	c.insert_pos(2,3);
	
	c.delete_pos(5);
	
	c.display();
	
}

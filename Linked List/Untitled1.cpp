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

class Singly {
	
	Node* head;
	Node* tail;
public:
	Singly () {
		head = NULL;
		tail = NULL;
	}
	
	void insert_tail(int val) {
			Node* newNode = new Node(val);
			
			if(head == NULL) {
				head = newNode;
				tail = newNode;
				return;
			}
			
			Node* temp = head;
			while(temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = newNode;
			tail = newNode;
	}
	
	void modify() {
		Node* temp = head;
		
		Node* evenHead = NULL;
		Node* evenTail = NULL;
		
		Node* oddHead = NULL;
		Node* oddTail = NULL;
		
		while(temp != NULL) {
			Node* nextNode = temp->next;
			
			if(temp->data%2 == 0) {
				if(evenHead == NULL) {
					evenHead = temp;
					evenTail = temp;
				}
				else {
					evenTail->next = temp;
					evenTail = temp;
				}
			}
			else {
				if(oddHead == NULL) {
					oddHead = temp;
					oddTail = temp;
				}
				else {
					oddTail->next = temp;
					oddTail = temp;
				}
			}
			temp= nextNode;
		}  
		if(evenHead != NULL) {
			head = evenHead;
			evenTail->next = oddHead;
		}
		else {
			head = oddHead;
		}
		if(oddTail != NULL) {
			oddTail->next = NULL;
		}
		if(oddTail != NULL) {
			tail = oddTail;
		}
		else {
			tail = evenTail;
		}
	}
	
	void display() {
		Node* temp = head;
		while(temp != NULL) {
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout << "NULL";
	}
	
};

int main() {
	Singly s;
	int n, val;
	cout << "Enter number of nodes: ";
	cin >> n;

	for(int i=0; i<n; i++) {
		cout << "Enter " << i+1 << " Linked List: ";
		cin >> val;
		s.insert_tail(val);
	}
	
	cout << endl;
	s.modify();
	s.display();
	
}

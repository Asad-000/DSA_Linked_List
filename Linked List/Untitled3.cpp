#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class CircularDouble {
    Node* head;
    Node* tail;

public:
    CircularDouble() {
        head = NULL;
        tail = NULL;
    }

    void insert_end(int val) {
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = newNode;
            tail = newNode;
            newNode->next = head;
            newNode->prev = tail;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
        tail = newNode;
    }

    void insert_head(int val) {
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = newNode;
            tail = newNode;
            newNode->next = head;
            newNode->prev = tail;
            return;
        }
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
    }

    void insert_pos(int pos, int val) {
    	Node* newNode = new Node(val);
        if(pos == 0) {
            insert_head(val);
            return;
        }
        Node* curr = head;

        for(int i = 0; i < pos; i++) {
            curr = curr->next;
        }
        newNode->next = curr;
        newNode->prev = curr->prev;
        curr->prev->next = newNode;
        curr->prev = newNode;

        if(curr == head) {
            tail = newNode;
        }
    }

    void delete_pos(int pos) {
        if(head == NULL) {
            return;
        }
        if(pos == 0) {
            Node* temp = head;

            if(head == tail) {
                head = NULL;
                tail = NULL;
            }
            else {
                head = head->next;
                head->prev = tail;
                tail->next = head;
            }
            delete temp;
            return;
        }

        Node* curr = head;

        for(int i = 0; i < pos; i++) {
            curr = curr->next;
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        if(curr == tail) {
            tail = curr->prev;
        }
        delete curr;
    }

    void display() {
        if(head == NULL) {
            return;
        }
        Node* temp = head;

        while(temp->next != head) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << temp->data << "->HEAD";
    }
};

int main() {
    CircularDouble cd;

    cd.insert_end(4);
    cd.insert_end(5);
    cd.insert_end(6);

    cd.insert_head(2);
    cd.insert_head(1);

    cd.insert_pos(2, 3);

    cd.delete_pos(5);

    cd.display();
}

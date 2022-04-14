#include <iostream>
using namespace std;

class doublyList {
private:
    struct Node {
        int value;
        Node *next;
        Node *prev;

        Node(int val) {
            value = val;
        }

        Node(int val, Node *nextNode, Node *prevNode) {
            value = val;
            next = nextNode;
            prev = prevNode;
        }
    };
    Node *head;

public:
    doublyList() {
        head = NULL;
    }

    void insertBeg(int data) {
        Node* node = new Node(data, head, NULL);
        if (head != NULL) {
            head->prev = node;
        }
        head = node;
    }

    void insertEnd(int data) {
        if (!head) {
            insertBeg(data);
            return;
        }
        Node *last = head;
        while(last->next != NULL) {
            last = last->next;
        }
        Node *node = new Node(data, NULL, last);
        last->next = node;
    }

    void insertAfter(int after, int data) {
        Node *temp = head;
        while(temp->value != after) {
            temp = temp->next;
            if (temp == NULL) {
                cout<<"The element wasn't found\n";
                return;
            }
        }
        Node *node = new Node(data, temp->next, temp);
        Node *last = temp->next;
        temp->next = node;
        last->prev = node;
    }

    void insertBefore(int before, int data) {
        if (head->value == before) {
            insertBeg(data);
            return;
        }
        Node *temp = head;
        while (temp-> value != before) {
            temp = temp->next;
            if (temp == NULL) {
                cout<<"The element wasn't found\n";
                return;
            }
        }
        Node *node = new Node(data, temp, temp->prev);
        Node *prevNode = temp->prev;
        temp->prev = node;
        prevNode->next = node;
    }

    void deleteBeg() {
        if (!head) {
            cerr<<"List is empty\n";
            return;
        }
        (head->next)->prev = NULL;
        head = head->next;
    }

    void deleteEnd() {
        if (!head) {
            cerr<<"List is empty\n";
            return;
        }
        Node *secondLast = head;
        while(secondLast->next->next != NULL) {
            secondLast = secondLast->next;
        }
        secondLast->next = NULL;
    }

    void deleteAfter(int after) {
        if(!head) {
            cerr<<"List is empty\n";
            return;
        }
        Node *temp = head;
        while(temp->value != after) {
            temp = temp->next;
            if (temp == NULL) {
                cout<<"The element wasn't found.\n";
                return;
            }
        }
        Node *nNode = temp->next->next;
        temp->next = temp->next->next;
        nNode->prev = temp;
    }

    void deleteBefore(int before) {
        if (!head) {
            cerr<<"List is empty\n";
            return;
        }
        Node *temp = head;
        while(temp->value != before) {
            temp = temp->next;
        }
        Node *nodePrev = temp->prev->prev;
        temp->prev = nodePrev;
        nodePrev->next = temp;
    }

    void display() {
        if(!head) {
            cerr<<"list is empty\n";
            return;
        }
        Node *temp = head;
        while(temp != NULL) {
            cout<<temp->value<<" -> ";
            temp = temp->next;
        }
        cout<<"END\n";
    }
};

int main() {
    doublyList d;
    d.insertBeg(5);
    d.insertBeg(3);
    d.insertEnd(7);
    d.insertAfter(5, 6);
    d.insertBefore(5, 4);
    d.deleteBeg();
    d.deleteEnd();
    d.insertEnd(7);
    d.insertEnd(8);
    d.deleteAfter(9);
    d.deleteAfter(6);
    d.deleteBefore(6);
    d.display();
    return 0;
}

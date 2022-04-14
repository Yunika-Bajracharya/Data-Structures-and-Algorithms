#include <iostream>
using namespace std;

class SinglyLinkedList {
private:
    struct Node {
        int value;
        Node *next;

        Node (int data) {
            value = data;
        }

        Node (int data, Node *nextNode) {
            value = data;
            next = nextNode;
        }
    };
    Node *head, *tail;
    int size;

public:
    SinglyLinkedList() {
        size = 0;
        head = tail = NULL;
    }

    void insertBeg(int data) {
        Node *node = new Node(data);
        node->next = head;
        head = node;

        // if list is empty
        if (tail == NULL) {
            tail = head;
        }
        size++;
    }

    void insertEnd(int data) {
        if (!head) {
            insertBeg(data);
            return;
        }
        Node *node = new Node(data);
        node->next = NULL;
        tail->next = node;
        tail = node;

        size++;
    }

    void insertAfter(int data, int after) {
        if (!head) {
            cout<<"Invalid Insertion: List is empty\n";
            return;
        }

        if (tail->value == after){
            insertEnd(data);
            return;
        }

        Node *temp = head;
        while (temp->value != after) {
            temp = temp->next;
            if (!temp) {
                cout<<"Invalid Insertion: Element not found\n";
                return;
            }
        }
        Node *node = new Node(data, temp->next);
        temp->next = node;
        size++;
    }

    void insertBefore(int data, int before) {
        if (!head) {
            cout<<"Invalid insertion: List is empty\n";
            return;
        }
        if (before == head->value) {
            insertBeg(data);
            return;
        }
        Node *temp, *prev;
        temp = head;
        while(temp->value != before) {
            prev = temp;
            temp = temp->next;
            if (!temp) {
                cout<<"Invalid insertion: Element not found\n";
                return;
            }
        }
        Node *node = new Node(data, temp);
        prev->next = node;
        size++;
    }

    int deleteBeg() {
        if(!head) {
            cout<<"List is empty\n";
            return -1;
        }
        int val = head->value;
        head = head->next;

        // if there was only 1 node
        if(head == NULL) {
            tail = NULL;
        }
        size--;
        return val;
    }

    int deleteEnd() {
        if (!head) {
            cout<<"List is empty\n";
            return -1;
        }
        Node *temp, *prev;
        temp = head;
        while(temp->next) {
            prev = temp;
            temp = temp->next;
        }
        int val = temp->value;
        prev->next = NULL;
        size--;
        return val;
    }

    int deleteAfter(int after) {
        if (!head) {
            cout<<"List is empty\n";
            return -1;
        }
        Node *temp = head;
        while(temp->value != after) {
            temp = temp->next;
            if (!temp) {
                cout<<"Invalid deletion: node not found\n";
                return -1;
            }
        }
        if (temp->next == NULL) {
            cout<<"Invalid deletion: no node after element"<<endl;
            return -1;
        }
        int val = temp->next->value;
        temp->next = (temp->next)->next;
        size--;
        return val;
    }


    void display() {
        if (head == NULL) {
            cout<<"\nList is empty\n";
            return;
        }
        Node *temp = head;
        while (temp != NULL) {
            cout<<temp->value<<"->";
            temp = temp->next;
        }
        cout<<"END";
        cout<<"\nNo of elements: "<<size<<endl<<endl;
    }
};

int main() {
    SinglyLinkedList l;
    l.insertEnd(3);
    l.insertBefore(2, 3);
    l.deleteBeg();
    l.insertBeg(4);
    l.insertEnd(5);
    l.display();
    l.deleteAfter(4);
    l.display();
    return 0;
}

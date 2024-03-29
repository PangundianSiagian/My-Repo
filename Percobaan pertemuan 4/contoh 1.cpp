#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

int main(){
    Node* head = new Node();
    head->data = 1;
    head->next = NULL;

    Node* second = new Node();
    second->data = 2;
    second->next = NULL;

    head->next = second;

    Node* third = new Node();
    third->data = 3;
    third->next = NULL;

    second->next = third;

    Node* node = head;
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
    return 0;
}

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

int size_list(Node* head){
    int length = 0;
    Node* curr = head;
    while (curr != NULL){
        length++;
        curr = curr->next;
    }
    return length;
}

void print(Node* head){
    Node* curr = head;
    while (curr != NULL){
        cout << curr->data << ' ';
        curr = curr->next;
    }
    cout << endl;
}

Node* insert_tail(Node* head, int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL){
        head = newNode;
        return head;
    }
    Node* curr = head;
    while (curr->next != NULL){
        curr = curr->next;
    }
    curr->next = newNode;
    newNode->prev = curr;
    return head;
}



int bai_3(Node* head){
    if (size_list(head) < 3) return 0;

    int cnt = 0;
    Node* curr = head->next;
    while (curr->next != NULL){
        if (curr->data + curr->next->data + curr->prev->data == 0) cnt++;
        curr = curr->next;
    }
    return cnt;
}


int main(){
    Node* l = NULL;
    int n;
    cin >> n;
    for (int i = 0; i< n; i ++){
        int element;
        cin >> element;
        l = insert_tail(l, element);
    }
    cout << bai_3(l) << endl;
    return 0;
}

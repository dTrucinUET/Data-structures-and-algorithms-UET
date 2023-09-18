#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
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

Node* insert_head(Node* head, int &value){
    Node* temp = new Node();
  //  cout << "value " << value << endl;
    temp->data = value;
    temp->next = NULL;
  //  print(temp);
    if (head == NULL){
        head = temp;
        return head;
    }

    temp->next = head;
    return temp;
}

Node* insert_tail(Node*head, int &value){
    Node* temp = new Node();
    temp->data = value;
    temp->next = NULL;

    Node* curr = head;
    while (curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;

    return head;
}

Node* insert_node(Node* head, int &position, int &value){
    if (head == NULL || position == 0) {
        head = insert_head(head, value);
        return head;
    }
    if (position == size_list(head)){
        head = insert_tail(head, value);
        return head;
    }

    Node* temp = new Node();
    temp->data = value;
    temp->next = NULL;
    Node* curr = head;
    for (int i = 0; i < position - 1; i ++) curr = curr->next;
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

Node* delete_head(Node* head){
    Node* curr = head->next, *del = head;
    delete del;
    return curr;
}

Node* delete_tail(Node* head){
    Node* del = head;
    while (del->next != NULL){
        del = del->next;
    }
    Node* curr = head;
    while (curr->next != del){
        curr = curr->next;
    }
    curr->next = NULL;
    delete del;
    return head;
}

Node* delete_node(Node* head, int &position){
    if (head == NULL) return head;

    if (position == 0){
        head = delete_head(head);
        return head;
    }
    if (position == size_list(head) - 1){
        head = delete_tail(head);
        return head;
    }

    Node* curr = head;
    for (int i = 0; i < position - 1; i ++) curr = curr->next;
    Node* del = curr->next;
    curr->next = del->next;
    delete del;
    return head;
}

int main(){
    Node *l = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++){
        string s;
        int position;
        cin >> s >> position;
        if (s == "insert"){
            int value;
            cin >> value;
            l = insert_node(l, position, value);
        }
        else l = delete_node(l, position);
    }
    print(l);
}

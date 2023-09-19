#include <iostream>

using namespace std;

struct Stack{
    int *arr;
    int max_size, cnt, top;

    Stack(int _max_size = 5){
        max_size = _max_size;
        arr = new int[max_size];
        cnt = 0;
        top = -1;
    }

    bool isEmpty(){
        return cnt == 0;
    }

    bool isFull(){
        return cnt == max_size;
    }

    bool push(int element){
        if (isFull()) return false;
        arr[cnt] = element;
        cnt ++;
        top ++;
        return true;
    }

    bool pop(){
        if (isEmpty()) return false;
        cnt--;
        top--;
        return true;
    }

    int peek(){
        if (isEmpty()) return false;
        return arr[top];
    }

    int getSize(){
        return cnt;
    }
};

struct Queue{
    Stack stack1, stack2;
    int cnt;
    int max_size;
    int fr, rear;

    Queue(int size_stack){
        max_size = size_stack;
        stack1 = Stack(max_size);
        stack2 = Stack(max_size);
        cnt = 0;
        fr = -1;
        rear = -1;
    }

   bool enqueue(int element) {
        if (isFull()) return false;
        while (!stack1.isEmpty()) {
            stack2.push(stack1.peek());
            stack1.pop();
        }
        stack1.push(element);
        while (!stack2.isEmpty()) {
            stack1.push(stack2.peek());
            stack2.pop();
        }
        cnt ++;
        rear = (rear + 1)%max_size;
        return true;
    }

    bool dequeue() {
        if (isEmpty()) return false;
        stack1.pop();
        fr = (fr + 1)%max_size;
        return true;
    }

    int front() {
        if (isEmpty()) return -1;
        return stack1.peek();
    }

    bool isEmpty() {
        return cnt == 0;
    }

    bool isFull() {
        return cnt == max_size;
    }

};

int main(){

    Queue q(6);
    for (int i = 1; i <= 6; i++){
        q.enqueue(i);
    }
    cout << q.front() << endl;
    q.dequeue();
    cout << q.front() << endl;
    return 0;
}


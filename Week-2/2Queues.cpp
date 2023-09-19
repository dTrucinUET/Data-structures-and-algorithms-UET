#include <iostream>

using namespace std;

struct Queue{
    int *arr;
    int fr, rear, cnt, max_size;

    Queue(int _max_size = 5){
        max_size = _max_size;
        arr = new int[max_size];
        fr = 0; rear = -1;
        cnt = 0;
    }

    bool isEmpty(){
        return (cnt == 0);
    }

    bool isFull(){
        return (cnt == max_size);
    }

    bool enqueue(int element){
        if (isFull()) return false;

        rear = (rear + 1)%max_size;
        arr[rear] = element;
        cnt ++;
        return true;
    }

    bool dequeue(){
        if (isEmpty()) return false;
        fr = (fr + 1)%max_size;
        cnt --;
        return true;
    }

    int peek(){
        if (isEmpty()) return -1;

        return arr[fr];
    }

};

int MAX = 6;
struct Stack{

    Queue queue1, queue2;
    int cnt;
    int max_size;

    Stack(int size_queue){
        max_size = size_queue;
        queue1 = Queue(max_size);
        queue2 = Queue(max_size);
        cnt = 0;
    }

    bool isEmpty(){
        return cnt == 0;
    }

    bool isFull(){
        return cnt == max_size;
    }

    bool push(int element){
        if (isFull()) return false;

        queue1.enqueue(element);
        cnt ++;
        return true;
    }

    bool pop(){
        if (isEmpty()) return false;
        while (queue1.cnt != 1) {
            queue2.enqueue(queue1.peek());
            queue1.dequeue();
        }
        queue1.dequeue();
        while(!queue2.isEmpty()) {
            queue1.enqueue(queue2.peek());
            queue2.dequeue();
        }
        cnt--;
        return true;
    }

    int top(){
        if (isEmpty()) return -1;
        while (queue1.cnt > 1) {
            queue2.enqueue(queue1.peek());
            queue1.dequeue();
        }
        int result = queue1.peek();
        queue2.enqueue(queue1.peek());
        queue1.dequeue();
        while(!queue2.isEmpty()) {
            queue1.enqueue(queue2.peek());
            queue2.dequeue();
        }
        return result;
    }

};

int main(){

    Stack s(6); // 1 2 3 4 5 6
    for (int i = 1; i <= 6; i ++){
        s.push(i);
    }
    cout << s.top() << endl; // 6
    s.pop(); // 1 2 3 4 5
    s.pop(); // 1 2 3 4
    cout << s.top() << endl; //4
    s.push(7); // 1 2 3 4 7
    s.pop(); // 1 2 3 4
    cout << s.top() << endl; // 4

    return 0;
}

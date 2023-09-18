#include <iostream>

using namespace std;

struct Queue{
    int *arr;
    int fr, rear, cnt, max_size;

    Queue(int _max_size){
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

    void print(){
        for (int i = fr; i <= rear; i ++) cout << arr[i] << ' ';
        cout << endl;
    }

};

int main(){

    int MAX = 10;
    Queue q(MAX);
    int n;
    cin >> n;

    for (int i = 0; i < n; i ++){
        string s;
        cin >> s;
        if (s == "enqueue"){
            int element;
            cin >> element;
            q.enqueue(element);
        }
        else q.dequeue();
    }
    q.print();

    return 0;
}

#include <iostream>

using namespace std;

struct Stack{
    int *arr;
    int top, max_size, cnt;

    Stack(int _max_size){
        max_size = _max_size;
        arr = new int[max_size];
        top = 0;
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
        arr[top] = element;
        top ++;
        cnt ++;
        return true;
    }

    bool pop(){
        if (isEmpty()) return false;
        top--;
        cnt--;
        return true;
    }

    void print(){
        for (int i = 0; i < top; i ++) cout << arr[i] << ' ';
        cout << endl;
    }

};

int main(){

    int MAX = 10;
    Stack st(MAX);
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++){
        string s;
        cin >> s;
        if (s == "push"){
            int element;
            cin >> element;
            st.push(element);
        }
        else st.pop();
    }
    st.print();

    return 0;
}

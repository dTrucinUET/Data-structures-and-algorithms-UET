#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

class Sort{

    public:

    void print(){
        for (int i = 0; i < int(arr.size()); i++)
        cout << arr[i] << ' ';
        cout << endl;
    }

    void print(vector<int> &temp){
        for (int i = 0; i < int(temp.size()); i++)
        cout << temp[i] << ' ';
        cout << endl;
    }

    void random(){
        int n = rand()%10 + 5;
        for (int i = 0; i < n; i ++){
            int x = rand()%100;
            arr.push_back(x);
        }
    }

    void bubble_sort(){
        int len = arr.size();
        for (int i = 0; i < len - 1; i ++){
            for (int j = i + 1; j < len; j ++){
                if (arr[i] > arr[j]) swap(arr[i], arr[j]);
            }
        }
    }
    void selection_sort(){
        int len = arr.size();
        for (int i = 0; i < len - 1; i ++){
            int min_value = arr[i + 1], min_index = i + 1;
            for (int j = i + 1; j < len; j ++){
                if (arr[j] < min_value){
                    min_value = arr[j];
                    min_index = j;
                }
            }
            if (i != min_index && arr[i] > min_value) swap(arr[i], arr[min_index]);
        }
    }

    void insection_sort(){
        int len = arr.size();
        for (int i = 0; i < len; i ++){
            int j = i, temp = arr[i];
            while (j > 0 && temp < arr[j - 1]) j --;
            if (true){
            for (int k = i; k > j; k --)
                arr[k] = arr[k - 1];
                arr[j] = temp;
            }
        }
    }

    void Merge(vector<int> &arr, int left, int mid, int right){
        vector<int> arr_left(arr.begin() + left, arr.begin() + mid + 1);
        vector<int> arr_right(arr.begin() + mid + 1, arr.begin() + right + 1);
        int i = 0, j = 0;
        int index = left;
        while (i < arr_left.size() && j < arr_right.size()){
            if (arr_left[i] <= arr_right[j]) arr[index++] = arr_left[i++];
            else arr[index++] = arr_right[j++];
        }
        while (i < arr_left.size()){
            arr[index] = arr_left[i];
            index ++; i ++;
        }
        while (j < arr_right.size()){
            arr[index] = arr_right[j];
            index ++; j ++;
        }
    }

    void merge_sort(int left, int right){
        if (left >= right) return;

        int mid = left + (right - left)/2;
        merge_sort(left, mid);
        merge_sort(mid + 1, right);
        Merge(arr, left, mid, right);
    }

    int Partition(int low, int high)
    {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    void quick_sort(int low, int high)
    {
        if (low < high) {
            int pi = Partition(low, high);
            quick_sort(low, pi - 1);
            quick_sort(pi + 1, high);
        }
    }


    int getSize(){
        return arr.size();
    }

    private:
        vector<int> arr;
};


int main(){

    srand(time(0));
    Sort v;
    v.random();
    cout << "Mang ban dau: ";
    v.print();
    v.quick_sort(0, v.getSize());
    v.print();

    return 0;
}


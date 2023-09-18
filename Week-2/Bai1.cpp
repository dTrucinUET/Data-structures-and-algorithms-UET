#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

void print(int *arr, int size_arr){

    for (int i = 0; i < size_arr; i ++)
        cout << arr[i] << ' ';
    cout << endl;

}

int nCk(int n, int k){

    if (k > n) return 0;
    int res = 1;
    if (k == n || k == 0) return res;
    for (int i = k + 1; i <= n; i ++) res *= i;
    int temp = 1;
    for (int i = 2; i <= n - k; i ++) temp *= i;
    return res/temp;
}


void Merge(int *arr, int left, int mid, int right){

    int left_size = mid - left + 1, right_size = right - mid;
    int *arr_left = new int[left_size];
    int *arr_right = new int[right_size];

    for (int i = 0; i < left_size; i ++)
        arr_left[i] = arr[left + i];

    for (int i = 0; i < right_size; i ++)
        arr_right[i] = arr[mid + i + 1];

    int i = 0, j = 0, index = left;
    while (i < left_size && j < right_size){
        if (arr_left[i] <= arr_right[j]){
            arr[index] = arr_left[i];
            index++;
            i++;
        }
        else{
            arr[index] = arr_right[j];
            index++;
            j++;
        }
    }
    while (i < left_size){
        arr[index] = arr_left[i];
        index++;
        i++;
    }
    while (j < right_size){
        arr[index] = arr_right[j];
        index++;
        j++;
    }

}

void merge_sort(int *arr, int left, int right){

    if (left >= right) return;
    int mid = left + (right - left)/2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    Merge(arr, left, mid, right);
}

int bai_1(int *arr, int size_arr){

    merge_sort(arr, 0, size_arr - 1);

    int cnt = 1, res = 0;
    for (int i = 0; i < size_arr - 1; i ++){
        if (arr[i] == arr[i + 1]) cnt ++;
        else{
            res += nCk(cnt, 2);
            cnt = 1;
        }
    }
    res += nCk(cnt, 2);
    return res;
}

int bai_1_test(int *arr, int size_arr){

    int cnt = 0;
    for (int i = 0; i < size_arr - 1; i ++){
        for (int j = i + 1; j < size_arr; j ++){
            if (arr[i] == arr[j]) cnt ++;
        }
    }
    return cnt;
}

int main(){

    int n = 6;
    int *arr = new int[n];
    for (int i = 0; i < n; i ++) cin >> arr[i];
    cout << boolalpha << (bai_1(arr, n) == bai_1_test(arr,n)) << endl;

    return 0;
}

#include <iostream>
using namespace std;
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void insertion_sort(int a[], int n){
    int j = 0;
    for(int i =1; i<n; i++){
        int value = a[i];
        j=i-1;
        while(value<a[j]&&j>=0){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = value;
    }
}
void selection_sort(int a[], int n){
    for(int i =0; i<n; i++){
        int min_pos=  i;
        for(int j =i+1; j<n; j++){
            if(a[i]>a[j]){
                min_pos = j;
            }
        }
        swap(a[i], a[min_pos]);
    }
}
void bubble_sort(int a[], int n){

    bool swapped;
    do{
        swapped = false;
        for(int i =0; i<n-1;i++){
            if(a[i]>a[i+1]){
                 swap(a[i], a[i+1]);
                 swapped =  true;
            }
        }
    }while(swapped);
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    //insertion_sort(a, n);
    selection_sort(a, n);
    //bubble_sort(a, n);

    for(int i = 0; i<n; i++){
        cout << a[i] << " ";
    }


}

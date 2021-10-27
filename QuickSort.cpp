#include <iostream>
#include <array>
using namespace std;

template <typename T, size_t size>
int partition(std::array<T,size>& arr,int low, int high) {
    int piv = arr.at(high);
    int i_ind = low - 1;
    T first;
    
    for(int j=low;j<high;j++) {
        if (arr.at(j)<piv) {
            i_ind ++;
            // Exchange A[i] with A[j]
            first = arr.at(i_ind);
            arr.at(i_ind) = arr.at(j);
            arr.at(j) = first;
        }
    }
    first = arr.at(i_ind+1);
    arr.at(i_ind+1) = arr.at(high);
    arr.at(high) = first;
    
    return (i_ind+1);
}

template <typename T,size_t size>
void quicksort(std::array<T,size>& arr,int low,int high) {
    if (low<high) {
        int q = partition(arr,low,high); // Partition
        quicksort(arr, low, q-1);  // Divide and Conquer recursive procedure
        quicksort(arr, q+1, high);
    }
}

int main() {
    
    array<int,8> arr = {3,8,5,2,10,7,4,6}; // Let's try our algorithm
    quicksort(arr, 0, arr.size()-1);
    
    for (const auto& s: arr) {
        cout<<s<<'\t';
    }
    
    cout<<'\n';
    
    return 0;
}

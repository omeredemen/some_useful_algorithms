#include <iostream>

class BinarySearch { 
 public:
    int binarySearch(int arr[], int r, int x) { 
        int l = 0; 
        while (l <= r) { 
            int m = l + (r - l) / 2;
            if (arr[m] == x) 
                return m;
            if (arr[m] < x) 
                l = m + 1;
            else
                r = m - 1; 
        } 
        return -1; 
    } 
};


int main(){
    BinarySearch search;
    int arr[5] = { 1, 3, 5, 7, 9 };
    int x = 7;
    int r = (sizeof(arr) / sizeof(int)) - 1;
    int result = search.binarySearch(arr, r, x); 
    std::cout<<"result: "<< result;
}

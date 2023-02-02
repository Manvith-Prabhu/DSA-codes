//Manvith Prabhu
//211EC228
#include <iostream>
using namespace std;

void create_heap(int a[], int n, int i) {
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  int largest = i;
  if (left<n&&a[left]>a[largest]) {
    largest = left;
  }
  if(right<n&&a[right]>a[largest]) {
    largest = right;
  }
  if(largest!=i) {
    int t=a[i];
    a[i]=a[largest];
    a[largest]=t;
    create_heap(a, n, largest);
  }
}

void createMaxHeap(int a[], int n) {
  for (int i = (n / 2) - 1; i >= 0; i--) {
    create_heap(a, n, i);
  }
}

int main() {
 
  int a[] = {4,1,3,2,16,9,10,14,8,7};
  /*input tree:
            4
          /   \
        1       3
       / \     / \
     2    16  9   10
    / \  /   
  14  8 7  
                              */
  int n = 10;

  createMaxHeap(a, n);

  cout << "Max heap: ";
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
 /*output max heap:
            16
          /   \
        14     10
       /  \    / \
     8     7  9   3
    / \   /   
   2   4 1  
                              */
  return 0;
}

#include <iostream>
using namespace std;


// Swaps Elements ---
void swaps(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}


// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int largest = root;
    int left = 2*root+1;  // left child --
    int right = 2*root +2; // Right Child --

    if(left<n && arr[left]> arr[root]){
        largest = left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest = right;
    }

    if(largest != root){
        swaps(arr[root],arr[largest]);

        heapify(arr,n,largest);
    }


}


// Build heap function ----
void buildHeap(int arr[],int n){
    for (int i = (n/2)-1; i >= 0; i--){
        heapify(arr, n, i);  // call heapify function --
    }
}


// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   buildHeap(arr,n);


   // extracting elements from heap one by one
   for (int i = n - 1; i >0; i--) {
        swaps(arr[0], arr[i]);
        heapify(arr, i, 0);
    }


}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}

// main program
int main()
{
   int arraySize;
    cout<<"Input Array size : ";
    cin>>arraySize;

    int heap_arr [arraySize];

    cout<<"Enter array : ";
    for(int i=0;i<arraySize;i++){
        cin>>heap_arr[i];
    }
   cout<<"Input array"<<endl;
   displayArray(heap_arr,arraySize);

   heapSort(heap_arr, arraySize);

   cout << "Sorted array"<<endl;
   displayArray(heap_arr, arraySize);
}

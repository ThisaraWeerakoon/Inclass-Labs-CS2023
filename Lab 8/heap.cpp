#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify

   //get index of the left child
   int leftChildIndex=2*root+1; 

   //get index of the right child
   int rightChildIndex=2*root+2;

   //To store current largest node among parent leftchild and rightchild
   int largest;

   //Check leftChild exceeds the array size
   //Compare what is larger from root and leftChild
   if(leftChildIndex<n && arr[leftChildIndex]>arr[root]){
      largest=leftChildIndex;
   }
   else{
      largest=root;
   }

   //Check rightChild exceeds the array size
   //Compare what is larger from current largest element and right child
   if(rightChildIndex<n && arr[largest]<arr[rightChildIndex]){
      largest=rightChildIndex;
   }

   //if the root element is not the largest swap largest child with root and once again call heapify on previous root
   if(largest!=root){
      swap(arr[root],arr[largest]);
      heapify(arr,n,largest);
   }
  
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for(int i=n/2-1;i>=0;i--){
      heapify(arr,n,i);
   }
   
  
   // extracting elements from heap one by one
   for(int i=n-1;i>=0;i--){
      swap(arr[0],arr[i]);//swap last element and the first one
      heapify(arr,i,0);//heapify array by reducing its size by 1
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
   //Get number of elements in array from user.
   int n;
   cout<<"Number of elements? ";
   cin>>n;

   //Get elements of the array by user
   int heap_arr[n];
   cout<<"Enter array :\n";
   for(int i=0;i<n;i++){
      cin>>heap_arr[i];
   }

   //Display input array 
   cout<<"\nInput array\n";
   displayArray(heap_arr,n);
  
   //Heapsort
   heapSort(heap_arr, n);
  
   //Display sorted array
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}

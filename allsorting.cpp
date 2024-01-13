#include <iostream>
using namespace std;

// Bubble Sort 
// Worst Case: O(n^2)
// Average Case: O(n^2)
// Best Case: O(n) (when the array is already sorted, but it still requires a pass through the array to confirm)

// void bubble(int arr[],int n){
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n-i-1;j++){
//             if(arr[j]>arr[j+1]){
//                 swap(arr[j],arr[j+1]);
//             }
//         }
//     }
// }
// int main(){
//     int arr[] = {11,22,33,44,55,66,77,88,99,45,35,48};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     cout<<"before"<<endl;
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl<<"after"<<endl;
//     bubble(arr,n);
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl<<"second last :- "<<arr[n-2];
//     return 0;
// }

// Insertion sort 
// Worst Case: O(n^2)
// Average Case: O(n^2)
// Best Case: O(n) (when the array is nearly sorted)

// void insertion(int arr[],int n){
//     for(int i=1;i<n;i++){
//         int j = i-1;
//         int key = arr[i];
//         while(j>=0 && arr[j]>key){
//             arr[j+1] = arr[j];
//             j--;
//         }
//         arr[j+1]=key;
//     }
// }

// int main(){
//     int arr[] = {11,22,33,44,55,66,77,88,99,45,35,48};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     cout<<"before"<<endl;
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl<<"after"<<endl;
//     insertion(arr,n);
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl<<"second last :- "<<arr[n-2];
//     return 0;
// }

// selection sort

// Time Complexity:
// Worst Case: O(n^2)
// Average Case: O(n^2)
// Best Case: O(n^2) (It does not depend on the input data)

// void selection(int arr[],int n){
//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             if(arr[i]>arr[j]){
//                 swap(arr[i],arr[j]);
//             }
//         }
//     }
// }

// int main(){
//     int arr[] = {11,22,33,44,55,66,77,88,99,45,35,48};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     cout<<"before"<<endl;
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl<<"after"<<endl;
//     selection(arr,n);
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl<<"second last :- "<<arr[n-2];
//     return 0;
// }

// Quick Sort:

// Time Complexity:
// Worst Case: O(n^2) - can occur when the pivot choice is poor (e.g., always picking the first element)
// Average Case: O(n log n)
// Best Case: O(n log n) (average time when a good pivot strategy is chosen)

// int quick(int arr[],int s,int e){
//     int p = arr[s];
//     int i=s+1;
//     int j=e;
//     do{
//         while(arr[i]<=p){
//             i++;
//         }
//         while (arr[j]>p)
//         {
//             j--;
//         }
//         if(i<j){
//             swap(arr[i],arr[j]);
//         }
//     }while(i<j);
//     swap(arr[j],arr[s]);
//     return j;
// }
// void quicksort(int arr[],int s,int e){
//     if(s<e){
//         int pi = quick(arr,s,e);
//         quicksort(arr,s,pi-1);
//         quicksort(arr,pi+1,e);
//     }
// }
// int main(){
//     int arr[] = {11,22,33,44,55,66,77,88,99,45,35,48};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     cout<<"before"<<endl;
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl<<"after"<<endl;
//     quicksort(arr,0,n-1);
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl<<"second last :- "<<arr[n-2];
//     return 0;
// }

// Merge Sort:

// Time Complexity:
// Worst Case: O(n log n)
// Average Case: O(n log n)
// Best Case: O(n log n) (It's consistent, regardless of the input)

void merge(int arr[],int mid,int s,int e){
    int i=s;
    int j=mid+1;
    int k = s;
    int b[100];
    while (i<=mid &&j<=e)
    {
        if(arr[i]<arr[j]){
            b[k] = arr[i];
            i++;
            k++;
        }
        else{
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i<=mid)
    {
        b[k] = arr[i];
            i++;
            k++;
    }
    while (j<=e)
    {
        b[k] = arr[j];
            j++;
            k++;
    }
    for(int i=s;i<=e;i++){
        arr[i] = b[i];
    }
    
}
void mergesort(int arr[],int s,int e){
    if(s<e){
        int mid = s+(e-s)/2;
        mergesort(arr,s,mid);
        mergesort(arr,mid+1,e);
        merge(arr,mid,s,e);
    }
}
int main(){
    int arr[] = {11,22,33,44,55,66,77,88,99,45,35,48};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"before"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"after"<<endl;
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"second last :- "<<arr[n-2];
    return 0;
}
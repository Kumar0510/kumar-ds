#include<stdio.h>
int partition(int a[],int low,int high){
    int i=low-1,pivot = a[high];
    for(int j=low;j<high;j++){
        if(a[j] <= pivot){
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[high];
    a[high] = a[i+1];
    a[i+1] = temp;
    return i+1;
}
void quicksort(int a[], int l,int h){
    if(l<h){
        int p = partition(a,l,h);
        quicksort(a,l,p-1);
        quicksort(a,p+1,h);
    }
}
int main(){
    int a[] = {9,6,2,1};
    int n = sizeof(a)/sizeof(a[0]);
    printf("before Quick sort: \n");
    for(int i =0;i<n;i++)
        printf("%d ",a[i]);
    quicksort(a,0,n-1);
    printf("\nAfter Quick sort: \n");
    for(int i =0;i<n;i++)
        printf("%d ",a[i]);
}

//
// Created by sneha on 18-06-2022.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * Quick sort:
 * an element is sorted if all the elements to the left of it are smaller
 * and all the elements to the right are bigger than it
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * find ith>pth and jth<pth, swap
 * stop when i>j
 * then swap jth with pth
 * 50 70 60 90 40 80 10 20 30 inf
 * p  i                    j
 * 50 30 60 90 40 80 10 20 70 inf
 * p     i              j
 * 50 30 20 90 40 80 10 60 70 inf
 * p        i        j
 * 50 30 20 10 40 80 90 60 70 inf
 * p           j  i
 * (40 30 20 10) 50 (80 90 60 70 inf)
 *
 * j is called partitioning position
 * now quick sort in both partitions
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Worst case (already sorted (asc or desc) or partitioning at any end) time complexity: O(n^2)
 * Best case time complexity (partitioning in middle): O(nlogn)
 * Average case time complexity: O(nlogn)
 * can change worst case to avg by taking middle as pivot
 *
 * */

int partition(int a[], int l, int h){
    int pivot = a[l];
    int i=l, j=h;
    do{
        do{i++;}while(a[i]<=pivot);
        do{j--;}while(a[j]>pivot);
        if(i<j)swap(a[i], a[j]);
    }while(i<j);
    swap(a[l], a[j]);
    return j;

}
void quick_sort(int a[], int l, int h){
    if(l<h){
        int j = partition(a, l, h);
        quick_sort(a, l, j);
        quick_sort(a, j+1, h);
    }
}

int main() {
    int a[] = {6, 5, 4, 3, 2, 1, INT_MAX};
    int n = sizeof(a)/sizeof(a[0]);
    quick_sort(a, 0, n-1);
    for(int i=0;i<n-1;i++){
        cout<<a[i]<<"\t";
    }
    return 0;
}
//
// Created by sneha on 18-06-2022.
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * Merge sort:
 * Divide and Conquer algorithm
 * Divide the input array into two halves, sort them, merge.
 */



//time complexity: O(m+n)
void merge(int a[], int l, int mid, int h){
    //one array with l-mid and mid+1-h
    int i=l, j=mid+1, k=l;
    int b[h+1];
    while(i<=mid && j<=h){
        if(a[i]<a[j]){
            b[k++]=a[i++];
        }
        else{
            b[k++]=a[j++];
        }
    }
    while(i<=mid){
        b[k++]=a[i++];
    }
    while(j<=h){
        b[k++]=a[j++];
    }
    for(int i=l;i<=h;i++){
        a[i]=b[i];
    }
}

/*
 * Iterative:
 * Pass 1: 8   3   7   4   9   2   6   5
 *          \/  \/  \/  \/  \/  \/  \/
 * Pass 2: 8   4   7   3   2   9   5   6
 *         -----   -----   -----   -----
 *            \      /       \       /
 * Pass 3: 3   4   7   8   2   5   6   9
 *         -------------   -------------
 *                 \            /
 * Pass 4: 2   3   4   5   6   7   8   9
 * Time Complexity: O(nlogn)
 */

void iterative_merge_sort(int a[], int n){
    int p, i, l, mid, h;
    //this for loop iterates for logn times
    for(p=2;p<=n;p*=2){
        for(i=0;i+p-1<n;i+=p){
            l = i;
            h = i+p-1;
            mid = (h+ l)/2;
            merge(a, l, mid, h);
        }
    }
    //if the number of elements is not in powers of two
    if(p/2<n){
        merge(a, 0, p/2-1, n);
    }
}

/* Recursive version
 * Time Complexity: O(nlogn)
 */
void recursive_merge_sort(int a[], int l, int h){
    if(l<h){
        int mid = (l+h)/2;
        //first half
        recursive_merge_sort(a, l, mid);
        //second half
        recursive_merge_sort(a, mid+1, h);
        merge(a, l, mid, h);
    }
}


int main() {
    int a[] = {6, 5, 4, 3, 2, 1};
    int n = sizeof(a)/sizeof(a[0]);
    iterative_merge_sort(a, n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<"\t";
    }
    cout<<"\n";
    int a1[] = {6, 5, 4, 3, 2, 1};
    int n1 = sizeof(a1)/sizeof(a1[0]);
    recursive_merge_sort(a1, 0, n1-1);
    for(int i=0;i<n1;i++){
        cout<<a1[i]<<"\t";
    }
    return 0;
}
//
// Created by sneha on 18-06-2022.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * Selection sort:
 * select a position, lets say i = 0. The minimum should be at that place
 * go to each position and decide who sits there
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Pass 1:
 * ikj
 * 8  6  3  2  5  4
 * i        k        j
 * 8  6  3  3  5  4
 * swap ith, kth
 * 2  6  3  8  5  4
 *   ijk
 * 2  6  3  8  5  4
 *    i  k           j
 * 2  3  6  8  5  4
 *      ijk
 * 2  3  6  8  5  4
 *       i        k  j
 * 2  3  4  8  5  6
 *         ijk
 * 2  3  4  8  5  6
 *          i  k     j
 * 2  3  4  5  8  6
 *            ijk
 * 2  3  4  5  8  6
 *             i  k  j
 * 2  3  4  5  6  8
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * k passes gives k smallest elements
 * Not adaptive. Cant be made adaptive
 * Not stable. Order not maintained
 *
 * */

void selection_sort(int a[], int n){
    int j, k;
    for(int i=0;i<n;i++){
        k=i;
        for(j=i;j<n;j++){
            if(a[j]<a[k])
                k=j;
        }
        swap(a[i], a[k]);
    }
}

int main() {
    int a[] = {6, 5, 4, 3, 2, 1};
    int n = sizeof(a)/sizeof(a[0]);
    selection_sort(a, n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<"\t";
    }
    return 0;
}
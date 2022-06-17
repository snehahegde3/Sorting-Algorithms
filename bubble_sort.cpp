//
// Created by sneha on 18-06-2022.
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * Bubble Sort:
 * Pass 1
 * 8 5 7 3 2
 * ___
 * 5 8 7 3 2
 *   ___
 * 5 7 8 3 2
 *     ___
 * 5 7 3 8 2
 *       ___
 * 5 7 3 2 8
 * Comparisions: 4
 * Max Swaps: 4
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Pass 2:
 * 5 7 3 2 8
 * 5 7 3 2 8
 * 5 3 7 2 8
 * 5 3 2 7 8
 * Comparisions: 3
 * Max Swaps: 3
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Pass 3:
 * 5 3 2 7 8
 * 3 5 2 7 8
 * 3 2 5 7 8
 * Comparisions: 2
 * Max Swaps: 2
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Pass 4:
 * 3 2 5 7 8
 * 2 3 5 7 8
 * Comparisions: 1
 * Max Swaps: 1
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Pass: O(n)
 * Comparisions: O(n^2)
 * Max Swaps: O(n^2)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Hence Time Complexity Max: O(n^2) ; n -> array size
 *
 * k parses gives k largest elements
 *
 * Stable: order doesnt change unless greater
 */
void bubble(int a[], int n){
    for(int i=0;i<n-1;i++){
        //the last element  finds its place each time, so we use n-i-1
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }
}


void adaptive_bubble(int a[], int n){
    int flag = 0;
    for(int i=0;i<n-1;i++){
        //the last element  finds its place each time, so we use n-i-1
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j], a[j+1]);
                flag = 1;
            }
        }
        //it was already sorted, hence no swaps...
        if(flag == 0 ) break;
    }
}
/* Hence Time Complexity Min: O(n) using flag ; n -> array size*/



int main() {
    int a[] = {6, 5, 4, 3, 2, 1};
    int n = sizeof(a)/sizeof(a[0]);
    bubble(a, n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<"\t";
    }
    cout<<endl;
    int a1[] = {1, 2, 3, 4, 5, 6};
    int n1 = sizeof(a)/sizeof(a[0]);
    adaptive_bubble(a1, n1);
    for(int i=0;i<n1;i++){
        cout<<a1[i]<<"\t";
    }
    return 0;
}

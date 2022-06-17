//
// Created by sneha on 18-06-2022.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * Insertion Sort:
 * Inserting into an array in a sorted fashion to a sorted position
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Insertion into array:
 * 2 6 10 15 20 25 30
 * 12
 * 2 6 10 12 15 20 25 30
 * Time taken for inserting: O(n)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Insertion into list:
 * qp
 * 2->6->10->15->30
 * 18
 * q  p
 * 2->6->10->15->20
 *    q  p
 * 2->6->10->15->20
 *       q   p
 * 2->6->10->15->20
 *           q   p
 * 2->6->10->15->18->20 [q->18->p]
 * Time taken for inserting: O(n) [min: O(1) at first]
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Sorting :
 * 8 | 5 7 3 2 (one element sorted, others to be inserted. Left always sorted)
 * Insert 5:
 * 5 8 | 7 3 2
 * Insert 7:
 * 5 7 8 | 3 2
 * Insert 3:
 * 3 5 7 8 | 2
 * Insert 2:
 * 2 3 5 7 8
 * Passes: O(n)
 * Comparisions: O(n^2)
 * Max swaps: O(n^2)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Here, unlike bubble pass, intermediate results arent useful
 * Since we can use with linked lists without shifting, more compatible for linked lists
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Adaptive as only n compparisions done for already sorted array is O(n) and swaps O(1).
 * By nature, it is adaptive
 * Best case (ascending): Time complexity: O(n)
 * Worst case (descending): Time complexity: O(n^2)
 * Stable algorithm
 * */

void insertion_sort(int a[], int n){
    //array with 1 element considered sorted
    int j, x;
    for(int i=1;i<n;i++){
        j = i - 1;
        x = a[i];
        while(j>=0 && a[j]>x){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
    }
}

int main() {
    int a[] = {6, 5, 4, 3, 2, 1};
    int n = sizeof(a)/sizeof(a[0]);
    insertion_sort(a, n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<"\t";
    }
    return 0;
}
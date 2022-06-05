/*
When this program runs, it create multiples arrays of size 5000 with random variables, sorts them with normal insertion sort, and binary insertion sort.
Measuring the time taken for each and printing the function performance  in a file named "p8.txt" in the same folder of this program.
*/

#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
#include <ctime>
#include <cstdlib>
using namespace std;

int BinarySearch(int arr[], int l, int r, int x);
void BinaryInsertionSort(int arr[], int n);
void InsertionSort(int arr[], int n);
int get_rand(int Max);

int main() {
    // when this program run
    double arrlength[10],arrBinInsertion[10],arrInsertion[10];
    int pos = 0;
    srand(time(0));
    for (int length=5000 ; length<=50000;length +=5000){
        arrlength[pos]=length;
        ofstream file;
        file.open ("P8.txt",ios::app);

        int arr[length],arr2[length];
        for (int i=0; i<length ;++i)  arr[i]=arr2[i]=get_rand(10210);

        double start = clock();
        BinaryInsertionSort(arr, length);
        double finish = clock();
        double duration = (double)(finish - start)/CLOCKS_PER_SEC;
        arrBinInsertion[pos]=duration;

        file <<"Binary Insertion Sort time: "<<duration<< endl;


        for (int i=0; i<length ;++i)  arr[i]=get_rand(10210);
        start =clock();
        InsertionSort(arr2, length);
        finish = clock();
        duration = (double)(finish - start)/CLOCKS_PER_SEC;
        arrInsertion[pos]=duration;
        file <<"Insertion Sort time: "<<duration<< endl;
        file <<endl;
        ++pos;
    }
    return 0;
}

int binarySearch(int arr[], int item, int low, int high) {
   if (high <= low)
      return (item > arr[low])? (low + 1): low;
      int mid = (low + high)/2;
   if(item == arr[mid])
      return mid+1;
   if(item > arr[mid])
      return binarySearch(arr, item, mid+1, high);
      return binarySearch(arr, item, low, mid-1);
}
void BinaryInsertionSort(int arr[], int n) {
   int i, place, j, k, key;
   for (i = 1; i < n; ++i) {
      j = i - 1;
      key = arr[i];
      place = binarySearch(arr, key, 0, j);
      while (j >= place) {
         arr[j+1] = arr[j];
         j--;
      }
      arr[j+1] = key;
   }
}

void InsertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int get_rand(int Max){
    int random=0;
    random = (rand() % Max )+1;
    return random;
}

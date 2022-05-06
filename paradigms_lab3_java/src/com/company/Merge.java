package com.company;

import java.util.ArrayList;

public class Merge<T extends Comparable<? super T>> implements Sort<T>{
    public void sort(T[] array){
        sort(array, 0, array.length - 1);
    }
    public void sort(T[] array, int l, int r){
        int m = l + (r-l)/2;
        if(l<r) {
            sort(array, l, m);
            sort(array, m + 1, r);
            merge(array, l, m, r);
        }
    }
    private void merge(T[] array, int l, int m, int r){
        int n1 = m - l + 1;
        int n2 = r - m;
        ArrayList<T> arr1 = new ArrayList<>();
        ArrayList<T> arr2 = new ArrayList<>();
        for(int i=0; i<n1; i++)
            arr1.add(array[l + i]);
        for(int i=0; i<n2; i++)
            arr2.add(array[m + 1 + i]);
        int i=0, j=0, k=l;
        while(i<n1 && j<n2){
            if(arr1.get(i).compareTo(arr2.get(j))<0){
                array[k] = arr1.get(i);
                i++;
            }else{
                array[k] = arr2.get(j);
                j++;
            }
            k++;
        }
        while(i<n1) {
            array[k++] = arr1.get(i++);
        }
        while(j<n2) {
            array[k++] = arr2.get(j++);
        }
    }
}

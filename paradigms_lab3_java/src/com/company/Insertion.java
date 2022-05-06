package com.company;

public class Insertion<T extends Comparable<? super T>> implements Sort<T>{
    public void sort(T[] arr){
        for(int i=1; i<arr.length; i++){
            T currentValue = arr[i];
            int j = i - 1;
            while(j>=0 && arr[j].compareTo(currentValue) > 0){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = currentValue;
        }
    }
}

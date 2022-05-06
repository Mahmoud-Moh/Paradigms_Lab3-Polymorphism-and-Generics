package com.company;

public class Bubble<T extends Comparable<? super T>> implements Sort<T>{
    public void sort(T[] array) {
        for (int i = array.length; i > 1; i--)
            for (int j = 0; j < i - 1; j++)
                if (array[j].compareTo(array[j + 1]) > 0) swap(j, array);
    }
    private void swap(int index, T[] arr) {
        T temp = arr[index]; arr[index] = arr[index + 1]; arr[index + 1] = temp;
    }
}
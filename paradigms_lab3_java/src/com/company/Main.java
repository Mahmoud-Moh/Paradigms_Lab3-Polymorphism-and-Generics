package com.company;

public class Main {

    public static void main(String[] args) {
        Integer[] intArr = { 47, 85, 62, 34, 7, 10, 92, 106, 2, 54 };
        String[] strArr = { "Gamma", "Beta", "Delta", "Alpha", "Theta" };
        Sort<Integer> algorithm = new Insertion<>();
        algorithm.sort(intArr);
        Sort<String> algorithm2 = new Insertion<>();
        algorithm2.sort(strArr);
        System.out.println("Sorted array- " + java.util.Arrays.toString(intArr));
        System.out.println("Sorted array- " + java.util.Arrays.toString(strArr));
    }
}

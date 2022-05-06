#include <iostream>
#include <bits/stdc++.h>
#include <string.h>

using namespace std;

// Map to store the characters with their order
// in the new alphabetical order

template<typename T>
class Sort{
public:
    virtual void sort(T array[], int n) = 0;
};

template<typename T>
class Bubble: public Sort<T>{
public:
    void sort(T array[], int n){
        for (int i = n; i > 1; i--)
            for (int j = 0; j < i - 1; j++)
                /*if (array[j] > array[i+1]) swap(j, array);*/
                if(Compare(array[j], array[j+1]) > 0)
                    swap(j, array);
    }

private:

    int Compare(string x, string y)
    {
        for (int i = 0; i < min(x.size(), y.size()); i++) {
            if (int(x[i]) == int(y[i]))
                continue;
            return int(x[i]) - int(y[i]);
        }
        return x.size() - y.size();
    }

    int Compare(double x, double y){
        return x - y;
    }
    void swap(int index, T arr[]) {
        T temp = arr[index]; arr[index] = arr[index + 1]; arr[index + 1] = temp;
    }
};

template<typename T>
class Insertion: public Sort<T>{
public:
    void sort(T arr[], int n){
        for(int i=1; i<n; i++){
            T currentValue = arr[i];
            int j = i - 1;
            while(j>=0 && Compare(arr[j], currentValue)>0){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = currentValue;
        }
    }

private:

    int Compare(string x, string y)
    {
        for (int i = 0; i < min(x.size(), y.size()); i++) {
            if (int(x[i]) == int(y[i]))
                continue;
            return int(x[i]) - int(y[i]);
        }
        return x.size() - y.size();
    }

    int Compare(double x, double y){
        return x - y;
    }
};

template<typename T>
class Merge: Sort<T>{
public:
    void sort(T array[], int n){
        sort(array, 0, n-1);
    }
    void sort(T array[], int l, int r){
        int m = l + (r-l)/2;
        if(l<r) {
            sort(array, l, m);
            sort(array, m + 1, r);
            merge(array, l, m, r);
        }
    }
private:
    void merge(T array[], int l, int m, int r){
        int n1 = m - l + 1;
        int n2 = r - m;
        vector<T> arr1 ;
        vector<T> arr2 ;
        for(int i=0; i<n1; i++)
            arr1.push_back(array[l + i]);
        for(int i=0; i<n2; i++)
            arr2.push_back(array[m + 1 + i]);
        int i=0, j=0, k=l;
        while(i<n1 && j<n2){
            if(Compare(arr1.at(i), arr2.at(j)) < 0){
                array[k] = arr1.at(i);
                i++;
            }else{
                array[k] = arr2.at(j);
                j++;
            }
            k++;
        }
        while(i<n1) {
            array[k++] = arr1.at(i++);
        }
        while(j<n2) {
            array[k++] = arr2.at(j++);
        }
    }
    int Compare(string x, string y)
    {
        for (int i = 0; i < min(x.size(), y.size()); i++) {
            if (int(x[i]) == int(y[i]))
                continue;
            return int(x[i]) - int(y[i]);
        }
        return x.size() - y.size();
    }

    int Compare(double x, double y){
        return x - y;
    }
};

int main() {
    int intArr[] = { 47, 85, 62, 34, 7, 10, 92, 106, 2, 54 };
    string strArr[] = { "Gamma", "Beta", "Delta", "Alpha", "Theta" };
    int n1 = sizeof(intArr)/sizeof(intArr[0]);
    int n2 = sizeof(strArr)/sizeof(strArr[0]);
    Insertion<int> insertionInt;
    Insertion<string> insertionStr;
    insertionInt.sort(intArr, n1);
    insertionStr.sort(strArr, n2);
    cout<<"Int array: "<<endl;
    for(int i=0; i< n1; i++){
        cout<<intArr[i]<<" ";
    }
    cout<<"\n";
    cout<<"String array: "<<endl;
    for(int i=0; i< n2; i++){
        cout<<strArr[i]<<" ";
    }
    return 0;
}

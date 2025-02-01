#include<iostream>
#include<fstream>
#include<random>
#include <chrono>
using namespace std;
using namespace std::chrono;

int min (int num[], int p, int q){
    int i = p;
    for (int j = p+1; j<q; j++){
        if(num[j] < num[i]){
            i = j;
        }
    }
    return i;
}

void swap(int num[], int p, int q){
    int i = num[p];
    num[p] = num[q];
    num[q] = i;
}

void selection_sort(int num[], int size){
    for(int i = 0; i<size-1; i++){
        swap(num, i, min(num, i, size));
    }
}

void insetion_sort(int num[], int size){
    int key;
    for(int i = 1; i<size; i++){
        key = num[i];
        int j;
        for(j = i-1; j >= 0; j--){
            if(num[j]>key){
                num[j+1] = num[j];
            }
            else{
                break;
            }
        }
        num[j+1] = key;

    }
}


void merge(int b[], int p, int q, int r){
    int* left = new int[q-p];
    int* right = new int[r-q];
    for (int i = 0; i < q-p; i++) left[i] = b[p + i];
    for (int j = 0; j < r-q; j++) right[j] = b[q + j];

    int l = 0, g = 0;
    for (int k = 0; k < r-p; k++){
        if(l >= q-p || (g < r-q && right[g] < left[l])){
            b[p+k] = right[g];
            g++;
        }
        else{
            b[p+k] = left[l];
            l++;
        }
    }
    delete[] left;
    delete[] right;
}

void merge_sort(int a[], int size, int start = 0){
    if(start >= size -1){
        return;
    }
    else{
        merge_sort(a, (size + start)/2, start);
        merge_sort(a, size, (size + start)/2);
        merge(a, start, (size + start)/2, size);
    }
}

int main(){
    int n = 3000;

    fstream fout("input.txt", ios::trunc | ios::out);
    fstream file;
    ofstream data;
    steady_clock::time_point start, stop;
    std::__1::chrono::microseconds duration;
    for(int i = 0; i<n; i++){
        fout << rand() << endl;
    }
    fout.close();

    int *num = new int[n];
    int size, i;

    size = 0;
    file.open("input.txt", ios::in);
    while(file >> i){
        num[size] = i;
        size++;
    }
    file.close();

    data.open("selection_sort.txt", ios::app);
    start = high_resolution_clock::now();
    selection_sort(num, size);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    data << n << " " << duration.count() << endl;
    data.close();

    size = 0;
    file.open("input.txt", ios::in);
    while(file >> i){
        num[size] = i;
        size++;
    }
    file.close();

    data.open("insersion_sort.txt", ios::app);
    start = high_resolution_clock::now();
    insetion_sort(num, size);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    data << n << " " << duration.count() << endl;
    data.close();

    size = 0;
    file.open("input.txt", ios::in);
    while(file >> i){
        num[size] = i;
        size++;
    }
    file.close();

    data.open("merge_sort.txt", ios::app);
    start = high_resolution_clock::now();
    merge_sort(num, size);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    data << n << " " << duration.count() << endl;
    data.close();

    delete[] num;
    return 0;
}
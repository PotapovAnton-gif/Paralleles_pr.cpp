#include <iostream>
#include <omp.h>
#include <chrono>

using namespace std;

int main() {
    
    int size;
    cin >> size;
    int* array = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    } 
    
    int res = 0;

auto start = chrono::high_resolution_clock::now();

    #pragma omp parellel num_threads(5)
    {
        #pragma omp for
        for (int i = 0; i < size; i++) {
           
            if (array[i] % 6 == 0){
            
                #pragma omp critical 
                {
                    res++;
                }
            }
        }
    }
auto finish = chrono::high_resolution_clock::now();

chrono::duration<float> time = finish - start;


    cout << res << endl << time.count() << endl;

    return 0;
}


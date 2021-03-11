#include <omp.h>
#include <iostream>
#include <chrono>

using namespace std;

int main() {
    int size;
    cin >> size;

    double* k = new double[size];
    double* n = new double[size];
    double* res = new double[size];

    for (int i = 0; i < size; i++)
        cin >> k[i] >> n[i];

    auto start = chrono::high_resolution_clock::now();

    /*#pragma omp parallel num_threads(4) 
    {
        #pragma omp for */ 
            for (int i = 0; i < size; i++) {
                res[i] = k[i] + n[i];
            }
    //}

    auto finish = chrono::high_resolution_clock::now();

    for (int i = 0; i < size; i++) {
        cout << res[i] <<'\n';
    }

    chrono::duration <float> time = finish - start;

    cout << "Difference is " << time.count() << endl;

    return 0;
}
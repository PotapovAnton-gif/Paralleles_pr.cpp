#include <iostream>
#include <omp.h>
#include <chrono>
#include <vector>


using namespace std;

int main() {

    int size;
    cin >> size;


    vector <double> a(size), b(size);

    for (int i = 0; i < size; i++) 
        cin >> a[i] >> b[i];

    long double result = 0;

auto start = chrono::high_resolution_clock::now();

    #pragma omp paralel num_threads(5)
    {
        #pragma omp for
            for (int i = 0; i < size; i++) {
                result += a[i]*b[i];
            }
    }

auto finish = chrono::high_resolution_clock::now();

chrono::duration<float> time = finish - start;

    cout << result << endl << time.count() << endl;

    return 0;
}
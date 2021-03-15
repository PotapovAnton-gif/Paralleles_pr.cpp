#include <iostream>
#include <omp.h>
#include <chrono>
#include <vector>


using namespace std;

int main() {

    double delta = 0.000001;
    double I = 0;
    long int over_delta = 1/delta;

auto start = chrono::high_resolution_clock::now();

    #pragma omp parallel num_threads(5)
    {
    #pragma omp for
        for (long int x = 0; x <= over_delta; x++) {
            double res = 4/(1+x*x*delta*delta) * delta;
        #pragma omp critical
        {
            I += res;
        }
        }
    }

auto finish = chrono::high_resolution_clock::now();

chrono::duration<float> time = finish - start;

    cout << I << endl << time.count() << endl;
    
    return 0;

}
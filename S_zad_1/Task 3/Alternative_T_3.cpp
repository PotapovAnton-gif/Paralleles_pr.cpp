#include <thread>
#include <iostream>

using namespace std;

void summ_of_massive(int curr_elem, double* mass, double* outputmass) {

    outputmass[curr_elem] = (mass[curr_elem] + mass[curr_elem + 1]); 

}



void thread_entry(int foo, int bar)
{
    int l=  foo + bar;
    cout << l; 
    // Do something with that, I guess
}


// Elsewhere in some part of the galaxy


int main() {
    
    int Size;
    cin >> Size;
    double* outputmass = new double[Size - 1];
    double* mass = new double[Size];
    thread summOfMassive[Size - 1];

    for (int i = 0; i < Size; i++) {

        cin >> mass[i];

    }
    
    for (int i = 0; i < Size - 1; i++) {

        summOfMassive[i] = thread(summ_of_massive, i, mass, outputmass);

    }
    
    for (int i = 0; i < Size - 1; i++) {
        
        summOfMassive[i].join();
    
    }

    for (int i = 0; i < Size - 1; i++) {

        cout << outputmass[i] << endl;

    }

    return 0;
}
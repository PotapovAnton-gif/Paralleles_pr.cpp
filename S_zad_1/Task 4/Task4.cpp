#include <thread>
#include <iostream>
#include <math.h>

using namespace std;

void summ_of_coordinate(int start_num,int last_num, double* vec1, double* vec2, double* scal_mult) {

    for (int i = start_num; i < last_num; i++)
    scal_mult[i] = vec1[i] * vec2[i];

}

int main() {

    int Size;
    cin >> Size;

    double *vec1 = new double[Size], *vec2 = new double[Size],*res = new double[Size];



    for (int i = 0; i < Size; i++) {

        cin >> vec1[i] >> vec2[i];

    }     

    thread summ_coord[5];


    for (int i = 0; i < 5; i++) {
            

        summ_coord[i] = thread(summ_of_coordinate, floor((Size/5) * i),floor((Size/5) * (i+1)), vec1, vec2, res);

    }

    for (int i = 0; i < 5; i++) {
        
        summ_coord[i].join();
    
    }
    double result = 0;
    for (int i = 0; i < Size; i++) {

        result += res[i];

    }
    cout << result << endl;
    return 0;

}




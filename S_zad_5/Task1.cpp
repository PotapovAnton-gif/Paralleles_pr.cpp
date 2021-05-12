#include <iostream>
#include <math.h>
#include <mpi.h>    

using namespace std;

double norma(int N,double* a) {
    
    int size, rank;
    
    MPI_Init(nullptr, nullptr);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (rank == 0) {
        for (int i = 1; i < size; i++){
        
            MPI_Bsend(&N, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
            MPI_Bsend(a, N, MPI_DOUBLE, i, 0, MPI_COMM_WORLD);
        }
    }
        
    if (rank != 0) {    
        MPI_Recv(&N, 1, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(a, N, MPI_DOUBLE, 0, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }
    double result = 0;

    bool rest = (N%size);

    double norma = 0;

    for (int i = (N / size + rest)*rank; i < (N / size + rest)*(i+1) && i < N; i++)
        result += a[i]*a[i];

    if (rank != 0)
        MPI_Bsend(&result, 1, MPI_DOUBLE, 0,0, MPI_COMM_WORLD);
    
    if (rank == 0) {
        for (int i = 0; i < size; i++){

            norma+= result;
            result = 0;
            if (i != 0)
            MPI_Recv(&result, 1, MPI_DOUBLE,i , MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
    }
    MPI_Finalize();



    
    

    return sqrt(norma);
}
int main() {
    

    int N;
    double* a = new double[N];

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cout << norma(N, a) << endl;

    return 0;
}

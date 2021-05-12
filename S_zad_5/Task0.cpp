#include <iostream>
#include "mpi.h"

using namespace std;

int main() {

    int N = 5;

    int size, rank;
    MPI_Init(nullptr, nullptr);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        for (int i = 1; i < size; i++) {
            MPI_Send(&N, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
        
        }
    }
    
    if (rank != 0) {
        
        MPI_Recv(&N, 1, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    
    }
    
    

    MPI_Finalize();

    if (rank == 0) {
        cout << N << endl;
    }

    return 0;



}
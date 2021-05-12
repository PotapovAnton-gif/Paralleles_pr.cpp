#include <iostream>
#include <mpi.h>

using namespace std;

void sort(int *a, int N) {

    int size,rank;
    MPI_Init(nullptr, nullptr);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
    for (int j = 1; j < size; j++){
        if (rank == 0) {
            MPI_Send(&N, 1, MPI_INT, j, 1, MPI_COMM_WORLD);
            MPI_Send(a, N, MPI_INT, j, 0, MPI_COMM_WORLD);
        }
    }

    if (rank != 0) {
        MPI_Recv(&N, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv (a, N, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    

}
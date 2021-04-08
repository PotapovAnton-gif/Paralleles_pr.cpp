#include <stdio.h>
#include <mpi.h> // Заголовочный файл MPI.int main(int argc, char *argv[]){int  numtasks, rank; // Номер и число процессов.MPI_Init(&argc, &argv); // Инициализация MPI.MPI_Comm_size(MPI_COMM_WORLD, &numtasks); // Число потоков.MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Номер текущего потока.printf("Hello, world!\n");MPI_Finalize(); // Завершение работы с MPI.return 0;}Н. И. Хохлов (МФТИ, Долгопрудный)Параллельные алгоритмы: MPI. Введение3 февраля 2021 г.11 / 19

int main(int argc, char *argv[]){
    int  numtasks, rank; // Номер и число процессов.
    MPI_Init(&argc, &argv); // Инициализация 
    MPI.MPI_Comm_size(MPI_COMM_WORLD, &numtasks); // Число потоков.
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Номер текущего потока.
    printf("Hello, world!\n");
    MPI_Finalize();
    return 0;
}

#include <iostream>
#include <omp.h>
using namespace std;


// Получение матрицы без i-й строки и j-го столбца
void GetMatr(int **mas, int **p, int i, int j, int m) {
  
  int di = 0;
  
  for (int ki = 0; ki< m - 1; ki++) { // проверка индекса строки
    
        if (ki == i) 
            di = 1;
    
        int dj = 0;
    
    for (int kj = 0; kj <m - 1; kj++) { // проверка индекса столбца
    
        if (kj == j) 
            dj = 1;
    
        p[ki][kj] = mas[ki + di][kj + dj];
    }
  }
}
// Рекурсивное вычисление определителя
int Determinant(int **mas, int m) {

    int **p;
    p = new int*[m];
    
    for (int i = 0; i < m; i++)
        p[i] = new int[m];
    
    int j = 0; int d = 0; int k = 1; int n = m - 1;

    if (m < 1) 
        cout << "Определитель вычислить невозможно!";
    
    if (m == 1) {
        d = mas[0][0];
        return(d);
    }
    
    if (m == 2) {
        d = mas[0][0] * mas[1][1] - (mas[1][0] * mas[0][1]);
        return(d);
    }
#pragma omp parallel num_threads(5)
{
    if (m>2) {
    
    #pragma omp for
        for (int i = 0; i < m; i++) {
        
            GetMatr(mas, p, i, 0, m);

            double M = k * mas[i][0] * Determinant(p, n);
            k = -k;
        #pragma omp critical
            {
                d += M;
            }
        }
    }
}
    
    return(d);
}
    // Основная функция
int main() {
    
    int m;
    cin >> m;
    
    int **mas;
    mas = new int*[m];
    
    for (int i = 0; i < m; i++) {
     
        mas[i] = new int[m];
    
        for (int j = 0; j < m; j++) {
            
            cin >> mas[i][j];
        
        }
    }

    cout << Determinant(mas, m) << endl;
 
    return 0;
}
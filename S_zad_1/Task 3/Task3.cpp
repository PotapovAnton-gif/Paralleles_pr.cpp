#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

using namespace std;



double vara[10];


class arr{
    private:
        int size;
        double *value;
        int currNum;
        double var[10];
    public:

    void writeVar(int i, double var) {
        this ->var[i] = var;
    }
    void writeSize(int n){
        this -> size = n;
    }
    void writeValue(double *value){
        this ->value = value;
    }
    void writeCurrNum(int i) {
        this ->currNum = i;
    }

    double* getVar() {
        return var;
    }
    int getSize(){
        return this->size;
    }
    int getCurrNum() {
        return currNum;
    }
    double *getValue(){
        return this -> value;
    }
    
};

arr massive;

void *arrThread(void *val) {
    
    pthread_t arrThid;
    arrThid = pthread_self();

    int i = massive.getCurrNum();
    double *value = massive.getValue();
    int n = massive.getSize();

    vara[i] = value[i] + value[i+1];
    cout << "Summ of values " << value[i] + value[i + 1] << endl;

    return 0;
}

int main() {

    int N;
    cin >> N;

    double* n = new double[N];

    for (int i = 0; i < N; i++){
        cin >> n[i];
    }
    
    massive.writeSize(N);
    massive.writeValue(n);

    int res;
    pthread_t thid, arrThid[N-1];
    for (int i = 0; i < N-1; i++){
        massive.writeCurrNum(i);
        res = pthread_create(&arrThid[i], nullptr, arrThread, nullptr);
        if (res != 0) {
            cout << "Error" << arrThid[i] << endl;
            exit(-1);
        }
        arrThid[i] = pthread_self();
    }

for (int i = 0; i < massive.getSize() - 1; i++){
    cout << vara[i] << endl;
}


return 0;

}

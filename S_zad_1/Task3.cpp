#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

pthread_mutex_t mutex;


class arr{
    private:
        int size;
        double *value;
        int currNum;
        double var;
    public:
    
    void writeSize(int n){
        this -> size = n;
    }
    void writeValue(double *value){
        this ->value = value;
    }
    void writeCurrNum(int i) {
        this ->currNum = i;
    }
    void writeVar(int var){
        this -> var = var;
    }

    int getSize(){
        return this->size;
    }
    int getCurrNum() {
        return this->currNum;
    }
    double *getValue(){
        return this -> value;
    }
    double getVar(){
        return this->var;
    }
};

arr massive;

void *arrThread(void *val) {
    
    pthread_t arrThid;
    arrThid = pthread_self();
    pthread_mutex_lock(&mutex);

    int i = massive.getCurrNum();
    double *value = massive.getValue();
    int n = massive.getSize();

    
    massive.writeVar(value[i] + value[i+1]);
    
    cout << "Thread and result = " << arrThid << " " << massive.getVar() << endl;

    pthread_mutex_unlock(&mutex);
    return 0;
}

int main() {

    int N;
    cin >> N;

    double n[N];

    for (int i = 0; i < N; i++){
        cin >> n[i];
    }
    
    massive.writeSize(N);
    massive.writeValue(n);

    int res;
    pthread_t thid, arrThid[N];
    for (int i = 0; i < N-1; i++){
        massive.writeCurrNum(i);
        res = pthread_create(&arrThid[i], nullptr, arrThread, nullptr);
        if (res != 0) {
            cout << "Error" << arrThid[i] << endl;
            exit(-1);
        }
        arrThid[i] = pthread_self();
        pthread_mutex_unlock(&mutex);
        cout << "Thread created" << thid << endl;
	    cout << "Thread and result = " << arrThid[i] << " " << massive.getValue() << endl;
    }

pthread_join(thid, nullptr);
pthread_mutex_destroy(&mutex);

return 0;

}

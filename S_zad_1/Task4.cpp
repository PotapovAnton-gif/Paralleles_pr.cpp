#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

pthread_mutex_t mutex;

class vec{
    private:
    int size;
    double* vector;
    
    public:
    vec(int size) {
        this->size = size;
        double *vector = new double[size];
    }
    ~vec() {
        delete vector;
    }

    double* get_vec(){
        return this->vector;
    }

    int get_size() {
        return size;
    }

    void set_vec(double* coordinate) {
        vector = coordinate;
    }

};
vec a(3), b(3);

void* get_mult(void* value) {

    pthread_t mult;
    mult = pthread_self();
    pthread_mutex_lock(&mutex);

    

}

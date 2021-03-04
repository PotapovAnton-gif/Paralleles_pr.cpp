#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

pthread_mutex_t mutex;


int a = 0;

void *mythread(void *value) {
	pthread_t mythid;
	mythid = pthread_self();
    pthread_mutex_lock(&mutex);
	a = a+1;
	cout << "Thread and result = " << mythid << " " << a << endl;
    pthread_mutex_unlock(&mutex);
	return 0;
}
void *hethread(void *value) {
	pthread_t hethid;
	hethid = pthread_self();
    pthread_mutex_lock(&mutex);
	a = a+3;
	cout << "Thread and result = " << hethid << " " << a << endl;
    pthread_mutex_unlock(&mutex);
	return 0;
}

int main() {
	
    pthread_mutex_t mutex;

    pthread_mutex_init(&mutex, nullptr);

	pthread_t thid, mythid, hethid;
	int result;
	result = pthread_create(&thid, nullptr, mythread, nullptr);

	int hesult;
	hesult = pthread_create(&thid, nullptr, hethread, nullptr);

	if (hesult != 0) {
		cout << "Error, return value" << hesult << endl;
		exit(-1);
	} 

	if (result != 0) {
		cout << "Error, return value" << result << endl;
		exit(-1);
	}

	mythid = pthread_self();
	hethid = pthread_self();
	
	a = a + 1;
	cout << "Thread created" << thid << endl;
	cout << "Thread and result = " << mythid << " " << a << endl;

	pthread_mutex_unlock(&mutex);
	pthread_join(thid, nullptr);
	pthread_join(hethid, nullptr);
	pthread_mutex_destroy(&mutex);


	return 0;
	
}

#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

int a = 0;

void *mythread(void *value) {
	pthread_t mythid;
	mythid = pthread_self();
	a = a+1;
	cout << "Thread and result = " << mythid << " " << a << endl;
	return 0;
}

int main() {
	
	pthread_t thid, mythid;

	int result;

	result = pthread_create(&thid, nullptr, mythid, nullptr);
	if ()

	return 0;
	
}

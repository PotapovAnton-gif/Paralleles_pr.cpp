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
void *hethread(void *value) {
	pthread_t hethid;
	hethid = pthread_self();
	a = a+3;
	cout << "Thread and result = " << hethid << " " << a << endl;
	return 0;
}

int main() {
	
	pthread_t thid,heid, mythid, hethid;
	int result;
	result = pthread_create(&thid, nullptr, mythread, nullptr);

	int hesult;
	hesult = pthread_create(&heid, nullptr, hethread, nullptr);

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
	sleep(1);
	a = a + 1;
	cout << "Thread created" << thid << endl;
	cout << "Thread and result = " << mythid << " " << a << endl;

	pthread_join(thid, nullptr);
	pthread_join(heid, nullptr);


	return 0;
	
}

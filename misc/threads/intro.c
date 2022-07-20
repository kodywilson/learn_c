#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

void* func(void* x) {
    int xi = (int)x;

    printf("Inside thread: x = %d\n", xi);

    sleep(10);

    return (void*)(xi + 12345);
}

int main(int argc, char** argv) {
    pthread_t th;
    pthread_create(&th, NULL, func, (void*)100);
    printf("Thread created, now outside\n");
    void* ret_from_thread;
    int ri;
    pthread_join(th, &ret_from_thread);
    ri = (int)ret_from_thread;

    printf("Outside thread, which returned %d\n", ri);
    return 0;
}

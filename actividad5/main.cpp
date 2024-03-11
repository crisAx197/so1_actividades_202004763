#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int child_processes = 0;
int threads_created = 0;

void *thread_function(void *arg) {
    pid_t pid = *((pid_t *)arg);
    printf("Se creó un hilo :D %d\n", pid); // Se imprime el proceso que genera el hilo
    threads_created++; // Se hace el conteo de hilos creados
    return NULL;
}

int main() {
    pid_t pid;
    pthread_t tid;

    pid = fork();

    if (pid == 0) {
        // Proceso hijo
        child_processes++;
        pid_t child_pid = getpid();  // Obtener el ID del proceso hijo actual
        pid = fork();  // Crear otro proceso hijo
        pthread_create(&tid, NULL, thread_function, (void *)&child_pid);
    }

    pid = fork(); // Imprime el process id actual
    printf("%d\n", pid);
    // Conteo final
    if (pid != 0) {
        sleep(2); // Espera para que los procesos e hilos hijos terminen antes de que el proceso padre termine
    }
    return 0;
}

#include <cstdio>
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::mutex stdout_lock;

void fun(int tid) {
    stdout_lock.lock();
    stdout_lock.unlock();
    printf("Empezar a escribir");
    for(int i = 0; i < 100; i++) {
        stdout_lock.lock();
        printf("0Saludos de la hebra: %d, iteracion: %d\n", tid, i);
        printf("1Saludos de la hebra: %d, iteracion: %d\n", tid, i);
        stdout_lock.unlock();
    }
    stdout_lock.lock();
    printf("terminar a escribir");
    stdout_lock.unlock();
}


int main(int argc, char** argv) {
    int thread = std::thread::hardware_concurrency();
    printf("cuantos threads hay en la maquina %d\n", thread);
    if(argc != 2) {
        printf("Se requiere un argumento\n");
        exit(1);
    }
    int num = std::stoi(argv[1]); //stoi creo que convierte char* a int

    //Crea una instancia t0 de la clase thread
    //Con parametros funcion y los parametros de 
    //la funcion
    //Guardar las hebras en un vector de punteros a objetos thread
    std::vector<std::thread*> threads;

    for(int i = 0; i < num; i++) {
        threads.push_back(new std::thread(fun, i));
    }
    //std::thread t0(fun, 0);
    //std::thread t1(fun, 1);

    for(int i = 0; i < num; i++) {
        threads.at(i)->join();
        delete threads.at(i);
    }

    //La hebra main espera a t0
    //t0.join();
    //La hebra main espera a t1
    //t1.join();

    printf("main() exiting\n");
    return 0;
}

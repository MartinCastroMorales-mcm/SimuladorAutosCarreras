#include <cstdio>
#include <vector>
#include <mutex>
#include <thread>
#include <stdlib.h>
#include <time.h>

std::mutex auto_pos_lock;

void sprint(int tid, std::vector<int> metrosAuto, int metros, std::vector<int>& lugares) {
    int avance;
    long lugar = 0;
    srand(time(0));
    while(true) {
        int aleatorio = rand();
        avance = (aleatorio % 10) + 1;
        //printf("avance: %d\n", avance);
        auto_pos_lock.lock();
        metrosAuto.at(tid) += avance;
        if(metrosAuto.at(tid) >= metros) {
            lugares.push_back(tid);
            lugar = lugares.size();
            //printf("agregar elemento %lu", lugares.size());
            auto_pos_lock.unlock();
            break;
        }
        printf("Auto%d avanza %d metros (total: %d)\n", tid, avance, metrosAuto.at(tid));
        auto_pos_lock.unlock();
        aleatorio = rand();
        int time = aleatorio % 401 + 100;
        std::this_thread::sleep_for (std::chrono::milliseconds(time));
    }
    //TODO: Agregar verde
    //lugares.push_back(tid);
    printf("\x1B[32mAuto%d avanza %d metros y termina la carrera en el lugar %lu\033[0m\n", tid, avance, lugar);
    return;
}
int main(int argc, char** argv) {
    if(argc != 3) {
        printf("Se requieren dos argumentos\n");
    }
    int metros = std::stoi(argv[1]);
    int autos = std::stoi(argv[2]);
    printf("Distancia total carrera: %d metros\n", metros);
    printf("-----------------------------------------\n");

    std::vector<int> metrosAuto;
    std::vector<std::thread*> threads;
    std::vector<int> lugares;
    for(int i = 0; i < autos; i++) {
        metrosAuto.push_back(0);
        threads.push_back(new std::thread(sprint, i, metrosAuto, metros, std::ref(lugares)));
    }
    for(int i = 0; i < autos; i++) {
        threads.at(i)->join();
        delete threads.at(i);
    }
    printf("Lugar   Auto\n");
    printf("-----------------------------------------\n");
    for(int i = 0; i < (int) lugares.size(); i++) {
        printf("%d        Auto%d\n", i + 1, lugares.at(i));
    }
    return 0;
}
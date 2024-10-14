Para compilar:
```
make main
```
Para ejecutar:
```
./carrera M A
```
Donde M son los metros de la carrera y A es el numero de autos.
Ej:
~~~
martin:tarea1/ (master✗) $ make main                                                                                                                                                       [16:57:54]
g++ carrera.cpp -Wall -Werror -g -o carrera -std=c++11
martin:tarea1/ (master✗) $ ./carrera 10 3                                                                                                                                                  [16:58:12]
Distancia total carrera: 10 metros
-----------------------------------------
Auto0 avanza 8 metros (total: 8)
Auto1 avanza 8 metros (total: 8)
Auto2 avanza 8 metros (total: 8)
Auto1 avanza 1 metros (total: 9)
Auto2 avanza 5 metros y termina la carrera en el lugar 1
Auto0 avanza 9 metros y termina la carrera en el lugar 2
Auto1 avanza 6 metros y termina la carrera en el lugar 3
Lugar   Auto
-----------------------------------------
1        Auto2
2        Auto0
3        Auto1    
~~~
## DEPARTAMENTO DE SISTEMAS DE INFORMACIÓN
# Sistemas Operativos
Tarea1: Simulador carrera de autos.
Objetivos
Reforzar conceptos básicos de procesos/hebras, comunicación entre procesos y sincro-
nizaci´on.
Implementar un programa que permita aplicar conceptos de concurrencia y paralelismo
mediante el uso de hebras.
### Descripción
Se solicita simular una carrera de autos utilizando programación multihebras. Cada au-
tomóvil competidor correría en una hebra distinta. La carrera consiste en que cada auto
recorrer´a una distancia de M metros en intervalos de tiempo aleatorios.
Cada automóvil:
Tendría un identificador único (ej: Auto1, Auto2, etc.).
Avanzaría una cantidad aleatoria de metros en cada iteración.
Se detendría por un tiempo aleatorio (representando la velocidad aleatoria del auto) en
cada iteraci´on.
La carrera finalizaría cuando todos los autos hayan terminado el recorrido.
Debería implementar la simulaci´on en C++ (compilador GNU g++ std=c++11 o supe-
rior) utilizando la biblioteca estándar de hebras (thread). El programa deber´a mostrar el
progreso de cada auto en la terminal y los resultados finales.
1
Requisitos:
Utilizar la biblioteca thread de C++ para manejar las hebras (cada auto en una hebra
separada).
Por cada auto y en cada iteraci´on, calcular un valor aleatorio para la distancia que
avanza (m´aximo de 10 metros) y cambia la velocidad (entre 100-500 ms).
Mostrar el avance de cada auto en tiempo real en la terminal.
La carrera debe tener un ganador y mostrar el orden de llegada.
La distancia total en metros (M) de la carrera y el n´umero de autos (N) se deben
indicar como par´ametros al iniciar la carrera.
Salida por la terminal, considerando una carrera de M=100 metros con N=3 autos:
```
$ . / c a r r e r a 100 3
D i s t a n c i a t o t a l c a r r e r a : 100 m e t r o s
−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
Auto2 avanza 7 m e t r o s ( t o t a l : 7 m e t r o s )
Auto1 avanza 10 m e t r o s ( t o t a l : 10 m e t r o s )
Auto0 avanza 10 m e t r o s ( t o t a l : 10 m e t r o s )
Auto1 avanza 2 m e t r o s ( t o t a l : 12 m e t r o s )
Auto2 avanza 3 m e t r o s ( t o t a l : 10 m e t r o s )
Auto0 avanza 1 m e t r o s ( t o t a l : 11 m e t r o s )
. . .
Auto0 avanza 7 metros y termina la carrera en el lugar 1!
Auto1 avanza 10 m e t r o s ( t o t a l : 87 m e t r o s )
Auto2 avanza 4 m e t r o s ( t o t a l : 93 m e t r o s )
Auto1 avanza 10 m e t r o s ( t o t a l : 97 m e t r o s )
Auto1 avanza 7 metros y termina la carrera en el lugar 2!
Auto2 avanza 5 m e t r o s ( t o t a l : 98 m e t r o s )
Auto2 avanza 6 metros y termina la carrera en el lugar 3!
Lugar Auto
−−−−−−−−−−−−
1 Auto0
2 Auto1
3 Auto2
```
Al revisar los procesos en el sistema mientras la carrera est´a en curso se deber´ıa poder
ver el proceso con sus 3 hebras (vista utilizando htop):
```
PID TGID USER PRI NI VIRT RES SHR S CPU% MEM% TIME+ Command
4 1 5 4 7 1 4 1 5 4 7 1 a m v a l d e s j 20 0 3 0 684 2028 1848 S 0 . 0 0 . 0 0 : 0 0 . 0 0 . / c a r r e r a 100 3
4 1 5 4 7 2 4 1 5 4 7 1 a m v a l d e s j 20 0 3 0 684 2028 1848 S 0 . 0 0 . 0 0 : 0 0 . 0 0 |− . / c a r r e r a 100 3
4 1 5 4 7 3 4 1 5 4 7 1 a m v a l d e s j 20 0 3 0 684 2028 1848 S 0 . 0 0 . 0 0 : 0 0 . 0 0 |− . / c a r r e r a 100 3
4 1 5 4 7 4 4 1 5 4 7 1 a m v a l d e s j 20 0 3 0 684 2028 1848 S 0 . 0 0 . 0 0 : 0 0 . 0 0 |− . / c a r r e r a 100 3
```
### Consideraciones
El programa debe correr en equipos con sistema operativo Linux.
Debe utilizar el lenguaje de programaci´on C++ y el compilador GNU g++.
Debe utilizar un archivo Makefile para la compilaci´on mediante el comando make.
No olvidar un archivo README con las intrucciones para compilar y ejecutar el
programa.
El programa debe est´ar bien documentado y utilizar nombres descriptivos de variables,
funciones, métodos, etc.
La tarea es en parejas.
El programa debe compilar para ser revisado, de lo contrario sería considerado como
NCR. Realice pruebas del programa en distintos equipos.
Entrega
Debe subir a la plataforma moodle un enlace al proyecto/repositorio alojado en alguna
plataforma de gesti´on de proyectos inform´aticos como Gitlab, Github, bitbucket, etc.
Para la revisión de la tarea se consideraría la fecha/hora del último commit realizado.
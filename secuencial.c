/* 
    - Jose Block
    - Francisco Rosal
    - Gian Luca Rivera

    Compilar: gcc -o secuencial secuencial.c
    Ejeutar: ./secuencial
*/

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {
    int N, err;
    double L, x, t, t0, tl, tr;
    double c = 0.000001; //10e-5 m^2/s

    printf("Ingrese la precisión requerida: ");
    scanf("%d", &err);
    printf("Ingrese el numero de intervalos discretos: ");
    scanf("%d", &N);
    printf("Ingrese la temperatura inicial: ");
    scanf("%lf", &t0);
    printf("Ingrese la temperatura del extremo izquierdo de la barra: ");
    scanf("%lf", &tl);
    printf("Ingrese la temperatura del extremo derecho de la barra: ");
    scanf("%lf", &tr);
    printf("err: %d  N: %d t0: %g tl: %g tr: %g", err, N, t0, tl, tr);


    // double nueva_temperatura;
    // for(int j = 2; j <= N-1; j++){
    //     nueva_temperatura = T_j(t_i) + (c)/
    // };
}
/*
    - Jose Block
    - Francisco Rosal
    - Gian Luca Rivera

    Compilar: gcc -o secuencial secuencial.c
    Ejeutar: ./secuencial

    gcc -o secuencial secuencial.c && ./secuencial
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char* argv[]) {
    int N, err, time_iterations;
    double L, x, t, t0, tl, tr;
    double c = 0.000001; //10e-5 m^2/s

    printf("Ingrese el las iteraciones de tiempo: ");
    scanf("%d", &time_iterations);
    // printf("Ingrese la precisión requerida: ");
    // scanf("%d", &err);
    printf("Ingrese el numero de intervalos discretos: ");
    scanf("%d", &N);
    // N = 10;
    printf("Ingrese la temperatura inicial: ");
    // scanf("%lf", &t0);
    t0 = 20;
    printf("Ingrese la temperatura del extremo izquierdo de la barra: ");
    // scanf("%lf", &tl);
    tl = 50;
    printf("Ingrese la temperatura del extremo derecho de la barra: ");
    // scanf("%lf", &tr);
    tr = 60;
    printf("err: %d  N: %d t0: %g tl: %g tr: %g", err, N, t0, tl, tr);

    // One dimensional heat dissipation equation
    // dT/dt = c*dT/dx
    // T(x,0) = t0
    // T(0,t) = tl
    // T(L,t) = tr

    // Division of the domain in discrete intervals
    L = 100.0;
    x = L / N;

    // Initialize the temperature matrix
    double current_T[N];
    double next_T[N];

    for (int j = 0; j < N; j++) {
        current_T[j] = t0;
        next_T[j] = 0.0;
    }

    // printf("\n\n");
    // for (int e = 0; e < N; e++) {
    //     printf("%f ", current_T[e]);
    // }

    // printf("\n\n");
    // for (int e = 0; e < N; e++) {
    //     printf("%f ", next_T[e]);
    // }


    int T_i = 0;
    double new_temp;
    // j es control de distancia
    // i es control de tiempo
    while (T_i < time_iterations) {
        printf("\n\nTime step: %d\n", T_i);
        // for(int j = 2; j <= L-1; j++) {
        for (int j = 0; j < N; j++) {
            new_temp = current_T[j] + (c/pow(x, 2)) * (current_T[j-1] - 2 * current_T[j] + current_T[j+1]);
            printf("\n%f", new_temp);
        };

        T_i++;
    };


    return 0;
}
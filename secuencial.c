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
    // One dimensional heat dissipation equation
    // dT/dt = c*dT/dx
    // T(x,0) = t0
    // T(0,t) = tl
    // T(L,t) = tr
    int N, err, time_iterations;
    double L = 100.0;
    double delta_x, delta_t, t0, tl, tr;
    double c = 0.000001; //10e-5 m^2/s

    printf("\nIngrese el las iteraciones de tiempo: ");
    scanf("%d", &time_iterations);
    // printf("Ingrese la precisión requerida: ");
    // scanf("%d", &err);
    printf("\nIngrese el numero de intervalos discretos: ");
    scanf("%d", &N);
    // N = 10;
    // printf("\nIngrese la temperatura inicial: ");
    // scanf("%lf", &t0);
    t0 = 20;
    // printf("\nIngrese la temperatura del extremo izquierdo de la barra: ");
    // scanf("%lf", &tl);
    tl = 50;
    // printf("\nIngrese la temperatura del extremo derecho de la barra: ");
    // scanf("%lf", &tr);
    tr = 60;
    printf("\nerr: %d\n  N: %d\n t0: %g\n tl: %g\n tr: %g\n", err, N, t0, tl, tr);

    delta_x = L / N;
    delta_t = 5;

    // Initialize the temperature vectors
    double current_T[N];
    double next_T[N];

    for (int j = 0; j < N; j++) {
        current_T[j] = t0;
        next_T[j] = 0.0;
    }

    // Set the boundary conditions
    current_T[0] = tl;
    current_T[N-1] = tr;

    // printf("\n\n");
    // for (int j = 0; j < N; j++) {
    //     printf("%f ", current_T[j]);
    // }


    // j es control de distancia
    // i es control de tiempo
    int T_i = 0;
    while (T_i < time_iterations) {
        printf("\n\nTime step: %d\n", T_i);
        // for(int j = 2; j <= N-1; j++) {???
        for (int j = 0; j < N; j++) {
            next_T[j] = current_T[j] + ((c * delta_t)/pow(delta_x, 2)) * (current_T[j-1] - 2 * current_T[j] + current_T[j+1]);
        };

        for (int j = 0; j < N; j++) {
            printf("%f ", current_T[j]);
        }

        printf("\n");
        for (int j = 0; j < N; j++) {
            printf("%f ", next_T[j]);
        }

        for (int j = 0; j < N; j++) {
            current_T[j] = next_T[j];
            next_T[j] = 0.0;
        }

        T_i++;
        printf("\n");
    };


    return 0;
}
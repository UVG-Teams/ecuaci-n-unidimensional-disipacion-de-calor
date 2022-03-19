/*
    - Jose Block
    - Francisco Rosal
    - Gian Luca Rivera

    Compilar: gcc -o paralelo paralelo.c -fopenmp
    Ejeutar: ./paralelo

    mac : gcc-11 -o paralelo paralelo.c -fopenmp
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>


int main(int argc, char* argv[]) {
    double t_init = omp_get_wtime();
    // One dimensional heat dissipation equation
    // dT/dt = c*dT/dx
    // T(x,0) = t0
    // T(0,t) = tl
    // T(L,t) = tr
    int N, err, time_iterations;
    double L, delta_x, delta_t, t0, tl, tr;
    double c = 1e-5; //10e-5 m^2/s

    // printf("\nIngrese el las iteraciones de tiempo: ");
    // scanf("%d", &time_iterations);
    // // printf("Ingrese la precisión requerida: ");
    // // scanf("%d", &err);
    // printf("\nIngrese el largo de la barra: ");
    // scanf("%lf", &L);
    // printf("\nIngrese el numero de intervalos discretos: ");
    // scanf("%d", &N);
    // printf("\nIngrese la temperatura inicial: ");
    // scanf("%lf", &t0);
    // printf("\nIngrese la temperatura del extremo izquierdo de la barra: ");
    // scanf("%lf", &tl);
    // printf("\nIngrese la temperatura del extremo derecho de la barra: ");
    // scanf("%lf", &tr);
    // printf("\nerr: %d\n  N: %d\n t0: %g\n tl: %g\n tr: %g\n", err, N, t0, tl, tr);

    time_iterations = 1000;
    L = 1;
    N = 5000;
    t0 = 20;
    tl = 90;
    tr = 100;

    delta_x = L / N;
    // delta_t = ((delta_x * delta_x)*0.5)/c;


    // double C = (c * delta_t) / (delta_x * delta_x);
    double C = 0.5;

    // return 1;

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


    // j es control de distancia
    // i es control de tiempo
    int T_i = 0;
    // #pragma omp parallel num_threads(8)
    while (T_i < time_iterations) {
        printf("\n\nTime step: %d\n", T_i);
        // for(int j = 2; j <= N-1; j++) {???
        #pragma omp for schedule(static , 1000)
        for (int j = 0; j < N; j++) {
            if (j == 0 || j== N-1){
                next_T[j] = current_T[j];
            } else {
                next_T[j] = current_T[j] + C * (current_T[j-1] - 2 * current_T[j] + current_T[j+1]);
            }
        };

        // for (int j = 0; j < N; j++) {
        //     printf("%f ", current_T[j]);
        // }

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

    double t_fin = omp_get_wtime();
    double delta = t_fin - t_init;

    printf("Tiempo: %lf ", delta);

    return 0;
}
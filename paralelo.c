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

    #pragma omp parallel num_threads(8) firstprivate(current_T)
    while (T_i < time_iterations) {
        printf("\n\nTime step: %d\n", T_i);

        #pragma omp for schedule(static , 1000)
        for (int j = 0; j < N; j++) {
            if (j == 0 || j == N-1){
                next_T[j] = current_T[j];
            } else {
                next_T[j] = current_T[j] + C * (current_T[j-1] - 2 * current_T[j] + current_T[j+1]);
            }
        };

        printf("\n");
        #pragma omp single
        {
            for (int j = 0; j < N; j++) {
                printf("%f ", next_T[j]);
            }

            for (int j = 0; j < N; j++) {
                current_T[j] = next_T[j];
                next_T[j] = 0.0;
            }
        }

        T_i++;
        printf("\n");
    };

    double t_fin = omp_get_wtime();
    double delta = t_fin - t_init;

    printf("Tiempo: %lf ", delta);

    return 0;
}
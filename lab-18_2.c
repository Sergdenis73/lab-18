#include <stdio.h>
#include <math.h>

void input_array(double arr[], int size, const char *name) {
    printf("Введіть %d елементів масиву %s:\n", size, name);
    for (int i = 0; i < size; i++) {
        printf("%s[%d] = ", name, i);
        scanf("%lf", &arr[i]);
    }
}

void process_array(double arr[], int size, double *s, double *p, double *A, double *B, double *C, int is_beta) {
    *s = 0.0;
    *p = 1.0;
    double sum_z_exp = 0.0;
    double sum_z_cos = 0.0;
    double sum_z_sin = 0.0;
    double sum_beta_sin = 0.0;
    double sum_beta_tan = 0.0;
    double sum_beta_abs = 0.0;

    for (int i = 0; i < size; i++) {
        *s += arr[i];
        *p *= arr[i];

        if (!is_beta) {

            sum_z_exp += arr[i] * exp(arr[i]);
            sum_z_cos += arr[i] * cos(arr[i]);
            sum_z_sin += arr[i] * sin(arr[i]);
        } else {

            sum_beta_sin += arr[i] * sin(arr[i]);
            sum_beta_tan += arr[i] * tan(arr[i]);
            sum_beta_abs += arr[i] * fabs(arr[i]);
        }
    }

    if (!is_beta) {
        *A = (*s) * sum_z_exp;
        *B = (*p) * sum_z_cos;
        *C = (*p) * sum_z_sin;
    } else {
        *A = (*s) * sum_beta_sin;  
        *B = (*p) * sum_beta_tan;  
        *C = (*p) * sum_beta_abs;  
    }
}

int main() {
    int n, m;
    printf("Введіть кількість елементів масиву z (n): ");
    scanf("%d", &n);
    printf("Введіть кількість елементів масиву beta (m): ");
    scanf("%d", &m);

    double z[n], beta[m];
    input_array(z, n, "z");
    input_array(beta, m, "beta");

    double s_z, p_z, A, B, C;
    process_array(z, n, &s_z, &p_z, &A, &B, &C, 0);

    double s_beta, p_beta, D, E, F;
    process_array(beta, m, &s_beta, &p_beta, &D, &E, &F, 1);

    double numerator = A + B + sin(C);
    double denominator = D + E + cos(F);
    double omega = numerator / denominator;

    printf("\nРезультати:\n");
    printf("A = %lf\n", A);
    printf("B = %lf\n", B);
    printf("C = %lf\n", C);
    printf("D = %lf\n", D);
    printf("E = %lf\n", E);
    printf("F = %lf\n", F);
    printf("ω = %lf\n", omega);

    return 0;
}
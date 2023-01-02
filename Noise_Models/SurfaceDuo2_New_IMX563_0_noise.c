/* Generated test code to dump a table of data for external validation
 * of the noise model parameters.
 */
#include <stdio.h>
#include <assert.h>
double compute_noise_model_entry_S(int plane, int sens);
double compute_noise_model_entry_O(int plane, int sens);
int main(void) {
    for (int plane = 0; plane < 4; plane++) {
        for (int sens = 33; sens <= 4205; sens += 100) {
            double o = compute_noise_model_entry_O(plane, sens);
            double s = compute_noise_model_entry_S(plane, sens);
            printf("%d,%d,%lf,%lf\n", plane, sens, o, s);
        }
    }
    return 0;
}

/* Generated functions to map a given sensitivity to the O and S noise
 * model parameters in the DNG noise model. The planes are in
 * R, Gr, Gb, B order.
 */
double compute_noise_model_entry_S(int plane, int sens) {
    static double noise_model_A[] = { 4.00438231579344e-06,4.000413461478453e-06,3.993283850965023e-06,3.973770186194941e-06 };
    static double noise_model_B[] = { 3.3395237806962355e-06,1.151514537131238e-05,1.1563119860027393e-05,9.699028266170454e-06 };
    double A = noise_model_A[plane];
    double B = noise_model_B[plane];
    double s = A * sens + B;
    return s < 0.0 ? 0.0 : s;
}

double compute_noise_model_entry_O(int plane, int sens) {
    static double noise_model_C[] = { 7.110962438432788e-11,7.648259181539043e-11,7.925251642489496e-11,7.413385819968427e-11 };
    static double noise_model_D[] = { 5.63438373402701e-07,3.257464366051307e-07,3.345318620549276e-07,4.803531596169392e-07 };
    double digital_gain = (sens / 262.0) < 1.0 ? 1.0 : (sens / 262.0);
    double C = noise_model_C[plane];
    double D = noise_model_D[plane];
    double o = C * sens * sens + D * digital_gain * digital_gain;
    return o < 0.0 ? 0.0 : o;
}

/* Generated test code to dump a table of data for external validation
 * of the noise model parameters.
 */
#include <stdio.h>
#include <assert.h>
double compute_noise_model_entry_S(int plane, int sens);
double compute_noise_model_entry_O(int plane, int sens);
int main(void) {
    for (int plane = 0; plane < 4; plane++) {
        for (int sens = 25; sens <= 6268; sens += 100) {
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
    static double noise_model_A[] = { 6.63183562946934e-06,6.77395884908739e-06,5.7726158549867406e-06,6.0446563317950505e-06 };
    static double noise_model_B[] = { -1.935503289717165e-05,-8.43499829084843e-06,-8.665151207747806e-06,-1.0700870106029772e-05 };
    double A = noise_model_A[plane];
    double B = noise_model_B[plane];
    double s = A * sens + B;
    return s < 0.0 ? 0.0 : s;
}

double compute_noise_model_entry_O(int plane, int sens) {
    static double noise_model_C[] = { 6.926420216866276e-11,4.715048584554048e-11,4.315211059438334e-11,5.947461885874832e-11 };
    static double noise_model_D[] = { 3.7702987375291133e-07,-3.399659564926426e-07,2.0598014853210017e-07,4.367285286148578e-07 };
    double digital_gain = (sens / 395.0) < 1.0 ? 1.0 : (sens / 395.0);
    double C = noise_model_C[plane];
    double D = noise_model_D[plane];
    double o = C * sens * sens + D * digital_gain * digital_gain;
    return o < 0.0 ? 0.0 : o;
}

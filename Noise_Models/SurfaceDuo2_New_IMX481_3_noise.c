/* Generated test code to dump a table of data for external validation
 * of the noise model parameters.
 */
#include <stdio.h>
#include <assert.h>
double compute_noise_model_entry_S(int plane, int sens);
double compute_noise_model_entry_O(int plane, int sens);
int main(void) {
    for (int plane = 0; plane < 4; plane++) {
        for (int sens = 13; sens <= 3389; sens += 100) {
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
    static double noise_model_A[] = { 1.2041622160027909e-05,1.2212106694406607e-05,1.0420513675974303e-05,1.114297193591758e-05 };
    static double noise_model_B[] = { -1.612741291155018e-05,-7.508667192753393e-06,-5.254501627732493e-06,-9.584092394242898e-06 };
    double A = noise_model_A[plane];
    double B = noise_model_B[plane];
    double s = A * sens + B;
    return s < 0.0 ? 0.0 : s;
}

double compute_noise_model_entry_O(int plane, int sens) {
    static double noise_model_C[] = { 2.315415999089418e-10,1.7095034140455638e-10,1.6005134669275169e-10,1.9564016376945445e-10 };
    static double noise_model_D[] = { 2.4896833177828285e-07,2.799683666506459e-07,4.337770575621151e-07,5.13079443495488e-07 };
    double digital_gain = (sens / 213.0) < 1.0 ? 1.0 : (sens / 213.0);
    double C = noise_model_C[plane];
    double D = noise_model_D[plane];
    double o = C * sens * sens + D * digital_gain * digital_gain;
    return o < 0.0 ? 0.0 : o;
}

#ifndef SINGLE_VARIABLE_KALMAN_FILTER
#define SINGLE_VARIABLE_KALMAN_FILTER

typedef struct {
  float measurementUncertainty;
  float estimateError;
  float processNoise;
  float lastEstimate;
} SV_KalmanFilter;

void SV_PopulateKalmanFilter(SV_KalmanFilter *, const float, const float, const float);
float SV_UpdateEstimate(SV_KalmanFilter *, const float);

#endif

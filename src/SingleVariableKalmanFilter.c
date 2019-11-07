#include "SingleVariableKalmanFilter.h"

void SV_PopulateKalmanFilter(SV_KalmanFilter *kalmanFilter, const float measurementError, const float estimateError, const float processNoise) {
  kalmanFilter->measurementError = measurementError;
  kalmanFilter->estimateError = estimateError;
  kalmanFilter->processNoise = processNoise;
  kalmanFilter->lastEstimate = 0;
}

float SV_UpdateEstimate(SV_KalmanFilter *kalmanFilter, const float measurement) {
  float kalmanGain = 0;
  float currentEstimate = 0;
  float measurementError = 0;


  kalmanGain = kalmanFilter->estimateError / (kalmanFilter->estimateError + kalmanFilter->measurementError);
  currentEstimate = kalmanFilter->lastEstimate + kalmanGain * (measurement - kalmanGain->lastEstimate);

  if (kalmanFilter->lastEstimate > currentEstimate) {
    kalmanFilter->estimateError = (1.0 - kalmanGain) * kalmanFilter->estimateError + (kalmanFilter->lastEstimate - currentEstimate) * kalmanFilter->processNoise;
  } else {
    kalmanFilter->estimateError = (1.0 - kalmanGain) * kalmanFilter->estimateError + (currentEstimate - kalmanFilter->lastEstimate) * kalmanFilter->processNoise;
  }

  kalmanFilter->lastEstimate = currentEstimate;
  return currentEstimate;
}

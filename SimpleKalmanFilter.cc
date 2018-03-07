// Based on
// https://www.youtube.com/playlist?list=PLX2gX-ftPVXU3oUFNATxGXY90AULiqnWT

#include <fstream>
#include <iostream>
#include <vector>

class SimpleKalmanFilter {
 public:
  // initial_est: The initial estimate to start with
  // initial_err_est: The initial error in the estimate to start with
  // err_measure: The expected error in the measurement (i.e. +/- some number)
  SimpleKalmanFilter(double initial_est, double initial_err_est,
                     double err_measure)
      : prev_est_(initial_est),
        prev_err_est_(initial_err_est),
        err_measure_(err_measure) {}

  // Run an iteration of the Kalman filter with a new measurement.
  void UpdateEstimate(double new_measurement) {
    // Calculate Kalman Gain.
    double gain = prev_err_est_ / (prev_err_est_ + err_measure_);
    // Calculate the new estimate.
    curr_est_ = prev_est_ + gain * (new_measurement - prev_est_);
    // Calculate the new estimated error.
    curr_err_est_ = (1 - gain) * prev_est_;

    // Set the old values to be the new ones in prep for the new iteration.
    prev_est_ = curr_est_;
    prev_err_est_ = curr_err_est_;
  }

  // Retrieve the current estimate.
  double GetEstimate() { return curr_est_; }

 private:
  // The expected error in the measured value. This value is provided
  // externally.
  const double err_measure_;

  // Previous state of the Kalman Filter.
  double prev_est_;
  double prev_err_est_;

  // Current state of the Kalman Filter.
  double curr_est_ = 0;
  double curr_err_est_ = 0;
};

int main() {
  SimpleKalmanFilter kf(8.0, 2.0, 24.0 /* Increase to stablise filter*/);

  // Create test data.
  std::vector<double> data(500);
  for (int i = 0; i < data.size(); i++) {
    // Fill data[i] with a random number from 100 to 6. (mean of 103)
    data[i] = rand() % 6 + 100;
  }

  // Initialise a filestream that creates a kf.csv file with plot data.
  std::ofstream fs;
  fs.open("kf.csv");
  fs << "i, data, Estimate\n";

  // Sequentially give the Kalman Filter the estimate list data.
  for (int i = 0; i < data.size(); i++) {
    kf.UpdateEstimate(data[i]);

    // Print out the current estimate.
    std::cout << "Iter: " << i << " Data: " << data[i]
              << " Est: " << kf.GetEstimate() << std::endl;

    // Write a new line to the filestream with the current estimate.
    fs << i << "," << data[i] << "," << kf.GetEstimate() << "\n";
  }

  // Close the filestream.
  fs.close();
}
#include "integrator.hpp"

#include <Eigen/Dense>
#include <iostream>

int main() {
  HarmonicOscillator ho;
  Eigen::MatrixXd y = ho.integrate(0.01, 1000, {1, 0});
  std::cout << y << std::endl;
  return 0;
}

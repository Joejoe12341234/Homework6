#pragma once

#include <Eigen/Dense>
#include <vector>

class IntegratorBase {
public:
  virtual Eigen::VectorXd f(double t, const Eigen::VectorXd &y) const = 0;
  virtual ~IntegratorBase() {}

  virtual Eigen::VectorXd compute_step(double t_n, const Eigen::VectorXd &y_n,
                                       double h) = 0;

  Eigen::MatrixXd integrate(double stepsize, int steps,
                            const std::vector<double> &init_y) {
    std::size_t order = init_y.size();

    Eigen::MatrixXd y(steps, order);
    for (int i = 0; i < order; i++) {
      y(0, i) = init_y[i];
    }

    for (int n = 0; n < steps - 1; n++) {
      y.row(n + 1) = compute_step(stepsize * n, y.row(n), stepsize);
    }

    return y;
  };
};

class EulerIntegrator : public IntegratorBase {
public:
  Eigen::VectorXd compute_step(double t_n, const Eigen::VectorXd &y_n,
                               double h) override {
    return y_n + h * f(t_n, y_n);
  }
};

class HarmonicOscillator : public EulerIntegrator {
public:
  Eigen::VectorXd f(double t, const Eigen::VectorXd &y) const override {
    Eigen::VectorXd dydt(2);
    dydt[0] = y[1];
    dydt[1] = -y[0];
    return dydt;
  }
};

#include "lowpass.hpp"

LowPass::LowPass(double alpha) : alpha_(alpha) {}

double LowPass::update(double x) {
  y_ += alpha_ * (x - y_);
  return y_;
}

double LowPass::value() const { return y_; }
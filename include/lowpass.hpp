#pragma once

class LowPass {
public:
  explicit LowPass(double alpha);
  double update(double x);
  double value() const;

private:
  double alpha_;
  double y_ = 0.0;
};
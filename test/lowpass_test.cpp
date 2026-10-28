#include <gtest/gtest.h>
#include "lowpass.hpp"

TEST(LowPass, StartsAtZero) {
  LowPass f(0.1);
  EXPECT_DOUBLE_EQ(f.value(), 0.0);
}

TEST(LowPass, AlphaOneFollowsInput) {
  LowPass f(1.0);
  EXPECT_DOUBLE_EQ(f.update(5.0), 5.0);
}

TEST(LowPass, ConvergesToConstantInput) {
  LowPass f(0.1);
  for (int i = 0; i < 200; ++i) f.update(10.0);
  EXPECT_NEAR(f.value(), 10.0, 1e-6);
}

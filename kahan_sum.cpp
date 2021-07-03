#include <cmath>
#include <iostream>
#include <vector>

template <typename T> T naive_sum(const std::vector<T> &values) {
  T sum{};
  for (auto v : values) {
    sum += v;
  }
  return sum;
}

template <typename T> T KahanSum(const std::vector<T> &values) {
  T sum{};
  T c{};
  for (auto v : values) {
    T y = v - c;
    T t = sum + y;
    c = (t - sum) - y;
    sum = t;
  }
  return sum;
}

template <typename T> T NeumaierSum(const std::vector<T> &values) {
  T sum{};
  T c{};

  for (auto v : values) {
    T t = sum + v;
    if (std::fabs(sum) >= std::fabs(v)) {
      c += (sum - t) + v;
    } else {
      c += (v - t) + sum;
    }
    sum = t;
  }

  return sum + c;
}

int main() {
  std::vector<double> is2{1.0, 100000000.0, -100000000.0, 1.0};
  std::vector<double> is2XXL{1.0, 10e100, 1.0, -10e100};
  std::vector<float> is2f{1.0f, 100000000.0f, -100000000.0f, 1.0f};
  std::vector<float> is2Mix{1.0f, 100000000.0f, 1.0f, -100000000.0f};

  std::cout << "----------------------------------------" << std::endl;
  std::cout << "naive_sum<d>(is2): " << naive_sum(is2) << std::endl;
  std::cout << "naive_sum<d>(is2XXL): " << naive_sum(is2XXL) << std::endl;
  std::cout << "naive_sum<f>(is2f): " << naive_sum(is2f) << std::endl;
  std::cout << "naive_sum<f>(is2Mix): " << naive_sum(is2Mix) << std::endl;
  std::cout << "----------------------------------------" << std::endl;

  std::cout << "KahanSum<d>(is2): " << KahanSum(is2) << std::endl;
  std::cout << "KahanSum<d>(is2XXL): " << KahanSum(is2XXL) << std::endl;
  std::cout << "KahanSum<f>(is2f): " << KahanSum(is2f) << std::endl;
  std::cout << "KahanSum<f>(is2Mix): " << KahanSum(is2Mix) << std::endl;
  std::cout << "----------------------------------------" << std::endl;

  std::cout << "NeumaierSum<d>(is2): " << NeumaierSum(is2) << std::endl;
  std::cout << "NeumaierSum<d>(is2XXL): " << NeumaierSum(is2XXL) << std::endl;
  std::cout << "NeumaierSum<f>(is2f): " << NeumaierSum(is2f) << std::endl;
  std::cout << "NeumaierSum<f>(is2Mix): " << NeumaierSum(is2Mix) << std::endl;

  return 0;
}
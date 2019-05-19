#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <vector>

class Function {
 public:
  Function(int power, std::string difficulty);

  int getPower() const;
  std::vector<double> getCoefficients() const;
  std::vector<double> getX() const;
  std::vector<double> getY() const;
  double getZero() const;

  void printFunc() const;
  double f(double x) const;
  void findZero();

  ~Function();
 private:
  double bisectionMethod(double start, double end, double error);

  std::vector<double> m_coefficients;
  std::vector<double> m_x;
  std::vector<double> m_y;
  double m_zero;
  double m_error;
  int m_power;
  std::string m_difficulty;
};

#endif

#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <vector>

class Function {
 public:
  Function(int power, std::string difficulty);
  std::vector<double> getCoefficients() const;
  int getPower() const;
  std::vector<double> getX() const;
  std::vector<double> getY() const;
  // std::vector<double> getExtremum() const;
  // void findExtreme();
  ~Function();
 private:
  // std::vector<double> bisectionMethod();
  // std::vector<double> m_extremum;
  std::vector<double> m_coefficients;
  std::vector<double> m_x;
  std::vector<double> m_y;
  std::string m_difficulty;
  int m_power;
};

#endif

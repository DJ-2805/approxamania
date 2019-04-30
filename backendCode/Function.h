#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>

class Function {
 public:
  Function(int power, double* coefficients);
  double* getConstants();
  int getPower();
  double* getExtremum();
  void findExtreme();
  ~Function();
 private:
  double* bisectionMethod();
  double* m_extremum;
  double* m_constants;
  double* m_x;
  double* m_y;
  int m_size;
  int m_power;
};

#endif

#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <vector>
#include <QVector>
#include <sstream>

class Function {
 public:
  Function(int power, std::string difficulty);

  int getPower() const;
  QVector<double> getCoefficients() const;
  QVector<double> getX() const;
  QVector<double> getY() const;
  double getZero() const;
  std::string getDiffiulty () const{
      return m_difficulty;
  }

  bool is_graphed(){

      if(m_x.size() == 1 || m_y.size() == 1){
          return false;
      }

      return true;
  }

  void printFunc(std::stringstream & x) const;
  double f(double x) const;

  ~Function();
 private:
  double bisectionMethod(double start, double end, double error);

  QVector<double> m_coefficients;
  QVector<double> m_x;
  QVector<double> m_y;
  double m_zero;
  double m_error;
  double m_factor;
  int m_power;
  double m_userError;
  std::string m_difficulty;
};

#endif

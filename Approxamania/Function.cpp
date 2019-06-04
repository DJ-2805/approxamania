#include "Function.h"
#include <cstdlib>
#include <math.h>
#include <string>

// ****************************************
// Constructor
// ****************************************
Function::Function(int power, std::string difficulty)
  :  m_power(power), m_difficulty(difficulty), m_error(0.001) {
  double step = .01;
  int size = 100;
  int i;

  if(difficulty == "simple")
    m_userError = 1;
  else if(difficulty == "intermediate")
    m_userError = 0.1;
  else if(difficulty == "difficult")
    m_userError = 0.001;
  else
    m_userError = 0.001;

  m_x.resize(size/step);
  double j = 0;
  for(i = 0; i < m_x.size(); i++) {
    this->m_x[i] = (j-size/2);
    j += step;
  }

  m_coefficients.resize(power);
  int len = m_coefficients.size();
  for(i = 0; i < len;i++)
    m_coefficients[i] = (rand() % 15) - 7;

  do {
         m_factor = (rand() % 15) - 8;
  } while(m_factor == 0);


  m_y.resize(size/step);
  for(i = 0; i < m_y.size();i++)
    m_y[i] = f(m_x[i]);

  m_zero = bisectionMethod(m_x.front(),m_x.back(),m_error);
}

// ****************************************
// Get Functions
// ****************************************
int Function::getPower() const {
  return m_power;
}

QVector<double> Function::getCoefficients() const {
  return m_coefficients;
}

QVector<double> Function::getX() const {
  return m_x;
}

QVector<double> Function::getY() const {
  return m_y;
}

double Function::getZero() const {
  return m_zero;
}

// ****************************************
// Other Public Functions
// ****************************************
void Function::printFunc(std::stringstream & x) const {
  std::string output = "";
  for(int i = 0 ; i < m_coefficients.size(); i++)
    output += "(x - " + std::to_string(m_coefficients[i]) + ")";
  x << output ;
}

double Function::f(double x) const {
  double y = 1;
  for(int j = 0; j < m_coefficients.size();j++)
    y *= x-m_coefficients[j];
  y *= m_factor;
  return y;
}

// ****************************************
// Destructor
// ****************************************
Function::~Function() {
  std::cout << "I'm deleted" << std::endl;
}

// ****************************************
// Private Functions
// ****************************************
double Function::bisectionMethod(double start, double end, double error) {
  int n = 0;
  double a = start;
  double b = end;
  double p = (a+b)/2;
  double lShift = -1*error;
  double rShift = error;
  double fp = this->f(p);

  while(fp < lShift || fp > rShift) {
    n++;
    double fa = this->f(a);
    double fb = this->f(b);

    if(fp > 0 && fa < 0)
      b = p;
    else if(fp > 0 && fb < 0)
      a = p;
    else if(fp < 0 && fa > 0)
      b = p;
    else if(fp < 0 && fb > 0)
      a = p;
    else
      break;

    p = (a+b)/2;
    fp = this->f(p);
    // std::cout << "a: " << a << " ";
    // std::cout << "b: " << b << " ";
    // std::cout << "p: " << p << " ";
    // std::cout << "n: " << n << std::endl;
  }

  // std::cout << "final p: " << p << " " << m_error << std::endl;
  return p;
}

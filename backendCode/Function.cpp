#include "Function.h"
#include <cstdlib>
#include <math.h>
#include <string>

// ****************************************
// Constructor
// ****************************************
Function::Function(int power, std::string difficulty)
  :  m_power(power), m_difficulty(difficulty) {
  double step = .01;
  int size = 20;
  int i;

  if(difficulty == "simple")
    m_error = 1;
  else if(difficulty == "intermediate")
    m_error = 0.1;
  else if(difficulty == "difficult")
    m_error = 0.001;
  else
    m_error = 0.001;

  this->m_x.resize(size/step);
  for(i = 0; i < this->m_x.size(); i++)
    this->m_x[i] = (i-size/2)+step;

  m_coefficients.resize(power+1);
  int len = m_coefficients.size();
  for(i = 0; i < len;i++)
    m_coefficients[i] = (rand() % size) - 10;

  double first = m_coefficients[0];
  double last = m_coefficients[len - 1];
  if(((first > 0) && (last > 0)) || ((first < 0) && (last < 0)))
    m_coefficients[len-1] *= -1;


  this->m_y.resize(size/step);
  for(i = 0; i < m_y.size();i++)
    m_y[i] = this->f(m_x[i]);
}

// ****************************************
// Get Functions
// ****************************************
int Function::getPower() const {
  return m_power;
}

std::vector<double> Function::getCoefficients() const {
  return m_coefficients;
}

std::vector<double> Function::getX() const {
  return m_x;
}

std::vector<double> Function::getY() const {
  return m_y;
}

double Function::getZero() const {
  return m_zero;
}

// ****************************************
// Other Public Functions
// ****************************************
void Function::printFunc() const {
  std::string output = "";
  for(int i = 0 ; i < m_coefficients.size(); i++) {
    int pow = m_power-i;
    output += std::to_string(m_coefficients[i]) + "*x^" +
      std::to_string(pow);
    if(pow != 0)
      output += " + ";
  }
  std::cout << output << std::endl;
}

double Function::f(double x) const {
  double y = 0;
  for(int j = 0; j < m_coefficients.size();j++)
    y += pow(x,m_power-j)*m_coefficients[j];
  return y;
}

void Function::findZero() {

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
  // int n = 0;
  // double a = start;
  // double b = end;
  // double p = (a+b)/2;
  // double lShift = -1*error;
  // double rShift = error;
  //
  // while(f(p) < lShift || f(p) >= rShift) {
  // n++;
  // if(f(p) > 0 && f(a) < 0)
  // b = p;
  // else if(f(p) > 0 && f(b) < 0)
  // a = p;
  // else if(f(p) < 0 && f(a) > 0)
  // b = p
  //
  // }
  return 0;
}

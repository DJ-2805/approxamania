#include "Function.h"
#include <cstdlib>
#include <math.h>

Function::Function(int power, std::string difficulty)
  :  m_power(power), m_difficulty(difficulty) {
  double step;
  int i;

  if(difficulty == "simple")
    step = .1;
  else if(difficulty == "intermediate")
    step = .01;
  else if(difficulty == "difficult")
    step = .001;
  else
    step = 0;

  this->m_x.resize(10/step);
  this->m_y.resize(10/step);

  for(i = 0; i < this->m_x.size(); i++)
    this->m_x[i] = (i-10)+step;

  m_coefficients.resize(power+1);
  for(i = 0; i < m_coefficients.size();i++)
    m_coefficients[i] = (rand() % 20)/2.0 + 1;

  for(i = 0; i < m_y.size();i++)
    for(int j = 0; j < m_coefficients.size();j++)
      m_y[i] += pow(m_x[i],power-j)*m_coefficients[j];
}

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

Function::~Function() {
  std::cout << "I'm deleted" << std::endl;
}

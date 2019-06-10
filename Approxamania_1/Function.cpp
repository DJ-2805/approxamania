#include "Function.h"
#include <cstdlib>
#include <math.h>
#include <string>

// ****************************************
// Constructor
// ****************************************
Function::Function(int power, std::string difficulty)
  :  m_power(power), m_difficulty(difficulty) {
  double step = .01;  // step size between points
  int size = 500;     // size of points to allocate for x,y
  int i;              // iterator used in for loops ahead

  // getting error bound for zero approximations
  if(m_difficulty == "simple")
      m_error = 1.5;
  else if(m_difficulty == "intermediate")
      m_error = 1.0;
  else if(m_difficulty == "difficult")
      m_error = 0.5;
  else
      m_error = 0.001;

  // allocates the x values for the function
  m_x.resize(size/step);
  double j = 0;
  for(i = 0; i < m_x.size(); i++) {
    this->m_x[i] = (j-size/2);
    j += step;
  }

  // randomly generates coefficients for the polynomial
  m_zeros.resize(power);
  int len = m_zeros.size();
  for(i = 0; i < len;i++)
    m_zeros[i] = (rand() % 30) - 15;

  do {
    m_coefficient = (rand() % 30) - 15;
  } while(m_coefficient == 0);

  // generates y values from x values and coefficients
  m_y.resize(size/step);
  for(i = 0; i < m_y.size();i++)
    m_y[i] = f(m_x[i]);
}

// ****************************************
// Get Functions
// ****************************************
int Function::getPower() const {
  return m_power;
}

QVector<double> Function::getX() const {
  return m_x;
}

QVector<double> Function::getY() const {
  return m_y;
}

QVector<double> Function::getZeros() const {
    return m_zeros;
}

double Function::getZero() const {
    int randi = rand()%m_zeros.size();
    return m_zeros[randi];
}

double Function::getZero(int index) const {
    try {
        return m_zeros[index];
    } catch (...) {
        std::cout << "The Index is out of range!" << std::endl;
        return -1;
    }
}

double Function::getCoefficient() const {
  return m_coefficient;
}

std::string Function::getDifficulty() const{
    return m_difficulty;
}

// ****************************************
// Other Public Functions
// ****************************************
bool Function::is_graphed() const {
    if(m_x.size() == 1 || m_y.size() == 1)
        return false;
    return true;
}

bool Function::is_zero(double zero) const {
    double lowerBound, upperBound;
    for(int i = 0; i < m_zeros.size(); i++) {
        lowerBound = m_zeros[i] - m_error;
        upperBound = m_zeros[i] + m_error;
        if(zero > lowerBound && zero < upperBound)
            return true;
    }
    return false;
}

void Function::printFunc(std::stringstream & x) const {
  std::string output = "f(x) = " + std::to_string(m_coefficient);
  for(int i = 0 ; i < m_zeros.size(); i++) {
    double val = m_zeros[i];
    if(val < 0)
      output += "(x - (" + std::to_string(m_zeros[i]) + "))\n";
    else
      output += "(x - " + std::to_string(m_zeros[i]) + ")\n";
  }
  x << output ;
}

void Function::printInfo(std::stringstream & y) const {
  if(m_power == 1)
    y << "This is a linear function!" << std::endl
              << "It follows the form f(x) = ax+b." << std::endl
              << "Where a and b are both constants" << std::endl
              << "This function can have at most one zero," << std::endl
              << " and it is considered a constant function if a = 0.";
  else if(m_power == 2)
    y << "This is a quadratic function!" << std::endl
              << "If follows the standard form f(x) = a*x^2+b*x+c." << std::endl
              << "Where a,b, and c are constants" << std::endl
              << "It can also be in the form f(x) = (x-x_1)(x-x_2)." << std::endl
              << "Where x_1 and x_2 are also constants, " << std::endl
              << "but are also the zeros of the function." << std::endl
              << "A final form is f(x) = a(x-h)^2 + k." << std::endl
              << "Where a,h and k are all constants." << std::endl
              << "This form is the vertex form, " << std::endl
              << "because (h,k) would be the vertex, and " << std::endl
              << "a is the same value as that in the standard form";
  else if(m_power == 3)
    y << "Ths is a cubic function!" << std::endl
              << "It follows the standard form f(x) = ax^3+bx^2+cx+d." << std::endl
              << "Where a,b,c, and d are constants." << std::endl
              << "It can also be in the factored form " << std::endl
              << "f(x) = (x-x_1)(x-x_2)(x-x_3)." << std::endl
              << "Where x_i are the zeros of the function." << std::endl;
  else if(m_power == 4)
    y << "This is quartic function!" << std::endl
              << "It follows the standard form, " << std::endl
              << "f(x) = ax^4+bx^3+cx^2+dx+e." << std::endl
              << "Where a,b,c,d, and e are all constants." << std::endl
              << "It also follows the form ";
}

double Function::f(double x) const {
  double y = 1;
  for(int j = 0; j < m_zeros.size();j++)
    y *= x-m_zeros[j];
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

  std::cout << "final p: " << p << " " << m_error << std::endl;
  return p;
}

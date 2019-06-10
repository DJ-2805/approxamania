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
        // check in case user asks for outside of index
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
  // print for linear functions
  if(m_power == 1)
    y << "This is a linear function!" << std::endl
              << "It follows the form f(x) = ax+b." << std::endl
              << "Where a and b are both constants" << std::endl
              << "This function can have at most one zero," << std::endl
              << " and it is considered a constant function if a = 0.";
  // print for quadratics
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
  // print for cubic functions
  else if(m_power == 3)
    y << "Ths is a cubic function!" << std::endl
              << "It follows the standard form f(x) = ax^3+bx^2+cx+d." << std::endl
              << "Where a,b,c, and d are constants." << std::endl
              << "It can also be in the factored form " << std::endl
              << "f(x) = (x-x_1)(x-x_2)(x-x_3)." << std::endl
              << "Where x_i are the zeros of the function." << std::endl;
  // print for higher order functions
  else if(m_power >= 4)
    y << "This is a higher-degree polynomial!" << std::endl
              << "It follows the standard form, " << std::endl
              << "f(x) = a_0*x^n+a_1*x^(n-1)+...+a_n*x^0" << std::endl
              << "Where a_n values are all constants" << std::endl
              << "In factored form it follows" << std::endl
              << "f(x) = a(x-x_0)(x-x_1)...(x-x_n)";
}

double Function::f(double x) const {
  // gets coefficient for slope direction and sizing
  double y = m_coefficient;
  // iterates through zeros to generate y value at given x
  for(int j = 0; j < m_zeros.size();j++)
    y *= x-m_zeros[j];
  // returns y
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

  // values needed for bisection
  int n = 0;                    // step start
  double a = start;             // left bound
  double b = end;               // right bound
  double p = (a+b)/2;           // middple point
  double lShift = -1*error;     // left error
  double rShift = error;        // right error
  double fp = this->f(p);       // value of y at p

  // iterates through bound to find zero
  while(fp < lShift || fp > rShift) {
    n++;                        // update step
    double fa = this->f(a);     // evaluate f at left bound
    double fb = this->f(b);     // evaluate f at right bound

    // checks which bound to shrink
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

    // update p and f(p)
    p = (a+b)/2;
    fp = this->f(p);
    /* PRINT CHECK */
    // std::cout << "a: " << a << " ";
    // std::cout << "b: " << b << " ";
    // std::cout << "p: " << p << " ";
    // std::cout << "n: " << n << std::endl;
  }

  std::cout << "final p: " << p << " " << m_error << std::endl;
  return p;
}

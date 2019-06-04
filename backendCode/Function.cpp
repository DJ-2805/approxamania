#include "Function.h"
#include <cstdlib>
#include <math.h>
#include <string>

// ****************************************
// Constructor
// ****************************************
Function::Function(int power, std::string difficulty)
  :  m_power(power), m_difficulty(difficulty), m_error(0.001) {
  double step = .01;  // step size between points
  int size = 500;     // size of points to allocate for x,y
  int i;              // iterator used in for loops ahead

  // sets the user error bound depending on user input on GUI
  if(difficulty == "simple")
    m_userError = 1;
  else if(difficulty == "intermediate")
    m_userError = 0.1;
  else if(difficulty == "difficult")
    m_userError = 0.001;
  else
    m_userError = 0.001;

  // allocates the x values for the function
  m_x.resize(size/step);
  double j = 0;
  for(i = 0; i < m_x.size(); i++) {
    this->m_x[i] = (j-size/2);
    j += step;
  }

  // randomly generates coefficients for the polynomial
  m_coefficients.resize(power+1);
  int len = m_coefficients.size();
  for(i = 0; i < len;i++)
    m_coefficients[i] = (rand() % 20) - 10;

  // forces signs between first and last coefficients
  // to ensure function is readable on the plot
  double first = m_coefficients[0];        // first coefficient
  double last = m_coefficients[len - 1];   //  last coefficient
  if(((first > 0) && (last > 0)) || ((first < 0) && (last < 0)))
    m_coefficients[len-1] *= -1;


  // generates y values from x values and coefficients
  m_y.resize(size/step);
  for(i = 0; i < m_y.size();i++)
    m_y[i] = f(m_x[i]);

  // finds a zero of the function
  m_zero = bisectionMethod(m_x.front(),m_x.back(),m_error);
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
  double y = 1;
  for(int j = 0; j < m_coefficients.size();j++)
    y *= x-m_coefficients[j];
  return y;
}

void Function::printInfo() const {
  if(m_power == 1)
    std::cout << "This is a linear function!" << std::endl
              << "It follows the form f(x) = ax+b." << std::endl
              << "Where a and b are both constants" << std::endl
              << "This function can have at most one zero," << std::endl
              << " and it is considered a constant function if a = 0.";
  else if(m_power == 2)
    std::cout << "This is a quadratic function!" << std::endl
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
    std::cout << "Ths is a cubic function!" << std::endl
              << "It follows the standard form f(x) = ax^3+bx^2+cx+d." << std::endl
              << "Where a,b,c, and d are constants." << std::endl
              << "It can also be in the factored form " << std::endl
              << "f(x) = (x-x_1)(x-x_2)(x-x_3)." << std::endl
              << "Where x_i are the zeros of the function." << std::endl;
  else if(m_power == 4)
    std::cout << "This is quartic function!" << std::endl
              << "It follows the standard form, " << std::endl
              << "f(x) = ax^4+bx^3+cx^2+dx+e." << std::endl
              << "Where a,b,c,d, and e are all constants." << std::endl
              << "It also follows the form ";
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

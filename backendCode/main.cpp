#include "Function.h"
#include <iostream>

int main() {
  Function *f = new Function(2,"simple");
  std::cout << "Power: ";
  std::cout << f->getPower() << std::endl;

  std::cout << "Coefficients: " << std::endl;
  std::vector<double> a = f->getCoefficients();
  std::vector<double>::const_iterator i;
  for(i=a.begin();i!=a.end();i++)
    std::cout << *i << " ";

  std::cout << "x-values: " << std::endl;
  a = f->getX();
  for(i=a.begin();i!=a.end();i++)
    std::cout << *i << " ";

  std::cout << "y-values: " << std::endl;
  a = f->getY();
  for(i=a.begin();i!=a.end();i++)
    std::cout << *i << " ";
}

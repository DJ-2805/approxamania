#include "Function.h"
#include <iostream>
#include <string>

int main() {
  Function *f = new Function(2,"simple");
  Function *g = new Function(3,"simple");
  Function *h = new Function(4,"simple");
  Function *ff = new Function(2,"simple");
  Function *fg = new Function(2,"simple");
  std::cout << "Power: ";
  std::cout << f->getPower() << std::endl;

  std::cout << "Coefficients: " << std::endl;
  std::vector<double> a = f->getCoefficients();
  std::vector<double>::const_iterator i;
  for(i=a.begin();i!=a.end();i++)
    std::cout << *i << " ";
  std::cout << std::endl;

  f->printFunc();
  std::cout << f->f(5) << std::endl;
  g->printFunc();
  std::cout << g->f(5) << std::endl;
  h->printFunc();
  std::cout << h->f(5) << std::endl;
  ff->printFunc();
  std::cout << ff->f(5) << std::endl;
  fg->printFunc();
  std::cout << fg->f(5) << std::endl;
  /*
  std::cout << "x-values: " << std::endl;
  a = f->getX();
  for(i=a.begin();i!=a.end();i++)
    std::cout << *i << " ";

  std::cout << "y-values: " << std::endl;
  a = f->getY();
  for(i=a.begin();i!=a.end();i++)
    std::cout << *i << " ";
  */
}

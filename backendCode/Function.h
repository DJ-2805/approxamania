#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <vector>

class Function {
 public:
  // ****************************************
  // Constructor
  // ****************************************
  /*
   * Function Function
   * Constructor for the Function class to generate a polynomial
   * @param power: int, the power of the polynomial function
   * @param difficulty: string, the setting from the game of how tough
   * @return: none
   */
  Function(int power, std::string difficulty);

  // ****************************************
  // Get Functions
  // ****************************************
  /*
   * Function getPower
   * gets power value of the function
   * @param: none
   * @return: int
   */
  int getPower() const;
  /*
   * Function getCoefficients
   * gets coefficients of the function
   * @param: none
   * @return: vector<double>
   */
  std::vector<double> getCoefficients() const;
  /*
   * Function getX
   * gets x-values of the function
   * @param: none
   * @return: vector<double>
   */
  std::vector<double> getX() const;
  /*
   * Function getY
   * gets y-values of the function
   * @param: none
   * @return: vector<double>
   */
  std::vector<double> getY() const;
  /*
   * Function getZero
   * gets a zero of the function
   * @param: none
   * @return: double
   */
  double getZero() const;

  // ****************************************
  // Other Public Functions
  // ****************************************
  /*
   * Function printFunc
   * print out the function in a_0*x^n+a_1*x^(n-1)+...+a_n*x^0 format
   * @param: none
   * @return: none
   */
  void printFunc() const;
  /*
   * Function f
   * takes in an x value and will generate the y-value accordingly
   * @param x: double, x-value
   * @return: double, y-value calculate at x
   */
  double f(double x) const;

  void printInfo() const;

  // ****************************************
  // Destructor
  // ****************************************
  /* Function ~Function
   * destructor for the class
   * @param: none
   * @return: none
   */
  ~Function();
 private:
  /* Function bisectionMethod
   * will approximate a zero of the function
   * @param start: double,the left bound of interest
   * @param end: double,the right bound of interest
   * @param error: double, error bound of zero
   * @return: double, the approximated zero
   */
  double bisectionMethod(double start, double end, double error);

  std::vector<double> m_coefficients;
  std::vector<double> m_x;
  std::vector<double> m_y;
  double m_zero;
  double m_error;
  int m_power;
  double m_userError;
  std::string m_difficulty;
};

#endif

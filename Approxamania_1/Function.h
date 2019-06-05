#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <vector>
#include <QVector>
#include <sstream>

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
   * @return: QVector<double>
   */
  QVector<double> getCoefficients() const;
  /*
   * Function getX
   * gets x-values of the function
   * @param: none
   * @return: QVector<double>
   */
  QVector<double> getX() const;
  /*
   * Function getY
   * gets y-values of the function
   * @param: none
   * @return: QVector<double>
   */
  QVector<double> getY() const;
  /*
   * Function getZero
   * gets a zero of the function
   * @param: none
   * @return: double
   */
  double getZero() const;
  /*
   * Function getDiffiulty
   * gets the difficulty of the function
   * @param: none
   * @return: str
   */
  std::string getDiffiulty() const;

  // ****************************************
  // Other Public Functions
  // ****************************************
  /*
   * Function is_graphed
   * checks if current curve has a size
   * @param: none
   * @return: bool
   */
  bool is_graphed() const;
  /*
   * Function printFunc
   * print out the function in factored format
   * @param: none
   * @return: str
   */
  void printFunc(std::stringstream & x) const;
  /*
   * Function printInfo
   * prints out information on the specific polynomial
   * @param: none
   * @return: str
   */
  void printInfo(std::stringstream & x) const;
  /*
   * Function f
   * takes in an x value and will generate the y-value accordingly
   * @param x: double, x-value
   * @return: double, y-value calculate at x
   */
  double f(double x) const;

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

  QVector<double> m_coefficients;  // all the zeros of the function
  QVector<double> m_x;             // x-valeus of the function
  QVector<double> m_y;             // y-values of the function
  double m_zero;                   // one approximated zero of the function
  double m_error;                  // error bound for approximate zero
  double m_factor;                 // determines whether positive or negative curve
  int m_power;                     // degree of the polynomial
  std::string m_difficulty;        // game level
};

#endif

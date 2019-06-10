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
   * Function getZeros
   * gets zeros of the function
   * @param: none
   * @return: QVector<double>
   */
  QVector<double> getZeros() const;
  /*
   * Function getZero
   * gets a random zero from the vector
   * @param: none
   * @return: double
   */
  double getZero() const;
  /*
   * Function getZero
   * gets the zero specified at
   * the index of the vector
   * @param index: int, index of the vector
   * @return: double
   */
  double getZero(int index) const;
  /*
   * Function getCoefficient
   * gets coefficient of fucntion
   * @param: none
   * @return: double
   */
  double getCoefficient() const;
  /*
   * Function getDifficulty
   * gets difficulty of game
   * @param: none
   * @return: str
   */
  std::string getDifficulty() const;

  // ****************************************
  // Other Public Functions
  // ****************************************
  /*
   * Function is_graphed
   * checks if current function is plotted
   * @param: none
   * @return: bool
   */
  bool is_graphed() const;
  /*
   * Function is_zero
   * checks if given zero is within the vector of zeros
   * @param zero: double, given zero to check
   * @return: bool
   */
  bool is_zero(double zero) const;
  /*
   * Function printFunc
   * print out the function in factored format
   * @param: none
   * @return: none
   */
  void printFunc(std::stringstream & x) const;
  /*
   * Function printInfo
   * prints general info about current polynomial out
   * @param: none
   * @return: none
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
  /* Function bisectionMethod---DEPRECATED
   * will approximate a zero of the function
   * @param start: double,the left bound of interest
   * @param end: double,the right bound of interest
   * @param error: double, error bound of zero
   * @return: double, the approximated zero
   */
  double bisectionMethod(double start, double end, double error);

  QVector<double> m_x;
  QVector<double> m_y;
  QVector<double> m_zeros;
  double m_error;
  double m_coefficient;
  int m_power;
  double m_userError;
  std::string m_difficulty;
};

#endif /* FUNCTION_H */

#include <iostream>

struct Rational {
  Rational() = default;

  explicit Rational(int numerator);

  Rational(int numerator, int denominator);

  bool operator==(const Rational &rhs) const;

  bool operator!=(const Rational &rhs) const;

  friend Rational operator+(const Rational &lhs, const Rational &rhs);

  friend Rational operator-(const Rational &lhs, const Rational &rhs);

  Rational &operator+=(const Rational &rhs);

  Rational &operator+=(int rhs);

  Rational &operator*=(int rhs);

  std::ostream &WriteTo(std::ostream &ostrm) const;

  std::istream &ReadFrom(std::istream &istrm);

  friend std::ostream &operator<<(std::ostream &ostrm, const Rational &rhs);

  friend std::istream &operator>>(std::istream &istrm, Rational &rhs);

  int numerator_{0};
  int denominator_{1};

  static const char separator_{'/'};

  void Simplify();

  void Verify();

  static int Gcd(int n, int d);
};
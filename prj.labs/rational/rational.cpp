#include <iostream>
#include <stdexcept>
#include <rational/rational.h>

Rational::Rational(const int numerator) : Rational(numerator, 1) {}
Rational::Rational(const int numerator, const int denominator) : numerator_(numerator), denominator_(denominator) {
  Verify();
  Simplify();
}
bool Rational::operator==(const Rational &rhs) const {
  return (numerator_ == rhs.numerator_) && (denominator_ == rhs.denominator_);
}
bool Rational::operator!=(const Rational &rhs) const { return !operator==(rhs); }
Rational operator+(const Rational &lhs, const Rational &rhs) {
  Rational sum(lhs);
  sum += rhs;
  return sum;
}
Rational operator-(const Rational &lhs, const Rational &rhs) {
  int numerator = lhs.numerator_ * rhs.denominator_ - rhs.numerator_ * lhs.denominator_;
  int denominator = lhs.denominator_ * rhs.denominator_;
  return Rational{numerator, denominator};
}
Rational &Rational::operator+=(const Rational &rhs) {
  numerator_ = numerator_ * rhs.denominator_ + rhs.numerator_ * denominator_;
  denominator_ *= rhs.denominator_;
  Simplify();
  return *this;
}
Rational &Rational::operator+=(const int rhs) {
  return operator+=(Rational(rhs));
}
Rational &Rational::operator*=(const int rhs) {
  numerator_ *= rhs;
  Simplify();
  return *this;
}

int Rational::Gcd(int n, int d) {
  while (d) {
    n %= d;
    std::swap(n, d);
  }
  return n;
}

std::ostream &operator<<(std::ostream &ostrm, const Rational &rhs) {
  return rhs.WriteTo(ostrm);
}

std::istream &operator>>(std::istream &istrm, Rational &rhs) {
  return rhs.ReadFrom(istrm);
}

std::ostream &Rational::WriteTo(std::ostream &ostrm) const {
  ostrm << numerator_ << separator_ << denominator_;
  return ostrm;
}

std::istream &Rational::ReadFrom(std::istream &istrm) {
  int numerator(0);
  char slash('/');
  int denominator(1);
  istrm >> numerator >> slash >> denominator;
  if (istrm.good()) {
    if (Rational::separator_ == slash) {
      Rational::numerator_ = numerator;
      Rational::denominator_ = denominator;
      Rational::Verify();
      Rational::Simplify();
    } else {
      istrm.setstate(std::ios_base::failbit);
    }
  }
  return istrm;
}

void Rational::Verify() {
  if (denominator_ == 0) {
    throw std::invalid_argument("Received null denominator");
  }
}

void Rational::Simplify() {
  if (denominator_ < 0) {
    numerator_ *= -1;
    denominator_ *= -1;
  }
  int g = Gcd(numerator_, denominator_);
  numerator_ /= g;
  denominator_ /= g;
}





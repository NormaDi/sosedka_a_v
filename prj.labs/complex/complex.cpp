#include <sstream>
#include <cmath>
#include <complex/complex.h>

Complex::Complex(const double real)
    : Complex(real, 0.0) {
}

Complex::Complex(const double real, const double imaginary)
    : real_(real), imaginary_(imaginary) {
}

Complex &Complex::operator+=(const Complex &rhs) {
  real_ += rhs.real_;
  imaginary_ += rhs.imaginary_;
  return *this;
}

Complex operator+(const Complex &lhs, const Complex &rhs) {
  Complex sum(lhs);
  sum += rhs;
  return sum;
}

Complex operator-(const Complex &lhs, const Complex &rhs) {
  return Complex(lhs.real_ - rhs.real_, lhs.imaginary_ - rhs.imaginary_);
}

Complex &Complex::operator*=(const double rhs) {
  real_ *= rhs;
  imaginary_ *= rhs;
  return *this;
}

std::ostream &Complex::WriteTo(std::ostream &ostrm) const {
  ostrm << left_brace_ << real_ << separator_ << imaginary_ << right_brace_;
  return ostrm;
}

std::istream &Complex::ReadFrom(std::istream &istrm) {
  char left_brace(0);
  double real(0.0);
  char comma(0);
  double imaginary(0.0);
  char right_brace(0);
  istrm >> left_brace >> real >> comma >> imaginary >> right_brace;
  if (istrm.good()) {
    if ((Complex::left_brace_ == left_brace) && (Complex::separator_ == comma) &&
        (Complex::right_brace_ == right_brace)) {
      real_ = real;
      imaginary_ = imaginary;
    } else {
      istrm.setstate(std::ios_base::failbit);
    }
  }
  return istrm;
}

Complex &Complex::operator-=(const Complex &rhs) {
  real_ -= rhs.real_;
  imaginary_ -= rhs.imaginary_;
  return *this;

}

Complex &Complex::operator*=(const Complex &rhs) {
  double a, b, c, d;
  a = real_ * rhs.real_;
  b = real_ * rhs.imaginary_;
  c = imaginary_ * rhs.real_;
  d = imaginary_ * rhs.imaginary_;
  real_ = a - d;
  imaginary_ = b + c;
  return *this;
}

bool Complex::operator==(const Complex &rhs) const {
  return DoubleEquals(real_, rhs.real_) && DoubleEquals(imaginary_, rhs.imaginary_);
}

bool Complex::operator!=(const Complex &rhs) const { return !operator==(rhs); }

bool Complex::DoubleEquals(const double a, const double b, const double epsilon) {
  return std::abs(a - b) < epsilon;
}
std::istream &operator>>(std::istream &istrm, Complex &rhs) {

  return rhs.ReadFrom(istrm);
}
std::ostream &operator<<(std::ostream &ostrm, const Complex &rhs) {
  return rhs.WriteTo(ostrm);
}
Complex &Complex::operator-=(const double rhs) { return operator-=(Complex(rhs)); }

Complex &Complex::operator+=(const double rhs) {
  { return operator+=(Complex(rhs)); }
}





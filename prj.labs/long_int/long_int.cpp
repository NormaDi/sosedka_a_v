#include <long_int/long_int.h>
LInt::LInt(const std::string &str) {}
LInt::LInt(std::int8_t number) {}
bool LInt::operator==(const LInt &rhs) const {
  return false;
}
bool LInt::operator!=(const LInt &rhs) const {
  return false;
}
std::ostream &operator<<(std::ostream &ostrm, const LInt &rhs) {
  return rhs.WriteTo(ostrm);
}
std::istream &operator>>(std::istream &istrm, LInt &rhs) {
  return rhs.ReadFrom(istrm);
}
LInt operator+(LInt &lhs, LInt &rhs) {
  return LInt();
}
LInt &LInt::operator+=(const LInt &rhs) {
  return *this;
}
LInt &LInt::operator+=(std::int8_t rhs) {
  return *this;
}
LInt operator-(LInt &lhs, LInt &rhs) {
  return LInt();
}
LInt &LInt::operator-=(const LInt &rhs) {
  return *this;
}
LInt &LInt::operator-=(std::int8_t rhs) {
  return *this;
}
LInt operator*(LInt &lhs, LInt &rhs) {
  return LInt();
}
LInt &LInt::operator*=(const LInt &rhs) {
  return *this;
}
LInt &LInt::operator*=(std::int8_t rhs) {
  return *this;
}
LInt operator/(LInt &lhs, LInt &rhs) {
  return LInt();
}
LInt &LInt::operator/=(const LInt &rhs) {
  return *this;
}
LInt &LInt::operator/=(std::int8_t rhs) {
  return *this;
}
std::ostream &LInt::WriteTo(std::ostream &ostrm) const {
  return ostrm;
}
std::istream &LInt::ReadFrom(std::istream &istrm) {
  return istrm;
}

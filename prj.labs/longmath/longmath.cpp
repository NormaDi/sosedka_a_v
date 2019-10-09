#include "longmath.h"
Longmath::Longmath(std::string str) {}
Longmath::Longmath(std::int64_t number, std::int64_t base) {

}
Longmath::Longmath(std::string str, std::int64_t base) {

}
bool Longmath::operator==(const Longmath &rhs) const {
  return false;
}
bool Longmath::operator!=(const Longmath &rhs) const {
  return false;
}
std::ostream &operator<<(std::ostream &ostrm, const Longmath &rhs) {
  return rhs.WriteTo( ostrm);
}
std::istream &operator>>(std::istream &istrm, Longmath &rhs) {
  return rhs.ReadFrom(istrm);
}
Longmath operator+(Longmath &lhs, Longmath &rhs) {
  return Longmath();
}
Longmath &Longmath::operator+=(const Longmath &rhs) {
  return *this;
}
Longmath &Longmath::operator+=(std::int64_t rhs) {
  return *this;
}
Longmath operator-(Longmath &lhs, Longmath &rhs) {
  return Longmath();
}
Longmath &Longmath::operator-=(const Longmath &rhs) {
  return *this;
}
Longmath &Longmath::operator-=(std::int64_t rhs) {
  return *this;
}
Longmath operator*(Longmath &lhs, Longmath &rhs) {
  return Longmath();
}
Longmath &Longmath::operator*=(const Longmath &rhs) {
  return *this;
}
Longmath &Longmath::operator*=(std::int64_t rhs) {
  return *this;
}
Longmath operator/(Longmath &lhs, Longmath &rhs) {
  return Longmath();
}
Longmath &Longmath::operator/=(const Longmath &rhs) {
  return *this;
}
Longmath &Longmath::operator/=(std::int64_t rhs) {
  return *this;
}
std::ostream &Longmath::WriteTo(std::ostream &ostrm) const {
  return ostrm;
}
std::istream &Longmath::ReadFrom(std::istream &istrm) {
  return istrm;
}

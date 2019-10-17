#include <vector>
#include <string>

struct LInt {
  LInt() = default;

  explicit LInt(const std::string &str);
  explicit LInt(std::int8_t number);

  bool operator==(const LInt &rhs) const;
  bool operator!=(const LInt &rhs) const;

  friend std::ostream &operator<<(std::ostream &ostrm, const LInt &rhs);
  friend std::istream &operator>>(std::istream &istrm, LInt &rhs);

  friend LInt operator+(LInt &lhs, LInt &rhs);
  LInt &operator+=(const LInt &rhs);
  LInt &operator+=(std::int8_t rhs);

  friend LInt operator-(LInt &lhs, LInt &rhs);
  LInt &operator-=(const LInt &rhs);
  LInt &operator-=(std::int8_t rhs);

  friend LInt operator*(LInt &lhs, LInt &rhs);
  LInt &operator*=(const LInt &rhs);
  LInt &operator*=(std::int8_t rhs);

  friend LInt operator/(LInt &lhs, LInt &rhs);
  LInt &operator/=(const LInt &rhs);
  LInt &operator/=(std::int8_t rhs);

  std::ostream &WriteTo(std::ostream &ostrm) const;
  std::istream &ReadFrom(std::istream &istrm);

 private:
  std::vector<std::uint8_t> number_{};
  bool is_negative_{false};
};
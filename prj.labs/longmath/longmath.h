#include <vector>
#include <string>

struct Longmath {
  Longmath() = default;

  explicit Longmath(std::string str);

  Longmath(std::int64_t number, std::int64_t base);
  Longmath(std::string str, std::int64_t base);

  bool operator==(const Longmath &rhs) const;
  bool operator!=(const Longmath &rhs) const;

  friend std::ostream &operator<<(std::ostream &ostrm, const Longmath &rhs);
  friend std::istream &operator>>(std::istream &istrm, Longmath &rhs);

  friend Longmath operator+(Longmath &lhs, Longmath &rhs);
  Longmath &operator+=(const Longmath &rhs);
  Longmath &operator+=(std::int64_t rhs);

  friend Longmath operator-(Longmath &lhs, Longmath &rhs);
  Longmath &operator-=(const Longmath &rhs);
  Longmath &operator-=(std::int64_t rhs);

  friend Longmath operator*(Longmath &lhs, Longmath &rhs);
  Longmath &operator*=(const Longmath &rhs);
  Longmath &operator*=(std::int64_t rhs);

  friend Longmath operator/(Longmath &lhs, Longmath &rhs);
  Longmath &operator/=(const Longmath &rhs);
  Longmath &operator/=(std::int64_t rhs);

  std::ostream &WriteTo(std::ostream &ostrm) const;
  std::istream &ReadFrom(std::istream &istrm);

 private:
  std::vector<std::int64_t> number_{};
  std::int64_t base_{10};
  bool is_negative_{false};
};
#include <iostream>
#include <sstream>
#include "complex.h" // NOLINT(modernize-deprecated-headers,hicpp-deprecated-headers)

bool TestParse(const std::string &str) {
  using namespace std;
  istringstream istrm(str);
  Complex z;
  istrm >> z;
  if (istrm.good()) {
    cout << "Read success: " << str << " -> " << z << endl;
  } else {
    cout << "Read error : " << str << " -> " << z << endl;
  }
  return istrm.good();
}

int main() {
  using namespace std;

  Complex z;
  z += Complex(8.0);
  TestParse("{8.9,9}");
  TestParse("{8.9, 9}");
  TestParse("{8.9,9");
  return 0;
}


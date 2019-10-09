#include "rational.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

bool TestParse(const std::string &str) {
  istringstream istrm(str);
  Rational z;
  istrm >> z;
  if (istrm.good()) {
    cout << "Read success: " << str << " -> " << z << endl;
  } else {
    cout << "Read error : " << str << " -> " << z << endl;
  }
  return istrm.good();
}

int main() {

  try {
    cout << Rational(1, 0) << endl;
  }
  catch (std::invalid_argument &e) {
    cout << e.what() << endl;
  }

  Rational z(1);
  z += Rational(8, 2);
  cout << z << endl;
  TestParse("{-8/9}");
  TestParse("{-8/ -9}");
  TestParse("{81/ -9}");
  TestParse("{3 /6}");
  TestParse("{8/9");
  return 0;
}
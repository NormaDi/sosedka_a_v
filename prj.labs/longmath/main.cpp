#include "longmath.h"
#include <iostream>
#include <sstream>

using namespace std;

bool TestParse(const std::string &str) {
  istringstream istrm(str);
  Longmath z;
  istrm >> z;
  if (istrm.good()) {
    cout << "Read success: " << str << " -> " << z << endl;
  } else {
    cout << "Read error : " << str << " -> " << z << endl;
  }
  return istrm.good();
}

int main() {
  return 0;
}
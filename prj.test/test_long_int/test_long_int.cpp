#include <long_int/long_int.h>

#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

bool TestParse(const std::string &str) {
  istringstream istrm(str + '\n');
  LInt z;
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
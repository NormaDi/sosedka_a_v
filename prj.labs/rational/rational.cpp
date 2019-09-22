#include <iostream>
#include <sstream>

struct Rational {
    Rational() {}
    explicit Rational(const int numerator);
    Rational(const int numerator, const int denominator);
    bool operator==(const Rational& rhs) const {
        return (num == rhs.num) && (denom == rhs.denom);
    }
    bool operator!=(const Rational& rhs) const { return !operator==(rhs);}
    Rational& operator+=(const Rational& rhs);
    Rational& operator+=(const int rhs) { return operator+=(Rational(rhs));}

    Rational& operator*=(const int rhs);
    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

    int num{0};
    int denom{1};

    static const char leftBrace{'{'};
    static const char separator{','};
    static const char rightBrace{'}'};

    void GCD();
};

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) {
    return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Rational& rhs) {
    return rhs.readFrom(istrm);
}

bool testParse(const std::string& str) {
    using namespace std;
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

Rational::Rational(const int numerator) : Rational(numerator, 1) {
}

Rational::Rational(const int numerator, const int denominator) : num(numerator), denom(denominator){
    if (denominator == 0){
        std::cout << "Denominator can't be 0" << std::endl;
        denom = 1;
    }
}

Rational& Rational::operator+=(const Rational& rhs) {
    num = num * rhs.denom + rhs.num * denom;
    denom *= rhs.denom;
    return *this;
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
    Rational sum(lhs);
    sum += rhs;
    return sum;
}

Rational operator-(const Rational& lhs, const Rational& rhs){
    int numerator = lhs.num * rhs.denom - rhs.num * lhs.denom;
    int denominator = lhs.denom * rhs.denom;
    return Rational(numerator, denominator);
}

Rational& Rational::operator*=(const int rhs) {
    num *= rhs;
    GCD();
    return *this;
}

std::ostream& Rational::writeTo(std::ostream& ostrm) const {
    ostrm << leftBrace << num << separator << denom << rightBrace;
    return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm) {
    char leftBrace(0);
    int numerator(0);
    char comma(0);
    int denominator(1);
    char rightBrace(0);
    istrm >> leftBrace >> numerator >> comma >> denominator >> rightBrace;
    if (istrm.good()) {
        if ((Rational::leftBrace == leftBrace) && (Rational::separator == comma) &&
            (Rational::rightBrace == rightBrace) && (denominator != 0)) {
            num = numerator;
            denom = denominator;
        } else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}

void Rational::GCD() {
    int n = num;
    int d = denom;
    while (d) {
        n %= d;
        std::swap (n, d);
    }
    num /= n;
    denom /= n;
}

int main() {
    using namespace std;

    Rational z;
    z += Rational(8, 2);
    cout << Rational(1, 0) << endl;
    z.GCD();
    cout << z << endl;
    testParse("{8,9}");
    testParse("{8, 9}");
    testParse("{8,9");
    return 0;
}
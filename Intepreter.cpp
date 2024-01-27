#include <cctype>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

enum Type {
  Identifier,
  Special,
  Operator,
  Int,
  Double,
  Long,
  Float,
  Short,
  Char,
  Byte
};

class Token {
 private:
  Type type;
  std::string content;

 public:
  Token(Type t, std::string s) : type(t), content(s) {}

  bool operator==(Type t) { return type == t; }

  bool operator==(std::string s) { return content == s; }
};

std::vector<Token> token;

void toToken(std::string s) {
  std::ostringstream oss;
  int i = 0;

  while (i < s.length()) {
    if (isdigit(s[i])) {
      oss << s[i];
      bool integer = true;

      while (isdigit(s[i + 1])) {
        ++i;
        oss << s[i];
      }

      if (s[i + 1] == '.') {
        oss << '.';
        integer = false;

        while (isdigit(s[i + 1])) {
          ++i;
          oss << s[i];
        }
      }

      Type t;

      if (isalpha(s[i + 1])) {
        ++i;
        switch (s[i]) {
          case 'i':
            t = Int;
            if (!integer) {
              throw std::runtime_error("illegal type");
            }
            break;
          case 'd':
            t = Double;
            break;
          case 'f':
            t = Float;
            break;
          case 'l':
            t = Long;
            if (!integer) {
              throw std::runtime_error("illegal type");
            }
            break;
          case 's':
            t = Short;
            break;
          case 'b':
            t = Byte;
            if (!integer) {
              throw std::runtime_error("illegal type");
            }
            break;
          default:
            throw std::runtime_error("illegal type");
            break;
        }
      } else {
        t = integer ? Int : Double;
      }

    } else if (isalpha(s[i])) {
      oss << s[i];
      while (isalpha(s[i + 1]) || isdigit(s[i + 1])) {
        ++i;
        oss << s[i];
      }

    } else {
    }
    ++i;
  }
}

void readLine() {}

int main() {
  char arr[50];

  scanf("%49[^\n]", arr);
  printf("%s", arr);
  return 0;
}
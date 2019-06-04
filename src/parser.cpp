#include "parser.h"

#include <fstream>
#include <iostream>
using namespace std;

void Parser::reportError(const string& expected, const string& actual) {
  cout << "Parse Error: Expected '" << expected << "', but found " << actual << endl;
  failed = true;
}

string Parser::parsePrintlnArgument() {
  if (input[pos++] != '(') {
    reportError("(", string{input[pos-1]});
  }

  if (input[pos++] != ('\'')) {
    reportError("\'", string{input[pos-1]});
  }

  auto argument = string{};
  while ((input[pos] >= 'A' && input[pos] <= 'Z') || (input[pos] >= 'a' && input[pos] <= 'z')) {
    argument += input[pos++];
  }

  return argument;
}

void Parser::parsePrintln() {
  auto println_length = 7;
  auto expected_println = string{};
  for (auto i = 0; i < println_length; i++) {
    expected_println += input[pos++];
  }

  if (expected_println != "println") {
    reportError("println", expected_println);
  }
}

string Parser::readName() {
  auto name = string{};
  while (input[pos] >= 'a' && input[pos] <= 'z') {
    name += input[pos++];
  }

  if (input[pos++] != ':') {
    reportError(":", string{input[pos-1]});
  }

  return name;
}

string Parser::parseFunction() {
  auto functionName = readName();
  return functionName;
}

void Parser::parse(const string& filename) {
  ifstream in{filename};
  if (in.is_open()) {
    auto current_char = char{};
    while (in.get(current_char)) {
      if (current_char != ' ' && current_char != '\n') {
        input += current_char;
      }
    }
    cout << input << endl;
    if (pos < input.size() && !failed) {
      auto functionName = parseFunction();
      parsePrintln();
      auto argument = parsePrintlnArgument();
      cout << "Parsed function '" << functionName << "' successful. Will print '" << argument << "'." << endl;
    }
    
  } else {
    cout << "Could not open file '" << filename << "'" << endl;
  }
}

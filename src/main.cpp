#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include "parser.h"

using namespace std;

string findCliArgumentElseDefault(const vector<string>& cliArguments, const string& argument, const string& _default) {
  auto it = find(cliArguments.begin(), cliArguments.end(), argument);
  if (it != cliArguments.end() && (it + 1) != cliArguments.end()) {
    return *++it;
  }

  return _default;
}

string getInputFilenameElseDefault(const vector<string>& cliArguments) {
  return findCliArgumentElseDefault(cliArguments, "-f", "main.blue");
}

string getOutputFilenameElseDefault(const vector<string>& cliArguments) {
  return findCliArgumentElseDefault(cliArguments, "-o", "out");
}

int main(int argc, char** argv) {
  auto cliArguments = vector<string>(argv, argv + argc);
  auto inputFilename = getInputFilenameElseDefault(cliArguments);
  auto outputFilename = getOutputFilenameElseDefault(cliArguments);

  auto parser = Parser();
  parser.parse(inputFilename);

  return 0;
}

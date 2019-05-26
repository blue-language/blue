#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
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

tuple<bool, int> readTheMagicNumber(const string& inputFilename) {
  ifstream in{inputFilename};
  if (in.is_open()) {
    int theMagicNumber;
    in >> theMagicNumber;
    return {true, theMagicNumber};
  }

  cout << "Could not open file '" << inputFilename << "'" << endl;
  return {false, 0};
}

int main(int argc, char** argv) {
  auto cliArguments = vector<string>(argv, argv + argc);
  auto inputFilename = getInputFilenameElseDefault(cliArguments);
  auto outputFilename = getOutputFilenameElseDefault(cliArguments);

  auto [success, magicNumber] = readTheMagicNumber(inputFilename);

  return 0;
}

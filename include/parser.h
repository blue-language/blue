#include <string>
using namespace std;

class Parser {
public:
  void parse(const string& filename);

private:
  void reportError(const string& expected, const string& found);
  string parsePrintlnArgument();
  void parsePrintln();
  string parseFunction();
  string readName();

  int pos{0};
  string input{};
  bool failed{false};
};
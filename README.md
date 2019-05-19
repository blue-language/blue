# The blue compiler

### Start development
- `./start_development`

### Build
- `mkdir build`
- `cd build`
- `cmake ../`
- `make`

Currently broken, use `g++ -g -O3 main.cpp -I/usr/usr/lib/llvm-8/include/llvm `llvm-config-8 --cxxflags --ldflags --system-libs --libs all` -o bluec`
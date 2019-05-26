INCLUDES = -I/usr/usr/lib/llvm-8/include/llvm -I/include
CFLAGS = -O3 -std=c++17
LDFLAGS = `llvm-config-8 --cxxflags --ldflags --system-libs --libs all`

.PHONY: build
build:
	@mkdir -p bin
	g++-8 src/main.cpp $(INCLUDES) $(LDFLAGS) $(CFLAGS) -o bin/bluec

.PHONY: clean
clean:
	@rm -rf bin

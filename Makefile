CFLAGS = -O3 -I/usr/usr/lib/llvm-8/include/llvm
LDFLAGS = `llvm-config-8 --cxxflags --ldflags --system-libs --libs all`

.PHONY: build
build:
	@mkdir -p bin
	@g++ main.cpp $(CFLAGS) $(LDFLAGS) -o bin/bluec

.PHONY: clean
clean:
	@rm -rf bin

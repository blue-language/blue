cmake_minimum_required(VERSION 3.4.3)
project(blue-language-compiler)

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# Now build our tools
add_executable(bluec main.cpp)

# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(llvm_libs support core irreader asmparser lto
passes
objcarcopts
mirparser
symbolize
debuginfopdb
debuginfodwarf
coverage
mca
tablegen
dlltooldriver
xray
orcjit
xcoredisassembler
xcorecodegen
xcoredesc
xcoreinfo
xcoreasmprinter
webassemblydisassembler
webassemblycodegen
webassemblydesc
webassemblyasmprinter
webassemblyasmparser
webassemblyinfo
systemzdisassembler
systemzcodegen
systemzasmparser
systemzdesc
systemzinfo
systemzasmprinter
sparcdisassembler
sparccodegen
sparcasmparser
sparcdesc
sparcinfo
sparcasmprinter
powerpcdisassembler
powerpccodegen
powerpcasmparser
powerpcdesc
powerpcinfo
powerpcasmprinter
nvptxcodegen
nvptxdesc
nvptxinfo
nvptxasmprinter
msp430disassembler
msp430codegen
msp430asmparser
msp430desc
msp430info
msp430asmprinter
mipsdisassembler
mipscodegen
mipsasmparser
mipsdesc
mipsinfo
mipsasmprinter
lanaidisassembler
lanaicodegen
lanaiasmparser
lanaidesc
lanaiasmprinter
lanaiinfo
hexagondisassembler
hexagoncodegen
hexagonasmparser
hexagondesc
hexagoninfo
bpfdisassembler
bpfcodegen
bpfasmparser
bpfdesc
bpfinfo
bpfasmprinter
armdisassembler
armcodegen
armasmparser
armdesc
arminfo
armasmprinter
armutils
amdgpudisassembler
amdgpucodegen
amdgpuasmparser
amdgpudesc
amdgpuinfo
amdgpuasmprinter
amdgpuutils
aarch64disassembler
aarch64codegen
aarch64asmparser
aarch64desc
aarch64info
aarch64asmprinter
aarch64utils
objectyaml
libdriver
option
optremarks
windowsmanifest
textapi
fuzzmutate
x86disassembler
x86asmparser
x86codegen
globalisel
selectiondag
asmprinter
x86desc
mcdisassembler
x86info
x86asmprinter
x86utils
mcjit
lineeditor
interpreter
executionengine
runtimedyld
codegen
target
coroutines
ipo
instrumentation
vectorize
scalaropts
linker
irreader
asmparser
instcombine
bitwriter
aggressiveinstcombine
transformutils
analysis
profiledata
object
mcparser
mc
debuginfocodeview
debuginfomsf
bitreader
core
binaryformat
support
demangle
)

# Link against LLVM libraries
target_link_libraries(bluec ${llvm_libs})

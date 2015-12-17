CXX = gcc
CFLAGS = -Wall -Werror -std=c90 -pedantic -fpic -g
LIBSDIR = -L./lib -L/usr/lib
INCLUDEDIR = -I./include -I./input_lib/include -I/usr/include

BIN_OUTPUT_DIR = ./bin/
LIB_OUTPUT_DIR = ./lib/

# Libraries-related macros
LIBTARGET2_INPUT = Input
LIBTARGET_INPUT = libInput.so
LIBSOURCE_INPUT = ./input_lib/src/input
LIBSOURCECFILE_INPUT = $(LIBSOURCE_INPUT:=.c)
LIBSOURCEOFILE_INPUT = $(LIBSOURCE_INPUT:=.o)

LIBTARGET2_BIG_INTEGER = BigInteger
LIBTARGET_BIG_INTEGER = libBigInteger.so
LIBSOURCE_BIG_INTEGER = ./src/BigInteger
LIBSOURCECFILE_BIG_INTEGER = $(LIBSOURCE_BIG_INTEGER:=.c)
LIBSOURCEOFILE_BIG_INTEGER = $(LIBSOURCE_BIG_INTEGER:=.o)

LIBTARGET2_BASE_N_INTEGER_LIST = BaseNIntegerList
LIBTARGET_BASE_N_INTEGER_LIST = libBaseNIntegerList.so
LIBSOURCE_BASE_N_INTEGER_LIST = ./src/BaseNIntegerList
LIBSOURCECFILE_BASE_N_INTEGER_LIST = $(LIBSOURCE_BASE_N_INTEGER_LIST:=.c)
LIBSOURCEOFILE_BASE_N_INTEGER_LIST = $(LIBSOURCE_BASE_N_INTEGER_LIST:=.o)

LIBTARGET2_BASE_N_INTEGER_LIST_OF_LIST = BaseNIntegerListOfList
LIBTARGET_BASE_N_INTEGER_LIST_OF_LIST = libBaseNIntegerListOfList.so
LIBSOURCE_BASE_N_INTEGER_LIST_OF_LIST = ./src/BaseNIntegerListOfList
LIBSOURCECFILE_BASE_N_INTEGER_LIST_OF_LIST = $(LIBSOURCE_BASE_N_INTEGER_LIST_OF_LIST:=.c)
LIBSOURCEOFILE_BASE_N_INTEGER_LIST_OF_LIST = $(LIBSOURCE_BASE_N_INTEGER_LIST_OF_LIST:=.o)

# Application-related macros
TARGET = radix-sort
EXESOURCE = ./src/main
EXESOURCECFILE = $(EXESOURCE:=.c)
EXESOURCEOFILE = $(EXESOURCE:=.o)

# Generating the executable
$(TARGET): $(BIN_OUTPUT_DIR) $(EXESOURCEOFILE) $(LIBTARGET_INPUT)
	@echo "\n Generating the executable " $@
	$(CXX) $(CFLAGS) $(EXESOURCEOFILE) -l$(LIBTARGET2_INPUT) $(LIBSDIR) -o $(BIN_OUTPUT_DIR)$(TARGET)

# Running the program
run: $(TARGET)
	@echo "\n Executing the executable " $(TARGET)
	./run.sh $(TARGET)

# Generating the BTree library binary code
$(LIBTARGET_INPUT): $(LIB_OUTPUT_DIR) $(LIBSOURCEOFILE_INPUT)
	@echo "\n Generating the library " $@
	$(CXX) $(CFLAGS) -shared $(LIBSOURCEOFILE_INPUT) -o $(LIB_OUTPUT_DIR)$(LIBTARGET_INPUT)

# Creating the library output directory
$(LIB_OUTPUT_DIR):
	@echo "\n Creating " $(LIB_OUTPUT_DIR) " directory"
	mkdir $(LIB_OUTPUT_DIR)

# Creating the binary output directory
$(BIN_OUTPUT_DIR):
	@echo "\n Creating " $(BIN_OUTPUT_DIR) " directory"
	mkdir $(BIN_OUTPUT_DIR)

# Generating an object file from a C file having the same name
.c.o:
	@echo "\n Generating " $@ " from " $<
	$(CXX) $(CFLAGS) $(INCLUDEDIR) $< -c -o $@

# Cleaning the content of the current directory
clean:
	@echo "\n Cleaning temporary files"
	rm -rf *.o *~ ./bin/* ./lib/*


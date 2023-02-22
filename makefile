CC=g++
CFLAGS=-I. -I./include/CppUnitLite
CXXFLAGS += -std=c++20 -Wall -Werror
# -std=c++20: valid for g++ 10 and greater.
# -Wall: reports all warnings
# -Werror: warnings reported as errors

OBJ = CppUnitLite/Failure.o CppUnitLite/Test.o CppUnitLite/TestRegistry.o CppUnitLite/TestResult.o CppUnitLite/WFailure.o \
      Main.o \
      Problem1_Swap.o Problem2_Factorial.o Problem3_MonthTable.o Problem4_Cat.o Problem5_ParseInt.o

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(CXXFLAGS)

Assignment2: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(CXXFLAGS)


all: Assignment2

clean:
	rm *.o
	rm ./CppUnitLite/*.o

CXX = g++
CXXFLAG = -Wall -Werror
TARGET = test

$(TARGET): *.cpp
	$(CXX) $(CXXFLAG) -o $@ $^

clean:
	rm $(TARGET) *.o -rf

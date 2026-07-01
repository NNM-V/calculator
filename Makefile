CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

TARGET = main

SRCS = main.cpp convertInfix.cpp calc.cpp separator.cpp utility.cpp yesno.cpp

OBJS    = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	-rm -f $(OBJS) $(TARGET) *.d

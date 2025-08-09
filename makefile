CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

Target = main

SRCS = SRCS = main.cpp convertInfix.cpp Calc.cpp Separator.cpp

OBJS    = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	-rm -f $(OBJS) $(TARGET) *.d

CXXFLAGS = -g -Wall -Werror
TARGET = a.out
OBJS = main.o GameState.o Map.o

$(TARGET): $(OBJS)
	g++ $(CXXFLAGS) -o $(TARGET) $(OBJS) -lncurses

clean:
	-rm -f $(TARGET) $(OBJS)

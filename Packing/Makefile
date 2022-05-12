CXX = g++
CXXFLAGS = -g

run: main
	./$<

main: main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf main.o
	rm -rf main
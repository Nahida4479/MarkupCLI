MarkupCLI++: MarkupCLI++.o string_utils.o
	g++ MarkupCLI++.o string_utils.o -o MarkupCLI++

MarkupCLI++.o: MarkupCLI++.cpp src.string_utils.h
	g++ -c MarkupCLI++.cpp

string_utils.o: src/string_utils.cpp src/string_utils.h
	g++ -c src/string_utils.cpp -o string_utils.o

clean:
	rm -f *.o MarkupCLI++
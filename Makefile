MarkupCLI++: MarkupCLI++.o string_utils.o table_flag.o
	g++ MarkupCLI++.o string_utils.o table_flag.o -o MarkupCLI++

MarkupCLI++.o: MarkupCLI++.cpp src/string_utils.h src/table_flag.h
	g++ -c MarkupCLI++.cpp

string_utils.o: src/string_utils.cpp src/string_utils.h
	g++ -c src/string_utils.cpp -o string_utils.o

table_flag.o: src/table_flag.cpp src/table_flag.h
	g++ -c src/table_flag.cpp -o table_flag.o

clean:
	rm -f *.o MarkupCLI++
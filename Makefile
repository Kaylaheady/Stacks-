stack: in2post.o stack.o
	g++ -o stack in2post.o stack.o

in2post.o: in2post.cpp stack.h
	g++ -c in2post.cpp

stack.o: stack.hpp stack.h
	g++ -c stack.cpp

clean:
	rm -f *.o stack

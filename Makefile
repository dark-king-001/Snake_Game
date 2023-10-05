all: compile link clean_obj

test: compile link clean_obj run clean_exe

compile:
	g++ -c src/*.cxx

link:
	g++ *.o -o main -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

clean_obj:
	rm -r *.o

clean_exe:
	rm -r *.exe

run:
	./main
all: compile link

test: compile link run

compile:
	g++ -c src/*.cxx

link:
	g++ *.o -o main -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

clean:
	del *.o
	del *.exe

run:
	./main
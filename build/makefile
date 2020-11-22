CC=g++
CFLAGS=-I.
DEPS = ../lib/*.h
OBJ = ../nfa_simulation.o

%.o:  %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

nfa_simulation: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf ../*o nfa_simulation 
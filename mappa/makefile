DEPENDANCIES = compito.cc grafo.cc liste.cc tipo.cc 

compito: compito.o grafo.o liste.o tipo.o
	g++ -g -Wall -o $@ $^

-include dep

dependancies: 
	g++ -MM $(DEPENDANCIES) > dep

clean:
	rm -rf *.o compito
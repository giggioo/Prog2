DEPENDANCIES = compito.cc grafi.cc

compito: compito.o grafi.o
	g++ -g -Wall -o $@ $^

-include dep

dependancies: 
	g++ -MM $(DEPENDANCIES) > dep

clean:
	rm -rf *.o compito
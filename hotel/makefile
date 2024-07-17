DEPENDANCIES = bst.cc hotel.cc compito.cc

compito: compito.o hotel.o bst.o
	g++ -Wall -o $@ $^

-include dep

dependancies:
	g++ -MM $(DEPENDANCIES) > dep

clean:
	rm -rf *.o compito
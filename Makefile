make all: bin/testListArray bin/testNode bin/testListLinked

bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp ListArray.h

bin/testNode: testNode.cpp Node.h 
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp Node.h
bin/testListLinked: testListLinked.cpp ListLinked.h List.h Node.h
	mkdir -p bin
	g++ -o bin/testListLinked testListLinked.cpp ListLinked.h List.h Node.h

clean:
	rm -r *.o *.gch bin

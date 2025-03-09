#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>

using namespace std;

SMIterator::SMIterator(const SortedMap& m) : map(m){ //default
	//TODO - Implementation
	
	index = 0;

}

void SMIterator::first(){ //default
	//TODO - Implementation

	index = 0; //for first elem in array
}

void SMIterator::next(){ //default
	//TODO - Implementation

	if (index < map.sizeOf) {
		index = index + 1;
	}
}

bool SMIterator::valid() const{ //default
	//TODO - Implementation

	if (index <= map.sizeOf - 1) { //or < size
		return true;

	}

	return false; 
}

TElem SMIterator::getCurrent() const{ //default
	//TODO - Implementation

	if (valid()) {
		return map.array[index];
	}

	return NULL_TPAIR;
}



#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>

using namespace std;

SMIterator::SMIterator(const SortedMap& m) : map(m){ //default
	//TODO - Implementation
	


}

void SMIterator::first(){ //default
	//TODO - Implementation

	index = 0; //for first elem in array
}

void SMIterator::next(){ //default
	//TODO - Implementation

	if (index < size) {
		index = index + 1;
	}
}

bool SMIterator::valid() const{ //default
	//TODO - Implementation

	if (index <= size - 1) { //or < size
		return true;

	}

	return false; //?

	//return false;
}

TElem SMIterator::getCurrent() const{ //default
	//TODO - Implementation

	if (valid()) {
		return data[index];
	}

	return NULL_TPAIR;
}



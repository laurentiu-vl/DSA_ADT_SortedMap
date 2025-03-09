#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
using namespace std;

static bool increasing(TKey c1, TKey c2) {
	if (c1 <= c2) {
		return true;
	}
	else {
		return false;
	}
}

static bool decreasing(TKey c1, TKey c2) {
	if (c1 >= c2) {
		return true;
	}
	else {
		return false;
	}
}

SortedMap::SortedMap(Relation r) {
	//TODO - Implementation

	capacity = 8;
	array = new TElem[capacity];
	ascending = r;
	sizeOf = 0;

}

TValue SortedMap::add(TKey k, TValue v) {
	//TODO - Implementation

	if (sizeOf == capacity) {
		resize();
	}

	if (sizeOf == 0) {
		array[0] = TElem(k, v);
		
	}


	return NULL_TVALUE;
}

TValue SortedMap::search(TKey k) const {
	//TODO - Implementation
	return NULL_TVALUE;
}

TValue SortedMap::remove(TKey k) {
	//TODO - Implementation
	return NULL_TVALUE;
}

int SortedMap::size() const {
	//TODO - Implementation
	return 0;
}

bool SortedMap::isEmpty() const {
	//TODO - Implementation
	return false;
}

SMIterator SortedMap::iterator() const {
	return SMIterator(*this);
}

SortedMap::~SortedMap() {
	//TODO - Implementation
}


#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
using namespace std;

SortedMap::SortedMap(Relation r) {

	capacity = 2;
	array = new TElem[capacity];
	sizeOf = 0;
	compare = r;

}

TValue SortedMap::add(TKey k, TValue v) {

	for (int i = 0; i < sizeOf; i++) { //if key k already exists
			if  (array[i].first == k) {
				TValue oldValue = array[i].second; //save the old value of the value of the k array[i].first for return
				array[i].second = v; //save the new value v to the key
				return oldValue; //return the old value of the k
			}
	}

	if (sizeOf == 0) { //sortedmap is empty
		array[0] = TElem(k, v);
		sizeOf = 1;
		return NULL_TVALUE;
	}

	if (sizeOf == 1) {
		if (array[0].first == k) {
			TValue oldValue = array[0].second;
			array[0] = TElem(k, v);
			return oldValue;
		}
		if (compare(array[0].first, k)) { //!!!!!!!!!!!! la increasing/decreasing c1 vine ca element din array, iar c2 ca noua cheie
			array[1] = TElem(k, v);
			sizeOf += 1;
		}
		else {
			array[1] = array[0];
			array[0] = TElem(k, v);
			sizeOf += 1;
		}
		return NULL_TVALUE;

	}

	if (sizeOf == capacity) { //resize
		resize();
	}

	int index = sizeOf;
	while (index > 0 && compare(k, array[index - 1].first)) {
		array[index] = array[index - 1];
		index--;
	}
	array[index] = TElem(k, v);
	sizeOf++;

	return NULL_TVALUE;

}

TValue SortedMap::search(TKey k) const {

	for (int i = 0; i < sizeOf; i++) {
		if (array[i].first == k) {
			return array[i].second;
		}
	}
	return NULL_TVALUE;

}

TValue SortedMap::remove(TKey k) {

	if (sizeOf == 0) {
		return NULL_TVALUE;
	}

	if (sizeOf == 1 && array[0].first == k) {
			TValue oldValue = array[0].second;
			//array[0] = NULL_TPAIR;
			sizeOf = 0;
			return oldValue;
	}

	bool found = false;
	int indexKeyFoundToBeRemoved = 0;
	TValue oldValue = NULL_TVALUE;
	for (int i = 0; i < sizeOf; i++) {
	 	if (array[i].first == k) {
	 		found = true; //key found
	 		oldValue = array[i].second;
	 		indexKeyFoundToBeRemoved = i;
	 		break;
	 	}
	}

	if (found) {
	 	for (int i = indexKeyFoundToBeRemoved; i < sizeOf; i++) {
	 		array[i] = array[i + 1];
	 	}
	 	sizeOf--;
	 	return oldValue;
	}
	return NULL_TVALUE;

}

int SortedMap::size() const {

	return sizeOf;

}

bool SortedMap::isEmpty() const {

	if (sizeOf == 0) {
		return true;
	}
	return false;

}

SMIterator SortedMap::iterator() const {

	return SMIterator(*this);

}

SortedMap::~SortedMap() {

	delete[] array;

}

void SortedMap::resize() {

	capacity *= 2;
	TElem *temp = new TElem[capacity];

	for (int i = 0; i < sizeOf; i++) {
		temp[i] = array[i];
	}

	delete[] array;
	array = temp;

}


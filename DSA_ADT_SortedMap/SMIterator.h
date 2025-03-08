#pragma once
#include "SortedMap.h"

//DO NOT CHANGE THIS PART
class SMIterator{
	friend class SortedMap;
private:
	const SortedMap& map;
	SMIterator(const SortedMap& mapionar);

	//TODO - Representation

	/* ADT SortedMap – repräsentiert mithilfe eines dynamischen Arrays von Paaren der Form
				(key, value) und sortiert mithilfe einer Relation auf den Schlüsseln (key)
		*/
	
	//SortedMap map;
	int index;
	int size;
	TElem* data;

	




public:

	void first();
	void next();
	bool valid() const;
    TElem getCurrent() const;
};


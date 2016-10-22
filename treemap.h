#ifndef TREEMAP_H
#define TREEMAP_H

#include "tree.h"

template<typename Key, typename Value>
class KeyValuePair {
    
public:
    
    const Key k;
    Value v;
    
    // TODO your code for KeyValuePair goes here

    KeyValuePair(const Key & myKey, const Value & myValue)
    : k(myKey), v(myValue) {}
    
    KeyValuePair(const Key & myKey)
    : k(myKey) {}

    bool operator<(const KeyValuePair<Key,Value> & myPair) const{
        return k < myPair.k;
    }
    
};



template<typename Key, typename Value>
ostream & operator<< (ostream & o, const KeyValuePair<Key,Value> & kv){
    o << kv.k << "," << kv.v;
    return o;
}



template<typename Key, typename Value>
class TreeMap {
  
private:
    BinarySearchTree<KeyValuePair<Key,Value> > tree;
    
public:
    
    KeyValuePair<Key,Value> * insert(const Key & k, const Value & v) {
        return &(tree.insert(KeyValuePair<Key,Value>(k,v))->data);
    }
    
    void write(ostream & o) const {
        tree.write(o);
    }
    
    // TODO your code for TreeMap goes here:
    
    KeyValuePair<Key,Value>* find (const Key & myKey){
        return &(tree.find(KeyValuePair<Key,Value>(myKey))->data);
    }
    
    
};


// do not edit below this line

#endif

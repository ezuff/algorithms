#include "Hashtable.hpp"

<<<<<<< HEAD
int HashTable::hash(const String& key){
    int hash = 0;
    for(int i = 0; i < key.size(); ++i){
        hash = key.at(i) + hash;
    }
    return hash % size;
}

HashTable::HashTable(){
    size = 5;
    table = new List[5];
}

HashTable::~HashTable(){
    delete [] table;
    size = 0;
}

HashTable::HashTable(int indices){
    size = indices;
    table = new List[indices];
    for(int i = 0; i < indices; ++i){
        table[i] = List();
    }
}

unsigned int HashTable::Size(){
    return size;
}

void HashTable::insert(const String& key, int data){
    int h = hash(key);
    table[h].push_back(key, data);
    // for(int i = 0; i < size; ++i){
    //     if(table[i].length() / size >= 8){
    //         double the size
    //     }else if(table[i].length() / size <= 2){
    //         halve the size
    //     }
    // }
}

void HashTable::remove(String& key){
    int to_remove = hash(key);
    table[to_remove].remove(key);
}

bool HashTable::search(String& key){
    int h = hash(key);
    if(table[h].index(key) != -1){
        return true;
    }else{
        return false;
    }
}

int HashTable::get(String& key){
    int h = hash(key);
    int idx = table[h].index(key);
    return table[h].at(idx);
}

bool HashTable::is_empty(){
    for(int i = 0; i < size; ++i){
        if(table[i].length() != 0){
            return false;
        }
    }
    return true;
}

void HashTable::print(){
    for(int i = 0; i < size; ++i){
        table[i].print();
    }
=======
int HashTable::hash(const String& key) {
  int hash = 0;
  for (unsigned int i = 0; i < key.size(); ++i) {
    hash = (hash * 7) + key.at(i);
  }
  return hash % m;
}

unsigned int HashTable::elements() const {
  return n;
}

void HashTable::grow() {
  List* newtable = new List[m * 2];
  for (unsigned int i = 0; i < m; ++i) {
    Node* n = table[i].top();
    newtable[hash(*(n->key))].push(*(n->key), n->val);
    table[i].pop();
  }
  delete[] table;
  table = newtable;
  m *= 2;
}

void HashTable::insert(const String& key, int data) {
  int h = hash(key);
  if (table[h].index(key) == -1) {
    table[h].push(key, data);
    n++;
    if ((n / m) >= 8) {
      grow();
    }
  } else {
    table[h].update(key, data);
  }
}

void HashTable::remove(String& key) {
  table[hash(key)].remove(key);
}

bool HashTable::search(String& key) {
  if (table[hash(key)].index(key) >= 0)
    return true;
  else
    return false;
}

int HashTable::get(String& key) {
  return table[hash(key)].at(table[hash(key)].index(key));
}

bool HashTable::is_empty() {
  for (unsigned int i = 0; i < m; ++i) {
    if (table[i].length() != 0)
      return false;
  }
  return true;
}

void HashTable::print(std::ostream& oss) {
  for (unsigned int i = 0; i < m; ++i) {
    oss << "Row: " << i << " => ";
    table[i].print(oss);
    oss << std::endl;
  }
>>>>>>> upstream/master
}
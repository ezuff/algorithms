#include "../String/String.hpp"
#include "../Trees/Trie.hpp"
#include <sstream>

/** Lexicographic Sorting
 * Sorting Strings in Alphabetical Order
 *
 * Inputs:
 * @param arr: An array of String pointers.
 * @param n: The number of Strings provided.
 *
 * Outputs:
 * arr should be directly modified such that it's contents
 * are in lexicographically sorted order.
 */
bool validnum(char c) {
  return 'a' <= c && c <= 'z';
}

void sort(String* arr[], int n) {
    Trie temp;
    std::ostringstream oss;
    for(int i = 0; i < n; ++i){
        temp.put((const char*)arr[i], i);
    }
    temp.print(oss);
    int j = 0;
    for(int k = 0; k < n; ++k){
        String* letter;
        while(!validnum(oss.str()[j])){
            ++j;
        }
        while(validnum(oss.str()[j])){
            letter->append(oss.str()[j++]);
        }
        arr[k] = letter;
    }
}
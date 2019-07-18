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
void sort(String* arr[], int n) {
    Trie temp;
    std::ostringstream oss;
    for(int i = 0; i < n; ++i){
        temp.put((const char*)arr[i], i);
    }
    temp.print(oss);
    for(int j = 0; j < n; ++j){
        //arr[j] = (String*)oss.str()[j];
    }
}
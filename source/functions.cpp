#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "functions.hpp"

int abs_val(int x) {
  return (x > 0) ? x : x * -1;
}

int pow(int base, int num) {
  int ret = 1;
  for (int i = 0; i < num; ++i) {
    ret *= base;
  }
  return ret;
}

int log(int base, int num) {
  int count = 0;
  for (num; num > 1; num /= base)
    ++count;
  return count;
}

int chartoint(char c) {
  int result = (int)c;
  result -= '0';
  return result;
}

char inttochar(int x) {
  return (char)(x + '0');
}

char chr(int x) {
  return (char)x;
}

int ord(char c) {
  return (int)c;
}

int max(int x, int y) {
  return (x > y) ? x : y;
}

int max(int x, int y, int z) {
  return max(x, max(y, z));
}

int max(int arr[], int n){
    int max = 0;
    for(int i = 0; i < n; ++i){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

int min(int x, int y) {
  return (x < y) ? x : y;
}

int min(int x, int y, int z) {
  return min(x, min(y, z));
}

int min(int arr[], int n){
    int min = arr[0];
    for(int i = 0; i < n; ++i){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}

int round(double x, char c) {
  if (x > 0) {
    return (c == 'd') ? (int)x : (int)x + 1;
  } else {
    return (c == 'd') ? (int)x - 1 : (int)x;
  }
}

bool all(bool arr[], int n){
    for(int i = 0; i < n; ++i){
        if(arr[i] == false){
            return false;
        }
    }
    return true;
}

bool any(bool arr[], int n){
    for(int i = 0; i < n; ++i){
        if(arr[i] == true){
            return true;
        }
    }
    return false;
}

int frequency(int arr[], int n, int x){
    int c = 0;
    for(int i = 0; i < n; ++i){
        if(arr[i] == x){
            c += 1;
        }
    }
    return c;
}

long sum(int arr[], int n){
    long total = 0;
    for(int i = 0; i < n; ++i){
        total += arr[i];
    }
    return total;
}

int index(char str[], char substr[]){
    int len = 0;
    while(*substr){
        ++len;
        ++substr;
    }
    int idx = -1;
    int i = 0;
    while(*str){
        if(substr[i] == str[i]){
            idx = i;
            for(int j = 0; j < len; ++j){
                if(substr[j] != str[i + j]){
                    idx = -1;
                    break;
                }
            }
        }
        ++i;
        ++str;
    }
    return idx;
}

bool is_sorted(int arr[], int n){
    return false;
}
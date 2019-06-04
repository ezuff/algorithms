#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "string.hpp"

String::String()
{
    array = new char [1];
    array[0] = '\0';
}

String::String(char* string)
{
    unsigned int length = 0;
    while(string[length] != '\0') ++length;

    array = new char [length];

    for(int j = 0; j < length; ++j)
    {
        array[j] = string[j];
    }
}

String::String(char c)
{
    array = new char (c);
}

String::~String()
{
    delete[] array;
}

char String::at(int x) const
{
    unsigned int length = 0;
    while(array[length] != '\0') ++length;

    return (x >= 0 && x < length) ? array[x] : throw x;
}

bool String::empty() const
{
    return (array[0] == '\0') ? true : false;
}

unsigned int String::size() const
{
    unsigned int length = 0;
    while(array[length] != '\0') ++length;

    return length;
}

unsigned int String::capacity() const
{
    return this->String::size();
}

void String::reserve(unsigned int extra)
{
    unsigned int length = this->String::size();

    char* newArray = new char [length + extra];
    newArray = array;
    this->~String();
    array = newArray;
}

void String::remove(int x)
{
    unsigned int length = this->String::size();

    char* newArray = new char [length];

    for(int i = 0; i < length; ++i)
    {
        if(i < x) newArray[i] = array[i];
        else newArray[i] = array[i + 1];
    }

    delete[] array;
    array = new char [length];

    for(int j = 0; j < length; ++j) array[j] = newArray[j];

    delete[] newArray;
}

/*
void String::erase(char c)
{
    unsigned int length = this->String::size();
    for(int i = 0; i < length; ++i)
    {
        if(array[i] == c)
        {
            this->String::remove(i);
            --length;
        }
    }
}*/


void String::append(char c)
{
    unsigned int length = 0;
    while(array[length] != '\0') ++length;

    char* newArray = new char [length + 1];

    for(int i = 0; i < length; ++i)
    {
        newArray[i] = array[i];
    }

    delete[] array;
    array = new char [length + 1];

    for(int j = 0; j < length; ++j) array[j] = newArray[j];

    delete[] newArray;

    array[length] = c;
    array[length + 1] = '\0';
}

void String::prepend(char c)
{

}

void String::insert(char c, int x)
{

}

bool String::compare(char *string) const
{
    for(int i = 0; i < this->String::size(); ++i) return(array[i] != string[i]) ? false : true;
}

bool String::compare(String compare) const
{
    unsigned int length = 0;
    while(array[length] != '\0') ++length;

    for(int i = 0; i < length; ++i) return(this->array[i] != compare.array[i]) ? false : true;
}

void String::concatenate(char *string)
{

}
/*  unsigned int length = 0;
    while(string[length] != '\0') ++length;

    int size = this->String::size() + length;

    char* temp = new char [size];
    for(int i = 0; i < this->String::size() - 1; ++i) temp[i] = array[i];

    int count = this->String::size();
    for(int j = 0; j < length; ++j, ++count) temp[count] = string[j];

    delete[] array;
    array = new char [size];

    if(temp[size - 1] != '\0') temp[size - 1] = '\0'; */
void String::concatenate(String string)
{

}

unsigned int String::find(char* string, int start) const
{
    unsigned int length = 0;
    while(string[length] != '\0') ++length;

    if(start == length && string[start] == array[start]) return start;
    for(int i = start; i < this->String::size(); ++i)
    {
        if(array[i] == string[0]) return find(string + 1, i + 1) - 1;
    }
    return this->String::size();
}

unsigned int String::find(char c, int start) const
{
    for(start; start < this->String::size(); ++start)
    {
        if(array[start] == c)
        {
            return start;
            break;
        }
    }
    return this->String::size();
}

unsigned int String::find(String string, int start) const
{
    return 0;
}

void String::reverse()
{

}

void String::shift(int x)
{

}

int String::toInt() const
{
    return 0;
}

String String::substr(int x, int y) const
{
    String string;
    return string;
}


#ifndef SYMBOLINFO_H
#define SYMBOLINFO_H

#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

class SymbolInfo
{
    string Name;
    string Type;
    SymbolInfo *next;

public:
    SymbolInfo();
    void setName(string name);
    void setType(string type);
    string getName();
    string getType();
    SymbolInfo* getNext();
    void setNext(SymbolInfo *ob);

};

#endif // SYMBOLINFO_H

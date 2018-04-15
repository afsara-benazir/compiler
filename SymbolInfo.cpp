#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

#include "SymbolInfo.h"

SymbolInfo::SymbolInfo()
{
   // next = NULL;

   // cout<<"in constructor"<<endl;
}

void SymbolInfo::setName(string name)
{
    Name = name;
}
void SymbolInfo::setType(string type)
{
    Type = type;
}
string SymbolInfo::getName()
{
    return Name;
}

string SymbolInfo::getType()
{
    return Type;
}
SymbolInfo* SymbolInfo:: getNext()
{
    return next;
}
void SymbolInfo:: setNext(SymbolInfo *Next)
{
   next = Next;
}

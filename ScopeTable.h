#ifndef SCOPETABLE_H
#define SCOPETABLE_H

#include "SymbolInfo.h"
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<string>
#include<vector>
using namespace std;

extern int tableSize;
class ScopeTable
{
    ///array of pointers
    SymbolInfo **arr;
    ScopeTable* parentScope; ///for maintaining a list of scope tables
    int id ;

    public:


        ScopeTable(int tableSize,int id);
        ~ScopeTable();
        int hash_func(string name);
        bool sym_insert(string name,string type);
        bool sym_delete(string name);
        void print();

        SymbolInfo* sym_lookup(string symbol);
        ScopeTable* get_parentScope();
        void set_parentScope(ScopeTable *ptr);
        int get_id();
        void set_id(int n);


};

#endif // SCOPETABLE_H

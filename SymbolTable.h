#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include "SymbolInfo.h"
#include "ScopeTable.h"
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<string>
#include<vector>
using namespace std;

extern int tableSize;


class SymbolTable
{
    ScopeTable *curr;
    public:
        SymbolTable();
        void enter_Scope();
        void exit_Scope();
        bool scope_insert(string name,string type);
        bool scope_remove(string symbol);
        SymbolInfo* scope_lookup(string symbol);
        void print_curr_scopeTable();
        void print_all_scopeTable();
        ScopeTable* get_Curr();


};

#endif // SYMBOLTABLE_H

#include "SymbolTable.h"
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

///problem-ctor e what to do
SymbolTable::SymbolTable()
{

    curr = new ScopeTable(tableSize,1);
    curr->set_parentScope(curr); ///----g



}
ScopeTable* SymbolTable::get_Curr()
{
    return curr;
}
void SymbolTable::enter_Scope()
{
    int i = curr->get_id();
    //incrementing scopeTable id
    i++;
    ScopeTable *new_scope_table;
    new_scope_table = new ScopeTable(tableSize,i);

    // c -> b -> a -> g
    ScopeTable *temp = curr;
    new_scope_table->set_parentScope(temp);
    curr = new_scope_table;


    cout<<"new scope table with id "<<curr->get_id()<<" created"<<endl;


}

void SymbolTable::exit_Scope()
{
    cout<<"scope Table with id "<<curr->get_id()<<" removed"<<endl;
    curr = curr->get_parentScope() ;

}
bool SymbolTable::scope_insert(string name,string type)
{
    curr->sym_insert(name,type);
    return true;

}
bool SymbolTable::scope_remove(string symbol)
{
    curr->sym_delete(symbol);
    return true;

}
SymbolInfo* SymbolTable::scope_lookup(string symbol)
{
    curr->sym_lookup(symbol);

}
void SymbolTable::print_curr_scopeTable()
{
    curr->print();
}

///PROBLEM - SHOB EKTA SCOPE EI PRINT HOCHE--solved
void SymbolTable::print_all_scopeTable()
{
    ScopeTable *temp = curr ;

    while(temp->get_id() != 1)
    {
        temp->print();
        ScopeTable *temp_2 = temp->get_parentScope();
        temp = temp_2;

    }

    temp->print();

}









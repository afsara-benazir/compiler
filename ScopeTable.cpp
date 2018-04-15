#include "ScopeTable.h"
#include "SymbolInfo.h"
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

extern int tableSize;

ScopeTable::ScopeTable(int tableSize,int id)
{
    //initiazlize array of pointers
    ///changed here
    arr = new SymbolInfo*[tableSize];
    for(int i = 0; i<tableSize; i++)
    {
        arr[i] = NULL;
    }
    set_id(id);

}
ScopeTable::~ScopeTable()
{
    delete arr;
}
void ScopeTable::set_id(int n)
{
    id = n;
}
int ScopeTable::get_id()
{
    return id;
}

int ScopeTable::hash_func(string name)
{
//inputs a string outputs an int

    int sum = 0;
    int index;
    for(int i = 0; i < int(name.length()); i++)
    {
        sum = sum + name[i];
    }

    index = sum % tableSize;
    //cout<<"index = "<<index<<endl<<endl;
    return index;

}
///problem-- co-ordinate e (index, ? )
bool ScopeTable::sym_insert(string name,string type)
{
    //index == key
    int index = hash_func(name);
    int i = 0;
    ///handle duplicate ---crashes
   /* if( sym_lookup(name) != NULL && sym_lookup(name)->getName() == name)
    {
        cout<<name<<" already exists"<<endl;
        return false;

    }*/
      if(arr[index] == NULL)
    {

        arr[index] = new SymbolInfo(); ///changed here
        arr[index]->setName(name);
        arr[index]->setType(type);
        arr[index]->setNext(NULL);


        cout<<"  Inserted in scope table# "<<id<<" at position "<<index<<" , "<<i<<endl;
        i++;
        return true;
    }

    else
    {
        i = 1; ///since it didnt enter if means there is one node present
        ///will increment from next node onwards if any
        ///check collision
        //stack implementation
        SymbolInfo *ob;
        ob = new SymbolInfo();

        ob->setName(name);
        ob->setType(type);
        ob->setNext(NULL);

        ///traverse to end of list .... do O(1)
        while(arr[index]->getNext() != NULL)
        {
            i++;
            arr[index] = arr[index]->getNext();

        }
        arr[index]->setNext(ob);
        cout<<"  Inserted in scope table# "<<id<<" at position "<<index<<" , "<<i<<endl;

        return true;
    }

    return false;
}

///problem - null bucket er jonne what to return-- solved
SymbolInfo* ScopeTable::sym_lookup(string symbol)
{
///symbol == name

    //SymbolInfo *parent;
    int index = hash_func(symbol);

    if(arr[index] != NULL && arr[index]->getName() == symbol  )
    {

        cout<<"  Found in scope table# "<<id<<" at index "<<index<<endl;
        // parent = arr[index];
        return arr[index];

    }
    else if(arr[index] != NULL)
    {
        while(arr[index] != NULL)
        {
            arr[index] = arr[index]->getNext();

            if(arr[index]->getName() == symbol  )
            {
                cout<<"  Found in scope table# "<<id<<" at index "<<index<<endl;

                return arr[index];
            }

        }

        return NULL;

    }
    else
    {
        cout<<"not found"<<endl;
        return NULL;
    }

}
bool ScopeTable :: sym_delete(string name)
{

    ///symbol == name


    int index = hash_func(name);

    SymbolInfo *cur = arr[index];
    SymbolInfo *prev = NULL;

    while(cur != NULL)
    {
        if(cur -> getName() == name)
        {
            cout<<"found in scopetable "<<id<<" at position "<<index<<endl;
            break;
        }

        prev = cur;
        cur = cur->getNext();
        //cur->setNext(cur->getNext())  ;
    }
    if(cur == NULL)
    {
        cout<<name <<" not found"<<endl;

        return false;
    }
    if(cur == arr[index])
    {
        cout<<"deleted entry from position "<<index<<endl;
        arr[index] = arr[index] -> getNext();
        return true;
        //delete cur;
    }

    else
    {
        cout<<"here3"<<endl;
        prev ->setNext( cur->getNext() );
        return true;
        //delete cur;
    }
    /*while(arr[index]->getName() != name)
    {


        arr[index] = arr[index]->getNext() ;
        if( arr[index] ->getName() == name)
        {

            previous->setNext(arr[index]->getNext());
            free( arr[index]);
            break;
        }

    }*/



    /* if(arr[index] != NULL && arr[index]->getName() == name  )
     {
         cout<<"  Found in scope table# "<<id<<" at index "<<index<<endl;

         arr[index] == NULL;
         cout<<"deleted entry at "<<index<<" , "<<" from current scope table"<<endl;
         return true;

     }
     else if(arr[index] != NULL)
     {

         parent = arr[index];
         while(arr[index] != NULL)
         {
             parent = arr[index];
             arr[index] = arr[index]->getNext();

             if(arr[index]->getName() == name  )
             {
                 cout<<"  Found in scope table# "<<id<<" at index "<<index<<endl;
                 parent->setNext( arr[index]->getNext() ) ;
                 arr[index] == NULL;
                 cout<<"deleted entry at "<<index<<" , "<<" from current scope table"<<endl;

                 return true;
             }

         }

     }
     else
     {
         cout<<"not found"<<endl;
         return false;
     }

     ///false koi
    */
}

void ScopeTable::print()
{

    cout<<"\n\nScopeTable # "<<id<<endl;
    for(int i = 0; i<tableSize; i++)
    {
        if(arr[i] == NULL)
        {
            cout<<i<<" --> "<<endl;
        }
        else
        {
            cout<<i<<" --> ";
            cout<<" < "<<arr[i]->getName()<<" : "<<arr[i]->getType()<<" > \t";
            while(arr[i]->getNext() != NULL)
            {
                arr[i] = arr[i]->getNext();
                cout<<" < "<<arr[i]->getName()<<" : "<<arr[i]->getType()<<" > \t";

            }
            cout<<endl;
        }
    }
}
ScopeTable* ScopeTable::get_parentScope()
{
    return parentScope;
}

void ScopeTable::set_parentScope(ScopeTable *ptr)
{
    parentScope = ptr;
}

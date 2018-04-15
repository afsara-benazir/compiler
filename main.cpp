#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;

#include "SymbolInfo.h"
#include "ScopeTable.h"
#include "SymbolTable.h"

int tableSize;
int main()
{
    ///input

    ifstream myFile;
    string line;
    myFile.open("input.txt");
    getline(myFile,line);
    stringstream ss(line);
    ss >> tableSize;
    cout<<tableSize<<endl;
    //ScopeTable ob(tableSize);
    SymbolTable ob_table;
    //ob_table.enter_Scope();

    while(getline(myFile, line))
    {
        char ch;
        stringstream ss(line);
        ss >> ch;
        cout<<ch<<endl;
        // cin>>ch;
        if(ch == 'I')
        {
            string symName;
            string symType;
            ss>>symName>>symType;
            ob_table.get_Curr()->sym_insert(symName,symType);
            //ob.sym_insert(symName,symType);

        }
        else if(ch == 'L')
        {
            string lookUp;
            ss>>lookUp;
            ob_table.get_Curr()->sym_lookup(lookUp);
            //ob.sym_lookup(lookUp);
        }
        else if(ch == 'D')
        {
            string deleteSym;
            ss>>deleteSym;
            ob_table.get_Curr()->sym_delete(deleteSym);
            //ob.sym_delete(deleteSym);

        }
        else if(ch == 'P')
        {
            ///print current
            char c;
            ss>>c;
            if(c == 'C')
            {
                ob_table.print_curr_scopeTable();
            }
            ///print all
            else if(c == 'A')
            {


                ob_table.print_all_scopeTable();

            }
            else
            {
                cout<<"invalid identifier"<<endl;

            }


        }
        else if(ch == 'S')
        {


            cout<<"here"<<endl;
            ob_table.enter_Scope();
            // continue;

        }
        else if(ch == 'E')
        {
            ob_table.exit_Scope();
        }
    }

}

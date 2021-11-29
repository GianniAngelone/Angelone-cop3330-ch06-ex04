/*
*  UCF COP3330 Fall 2021 Assignment 5 Solution
*  Copyright 2021 Gianni Angelone
*/
#include "std_lib_facilities.h"

class Name_Value{
public:
    string name;
    int value;
};
vector<Name_Value> Name_Value_Vector; //The vector which will store all our names/values
bool Duplication_Check(string name, vector<Name_Value> Name_Value_Vector){ //Function for checking duplicates
    for(int i = 0; i < Name_Value_Vector.size(); i++){
        if(name == Name_Value_Vector[i].name){
            return true;
        }
    }
    return false;
}

int main(){
    Name_Value nv; //Declare new object
    cout << "Enter a Name and Value pair(ex: Heather 25).\n";
    cout << "To exit, enter 'NoName 0'.\n";
    string string;
    int number;
    while(cin >> string >> number && string != "NoName" || number != 0){ //If Name_Value = "NoName 0", end the program.
        nv.name = string; //Add it to Name_value
        nv.value = number;
        if(Duplication_Check(string, Name_Value_Vector) == true){ //Calling the 'Duplication_Check' function
            cerr << string << " has already been entered.\n";
            break;
        }
        Name_Value_Vector.push_back(nv); //We must pushback to vector
    }
    cout << "List of all Name - Value pairs: \n";
    for(int i = 0; i < Name_Value_Vector.size(); i++){
        cout << Name_Value_Vector[i].name << " " << Name_Value_Vector[i].value << ".\n";
    }
    return 0;
}
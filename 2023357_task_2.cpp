#include<iostream>
#include "2023357_definations_2.cpp"
using namespace std;
int main(){
    Person person_record[5];
    Person* pointer;
    pointer=person_record;
    insertNewRecord(pointer);
    cout<<endl;
    showAllRecords(pointer);
    return 0;
}
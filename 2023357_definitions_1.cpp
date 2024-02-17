#include<iostream>
using namespace std;
int *nationality_type=new int ;
int genderselection;
struct Address
{
    char city[20];
    char street[20] ;
};

    struct National
    {
        char n_cnic[20];
        int n_familyNo;
    };
    struct Foreigner
    {
        char f_visitorNo[20];
        char f_passportNo[20];
    };
union PersonType
{   National p_national;
    Foreigner p_foreigner;
};
enum Gender{Female=1,Male};
struct Person{                  
    string p_name;
    int p_age;
    Address p_address;
    PersonType p_type;
    Gender p_gender;
    string *p_degree=new string[3];
    
};
Person person_record[5];
void coutPersonRecord (Person person){
    cout<<"--------Record-------------"<<endl;
    cout<<"Name :\t"<<person.p_name<<endl;
    cout<<"Age : \t"<<person.p_age<<endl;
    cout<<"Gender :\t";
    if(person.p_gender==1){
        cout<<"FEMALE"<<endl;
    }else if(person.p_gender==2){
        cout<<"Male"<<endl;
    } cout<<"Degrees "<<endl;
        for(int i=0;i<3;i++){
        cout<<"degree # "<<i+1<<"\t";
        cout<<person.p_degree[i]<<endl;//p_degree[i]=*(p+i)
    }
    cout<<"Address "<<endl;
    cout<<"city  :"<<"\t"<<person.p_address.city<<endl;
    cout<<"street  :"<<"\t"<<person.p_address.street<<endl;
    if(*nationality_type==1){
        cout<<"CNIC No :"<<"\t"<<person.p_type.p_national.n_cnic<<endl;
        cout<<"Family No :"<<"\t"<<person.p_type.p_national.n_familyNo<<endl;
    }if(*nationality_type==2){
        cout<<"Passport No : "<<"\t"<<person.p_type.p_foreigner.f_passportNo<<endl;
        cout<<"Visitor No : "<<"\t"<<person.p_type.p_foreigner.f_visitorNo<<endl;
    }
    
}
void editPersonRecord(Person& person){
    char selectchar;
    cout<<"Type A to change Name"<<endl;
    cout<<"Type B to change Age"<<endl;
    cout<<"Type C to change Address"<<endl;
    cout<<"Type D to change Gender(if wrongly added)"<<endl;
    cout<<"Type E to change your Nationality  type "<<endl;
    cout<<"Type F to change your Degree    "<<endl;
    cin>>selectchar;
    switch (selectchar){
        case ('a') :
        cout<<"enter your new name"<<endl;
        cin>>person.p_name;
        break;
        case ('b') :
        cout<<"enter your new Age"<<endl;
        cin>>person.p_age;
        break;
        case ('e') :
        cout<<"press 1)National"<<endl;
        cout<<"press 2)Foreigner"<<endl;
        cin>>(*nationality_type);
        if(*nationality_type==1){
            cout<<"enter your new cnic No"<<endl;
            cin>>person.p_type.p_national.n_cnic;
            cout<<"enter your new Family No "<<endl;
            cin>>person.p_type.p_national.n_familyNo;
        }
        else if(*nationality_type==2){
            cout<<"enter your new  Passport No "<<endl;
            cin>>person.p_type.p_foreigner.f_passportNo;
            cout<<"enter your new Visitor No "<<endl;
            cin>>person.p_type.p_foreigner.f_visitorNo;
        }
        else {
            cout<<"---invalid----"<<endl;
            exit(0);
        }
        break;
        case ('c') :
        int selectaddress;
        cout<<"press 1)Street"<<endl;
        cout<<"press 2)City"<<endl;
        cin>>selectaddress;
        if(selectaddress==1){
            cout<<"street  : ";
            cin>>person.p_address.street;
        }
        else if(selectaddress==2){
            cout<<"City  : ";
            cin>>person.p_address.city;
        }else {
            cout<<"----Invalid"<<endl;
            exit(0);
        }
        break;
        case ('d') :
        
        cout<<"select "<<endl;
        cout<<"press 1)Female"<<endl;
        cout<<"press 2)Male"<<endl;
        cin>>genderselection;
        if(genderselection==1){
            person.p_gender=Female;
        }else if (genderselection==2){
            person.p_gender=Male;
        }
        else {
            cout<<"----invalid1------"<<endl;
        } break;
        case ('f') :
        cout<<"enter the New Degrees"<<endl;
        for(int i=0;i<3;i++){
            cout<<"degree # "<<i+1<<endl;
            cin>>person.p_degree[i];
        }break;
    default:
        cout<<"---invlaid----"<<endl;
        exit(0);
    }
}
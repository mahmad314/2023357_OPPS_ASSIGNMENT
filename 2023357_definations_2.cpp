#include<iostream>
using namespace std;
int number_of_records=0;
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

void inputdata(Person &person){
    cout<<"enter your name ";
    cin>>person.p_name;
    cout<<"enter your age ";
    cin>>person.p_age;
    cout<<"enter your gender  1)Female   2)Male "<<endl;
    cin>>genderselection;
    if(genderselection==1){
        person.p_gender=Female;
    }else   if(genderselection==2){
        person.p_gender=Male;
    }else {
        cout<<"---invalid---"<<endl;
    }
    cout<<"Enter your degree"<<endl;
    for(int i=0;i<3;i++){
        cout<<"degree # "<<i+1<<endl;
        cin>>person.p_degree[i];
    }
    cout<<"enter your Address "<<endl;
    cout<<"city  : ";
    cin>>person.p_address.city;
    cout<<"street  : ";
    cin>>person.p_address.street;
    cout<<"Select 1) National "<<endl;
    cout<<"       2) Foreigner "<<endl;
    cin>>*nationality_type;
    if(*nationality_type==1){
        cout<<"enter your CNIC No "<<endl;
        cin>>person.p_type.p_national.n_cnic;
        cout<<"enter your Family No "<<endl;
        cin>>person.p_type.p_national.n_familyNo;

    }else if(*nationality_type==2){
        cout<<"enter your Passport No "<<endl;
        cin>>person.p_type.p_foreigner.f_passportNo;
        cout<<"enter your Visitor No "<<endl;
        cin>>person.p_type.p_foreigner.f_visitorNo;
    }else {
        cout<<"-------Invalid--------"<<endl;
        exit(0);
        }
}
void insertNewRecord(Person person[]){
    int condition;
    cout<<"Enter the data "<<endl;
    for(int i=0;i<5;i++){
        cout<<"Person # "<<i+1<<endl;
        inputdata(person[i]);
        number_of_records++;
        cout<<"do you Insert  one more record   1)Yes   0)No"<<endl;
        cin>>condition;
        if(condition==0){
            break;
        }else if(condition!=1){
            cout<<"enter right number"<<endl;
            exit(0);
        }
    }
    
}
void showAllRecords(Person person[]){
    cout<<"-----Displaying------ "<<endl;
    for(int i=0;i<number_of_records;i++){
        cout<<"Person # "<<i+1<<endl;
        coutPersonRecord(person[i]);
    }

}
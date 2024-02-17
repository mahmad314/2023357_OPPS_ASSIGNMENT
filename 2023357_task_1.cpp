#include<iostream>
using namespace std;
#include "2023357_definitions_1.cpp"

int main(){
    int editselection;
    Person p1;
    cout<<"enter your name ";
    getline(cin,p1.p_name);
    cout<<"enter your age ";
    cin>>p1.p_age;
    cout<<"enter your gender  1)Female   2)Male "<<endl;
    cin>>genderselection;
    if(genderselection==1){
        p1.p_gender=Female;
    }else   if(genderselection==2){
        p1.p_gender=Male;
    }else {
        cout<<"---invalid---"<<endl;
    }
    cout<<"Enter your degree"<<endl;
    for(int i=0;i<3;i++){
        cout<<"degree # "<<i+1<<endl;
        cin>>p1.p_degree[i];
    }
    cout<<"enter your Address "<<endl;
    cout<<"city  : ";
    cin>>p1.p_address.city;
    cout<<"street  : ";
    cin>>p1.p_address.street;
    cout<<"Select 1) National "<<endl;
    cout<<"       2) Foreigner "<<endl;
    cin>>*nationality_type;
    if(*nationality_type==1){
        cout<<"enter your CNIC No "<<endl;
        cin>>p1.p_type.p_national.n_cnic;
        cout<<"enter your Family No "<<endl;
        cin>>p1.p_type.p_national.n_familyNo;

    }else if(*nationality_type==2){
        cout<<"enter your Passport No "<<endl;
        cin>>p1.p_type.p_foreigner.f_passportNo;
        cout<<"enter your Visitor No "<<endl;
        cin>>p1.p_type.p_foreigner.f_visitorNo;
    }else {
        cout<<"-------Invalid--------"<<endl;
        exit(0);
        }
        coutPersonRecord(p1);
        cout<<endl;
        cout<<"Do you want to change data 1)yes   0)No  "<<endl;
        cin>>editselection;
        if(editselection==1){
            editPersonRecord(p1);
            
            cout<<"after editing "<<endl;
            coutPersonRecord(p1);
        }
        else{
            cout<<"bye"<<endl;
        }


    return 0;
}
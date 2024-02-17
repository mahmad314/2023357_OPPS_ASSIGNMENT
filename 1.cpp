#include<iostream>
using namespace std;
void fun(int*a){
    for(int i=0;i<4;i++){
        cout<<"enter the elements"<<endl;

        cin>>a[i];
    }
}
int main(){
    int a[4]={1,45,5,2};
    int *ptr;
    ptr=a;
    fun(ptr);
    cout<<a<<endl;
    for(int i=0;i<4;i++){
        cout<<a[i]<<"\t";
    }
    return 0;
}
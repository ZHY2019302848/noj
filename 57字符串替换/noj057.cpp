#include <bits/stdc++.h>

using namespace std;

void str_replace(string str,string olds,string news){
    string res="";
    
    while(1){
        int pos=str.find(olds);
        if(pos==-1){
            res+=str;
            break;
        }
        else{
            res=res+str.substr(0,pos)+news;
            str=str.substr(pos+olds.length());
            
        }
    }
    cout<<res;

}

int main(){
    string str,olds,news;
    getline(cin,str);
    getline(cin,olds);
    getline(cin,news);
    str_replace(str,olds,news);
    
}

/*
ebe
*/
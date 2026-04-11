#include<bits/stdc++.h>
using namespace std;



// .size() has unsigned long data type
int main(){
    //initailizing
    string str = "harsh";
    string str2 = "ambekar";
    //length of string
    cout<<str.length()<<endl;
    //Concatenation of Strings
    str2 = str + str2;//on+m
    cout<<str2;
    str.push_back('a');//o1
    str.pop_back();//o1
    str.insert(2,"hahah");//oN
    str.erase(2,4);//oN from index 2 4 chars
    cout<<str.substr(2,4);//0len
    str.find("har");//return index if not found return string::npos
    //s.find(sub, pos, n);
    /*
    s: String which is to be searched.
    sub: Substring to search. Can be C++ or C style string.
    pos: Position from where the string search is to begin. By default, it is 0.
    n: Number of characters to match.
    */
    
}
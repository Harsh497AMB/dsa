#include<bits/stdc++.h>
using namespace std;

//ITERATOR: dataType::iterator name = v.begin();

bool comp(pair<int,int>p1 ,pair<int,int>p2){
    if(p1.second==p2.second) return p1.first<p2.first;
    return p2.second>p1.second;
}

int n=5;

int main(){



//PAIRS
cout<<"PAIRS"<<endl;
    pair<int , int> p = {2,3};
    cout<<p.first<<" "<<p.second<<endl;

    pair<int , pair<int , int>> pip = {2 , {3,4}};
    cout<<pip.second.second<<endl;

    pair<int , int> arrayOfPairs[5] = {{1,2},{3,4},{5,6},{7,8},{9,0}};
    cout<<arrayOfPairs[4].first<<endl;



//VECTORS
cout<<"VECTORS"<<endl;
    vector<int> v = {1};
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.emplace_back(3);//v{1,2,34,5,6,3}
    v.back(); //points last element

    vector<int> vectorOfSameElements(5,100); //{100,100,100,100,100} (size,value)
    vector<int> vectorOfSameElementsWith0(5); //(size)
    vector<int> copiedVector(v); //copiedVector=v

    //v.begin() points the memory || to print the value use *(it)
    vector<int>::iterator vbegin = v.begin();
    vector<int>::iterator vend = v.end(); //locates after the last index
    vector<int>::reverse_iterator vrbegin = v.rbegin();//last element || it++ works in reverse manner
    vector<int>::reverse_iterator vrend = v.rend();//before first element || it++ works in reverse manner

    cout<<*(vbegin)<<" ";
    vbegin++;
    cout<<*(vbegin)<<" "<<endl;

    for(auto it=v.begin(); it!=v.end();it++){
        cout<<*(it);
    }
    cout<<endl;

    //for each loop
    for(auto it:v){
        cout<<it;
    }
    cout<<endl;

    v.erase(v.begin()+1);//(address to be deleted)
    v.erase(v.begin()+1 , v.begin()+4); //[start , end)

    v.insert(v.begin() , 100);
    v.insert(v.begin()+2 , 3 ,5); //(position , no. of times , value)

    vector<int> copy(2,50);
    v.insert(v.begin() , copy.begin() , copy.end());

    v.pop_back();

    //v.clear();
    //v.empty(); true or false


    //ADDING A ROW DYNAMICALLY TO VECTOR(FOR 2D VECTOR)
    vector<vector<int>> vec2D;

    for(int i = 0 ; i<n ; i++){
        vec2D.push_back(vector<int>(i+1));//this line adds the new row of 0 and size i+1
        for(int j = 0; j<=i ; j++){
            vec2D[i][j]=1;
        }
    }




//LISTS
    list<int> ls;
    ls.push_back(2);
    ls.emplace_back(3);

    ls.push_front(5); //less time complexity than insert in vector


//DEQUE
    deque<int> dq;
    dq.push_back(2);
    dq.emplace_back(3);

    dq.push_front(5);

/* 
| Feature           | vector | deque   | list    |
| ----------------- | ------ | -----   | ----    |
| Random access     | ⭐⭐⭐| ⭐⭐⭐| ❌     |
| Push back         | ⭐⭐⭐| ⭐⭐⭐| ⭐⭐⭐|
| Push front        | ❌     | ⭐⭐⭐| ⭐⭐⭐|
| Insert middle     | ❌     | ❌     | ⭐⭐⭐|
| Memory efficiency | ⭐⭐⭐| ⭐⭐   | ❌     |
*/

//STACK    all operations o(1)
stack<int> stk;
stk.push(1);
stk.push(2);
stk.push(3);
stk.push(4);

cout<<stk.top();//4

stk.pop();
cout<<stk.top();//3



//QUEUE   all operations o(1)
queue<int> q;
q.push(1);
q.push(2);
q.push(3);
q.push(4);

q.back();//4
q.front();//1
q.pop();//deletes 1



//PRIORITY_QUEUE   push-logn pop-logn top-o1
priority_queue<int> pq;
pq.push(3);
pq.push(4);
pq.push(1);
pq.push(7);//{7,4,3,1}

cout<<pq.top();//7
pq.pop();//deletes 7

priority_queue<int , vector<int>, greater<int>> qp;
qp.push(3);
qp.push(4);
qp.push(1);
qp.push(7);//{1,3,4,7}


//SET  Unique Sorted  logn
set<int> st;
st.insert(1);
st.insert(2);
st.insert(3);
st.insert(4);
st.insert(1);
st.insert(2);//{1,2,3,4}

auto it = st.find(3);//returns the iterator(memory) of 3
st.erase(4);//logn time
st.erase(it);//o1 time
int cnt = st.count(1);//returns true or false


//MULTISET Sorted NotUnique 
multiset<int> ms;
ms.insert(1);
ms.insert(1);
ms.insert(1);
ms.insert(2);
ms.insert(3);

ms.erase(1);//erase all 1
ms.erase(ms.find(1));//erase only first 1
//ms.erase(ms.find(1) , ms.find(1)+2);


//UNORDERED_SET NotSorted unique o1 worst-oN
unordered_set<int> ust;


//MAP  unique key in sorted order ologn
map<int,int> mpp;//<key,value>  key should be unique 
mpp[1]=2; // key1 value2
mpp.emplace(3,2); // key3 value2
mpp.insert({2,4}); // key2 value4

for(auto it:mpp){
    cout<<it.first<<" "<<it.second<<endl;
}

auto it = mpp.find(3);
// cout<<*(it).second;

//MULTIMAP
multimap<int,int> mmpp;
//UNORDERED MAP o1 worst-oN
unordered_map<int,int> umpp;
//UNORDERED MULTIMAP
unordered_multimap<int,int> ummpp;


//ALGORITHMS
int arr[5]={1,3,52,3,6};
sort(arr , arr+5);//sort function requires pointers
sort(arr , arr+5, greater<int>());

pair<int,int> a[] = {{1,2},{2,1},{4,1}};
sort(a , a+3 , comp);

int cnt = __builtin_popcount(5); //cnt=number of 1 in 5 101 =>2  cnt=2





















}
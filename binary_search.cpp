#include<bits/stdc++.h>
using namespace std;

//main intutuin is to eliminate one half of array

int binary_search(vector<int> v , int k){
    int low = 0;
    int high = v.size()-1;
    bool found = false;

    while(low<=high){
        int mid = low + ((high - low)/2);

        if(v[mid] == k) {
            found = true;
            return mid;
        }

        else if(k > v[mid]) low = mid + 1;
        else high = mid - 1;
    }

    if(found == false) return -1;
}

int bs(vector<int> v , int low, int high ,  int k){
    bool found = false;

    while(low<=high){
        int mid = low + ((high - low)/2);

        if(v[mid] == k) {
            found = true;
            return mid;
        }

        else if(k > v[mid]) low = mid + 1;
        else high = mid - 1;
    }

    if(found == false) return -1;
}

int Lower_bound(vector<int> v , int k){
    int low = 0;
    int high = v.size() - 1;
    int lb = v.size();

    while(low <= high){
        int mid = low + ((high - low)/2);
        if(v[mid] < k) low = mid + 1;
        else{
            lb = mid;
            high = mid - 1;
        }
    }
    return lb;
}

int Upper_bound(vector<int> v , int k){
    int low = 0;
    int high = v.size() - 1;
    int ub = v.size();

    while(low<=high){
        int mid = low + ((high - low)/2);
        if(v[mid] <= k) low = mid + 1;
        else{
            ub = mid;
            high = mid -1;
        }
    }
    return ub;
}

int sqrrt(int k){
    if(k<1) return -1;
    int low = 1;
    int high = k;
    int ans = 1;

    while(low <= high){
        int mid = low + ((high - low)/2);

        if(mid*mid <= k){
            ans = mid;
            low = mid + 1;
            }
        if(mid * mid > k) high = mid - 1;
    }
    return ans;
}

int main(){
    vector<int> v = {1,2,4,5,6,7,8,9};
    //indexs         0,1,2,3,4,5,6,7

    vector<int> nums = {8,8,9,1,2,3,3,4,5,6, 7, 7, 7};
                  //    0,1,2,3,4,5,6,7,8,9,10,11,12
    //BUILT IN LOWER BOUND AND UPPER BOUND FUNCTIONS
        int lb = lower_bound(v.begin() , v.end() , 3) - v.begin();
        int ub = upper_bound(v.begin() , v.end() , 4) - v.begin();

    cout<<binary_search(v , 3)<<endl;
    cout<<Lower_bound(v , 3)<<endl;
    cout<<Upper_bound(v , 4)<<endl;
    cout<<sqrrt(10000);
}
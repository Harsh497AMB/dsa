#include<bits/stdc++.h>
using namespace std;

//TWO POINTER
//SLIDING WINDOW
//PREFIX SUM

int largestElementInArray(int arr[] , int n){
    int large = INT_MIN;
    for(int i=0; i<n ; i++){
        if(arr[i]>large){
            large=arr[i];
        }
    }
    return large;
}

int secondLargestElement(int arr[] , int n){
    int largest= arr[0];
    int secondLargest = -1;

    for(int i=0; i<n ; i++){
        if(arr[i]>secondLargest && arr[i]>largest){
            secondLargest=largest;
            largest=arr[i];
        }
        else if(arr[i]>secondLargest && arr[i]<largest){
            secondLargest = arr[i];
        }
    }

    return secondLargest;
}

bool checkIfArrayIsSorted(int arr[] , int n){
    for(int i=0 ; i<n-1 ; i++){
        if(arr[i]>arr[i+1]){
            return false;
        }
    }
    return true;
}

void removeDuplicatesFromArray(int arr[] , int n){
    vector<int> a;
    unordered_set<int> ust;
    for(int i=0;i<n;i++){
        // set.find(key)!=set.end()
        if(ust.count(arr[i])==0){
            ust.insert(arr[i]);
            a.push_back(arr[i]);
        }
    }
    for(auto it:a){
        cout<<it<<" ";
    }
    cout<<endl;
}

void removeDuplicateFromSortedArray(int arr[]  ,int n){
    vector<int> v;
    v.push_back(arr[0]);
    for(int i=1 ; i<n ; i++){
        if(arr[i]!=arr[i-1]){
            v.push_back(arr[i]);
        }
    }
    for(auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;
}

void reverseArray(int arr[] , int low , int high){
    int mid = (high+low-1)/2;
    for(int i=0; i<=mid-low ; i++){
        swap(arr[low+i] , arr[high-i]);
    }
}

void rotateArray(int arr[] , int k  ,int length){
    int r = k % length;
    reverseArray(arr , 0 , r-1);
    reverseArray(arr , r , length-1);
    reverseArray(arr , 0 , length-1);

    for(int i = 0; i<length ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void moveAllzeroesToTheEndOfArray(int arr[] , int n){
    int i=0;
    int j=0;
    while(i<n && j<n){
        if(arr[i]!=0 && arr[j]!=0){ i++ ; j++;}
        else if(arr[i]==0 && arr[j]==0){j++;}
        else if(arr[i]==0 && arr[j]!=0){
            swap(arr[i] , arr[j]);
            i++; j++;
        }
        else{
            j++;
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int linearSearch(int arr[] , int n, int num){
    for(int i=0 ; i<n ; i++){
        if(arr[i] == num){
            return i;
        }
    }
}

void unionOfTwoSortedArray(int arr1[] , int arr2[] , int l1 , int l2){
    int i=0;
    int j=0;
    int k;
    vector<int> v;

    if(arr1[0]<=arr2[0]){
        v.push_back(arr1[0]);
        i++;
        k=0;
    }
    else{
        v.push_back(arr2[0]);
        j++;
        k=0;
    }

    while(i<l1 && j<l2){
        if(arr1[i]<=arr2[j]){
            if(arr1[i]>v[k]){
                v.push_back(arr1[i]);
                k++;
            }
            i++;
        }
        else{
            if(arr2[j]>v[k]){
                v.push_back(arr2[j]);
                k++;
            }
            j++;
        }
    }

    while(i<l1){
        if(arr1[i]>v[k]){
                v.push_back(arr1[i]);
                k++;
            }
            i++;
    }

    while(j<l2){
        if(arr2[j]>v[k]){
                v.push_back(arr2[j]);
                k++;
            }
            j++;
    }

    for(auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;
}

void intersectionOfTwoArrays(int arr1[] , int arr2[] , int l1 , int l2){
    int i=0;
    int j=0;
    vector<int> v;
    while(i<l1 && j<l2){
        if(arr1[i]<arr2[j]){
        i++;
    }
    else if(arr1[i]>arr2[j]){
        j++;
    }
    else if(arr1[i]==arr2[j]){
        v.push_back(arr2[j]);
        i++;
        j++;
    }
    }
    
    for(auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;
}

int findMissingNumber(int arr[] , int n){
    int sum=0;
    for(int i=0 ; i<n ; i++){
        sum+=arr[i];
    }
    return (n+1)*(n+2)/2 - sum ;
}

int maxConsecutiveOnes(vector<int> arr , int n){
    int maxCount = 0;
    int i=0;
    int j=0;

    while(i<n && j<n){
        if(arr[j]==1){
            maxCount = max(j-i+1 , maxCount);
            j++;
        }else{
            while(arr[j]!=1 && j<n){
                j++;
            } 
            i=j;
        }
    }
    return maxCount;
}

int numberThatAppearsOnceAndOtherTwice(vector<int> v){
    int ans=0;
    for(int i=0 ; i<v.size() ; i++){
        ans^=v[i];
    }
    return ans;
}

int longestSubArraySumK(vector<int> v , int k){
    int n = v.size();
    int i=0;
    int j=0;
    int sum=0;
    int mc=0;
    while(i<n && j<n){
            sum+=v[j];

        while(sum>k && i<=j){
            sum-=v[i];
            i++;
        }
        if(sum<k){
            j++;
        }
        else if(sum==k){
            mc = max(mc , j-i+1);
            j++;
        }
    }
    return mc;
}

int longestSubArrayWithSumKWithNegatives(vector<int> v , int k){
    map<int , int> mpp;
    int ml=0;
    int n = v.size();
    int sum=0;
    for(int i=0 ; i<n ; i++){
        sum+=v[i];
        if(sum==k){
            ml = max(ml , i+1);
        }
        int rem = sum - k;
        if(mpp.find(rem)!=mpp.end()){
            ml = max(ml , i-mpp[rem]);
        }
        if(mpp.find(sum)==mpp.end()){
            mpp[sum] = i;
        }
    }
    return ml;
}

void TwoSum(vector<int> v , int target){
    map<int , int> hash;
    for(int i=0 ; i<v.size() ; i++){
        int tar = target - v[i];
        if(hash.find(tar)!=hash.end()){
            cout<<hash[tar]<<" "<<i;
            break;
        }
        else{
            hash[v[i]] = i;
        }
    }
    cout<<endl;
}

void sortArrayOf012(vector<int> v){
    int low=0;
    int mid=0;
    int high=v.size()-1;
     
    while(mid<=high){
        if(v[mid]==0){
            swap(v[mid] , v[low]);
            low++;
        }
        else if(v[mid]==1){
            mid++;
        }
        else if(v[mid]==2){
            swap(v[mid] , v[high]);
            high--;
        }
    }

    for(auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;
}

int majorityElementN2(vector<int> v){
    int count=0;
    int me;
    int cc;
    for(int i=0 ; i<v.size() ; i++){
        if(count==0){
            me=v[i];
            count++;
        }else{
            if(me==v[i]){
                count++;
            }else{
                count--;
            }
        }
    }
    for(int i=0 ; i<v.size() ; i++){
        if(me==v[i]){
            cc++;
        }
    }
    if(cc>(v.size()/2)){
        return me;
    }else{
        return -1;
    }
}

int maxSubArraySum(vector<int> v){
    int sum=0;
    int ms = INT_MIN;

    for(int i=0 ; i<v.size() ; i++){
        if(sum<0){
            sum=0;
        }
        sum+=v[i];
        ms = max(ms , sum);
    }
    return ms;
}

int main(){
    int arr[] = {42, 7, 89, 15, 63, 28, 94, 3, 56};
    int arr0[] = {1,0,2,3,2,0,0,4,5,1};
    int arr1[] = {2, 4, 4, 7, 9, 9, 12, 15, 15};
    int missingNumberArray[] = {1,2,4,5};
    int sortedArray1[] = {1,1,2,3,4,5};
    int sortedArray2[] = {2,3,4,4,5,6};
    vector<int> maxConsecutiveOnesArray = {1,1,0,1,1,1,1,0,0,0,0,1,1};
    vector<int> numberThatAppearsOnceAndOtherTwiceV = {7, 3, 5, 4, 5, 3, 4, 9, 7};
    vector<int> longestSubArraySumKV = {1,2,3,1,1,1,1,4,2,3};
    vector<int> longestSubArraySumKNegativeV = {4, -1, 2, -3, 5, -2, 3, -4, 6, -1, 2, -5, 4};
    vector<int> TwoSumV = {21, 5, -10, 3, 9, 14};
    vector<int> sortArrayOf012V = {2,0,2,1,1,0};
    vector<int> majorityElementN2V = {7, 2, 7, 5, 7, 7, 1, 7, 3};
    vector<int> maxSubArraySumV ={-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int length =  sizeof(arr) / sizeof(arr[0]);
    int length1 = sizeof(sortedArray1) / sizeof(arr[0]);
    int length2 = sizeof(sortedArray2) / sizeof(arr[0]);
    int length3 = sizeof(missingNumberArray) / sizeof(arr[0]);

    cout<<largestElementInArray(arr , length)<<endl;
    cout<<secondLargestElement(arr , length)<<endl;
    cout<<checkIfArrayIsSorted(arr , length)<<endl;
    removeDuplicatesFromArray(arr1, length);
    removeDuplicateFromSortedArray(arr1, length);
    // rotateArray(arr , 10 , length);
    moveAllzeroesToTheEndOfArray(arr0 , length);
    cout<<linearSearch(arr , length , 94)<<endl;
    unionOfTwoSortedArray(sortedArray1,sortedArray2,length1,length2);
    intersectionOfTwoArrays(sortedArray1,sortedArray2,length1,length2);
    cout<<findMissingNumber(missingNumberArray , length3)<<endl;
    cout<<maxConsecutiveOnes(maxConsecutiveOnesArray , maxConsecutiveOnesArray.size())<<endl;
    cout<<numberThatAppearsOnceAndOtherTwice(numberThatAppearsOnceAndOtherTwiceV)<<endl;
    cout<<longestSubArraySumK(longestSubArraySumKV , 6)<<endl;
    cout<<longestSubArrayWithSumKWithNegatives(longestSubArraySumKNegativeV,5)<<endl;
    TwoSum(TwoSumV , 11);
    sortArrayOf012(sortArrayOf012V);
    cout<<majorityElementN2(majorityElementN2V)<<endl;
    cout<<maxSubArraySum(maxSubArraySumV)<<endl;
}
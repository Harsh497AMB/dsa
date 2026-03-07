#include<bits/stdc++.h>
using namespace std;

int i=0;

void printName(int n){
    if(i==n) return;
    cout<<"harsh"<<endl;
    i++;
    printName(n);
}

void print1toN(int i, int n){
    if(i==n) return;
    cout<<i+1<<" ";
    // i++;
    print1toN(i+1,n);
}

void printNto1(int n){
    if(i==n) return;
    cout<<n-i<<" ";
    i++;
    printNto1(n);
}

int sumOfNNumbers(int i,int n,int sum){
    if(i>n) return sum;
    sumOfNNumbers(i+1,n,sum+i);
}

int sumOfNNumbersReturn(int n){
    if(n==0)return 0;
    return n + sumOfNNumbersReturn(n-1);
}

int factorial(int n){
    if(n==1) return 1;
    return n*factorial(n-1);
}

void reverseAnArray(int arr[] , int size ,int i){
    if(i>=size/2) {
        for(int i=0 ; i<4 ; i++){
            cout<<arr[i]<<" ";
        }
        return;}
    swap(arr[i] , arr[size-i-1]);
    reverseAnArray(arr , 4 , i+1);
}

void palidrome(string s , int length , int i){
    if(i>=length/2) {
        cout<<"palidrome";
        return;
    }
    if(s[i]!=s[length-i-1]){
        cout<<"not palidrome";
        return;
    }
    palidrome(s,s.length(),i+1);
}

int fibonacci(int i, int j, int n){
    if(n==1) return i;
    if(n==2) return j;
    if(n==3) return j+i;
    return fibonacci(j,j+i,n-1);

}

void printPermutations(int ind , vector<int> ds , int arr[] , int n){
    if(ind>=n){
        for(auto it:ds){
            cout<< it << " ";
        }
        cout<<endl;
        return;
    }
    ds.push_back(arr[ind]);
    printPermutations(ind+1 , ds , arr , n);
    ds.pop_back();
    printPermutations(ind+1 , ds , arr , n);
}

void printSubsequencesWithSumK(int ind , vector<int> ds , int arr[] , int n , int k ){
    int sum;
    if(ind>=n){
            sum=0;
            for(auto it:ds){
                sum+=it;
            }
        if(sum==k){
            for(auto it:ds){
            cout<< it << " ";
        }
        cout<<endl;}
        return;
    }
    ds.push_back(arr[ind]);
    printSubsequencesWithSumK(ind+1 , ds , arr , n , k );
    ds.pop_back();
    printSubsequencesWithSumK(ind+1 , ds , arr , n , k);
}

// void printFirstSubsequencesWithSumK(int ind , vector<int> ds , int arr[] , int n , int k ){
//     int sum;
//     if(ind>=n){
//             sum=0;
//             for(auto it:ds){
//                 sum+=it;
//             }
//         if(sum==k){
//             for(auto it:ds){
//             cout<< it << " ";
//         }
//         cout<<endl;}
//         return;
//     }
//     ds.push_back(arr[ind]);
//     printFirstSubsequencesWithSumK(ind+1 , ds , arr , n , k );
//     ds.pop_back();
//     printFirstSubsequencesWithSumK(ind+1 , ds , arr , n , k);
// }

void merge(int arr[] , int low , int mid  , int high){
    int left = low;
    int right = mid+1;
    vector<int> temp;

    while (left<=mid && right<=high){
        if(arr[left]<=arr[right]){
        temp.push_back(arr[left]);
        left++;
    }
    else if(arr[left]>arr[right]){
        temp.push_back(arr[right]);
        right++;
    }
    }

        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
    
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }

    for(int i=low; i<=high;i++){
        arr[i] = temp[i-low];
    }
}

void mergeSort(int arr[] , int low , int high){
    if(low == high) return;
    int mid = (low+high)/2;
    mergeSort(arr , low , mid);
    mergeSort(arr , mid+1 , high);
    merge(arr , low , mid , high);
}

int findPivotAndSwap(int arr[] , int low , int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j)swap(arr[i] , arr[j]);
    }
    swap(arr[low] , arr[j]);
    return j;
}

void quickSort(int arr[] , int  low , int high){
    if(low<high){
        int pIndex = findPivotAndSwap(arr , low , high);
            quickSort(arr , low , pIndex-1);
            quickSort(arr , pIndex+1 , high);
        }
    }
    

int main(){
    // printName(5);
    // print1toN(0,5);
    // printNto1(5);
    // cout<<sumOfNNumbers(0,6,0)<<" ";
    // cout<<sumOfNNumbersReturn(5)<<endl;
    // cout<<factorial(5);
    // int arr[5] = {1,2,3,4,5};
    // int arp[4] = {1,2,3,4};
    // reverseAnArray(arp, 4 , 0);
    // string s ="madam";
    // palidrome(s , s.length() , 0);
    // cout<<fibonacci(0,1,8);
    int arr[] = {3,1,2,4,56,7,5,3,5};
    int length = sizeof(arr) / sizeof(arr[0]);
    vector<int> ds;
    // printPermutations(0,ds,arr,n);
    // printSubsequencesWithSumK(0,ds,arr,n,4);
    // mergeSort(arr,0,length-1);
    quickSort(arr , 0 , length-1);
    for(int i=0;i<length;i++){
        cout<<arr[i]<<" ";
    }
}
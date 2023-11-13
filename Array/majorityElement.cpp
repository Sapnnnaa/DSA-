// brute force O(N^2)

#include<bits/stdc++.h>
using namespace std;

int findMajority(int arr[], int n)
{
    for (int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++)
        {
            if (arr[j]==arr[i]){
                count++;
            }
        }
        if(count>(n/2))
        return arr[i];
    }
    return -1;

}
int main()
{
    int arr[] = { 1, 1, 2, 1, 3, 5, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // Function calling
    int ans = findMajority(arr, n);
    cout << "The majority element is: " << ans << endl;
    return 0;
}

//or


#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();

    for (int i = 0; i < n; i++) {
        //selected element is v[i]
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            // counting the frequency of v[i]
            if (v[j] == v[i]) {
                cnt++;
            }
        }

        // check if frquency is greater than n/2:
        if (cnt > (n / 2))
            return v[i];
    }

    return -1;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
} 

// better solution O(NlogN)+O(N)

int majorityElement(vector<int> v)
{
    int n=v.size();

    map<int,int>mpp;

    // storing the elements with its occurence
    for(int i=0;i<n;i++){
        mpp[v[i]]++;
    }
//searching for the majority element:
    if(auto it: mpp){
        if(it.second>(v.size()/2)){
            return it.first;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}

// optimal solution O(N)+O(N)

int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();
    int cnt = 0; // count
    int el; // Element

    //applying the algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i]) cnt++;
        else cnt--;
    }

    //checking if the stored element
    // is the majority element:
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el) cnt1++;
    }

    if (cnt1 > (n / 2)) return el;
    return -1;
}

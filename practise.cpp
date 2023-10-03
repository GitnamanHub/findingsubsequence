#include<iostream>
#include<vector>
using namespace std;

bool findingcombinations(vector<int> &arr, int size, int target, vector< int> &ans, int start)
{
    if(target==0)
        {
            return true;
        }
    for(int i=start;i<size;i++)
    {
        
        if(arr[i]<=target)
        {
            ans.push_back(arr[i]);//adds element in ans
            if(findingcombinations(arr,size,target-arr[i],ans,i+1))
            {
                return true;
            }
            else 
            {
                ans.pop_back();//removes last added element
            }
        }
    }
    return false;
}

int main()
{
    int size,target;
    vector<int> arr={2,4,3,7,1,2};
    vector<int> ans;
    //let target be 11
    size=6;
    target = 11;
    if(findingcombinations(arr, size, target, ans,0))
    {
        for(int num : ans)
        {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"No solution"<<endl;
    }
}
//
//  main.cpp
//  Peak Element
//
//  Created by Chetna on 22/01/22.
//

class Solution
{
    public:
    int findPeakUntil(int arr[], int low, int high, int n)
    {
        int mid=(low+high)/2;
        //if mid is last or first index with first element graeter than next
        //also check if mid element is greater than mid-1 and mid+1
        
        if((mid==0 || arr[mid-1] <= arr[mid]) && (mid==n-1 || arr[mid+1] <= arr[mid]))
        {
            return mid;
        }
        //if mid is not at 0 index, if so then check if mid element is lesser than the previous element and then recurse for the lower half
        else if(mid>0 && arr[mid-1]> arr[mid])
        {
            return findPeakUntil(arr, low,mid-1,n);
        }
        //else recurse for the upper half
        else
        {
            return findPeakUntil(arr, mid+1,high,n);
        }
    }
    
    
    int peakElement(int arr[], int n)
    {
       return findPeakUntil(arr, 0, n-1, n);
    }
};

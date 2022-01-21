//
//  main.cpp
//  min ele-sorted rotated array
//
//  Created by Chetna on 21/01/22.
//

int minNumber(int arr[], int low, int high)
    {
        //the min element is the only element whose previous element is greater than itslef
        //i.e. when there is no previous element
        if(high<low){
            return arr[0];
        }
        //when there is no middle element
        if(low==high){
            return arr[low];
        }
        //compute middle element
        int mid=(low+high)/2;
        
        //check if the element at (mid+1) is the min element. Consider cases like {3,4,5,1,2}
        if(high>mid && arr[mid] > arr[mid+1])
        {
            return arr[mid+1];
        }
        
        //check if the middle element itself is the min element
        if(low<mid && arr[mid] < arr[mid-1])
        {
            return arr[mid];
        }
        
        //decide whether to left half or the right half of the array since one half of the rotated sorted array will always be sorted so we can ignore one half utilising this.
        if(arr[high] > arr[mid])
        {
            return minNumber(arr,low,mid-1);
        }
        else
        {
        return minNumber(arr,mid+1,high);
        }
        
    }
};

// Leetcode problem - EASY - 26 - Remove duplicates from sorted array (sorted in non-decreasing order)
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    // initialize new value with -1, sice the array can never have negative numbers
    int newValue = -1;

    // boolean variable to check if the new number is repeating
    bool sameNumber = false;

    // the range of elements upto which the array is to be erased
    int start, end, i, count=0;

    // Iterating the vector array
    for (i=0; i<nums.size(); i++){

        // if array element is not same as new value
        if (nums[i] != newValue){
            newValue = nums[i];

            // if the elements were already repeating
            if (sameNumber==true){
                end = i;
                sameNumber = false;

                // erasing elements in the range start->end
                nums.erase(nums.begin() + start, nums.begin() + end);
                i-= end-start;
            }
        }

        // if the elements started repeating
        else if (nums[i]==newValue){
            if (sameNumber==false){
                sameNumber = true;

                // defining the starting constraint
                start = i;
            }
        }
    }

    // Iterating the vector array from back
    for (i=nums.size()-1; i>=0; i--){
        if (nums[i]==nums[i-1]){
            nums.pop_back();
        }
    }

    return nums.size();
}

int main(){
    vector<int> nums = {1,2,2,3,3,3,4,4,4,4,5,5,5,5,5,6,6};
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }
    cout << endl << Remove_Duplicates(nums) << endl;
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }
}
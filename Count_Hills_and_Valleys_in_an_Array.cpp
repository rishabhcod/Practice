//Count Hills and Valleys in an Array
//Easy
/*Given a 0-indexed array nums and the condition of ith index to be called hill is that it's closest non-equal neighbour should be less than nums[i] and the condition for it to be called a valley is that closest non-equal neighbour 
should be greater than nums[i]. Adjacent indices i and j are part of the same hill or valley if nums[i]==nums[j]*/


//Naive Solution:
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        int i=1;

        while(i<nums.size()-1) {
            int j = i - 1;
            while (j >= 0 && nums[j] == nums[i]) j--;
            
            int k = i + 1;
            while (k < n && nums[k] == nums[i]) k++;

            // Make sure j and k are within bounds
            if (j >= 0 && k < n) {
                if (nums[i] > nums[j] && nums[i] > nums[k]) cnt++; // Hill
                else if (nums[i] < nums[j] && nums[i] < nums[k]) cnt++; // Valley
            }
            i=k;
        }
        return cnt;
    }
};

//More clean code
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 1;

        int count = 0;

        while(j+1 < n){
            if ((nums[i] < nums[j] && nums[j] > nums[j+1])
            ||
            (nums[i] >nums[j] && nums[j] < nums[j+1])){
                count++;
                i = j;
            }
            j++;
        }
        return count;
    }
};

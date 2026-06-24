class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int> count;
        int one, zero, two ,k=0; 
        for(int i=0;i<nums.size();i++)
        {
            if(count.find(nums[i])==count.end())
            {
                count.insert(make_pair(nums[i],1));
            }
            else
            {
                count[nums[i]]++;
            }
        }
        
        zero=count[0];
        one=count[1];
        two=count[2];
        
        while(zero>0)
        {
            nums[k]=0;
            k++;
            zero--;
        }
        while(one>0)
        {
            nums[k]=1;
            k++;
            one--;
        }
        while(two>0)
        {
            nums[k]=2;
            k++;
            two--;
        }
    }
};
class Solution {
public:
void invCount(vector<int> &count, vector<pair<int, int>> &v, int low, int high)
{
    int mid=low+(high-low)/2, i=low, k=0, j=mid+1;
    vector<pair<int, int>> temp(high-low+1);
    
    while(i<=mid && j<=high)
    {
        if(v[i].first>v[j].first)
        {
            count[v[i].second] += high-j+1;
            temp[k++]=v[i++];
        }
        else    temp[k++]=v[j++];
        
    }
    while(i<=mid)
        temp[k++]=v[i++];

    while(j<=high)
        temp[k++]=v[j++];
    
    for(int x=low; x<=high; x++)
    {
            v[x]=temp[x-low];
    }
    
}

void mergeSort(vector<int> &count, vector<pair<int, int>> &v, int low, int high)
{
    if(low>=high)   return;
    int mid=low+(high-low)/2;
    mergeSort(count, v, low, mid);
    mergeSort(count, v, mid+1, high);
    invCount(count, v, low, high);
}

vector<int> countSmaller(vector<int>& nums) {
    int n=nums.size();
    vector<pair<int, int>> v;
    vector<int> count(n,0);
    for(int i=0; i<n; i++)
        v.push_back(make_pair(nums[i], i));

    mergeSort(count, v, 0, n-1);
    return count;    
}
};
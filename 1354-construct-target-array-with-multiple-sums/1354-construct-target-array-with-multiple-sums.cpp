class Solution {
public:
bool isPossible(vector<int>& target) {
    int n = target.size();
    
	//if there is oly one element then i must be equal to '1' for satisfy the given condition.
    if(n == 1){
        return target[0] == 1;
    }
     
	//max heap to hold the elements in each step in reverse direction
    priority_queue<long> pq;
    long sum = 0;
    
    for(int i=0; i<n; i++){
        sum += target[i];
        pq.push(target[i]);
    }
    
	//if the max element is equa to the sum => that there must be a zero in the array..which is not possible so return false.
    if(pq.top() == sum){
        return false;
    }
    
	//iterale while the largest element of the array is not '1'.
    while(pq.top() != 1){
        
        long largest = pq.top();
        pq.pop();
        
		//the element that was repleced by the current max element in the previous array
        long element = 2*largest - sum;
        
		//its an special case -> [1,1], [1,2], [1,3]....[1,n]
        if(sum - largest == 1){
            return true;
        }
        
		//if the replaced element is less than or equals zero then return false.
        if(element % (sum - largest) <= 0){
            return false;
        }
        
		//add the replaced element to the maxHeap.
        pq.push(element % (sum - largest));
        
		//update the sum
        sum += element % (sum - largest) - largest;
        
    }
    return true;
}
};
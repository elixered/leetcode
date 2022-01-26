class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        double mini = -1, maxi = -1;
        double mean = 0;
        double mode = -1;
        double median=0;
        int c= 0;
        double sum = 0;
        int total =0;
        for(double i=0; i<=255; i++)
        {
            if(count[i]>0)
            {
                if(mini == -1)
                    mini = i;
                maxi = i;
                if(count[i]>c)
                {
                    c = count[i];
                    mode = i;
                }
                sum += count[i]*i;
                total += count[i];
            }
        }
        mean = sum/total;
       if(total%2!=0)
       {
           int x = total/2+1;
           int curr = 0;
           for(int i=0; i<=255; i++)
           {
               if(curr+count[i]>=x)
               {
                   median = i;
                   break;
               }
               curr += count[i];
           }
       }
        else
        {
            int x = total/2;
            int y = x+1;
            int curr = 0;
            for(int i=0; i<=255; i++)
            {
                if(curr+count[i]>=x)
                {
                    median += i;
                    break;
                }
                else curr += count[i];
            }
            curr = 0;
            for(int i=0; i<=255; i++)
            {
                if(curr+count[i]>=y)
                {
                    median += i;
                    break;
                }
                else curr += count[i];
            }
            median /= 2.0;
        }
        return {mini,maxi,mean,median,mode};
    }
};
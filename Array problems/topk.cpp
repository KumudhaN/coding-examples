// https://leetcode.com/problems/top-k-frequent-elements/description/
class Solution {
public:    
    static bool compare(pair<int,int> p1, pair<int,int> p2){
        if(p1.second == p2.second)
            return p1.first > p2.first;
        return p1.second > p2.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::map<int, int> counter;
        for(auto num : nums){
            counter[num]++;
        }
    
    // vector<pair<int,int>> freq(counter.begin(), counter.end());
    // sort(freq.begin(), freq.end(), compare);

    priority_queue<pair<int, int>, 
    vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto count: counter){
        pq.push({count.second, count.first});
        //std::cout << "Inserting: " << count.first << " ";
        if(pq.size() > k){
            //std::cout << "Popping: " << pq.top().second << std::endl;
            pq.pop();
        }
    }
    vector<int> topk;
    for(int i=0; i< k; i++){
        //topk.push_back(freq[i].first);
        topk.push_back(pq.top().second);
        pq.pop();
    }
    return topk;
    }
};
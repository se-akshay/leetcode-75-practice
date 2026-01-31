class RecentCounter {
public:
int i;
int j;
vector<int> calls;
    RecentCounter() {
        i = 0;
        j = -1;
    }
    
    int ping(int t) {
        calls.push_back(t);
        j++;

    // update the window
        while(i<j && (t-3000 > calls[i])){
            i++;
        }

        return j-i+1;       
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
class StockSpanner {
private:
vector<int> lifo;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        if(lifo.empty()){
            lifo.push_back(price);
            return lifo.size();
        }
        lifo.push_back(price);
        for(int i = lifo.size()-1; i >= 0;i--){
            if(lifo[i] > price) return lifo.size() - i - 1;
        }
        return lifo.size();
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
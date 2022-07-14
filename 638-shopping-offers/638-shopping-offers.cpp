class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int bestPrice = calculateWOOffers(price, needs);
        for (const auto& sp : special) {
            substractOffer(sp, needs);
            if (noNegatives(needs)) {
                int withOffer = sp.back() + shoppingOffers(price, special, needs);
                bestPrice = min(bestPrice, withOffer);
            }
            addOffer(sp, needs);
        }

        return bestPrice;
    }
    
    int calculateWOOffers(const vector<int>& price, const vector<int>& needs) {
        int totalPrice{0};
        for (size_t i = 0; i < price.size(); ++i)
            totalPrice += price[i] * needs[i];
        return totalPrice;
    }
    
    void substractOffer(const vector<int>& special, vector<int>& needs) {
        for (size_t i = 0; i < needs.size(); ++i)
            needs[i] -= special[i];
    }
    
    void addOffer(const vector<int>& special, vector<int>& needs) {
        for (size_t i = 0; i < needs.size(); ++i)
            needs[i] += special[i];
    }
    
    bool noNegatives(const vector<int>& needs) {
        for (int n : needs)
            if (n < 0)
                return false;
        return true;
    }
};
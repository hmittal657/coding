// https://leetcode.com/problems/design-movie-rental-system/

class MovieRentingSystem {
public:

    unordered_map<int, unordered_map<int, int>> prices; // movie -> shop -> price
    unordered_map<int, set<pair<int, int>>> dropped; // movie -> price, shop
    set<array<int, 3>> rented; // price, shop, movie


    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (int i =0; i < entries.size(); i++) {
            prices[entries[i][1]][entries[i][0]] = entries[i][2];
            dropped[entries[i][1]].insert({entries[i][2], entries[i][0]});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        for (auto it : dropped[movie]) {
            res.push_back(it.second);
            if (res.size() == 5) return res;
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        int price = prices[movie][shop];
        rented.insert({price, shop, movie});
        dropped[movie].erase(dropped[movie].find({price, shop}));
    }
    
    void drop(int shop, int movie) {
        int price = prices[movie][shop];
        dropped[movie].insert({price, shop});
        rented.erase({price, shop, movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;

        for (auto it : rented) {
            vector<int> temp;
            temp.push_back(it[1]);
            temp.push_back(it[2]);
            res.push_back(temp);
            if (res.size() == 5) return res;
        }

        return res;

    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
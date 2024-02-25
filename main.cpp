#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include<set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <unordered_set>


namespace std{

    class Solution {
    public:

        void FindS(unordered_map<int, vector<int>> &mapP, unordered_set<int> &Key) {
            queue<int> queueS;
            for (const auto &i : Key) {
                queueS.emplace(i);
            }

            while (!queueS.empty()) {
                int key = queueS.front();
                queueS.pop();

                if (mapP.find(key) != mapP.end()) {
                    for (const auto &i : mapP[key]) {
                        if (!Key.count(i)) {
                            queueS.push(i);
                            Key.emplace(i);
                        }
                    }
                }
            }
        }



        vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
            map<int,unordered_map<int,vector<int>>> mapp;
            for (const auto &i: meetings) {
                mapp[i[2]][i[1]].emplace_back (i[0]);
                mapp[i[2]][i[0]].emplace_back (i[1]);
            }
            unordered_set<int> KeySecret = {0,firstPerson};

            for (auto &i: mapp) {
                FindS(i.second,KeySecret);
            }
            return vector<int>(KeySecret.begin(), KeySecret.end());
        }
    };
}


int main(){
    auto t = new std::Solution;
    std::vector<std::vector<int>> tt = {
            {1,2,5},{2,3,8},{1,5,10},{6,7,10}};
    auto tm = t->findAllPeople(6,tt,1);
    for (auto& i : tm) {
        std::cout << i;
    }

    return 0;
}
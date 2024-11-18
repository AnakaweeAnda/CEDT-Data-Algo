#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>

using std::string;

void change_1(std::stack<std::vector<std::queue<int>>> &a, int from, int to)
{
    std::vector<std::vector<std::queue<int>>> result;
    while(!a.empty()) {
        result.push_back(a.top());
        a.pop();
    }
    for(auto &vec : result) {
        for(auto &q : vec) {
            int n = q.size();
            for(int i=0;i<n;i++) {
                int a = q.front();
                q.pop();
                if(a==from) {
                    a=to;
                }
                q.push(a);
            }
        }
    }
    while(!result.empty()) {
        a.push(result.back());
        result.pop_back();
    }
}

void change_2(std::map<string, std::pair<std::priority_queue<int>, int>> &a, int from, int to)
{
    for(auto &[s,p] : a) {
        if(p.second == from) p.second = to;
        std::vector<int> tmp;
        while(!p.first.empty()) {
            int i = p.first.top();
            p.first.pop();
            if(i==from) i = to;
            tmp.push_back(i);
        }
        while(!tmp.empty()) {
            p.first.push(tmp.back());
            tmp.pop_back();
        }
    }
}

void change_3(std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> &a, int from, int to)
{
    std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> new_set;
    for(auto [li,mp] : a) {
        std::list<int> nlist;
        for(auto val : li) {
            if(val == from) val = to;
            nlist.push_back(val);
        }
        std::map<int, std::pair<int, string>> nmap;
        for(auto [key,val] : mp) {
            if(val.first == from) val.first = to;
            if(key == from) {
                nmap[to] = val;
            }
            else nmap[key] = val;
        }
        new_set.insert({nlist,nmap});
    }
    a = new_set;
}

#endif

/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 26, 2014
    Problem:    Merge Intervals
    Source:     https://oj.leetcode.com/problems/merge-intervals/
    Note:

    Given a collection of intervals, merge all overlapping intervals.

    For example,
    Given [1,3],[2,6],[8,10],[15,18],
    return [1,6],[8,10],[15,18].

    Definition for an interval.

        struct Interval {
            int start;
            int end;
            Interval() : start(0), end(0) {}
            Interval(int s, int e) : start(s), end(e) {}
        };



    Solution:   Merge the interval according to their position.

 */ 


#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> myresult;
        vector<int> Num;

        for(long i=0; i<intervals.size(); i++){
            bool found_start, found_end;
            int pos_start = findPosition(intervals[i].start, Num, 0, Num.size()-1, found_start);
            int pos_end = findPosition(intervals[i].end, Num,  0, Num.size()-1, found_end);

            if(found_start && found_end){
                if(pos_start%2==0 && pos_end%2==1)
                    Num.erase(Num.begin()+pos_start+1, Num.begin()+pos_end);
                else if(pos_start%2==0)
                    Num.erase(Num.begin()+pos_start+1, Num.begin()+pos_end+1);
                else if(pos_end%2==1)
                    Num.erase(Num.begin()+pos_start, Num.begin()+pos_end);
                else
                    Num.erase(Num.begin()+pos_start, Num.begin()+pos_end+1);

            }
            else if(found_start && pos_start%2==0){
                if(pos_end%2==1)
                    Num.erase(Num.begin()+pos_start+1, Num.begin()+pos_end);
                else{
                    Num.insert(Num.begin()+pos_end, intervals[i].end);
                    Num.erase(Num.begin()+pos_start+1, Num.begin()+pos_end);
                }
            }
            else if(found_start && pos_start%2==1){
                if(pos_end%2==1)
                    Num.erase(Num.begin()+pos_start, Num.begin()+pos_end);
                else{
                    Num.insert(Num.begin()+pos_end, intervals[i].end);
                    Num.erase(Num.begin()+pos_start, Num.begin()+pos_end);
                }
            }
            else if(found_end && pos_end%2==1){
                if(pos_start%2==0){
                    Num.erase(Num.begin()+pos_start, Num.begin()+pos_end);
                    Num.insert(Num.begin()+pos_start, intervals[i].start);
                }
                else
                    Num.erase(Num.begin()+pos_start, Num.begin()+pos_end);
            }
            else if(found_end && pos_end%2==0){
                if(pos_start%2==0){
                    Num.erase(Num.begin()+pos_start, Num.begin()+pos_end+1);
                    Num.insert(Num.begin()+pos_start, intervals[i].start);
                }
                else
                    Num.erase(Num.begin()+pos_start, Num.begin()+pos_end+1);
            }
            else{
                if(pos_start%2==0 && pos_end%2==0){
                    Num.insert(Num.begin()+pos_end, intervals[i].end);
                    Num.erase(Num.begin()+pos_start, Num.begin()+pos_end);
                    Num.insert(Num.begin()+pos_start, intervals[i].start);
                }
                else if(pos_start%2==0){
                    Num.erase(Num.begin()+pos_start, Num.begin()+pos_end);
                    Num.insert(Num.begin()+pos_start, intervals[i].start);
                }
                else if(pos_end%2==0){
                    Num.insert(Num.begin()+pos_end, intervals[i].end);
                    Num.erase(Num.begin()+pos_start, Num.begin()+pos_end);
                }
                else{
                    Num.erase(Num.begin()+pos_start, Num.begin()+pos_end);
                }
            }
        }

        for(int i=0; i<Num.size(); i+=2)
            myresult.push_back(Interval(Num[i], Num[i+1]));

        return myresult;
    }

    int findPosition(const int& target,const vector<int> &Num, int start, int end, bool& found){
        if(start > end){
            found = false;
            return start;
        }

        int mid = (start+end)/2;
        if(Num[mid] == target){
            found = true;
            return mid;
        }

        if(target < Num[mid])
            return findPosition(target, Num, start, mid-1, found);
        else
            return findPosition(target, Num, mid+1, end, found);
    }

};

/*
    Author:     Edlin(LIN Junhao) edlinlink@qq.com
    Date:       Nov. 26, 2014
    Problem:    Insert Interval
    Source:     https://oj.leetcode.com/problems/insert-interval/
    Note:

    Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
    You may assume that the intervals were initially sorted according to their start times.

    Example 1:
    Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

    Example 2:
    Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

    This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

    Definition for an interval.

        struct Interval {
            int start;
            int end;
            Interval() : start(0), end(0) {}
            Interval(int s, int e) : start(s), end(e) {}
        };


    Solution:   Similar to Problem `Merge Intervals`
 */ 



class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> myresult;
        vector<int> Num;

        for(long i=0; i<intervals.size(); i++){
            Num.push_back(intervals[i].start);
            Num.push_back(intervals[i].end);
        }

        bool found_start, found_end;
        int pos_start = findPosition(newInterval.start, Num, 0, Num.size()-1, found_start);
        int pos_end = findPosition(newInterval.end, Num,  0, Num.size()-1, found_end);

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
                Num.insert(Num.begin()+pos_end, newInterval.end);
                Num.erase(Num.begin()+pos_start+1, Num.begin()+pos_end);
            }
        }
        else if(found_start && pos_start%2==1){
            if(pos_end%2==1)
                Num.erase(Num.begin()+pos_start, Num.begin()+pos_end);
            else{
                Num.insert(Num.begin()+pos_end, newInterval.end);
                Num.erase(Num.begin()+pos_start, Num.begin()+pos_end);
            }
        }
        else if(found_end && pos_end%2==1){
            if(pos_start%2==0){
                Num.erase(Num.begin()+pos_start, Num.begin()+pos_end);
                Num.insert(Num.begin()+pos_start, newInterval.start);
            }
            else
                Num.erase(Num.begin()+pos_start, Num.begin()+pos_end);
        }
        else if(found_end && pos_end%2==0){
            if(pos_start%2==0){
                Num.erase(Num.begin()+pos_start, Num.begin()+pos_end+1);
                Num.insert(Num.begin()+pos_start, newInterval.start);
            }
            else
                Num.erase(Num.begin()+pos_start, Num.begin()+pos_end+1);
        }
        else{
            if(pos_start%2==0 && pos_end%2==0){
                Num.insert(Num.begin()+pos_end, newInterval.end);
                Num.erase(Num.begin()+pos_start, Num.begin()+pos_end);
                Num.insert(Num.begin()+pos_start, newInterval.start);
            }
            else if(pos_start%2==0){
                Num.erase(Num.begin()+pos_start, Num.begin()+pos_end);
                Num.insert(Num.begin()+pos_start, newInterval.start);
            }
            else if(pos_end%2==0){
                Num.insert(Num.begin()+pos_end, newInterval.end);
                Num.erase(Num.begin()+pos_start, Num.begin()+pos_end);
            }
            else{
                Num.erase(Num.begin()+pos_start, Num.begin()+pos_end);
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

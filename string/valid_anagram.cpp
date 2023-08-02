https://leetcode.com/problems/valid-anagram/description/


242. Valid Anagram
Easy
9.9K
318
Companies
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false


approach::-->>put the first string into the map and itereate the second string and remove the character one by one if the map becom empty than string is anagram otherwise not;

code::-->>
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        for(auto it:s){
            mp[it]++;
        }
        for(int i=0;i<t.size();i++){
            mp[t[i]]--;
            if(mp[t[i]]==0)mp.erase(t[i]);
        }
        cout<<mp.size();
        return mp.size()==0;
    }
};
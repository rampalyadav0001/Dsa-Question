Count Occurences of Anagrams
LINK::-->>https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

Given a word pat and a text txt. Return the count of the occurrences of anagrams of the word in the text.

Example 1:

Input:
txt = forxxorfxdofr
pat = for
Output: 3
Explanation: for, orf and ofr appears
in the txt, hence answer is 3.
Example 2:

Input:
txt = aabaabaa
pat = aaba
Output: 4
Explanation: aaba is present 4 times
in txt.






optimized code using two hashmap::--->>
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int search(string pat, string txt)
    {

        map<char, int> mp1;

        for (int i = 0; i < pat.size(); i++)
            mp1[pat[i]]++;

        int i = 0, j = 0;
        map<char, int> mp2;
        int cnt = 0;

        while (j < txt.size())
        {
            mp2[txt[j]]++;
            if ((j - i + 1) < pat.size())
                j++;

            else
            {
                if (mp1 == mp2)
                    cnt++;

                mp2[txt[i]]--;
                if (mp2[txt[i]] == 0)
                    mp2.erase(txt[i]);
                i++;
                j++;
            }
        }

        return cnt;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends

MY CODE::--->>>
//{ Driver Code Starts
#include <bits/stdc++.h>

    using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int search(string pat, string txt)
    {
        unordered_map<char, int> mp;
        for (auto it : pat)
        {
            mp[it]++;
        }
        int ans = 0;
        int count = mp.size();
        int left = 0, right = 0;
        while (right < txt.size())
        {
            mp[txt[right]]--;
            if (mp[txt[right]] == 0)
            {
                count--;
            }

            if (right - left + 1 < pat.size())
            {
                right++;
            }
            else
            {
                if (count == 0)
                {
                    ans++;
                }
                mp[txt[left]]++;
                if (mp[txt[left]] > 0)
                {
                    count++;
                }
                left++;
                right++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends

chat gpt code:: : --->>>
    class Solution
{
public:
    int search(string pat, string txt)
    {
        unordered_map<char, int> mp;
        for (auto it : pat)
        {
            mp[it]++;
        }
        int ans = 0;
        int count = mp.size();
        int left = 0, right = 0;

        while (right < txt.size())
        {
            // Expand the window
            mp[txt[right]]--;
            if (mp[txt[right]] == 0)
            {
                count--;
            }

            // Contract the window when it reaches the size of the pattern
            if (right - left + 1 == pat.size())
            {
                if (count == 0)
                {
                    ans++;
                }
                mp[txt[left]]++;
                if (mp[txt[left]] > 0)
                {
                    count++;
                }
                left++;
            }

            right++;
        }

        return ans;
    }
};

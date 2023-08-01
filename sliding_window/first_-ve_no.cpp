Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.



Example 1:

Input :
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output :
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6

HINT and APPROACH::---->>>
It is a variation of the problem of Sliding Window Maximum.
We create a Dequeue, Di of capacity k, that stores only useful elements of the current window of k elements. An element is useful if it is in the current window and it is a negative integer. We process all array elements one by one and maintain Di to contain useful elements of current window and these useful elements are all negative integers. For a particular window, if Di is not empty then the element at front of the Di is the first negative integer for that window, else that window does not contain a negative integer.









vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{
    queue<long long int> q;
    vector<long long> ans;

    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
            q.push(A[i]);
    }
    if (q.empty())
    {
        ans.push_back(0);
    }
    else
    {
        ans.push_back(q.front());
        if (A[0] == q.front())
            q.pop();
    }

    for (int i = K; i < N; i++)
    {

        if (A[i] < 0)
            q.push(A[i]);
        if (q.empty())
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(q.front());
            if (!q.empty() && A[i - K + 1] == q.front())
                q.pop();
        }
    }
    return ans;
}
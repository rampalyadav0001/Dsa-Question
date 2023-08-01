/*
Given a string w, integer array b,  character array x and an integer n. n is the size of array b and array x. Find a substring which has the sum of the ASCII values of its every character, as maximum. ASCII values of some characters are redefined.
Note: Uppercase & lowercase both will be present in the string w. Array b and Array x contain corresponding redefined ASCII values. For each i, b[i] contain redefined ASCII value of character x[i].

Example 1:

Input:
W = abcde
N = 1
X[] = { 'c' }
B[] = { -1000 }
Output:
de
Explanation:
Substring "de" has the
maximum sum of ascii value,
including c decreases the sum value
Example 2:

Input:
W = dbfbsdbf 
N = 2
X[] = { 'b','s' }
B[] = { -100, 45  }
Output:
dbfbsdbf
Explanation:
Substring "dbfbsdbf" has the maximum
sum of ascii value.
*/




//  this question is based on  kadane alo.
class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
        int  chartoindex[100]={0};
          int currsum=0;
          string currstr="";
          string maxstr="";
          int maxsum=INT_MIN;
        //   here we create a mapping of character of array X[] to index;
          for(int i=0;i<n;i++){
              chartoindex[x[i]-'A']=i+1;
          }
          for(int i=0;i<w.length();i++){
              if(chartoindex[w[i]-'A']>0){// if mapping of character is present than we take value from arr B[];
                  int index=chartoindex[w[i]-'A']-1;
                  currsum+=b[index];
              }
              else{
                  currsum=currsum+(int)w[i];
              }
              currstr+=w[i];
              if(currsum>maxsum){
                  maxsum=currsum;
                  maxstr=currstr;
              }
              if(currsum<0){
                  currsum=0;
                  currstr="";
              }
          }
        return maxstr;   
      }
};
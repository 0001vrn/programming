/*
A C++ program to demonstrate pattern searching using naive algorithm and KMP. 

    Dated : 15/06/2017
    By    : Varun Thakur
    
Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], char txt[]) 
that prints all occurrences of pat[] in txt[]. You may assume that n > m.
*/
#include <bits/stdc++.h>
//Module Name : search 
//Input : pattern, text
//Output: all occurences of pattern in text (if any)
void search(char *pat, char *txt)
{
    int m = strlen(pat);
    int n = strlen(txt);
    int i;
    int j;
    for(i=0;i<=n-m;i++)
    {
        for(j=0;j<m;j++)
            if(txt[i+j]!=pat[j])
                break;
        
        if(j==m)
        printf("Pattern found at index : %d\n",i);
    }
}
//Time Complexity
//Best Case : O(n)
//Worst Case : (m*(n-m+1)






//Module Name : ComputeLPSArray 
//Input : pattern, length of pattern, lps[] array used to skip characters while matching.
//Output: lps[] array computed 
void ComputeLPSArray(char *pat, int m, int *lps)
{
    int len=0;
    lps[0]=0;
    
    int i=1;
    while(i<m)
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len = lps[len-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
}


//Module Name : KMPsearch 
//Input : pattern, text
//Output: all occurences of pattern in text (if any)
void KMPSearch(char *pat, char * txt)
{
    int m = strlen(pat);
    int n = strlen(txt);
    
    int lps[m];
    
    ComputeLPSArray(pat,m,lps);
    
    int i = 0;  // index for txt[]
    int j  = 0;  // index for pat[]
    while(i<n)
    {
        if(pat[j]==txt[i])
        {
            i++;
            j++;
        }
        if(j==m)
        {
            printf("Pattern found at index : %d\n",i);
            j=lps[j-1];
        }
        else if(i<n && pat[j]!=txt[i])
        {
            if(j!=0)
                j=lps[j-1];
            else
                i++;
        }
        
    }
}
//Time Complexity
//Best Case : O(n)
//Worst Case : O(n)


int main()
{
    char txt[] = "THIS IS A TEST TEXT";
    char pat[] = "TEST";
    search(pat,txt);
    
    
    //The best case occurs when the first character of the pattern is not present in text at all.
    char t[]= "AABCCAADDEE";
    char p[]= "FAA";
    search(p,t);
    //The number of comparisons in best case is O(n).
    
    //The worst case of Naive Pattern Searching occurs in following scenarios.
    //1) When all characters of the text and pattern are same.

    char tx[] = "AAAAAAAAAAAAAAAAAA";
    char pa[] = "AAAAA";
    search(pa,tx);
    //2) Worst case also occurs when only the last character is different.

    char text[] = "AAAsAAAAAAAAAAAAAAB";
    char patt[] = "AAAAB";
    search(patt,text);
    //Number of comparisons in worst case is O(m*(n-m+1)).
    
    KMPSearch(pat,txt);
    
    
    return 0;
}
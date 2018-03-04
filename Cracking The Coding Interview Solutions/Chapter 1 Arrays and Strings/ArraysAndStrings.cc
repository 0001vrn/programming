/*
1.2 Write code to reverse a C-Style String. (C-String means that “abcd” is represented as five characters, including the null character.)

1.3 (Continued)
    Remove all duplicates from a given string
    
1.4 Write a method to decide if two strings are anagrams or not.

1.5 Write a method to replace all spaces in a string with ‘%20’.

by    : Varun Thakur
Dated : 25-02-2018
*/
#include<bits/stdc++.h>
using namespace std;

void reverse(char *str);

/*
    Method 1 (Use Sorting)
    1) Sort the elements.
    2) Now in a loop, remove duplicates by comparing the current character with previous character.
    3) Remove extra characters at the end of the resultant string.
*/
char *removeDups(char *str);
char *removeDupsSorted(char *str);
/*
    Time Complexity: O(nlogn) If we use some nlogn sorting algorithm instead of quicksort.
*/


/*
    Method 2 (Use Hashing )
    1: Initialize:
        str  =  "test string" // input string 
        ip_ind =  0          //index to  keep track of location of next
                                 //character in input string 
        res_ind  =  0         //index to  keep track of location of
                                //next character in the resultant string 
        bin_hash[0..255] = {0,0, ….} // Binary hash to see if character is 
                                            //already processed or not 
    2: Do following for each character *(str + ip_ind) in input string:
                  (a) if bin_hash is not set for *(str + ip_ind) then
                       // if program sees the character *(str + ip_ind) first time
                             (i)  Set bin_hash for *(str + ip_ind)
                             (ii)  Move *(str  + ip_ind) to the resultant string.
                                  This is done in-place.
                             (iii) res_ind++
                  (b) ip_ind++
       //String obtained after this step is "te sringng" 
    3: Remove extra characters at the end of the resultant string.
      // String obtained after this step is "te sring" 

*/
char *removeDupsUsingHashing(char *str);
/*
    Time Complexity: O(n)
*/

// Solution #1: Sort the strings

bool anagram(string s, string t);
/*
    Time Complexity : O(nlogn)
*/

// Solution #2: Check if the two strings have identical counts for each unique char.

bool anagramUsingCounts(string s, string t);
/*
    Time Complexity : O(n)
*/

string ReplaceFun(string s);
/*
    Time Complexity: O(n)
*/
int main(void){

    char str[] = "ccbbadd";
    printf("%s\n",str);
    reverse(str);
    printf("%s\n",str);
    printf("%s\n",removeDupsUsingHashing(str));
    
    
    cout<< anagram("abcd", "dcba") <<'\n';
    cout<< anagram("abcd", "dcdba") <<'\n';

    cout<< anagramUsingCounts("abcd", "dcba") <<'\n';  
    cout<< anagramUsingCounts("abcd", "dcdba") <<'\n';
    
    cout << ReplaceFun("Hello, My name is Varun") << '\n';
    return 0;
}
string ReplaceFun(string str){
    int len=str.length();
    int i,spaceCount=0;
    int newLen;
    
    for(i=0;i<len;i++)
        if(str[i]==' ')
            spaceCount++;
    
    newLen = len + 2 * spaceCount;
    char *ans = new char[newLen+1];
    ans[newLen]='\0';
    
    for(i=len-1;i>=0;i--){
        if(str[i] == ' '){
            ans[newLen-1]='0';
            ans[newLen-2]='2';
            ans[newLen-3]='%';
            newLen = newLen-3;
        }
        else {
            ans[newLen - 1] = str[i];
            newLen--;
        }
    }
    
    string res = ans;
    return res;
}
bool anagramUsingCounts(string s, string t){
    
    if(s.length() != t.length()) return false;
    
    int letters[256]={0};
    int num_unique_chars=0;
    int num_completed_t=0;
    
    for(char c: s){
        if(letters[c]==0) ++num_unique_chars;
        ++letters[c];
    }    
    
    for(int i=0;i<t.length();i++){
        int c = (int)t[i];
        if(letters[c]==0)
            return false;
        --letters[c];
        if(letters[c]==0){
            ++num_completed_t;
            if(num_completed_t == num_unique_chars)
                return i == t.length()-1;
        }
    }
    
    return false;
}

bool anagram(string s, string t){
    
    sort(s.begin(), s.end());
    sort(t.begin(),t.end());
    
    return (s==t);
}

char *removeDupsUsingHashing(char *str){
    bool bin_hash[256]={0};
    int ip_idx=0;
    int res_idx=0;
    char temp;
    /* In place removal of duplicate characters*/
      while (*(str + ip_idx))
      {
        temp = *(str + ip_idx);
        if (bin_hash[temp] == 0)
        {
            bin_hash[temp] = 1;
            *(str + res_idx) = *(str + ip_idx);
            res_idx++;
        }
        ip_idx++;
      }      
 
      /* After above step string is stringiittg.
         Removing extra iittg after string*/
      *(str+res_idx) = '\0';   
 
    return str;
}
char* removeDups(char *str){
    int n = strlen(str);
    
    sort(str, str + n);
    
    return removeDupsSorted(str);
}

char *removeDupsSorted(char *str){
    int res_idx=1;
    int ip_idx=1;
    
    while(*(str + ip_idx)){
        if (*(str + ip_idx) != *(str + ip_idx - 1))
        {
            *(str + res_idx) = *(str + ip_idx);
            res_idx++;
        }
        ip_idx++;
    }
    /* After above step string is efgkorskkorss.
       Removing extra kkorss after string*/
    *(str + res_idx) = '\0';
 
    return str;
}

void reverse(char *str){
    char *end = str;
    char tmp;
    if(str){
        
        while(*end)
            end++;
        
        --end;
        
        while(str<end){
            tmp = *str;
            *str++ = *end; // *str = *end; str++;
            *end-- = tmp;  // *end = tmp; end--;
        }
    }
}
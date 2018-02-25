/*

1.1 Implement an algorithm to determine if a string has all unique characters. What if
    you can not use additional data structures?

1.3 Design an algorithm and write code to remove the duplicate characters in a string
    without using any additional buffer. NOTE: One or two additional variables are fine.
    An extra copy of the array is not.
    FOLLOW UP
    Write the test cases for this method.

by    : Varun Thakur
dated : 23-02-2018
*/
import java.util.Arrays;


public class ArraysAndStrings{
    //region Answer to 1.1
    
    //approach 1 - use extra space
    public static boolean isUniqueChars2(String str){
        
        boolean[] char_set = new boolean[256];
        
        for(int i=0;i<str.length();i++){
            
            int val = str.charAt(i);
            
            if(char_set[val])
                return false;
                
            char_set[val] = true;
        }
        
        return true;
    }
    
    //Time Complexity - O(n)
    //Space Complexity - O(n)
    //where n is the length of string
    
    //approach 2 - use bit vector
    
    public static boolean isUniqueChars(String str){
        
        int checker = 0;
        
        for(int i=0;i<str.length();i++){
            
            int val = str.charAt(i)-'a';
            
            if((checker & (1<<val)) > 0)
                return false;
                
            checker |= (1<<val); 
        }
        
        return true;
    }
    
    //Time Complexity - O(n)
    //Space Complexity - Constant
    //where n is the length of string
    
    //approach 3 - use brute force
    
    public static boolean isUniqueCharsBruteForce(String str){
        
        for(int i = 0; i < str.length(); i++) 
            for(int j = i + 1; j < str.length(); j++) 
                if(str.charAt(i) == str.charAt(j)) 
                    return false;
        
        // If no duplicate characters encountered,
        // return true
        return true;
    }
    
    //Time Complexity - O(n^2)
    //Space Complexity - No extra space
    //where n is the length of string
    
    /*
    Approach 3 - sorting
    
    If we are allowed to destroy the input string, we could sort the string in O(n log n) time
    and then linearly check the string for neighboring characters that are identical. 
    */
    
    public static boolean isUniqueCharsSorting(String str){
        
        char[] strArr = str.toCharArray();
        Arrays.sort(strArr);
        
        for(int i=0;i<strArr.length-1;i++)
            if(strArr[i]==strArr[i+1])
                return false;
                
        return true;
    }
    
    //Time Complexity - O(nlogn)
    //Space Complexity - No extra space
    //where n is the length of string
    
    //endregion
    
    //region Answer to 1.2
    
    public static void removeDuplicates(char[] str){
        if(str==null) return;
        int len = str.length;
        if(len<2)
            return;
            
        int tail = 1;
        for(int i=1;i<len;i++){
            
            int j;
            
            for(j=0;j<tail;j++)
                if(str[i]==str[j])
                    break;
                    
            if (j == tail) {
                str[tail] = str[i];
                ++tail;
            }
        }
        
        str[tail] = 0;
    }
    //Time Complexity - O(n^2)
    //Space Complexity - O(1)
    /*
    
    Test Cases:
    
    1. String does not contain any duplicates, e.g.: abcd
    2. String contains all duplicates, e.g.: aaaa
    3. Null string
    4. String with all continuous duplicates, e.g.: aaabbb
    5. String with non-contiguous duplicate, e.g.: abababa
    
    */
    
    
    public static void removeDuplicatesEff(char[] str) {
        if (str == null) return;
        int len = str.length;
        if (len < 2) return;
        boolean[] hit = new boolean[256];
        for (int i = 0; i < 256; ++i) {
            hit[i] = false;
        }
        hit[str[0]] = true;
        int tail = 1;
        for (int i = 1; i < len; ++i) {
            if (!hit[str[i]]) {
                str[tail] = str[i];
                ++tail;
                hit[str[i]] = true;
            }
        }
        str[tail] = 0;
    }
    //Time Complexity - O(n)
    //Space Complexity - Constant
    /*
    
    Test Cases:
    
    1. String does not contain any duplicates, e.g.: abcd
    2. String contains all duplicates, e.g.: aaaa
    3. Null string
    4. Empty string
    5. String with all continuous duplicates, e.g.: aaabbb
    6. String with non-contiguous duplicates, e.g.: abababa
    
    */
    
    //endregion
    public static void main(String[] args){
        
        //region sample testcases for 1.1
        System.out.println(isUniqueChars2("BACD"));
        System.out.println(isUniqueChars2("BACCD"));
        
        System.out.println(isUniqueChars("BACD"));
        System.out.println(isUniqueChars("BACCD"));
        
        System.out.println(isUniqueCharsBruteForce("BACD"));
        System.out.println(isUniqueCharsBruteForce("BACCD"));
        
        System.out.println(isUniqueCharsSorting("BACD"));
        System.out.println(isUniqueCharsSorting("BACCD"));
        //endregion
        
        //String[] strTbl = {"abcd", "aaaa", "", "aaabbb", "abababa"};
        
        char[] str= "aabcd".toCharArray();
        System.out.println(str);
        removeDuplicatesEff(str);
        System.out.println(str);
        
        
    }
}

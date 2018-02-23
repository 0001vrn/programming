/*

Implement an algorithm to determine if a string has all unique characters. What if
you can not use additional data structures?

by    : Varun Thakur
dated : 23-02-2018
*/
import java.util.Arrays;


public class ArraysAndStrings{
    
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
    
    //Time Complexity - O(n)
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
    
    
    public static void main(String[] args){
        
        System.out.println(isUniqueChars2("BACD"));
        System.out.println(isUniqueChars2("BACCD"));
        
        System.out.println(isUniqueChars("BACD"));
        System.out.println(isUniqueChars("BACCD"));
        
        System.out.println(isUniqueCharsBruteForce("BACD"));
        System.out.println(isUniqueCharsBruteForce("BACCD"));
        
        System.out.println(isUniqueCharsSorting("BACD"));
        System.out.println(isUniqueCharsSorting("BACCD"));
        
    }
}
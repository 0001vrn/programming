/*

1.1 Implement an algorithm to determine if a string has all unique characters. What if
    you can not use additional data structures?

1.3 Design an algorithm and write code to remove the duplicate characters in a string
    without using any additional buffer. NOTE: One or two additional variables are fine.
    An extra copy of the array is not.
    FOLLOW UP
    Write the test cases for this method.
    
1.4 Write a method to decide if two strings are anagrams or not.

1.5 Write a method to replace all spaces in a string with ‘%20’.

1.6 Given an image represented by an NxN matrix, where each pixel in the image is 4
    bytes, write a method to rotate the image by 90 degrees. Can you do this in place?

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
    
    //region Answer to 1.3
    
    public static String removeDuplicates(char[] str){
        if (str == null) return "";
        int len = str.length;
        if (len < 2) return new String(str);
            
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
        
        return (new String(str)).substring(0,tail);
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
    
    /*
        Method 2 (Use Hashing)
        
        hint: use LinkedHashSet to make your life easier :)
    */
    public static String removeDuplicatesEff(char[] str) {
        if (str == null) return "";
        int len = str.length;
        if (len < 2) return new String(str);
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
        return (new String(str)).substring(0,tail);
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
    
    //region Answer to 1.4
    
    //Solution #1: Sort the strings

    public static boolean anagram(String s, String t){
        
        char[] sArr = s.toCharArray();
        char[] tArr = t.toCharArray();
        
        Arrays.sort(sArr);
        Arrays.sort(tArr);
        
        return (new String(sArr).equals(new String(tArr)));
    }
    
    //Time Complexity : O(nlogn)
    
    //Solution #2: Check if the two strings have identical counts for each unique char.
    public static boolean anagramUsingCounts(String s, String t){
        
        if(s.length() != t.length()) return false;
        
        int[] letters = new int[256];
        int num_unique_chars = 0;
        int num_completed_t = 0;
        char[] s_array = s.toCharArray();
        
        for(char c : s_array){
            if(letters[c]==0) ++num_unique_chars;
            ++letters[c];
        }
        
        for(int i=0;i<t.length();i++){
            int c = (int) t.charAt(i);
            if(letters[c]==0) return false; // Found more of char c in t than in s.
            --letters[c];
            if(letters[c]==0){
                ++num_completed_t;
                if(num_completed_t == num_unique_chars){
                    // it’s a match if t has been processed completely
                    return i == t.length() - 1;
                }
            }
        }
        
        return false;
    }
    
    //Time Complexity : O(n)
    //Space Complexity : Constant
    
    //endregion
    
    //region Answer to 1.5
    
    public static String ReplaceFun(String s){
        char[] str = s.toCharArray();
        
        int len = str.length;
        int i,spaceCount=0;
        int newLen;
        
        for(i=0;i<len;i++)
            if(str[i]==' ')
                spaceCount++;
        
        newLen = len + 2 * spaceCount;
        char[] ans = new char[newLen+1];
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
        return new String(ans);
    }
    
    //endregion
    
    //region Answer to 1.6
    
    public static void  rotate(int[][] matrix, int n){
        for(int layer = 0; layer < n/2; ++layer){
            int first = layer;
            int last = n - 1 - layer;
            for(int i=first;i<last;++i){
                int offset = i - first;
                int top = matrix[first][i]; //save top
                // left -> top
                matrix[first][i] = matrix[last-offset][first];
                // bottom -> left
                matrix[last-offset][first] = matrix[last][last - offset]; 
                // right -> bottom
                matrix[last][last - offset] = matrix[i][last];
                // top -> right
                matrix[i][last] = top; // right <- saved top
            }
        }
    }
    
    public static void printMatrix(int[][] matrix, int n){
        for(int[] i:matrix){
            for(int j: i)
                System.out.print(j);
            System.out.println();
        }
    }
    
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
        
        //region sample testcases for 1.3
        
        //String[] strTbl = {"abcd", "aaaa", "", "aaabbb", "abababa"};
        
        char[] str= "aababbceecd".toCharArray();
        System.out.println(str);
        System.out.println(removeDuplicates(str));

        System.out.println(removeDuplicatesEff(str));
        
        //endregion
        
        //region sample testcases for 1.4
        System.out.println(anagram("abcd","dbca"));
        System.out.println(anagram("abcd","dbaca"));
        
        System.out.println(anagramUsingCounts("abcd","dbca"));
        System.out.println(anagramUsingCounts("abcd","dbaca"));
        //endregion
        
        //region sample testcases for 1.5
        System.out.println(ReplaceFun(" "));
        System.out.println(ReplaceFun("Hello, My name is Varun"));
        System.out.println(ReplaceFun("                        "));
        //endregion
        
        //region sample testcases for 1.6
        int mat1[][] = { {1,2},
                         {3,4}};
        int n1 = mat1.length;
        
        printMatrix(mat1,n1);
        rotate(mat1,n1);
        printMatrix(mat1,n1);
        
        int mat[][] = { {1,2,3}, 
                        {4,5,6},
                        {7,8,9}};
        
        int n = mat.length;
        printMatrix(mat,n);
        rotate(mat,n);
        printMatrix(mat,n);
        //endregion
        
    }
}

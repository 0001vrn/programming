/*
3.6 Write a program to sort a stack in ascending order. You should not make any assumptions
    about how the stack is implemented. The following are the only functions that
    should be used to write this program: push | pop | peek | isEmpty
*/
import java.util.Stack;

class StacksAndQueues{
    
    
    public static Stack<Integer> sort(Stack<Integer> s){
        Stack<Integer> r = new Stack<>();
        while(!s.empty()){
            int tmp = s.pop();
            while(!r.empty() && r.peek() > tmp){
                s.push(r.pop());
            }
            r.push(tmp);
        }
        return r;
    }
    
    /*
    Time Complexity : O(n^2)
    Space Complexity : O(n)
    */
    
    public static void main(String[] args){
        Stack<Integer> s = new Stack<>();
        s.push(1);
        s.push(3);
        s.push(4);
        s.push(2);
        System.out.println(s.toString());
        Stack<Integer> sorted = sort(s);
        System.out.println(sorted.toString());
    }
}
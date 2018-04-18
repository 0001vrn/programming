/*
3.5 Implement a MyQueue class which implements a queue using two stacks.

In this program we are making pop operation costly.
*/
import java.util.Stack;

public class MyQueue<T> {
    Stack<T> s1,s2;

    public MyQueue() {
        s1 = new Stack<T>();
        s2 = new Stack<T>();
    }

    public int size(){
        return s1.size()+s2.size();
    }
    public void add(T value){
        s1.push(value);
    }

    public T peek(){
        if(!s2.empty()) return s2.peek();
        while(!s1.empty()) s2.push(s1.pop());
        return s2.peek();
    }

    public T remove(){
        if(!s2.empty()) return s2.pop();
        while(!s1.empty()) s2.push(s1.pop());
        return s2.pop();
    }
    public boolean empty(){
        return this.size()==0;
    }
}

public class ThreeStacks{
    
    int stackSize;
    int[] buffer;
    int[] stackPointer = {0,0,0};
    
    ThreeStacks(int stackSize){
        this.stackSize = stackSize;
        buffer = new int[3*this.stackSize];
    }
    
    void push(int stackNum, int value){
        int index = stackNum * stackSize + stackPointer[stackNum] + 1;
        stackPointer[stackNum]++;
        buffer[index] = value;
    }
    
    int pop(int stackNum) {
        if(isEmpty(stackNum))
            return -1;
        
        int index = stackNum * stackSize + stackPointer[stackNum];
        stackPointer[stackNum]--;
        int value = buffer[index];
        buffer[index]=0;
        return value;
    }
    
    int peek(int stackNum) {
        int index = stackNum * stackSize + stackPointer[stackNum];
        return buffer[index];
    }

    boolean isEmpty(int stackNum) {
        return stackPointer[stackNum] == stackNum*stackSize;
    }
    
    public static void main(String[] args){
        ThreeStacks s = new ThreeStacks(100);
        
        int stackNum = 0;
        s.push(0,0);
        for(int i=0;i<5;i++)
            s.push(stackNum,i+1);
            
        while(!s.isEmpty(stackNum)){
            System.out.printf("%d %b\n",s.pop(stackNum),s.isEmpty(stackNum));
        }
    }
}
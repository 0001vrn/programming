class Test
{
    public static void main(String[] args){
        MyQueue<Integer> q = new MyQueue<Integer>();
        
        for(Integer i=0;i<10;i++)
            q.add(i+1);
        while(!q.empty()){
            System.out.println(q.remove());
        }
    }
}
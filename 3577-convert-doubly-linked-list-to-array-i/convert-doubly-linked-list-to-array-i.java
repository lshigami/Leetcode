/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
};
*/

class Solution {
    public int[] toArray(Node head) {
        List<Integer> arr= new ArrayList<>();
        for(Node current=head; current!=null;current=current.next){
            arr.add(current.val);
        }
        return arr.stream().mapToInt(i -> i).toArray(); 

    }
}
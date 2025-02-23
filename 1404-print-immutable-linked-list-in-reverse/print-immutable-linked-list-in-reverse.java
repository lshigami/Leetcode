/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * interface ImmutableListNode {
 *     public void printValue(); // print the value of this node.
 *     public ImmutableListNode getNext(); // return the next node.
 * };
 */

class Solution {
    public void printLinkedListInReverse(ImmutableListNode head) {
        ImmutableListNode run;
        ImmutableListNode end=null;
        while(head!=end){
            run=head;
            while(run.getNext()!=end){
                run=run.getNext();
            }
            run.printValue();
            end=run;
        }
    }
}
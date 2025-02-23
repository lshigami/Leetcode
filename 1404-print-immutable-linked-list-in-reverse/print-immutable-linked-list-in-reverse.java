/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * interface ImmutableListNode {
 * public void printValue(); // print the value of this node.
 * public ImmutableListNode getNext(); // return the next node.
 * };
 */

class Solution {
    public void printLinkedListInReverse(ImmutableListNode head) {
        List<ImmutableListNode> arr = new ArrayList<>();
        ImmutableListNode current = head;
        while (current.getNext() != null) {
            arr.add(current);
            current = current.getNext();
        }
        arr.add(current);
        Collections.reverse(arr);
        arr.forEach(n -> n.printValue());
    }
}
package main.java;

import java.util.*;

public class MyBinaryTree {

    public static void main(String[] args) {
        TreeNode root = null;
        root = buildTree(root);
        System.out.print("\nInorder Tree Traversal: ");
        recursiveInorder(root);
        System.out.print("\nPreorder Tree Traversal: ");
        recursivePreorder(root);
        System.out.print("\nPostorder Tree Traversal: ");
        recursivePostorder(root);
        System.out.println();
        System.out.println("BT size = " + size(root));
        System.out.println("BT height = " + height(root));
        Stack<Integer> s = new Stack<>();
        if(pathRootToLeafSum(root, 10, s)) {
            System.out.println("Path Stack: " + s);
        }
    }

    public static TreeNode buildTree(TreeNode root) {
        if ( root == null ) {
            root = new TreeNode(1);
        }
        root.setLeft(new TreeNode(2));
        root.setRight(new TreeNode(3));
        root.getLeft().setLeft(new TreeNode(4));
        root.getLeft().setRight(new TreeNode(5));
        root.getRight().setLeft(new TreeNode(6));
        root.getRight().setRight(new TreeNode(7));
        return root;
    }

    public static void recursiveInorder(TreeNode root){
        if(root != null) {
            recursiveInorder(root.getLeft());
            System.out.print(root.getVal() + " ");
            recursiveInorder(root.getRight());
        }
    }

    public static void recursivePreorder(TreeNode root){
        if(root != null) {
            recursivePreorder(root.getLeft());
            recursivePreorder(root.getRight());
            System.out.print(root.getVal() + " ");
        }
    }

    public static void recursivePostorder(TreeNode root){
        if(root != null) {
            System.out.print(root.getVal() + " ");
            recursivePostorder(root.getLeft());
            recursivePostorder(root.getRight());
        }
    }

    public static boolean searchNode(TreeNode root, TreeNode keyNode){
        if(root==null && keyNode!=null)
            return false;
        if(root==keyNode)
            return true;
        return searchNode(root.getLeft(), keyNode) || searchNode(root.getRight(), keyNode);
    }

    public static TreeNode searchValue(TreeNode root, int keyValue){
        if(root==null)
            return null;
        if(root.getVal()==keyValue)
            return root;
        else if(searchValue(root.getLeft(), keyValue)!=null)
            return searchValue(root.getLeft(), keyValue);
        else
            return searchValue(root.getRight(), keyValue);
    }

    public static List<Integer> inorderTraversal(TreeNode root) {
        ArrayList<Integer> l = new ArrayList<>();
        Stack<TreeNode> s = new Stack<>();
        if(root == null){
            return l;
        }
        while(true) {
            if (root != null) {
                s.push(root);
                root=root.getLeft();
            } else {
                if (s.isEmpty())
                    break;
                else {
                    root = s.pop();
                    l.add(root.getVal());
                    root=root.getRight();
                }
            }
        }
        return l;
    }

    public static List<Integer> preorderTraversal(TreeNode root) {
        ArrayList<Integer> l = new ArrayList<>();
        Stack<TreeNode> s = new Stack<>();
        if(root == null){
            return l;
        }
        s.push(root);
        while(!s.isEmpty()){
            TreeNode curr = s.pop();
            l.add(curr.getVal());
            if(curr.getRight() != null)
                s.push(curr.getRight());
            if(curr.getLeft() != null)
                s.push(curr.getLeft());
        }
        return l;
    }

    public static List<Integer> postorderTraversal(TreeNode root) {
        Stack<TreeNode> s1 = new Stack<>();
        Stack<TreeNode> s2 = new Stack<>();
        ArrayList<Integer> l = new ArrayList<>();
        if (root == null)
            return l;
        s1.push(root);
        while(!s1.isEmpty()) {
            TreeNode curr = s1.pop();
            s2.push(curr);
            if(curr.getLeft() != null)
                s1.push(curr.getLeft());
            if(curr.getRight() != null)
                s1.push(curr.getRight());
        }
        while(!s2.isEmpty())
            l.add(s2.pop().getVal());
        return l;
    }

    public static List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> l = new ArrayList<>();
        List<Integer> i = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        if (root == null)
            return l;
        q.add(root);
        q.add(null);
        while (true) {
            TreeNode curr = q.remove();
            if(curr==null) {
                l.add(new ArrayList<>(i)); // could also write own function to clone list
                // l.add(0, new ArrayList<>(i)); // For bottom-up level order traversal
                i.clear();
                if(q.isEmpty())
                    break;
                else
                    q.add(null);
            } else {
                i.add(curr.getVal());
                if(curr.getLeft()!=null)
                    q.add(curr.getLeft());
                if(curr.getRight()!=null)
                    q.add(curr.getRight());
            }
        }
        return l;
    }

    public static List<Integer> rightSideView(TreeNode root) {
        ArrayList<Integer> l = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        if(root==null)
            return l;
        q.add(root);
        q.add(null);
        while(true) {
            TreeNode curr = q.remove();
            if(curr==null){
                if(q.isEmpty())
                    break;
                else
                    q.add(null);
            } else {
                if(q.element()==null) {
                    l.add(curr.getVal());
                }
                if(curr.getLeft()!=null)
                    q.add(curr.getLeft());
                if(curr.getRight()!=null)
                    q.add(curr.getRight());
            }
        }
        return l;
    }

    public int findBottomLeftValue(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        int res = 0;
        TreeNode prev=null;
        q.add(root);
        q.add(null);
        while(true){
            TreeNode curr = q.remove();
            if(curr==null){
                if(q.isEmpty())
                    break;
                else
                    q.add(null);
            }
            else {
                if(prev==null)
                    res=curr.getVal();
                if(curr.getLeft()!=null)
                    q.add(curr.getLeft());
                if(curr.getRight()!=null)
                    q.add(curr.getRight());
            }
            prev=curr;
        }
        return res;
    }

    public static List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> l = new ArrayList<>();
        if(root == null)
            return l;
        List<Integer> i = new ArrayList<>();
        Stack<TreeNode> s1 = new Stack<>();
        Stack<TreeNode> s2 = new Stack<>();
        s1.push(root);
        while (!s1.isEmpty() || !s2.isEmpty()) {
            while (!s1.isEmpty()) {
                TreeNode curr = s1.pop();
                if(curr.getLeft()!=null)
                    s2.push(curr.getLeft());
                if(curr.getRight()!=null)
                    s2.push(curr.getRight());
                i.add(curr.getVal());
            }
            if(!i.isEmpty())
                l.add(new ArrayList<>(i));
                // l.add(0, new ArrayList<>(i)); // For bottom-up zigzag traversal
            i.clear();
            while (!s2.isEmpty()) {
                TreeNode curr = s2.pop();
                if(curr.getRight()!=null)
                    s1.push(curr.getRight());
                if(curr.getLeft()!=null)
                    s1.push(curr.getLeft());
                i.add(curr.getVal());
            }
            if(!i.isEmpty())
                l.add(new ArrayList<>(i));
                // l.add(0, new ArrayList<>(i)); // For bottom-up zigzag traversal
            i.clear();
        }
        return l;
    }

    public static boolean verifySameBinaryTree(TreeNode root1, TreeNode root2) {
        if(root1 == null && root2 == null)
            return true;
        else if(root1 == null || root2 == null)
            return false;
        else if(root1.getVal()==root2.getVal())
            return true;
        else
            return  (root1.getVal()==root2.getVal()) &&
                    (verifySameBinaryTree(root1.getLeft(), root2.getLeft())) &&
                    (verifySameBinaryTree(root1.getRight(), root2.getRight()));
    }

    public static int size(TreeNode root) {
        return (root==null)?0:(1+size(root.getLeft())+size(root.getRight()));
    }

    public static int height(TreeNode root) {
        return (root==null)?0:(1+Math.max(height(root.getLeft()), height(root.getRight())));
    }

    public static int diameter(TreeNode root) {
        return 0;
    }

    public static boolean hasPathSum(TreeNode root, int sum) {
        /*if(root==null && sum==0)
            return true;*/
        if(root==null)
            return false;
        if(isLeafNode(root) && root.getVal()==sum)
            return true;
        return hasPathSum(root.getLeft(), sum-root.getVal()) ||
                hasPathSum(root.getRight(), sum-root.getVal());
    }

    public static boolean isLeafNode(TreeNode node) {
        if(node !=null && node.getLeft()==null & node.getRight()==null)
            return true;
        return false;
    }

    //Q1 - https://leetcode.com/problems/path-sum/description/ 
    //Q2 - https://leetcode.com/problems/path-sum-ii/description/
    public static boolean pathRootToLeafSum(TreeNode root, int sum, Stack<Integer> s) {
        if (root != null && ((root.getLeft()==null && root.getRight() == null && root.getVal()==sum) ||
                pathRootToLeafSum(root.getLeft(), sum-root.getVal(), s) ||
                pathRootToLeafSum(root.getRight(), sum-root.getVal(), s))) {
            s.push(root.getVal());
            return true;
        }
        return false;
    }

    public static boolean isValidBST(TreeNode root) {
        if(isBST(root, Long.MIN_VALUE, Long.MAX_VALUE))
            return true;
        return false;
    }

    public static boolean isBST(TreeNode root, long min, long max) {
        if(root==null)
            return true;
        if(root.getVal()<=min || root.getVal()>=max)
            return false;
        return isBST(root.getLeft(), min, root.getVal()) &&
                isBST(root.getRight(), root.getVal(), max);
    }

    /* Assumptions for LCA Problem:
       All Node.val are unique.
       p!=q
       p and q will exist in the BST. */

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root==null || root.getVal()==p.getVal() || root.getVal()==q.getVal())
            return root;
        TreeNode lft=lowestCommonAncestor(root.getLeft(), p, q);
        TreeNode rht=lowestCommonAncestor(root.getRight(), p, q);
        if(lft!=null && rht!=null)
            return root;
        return (lft!=null)?lft:rht;
    }
    
    // https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        int p_len=preorder.length;
        int i_len=inorder.length;
        return constructTree(preorder, 0, p_len-1, inorder, 0, i_len-1);
    }
    public TreeNode constructTree(int[] preorder, int pstart, int pend, int[] inorder, int istart, int iend) {
        if(istart>iend || pstart>pend)
            return null;
        int i = 0;
        int data=preorder[pstart];
        TreeNode root = new TreeNode(data);
        for(i=istart;i<iend;i++)
            if(data==inorder[i])
                break;
        root.left=constructTree(preorder, pstart+1, pstart+i-istart, inorder, istart, i-1);
        root.right=constructTree(preorder, pstart+i-istart+1, pend, inorder, i+1, iend);
        return root;
    }
    
    // https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
    // Method 1 -->
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        
        int p_len=postorder.length;
        int i_len=inorder.length;
        return constructTree(postorder, 0, p_len-1, inorder, 0, i_len-1);
    }
    public TreeNode constructTree(int[] postorder, int pstart, int pend, int[] inorder, int istart, int iend) {
        if(istart>iend || pstart>pend)
            return null;
        int i;
        int data=postorder[pend];
        TreeNode root = new TreeNode(data);
        for(i=istart;i<iend;i++)
            if(data==inorder[i])
                break;
        root.left=constructTree(postorder, pstart, pstart+i-istart-1, inorder, istart, i-1);
        root.right=constructTree(postorder, pstart+i-istart, pend-1, inorder, i+1, iend);
        return root;
    }
    // Method 2 -->
    static int postorderIdx;
    Map<Integer,Integer> inorderMap;
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        inorderMap = new HashMap<>();
        postorderIdx = postorder.length -1;
        for(int i=0;i<inorder.length ;i++)
        {
            inorderMap.put(inorder[i],i);
        }
        
        TreeNode root = buildTreeHelper(inorder , postorder, 0 , inorder.length -1);
        return root;
    }
    private TreeNode buildTreeHelper(int[] inorder, int[] postorder, int start , int end) {
        if(start>end) return null;
        int rootValue = postorder[postorderIdx--];
        
        TreeNode root = new TreeNode(rootValue);
        
        root.right = buildTreeHelper(inorder , postorder , inorderMap.get(rootValue) +1,end);
        root.left = buildTreeHelper(inorder , postorder ,start, inorderMap.get(rootValue) -1);
        
        return root;
    }

}

// https://leetcode.com/problems/diameter-of-binary-tree/
class Solution {
    int max_result=0; //Global variable
    
    public int diameterOfBinaryTree(TreeNode root) {
        maxDepth(root);
        return max_result;
    }
    
    // This function will keep on modifying the global variable max_result
    private int maxDepth(TreeNode root) {
        if (root == null) return 0;
        
        int left = maxDepth(root.left);
        int right = maxDepth(root.right);
        
        //Global variable
        max_result = Math.max(max_result, left + right);
        
        return Math.max(left, right) + 1;
    }
}

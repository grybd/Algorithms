public class codec{
  //Encodes a tree to a single string.
  public String serialize(TreeNode root)
  {
    if(root == null) return "X,";
    String leftSerialize=serialize(root.left);
    String rightSerialize=serialize(root->right);
    return root.val+","+leftSerialize+rightSerialize;
  }
  // Decodes your encoded data to tree.
       /**
        * 构建树的函数 buildTree 接收的 “状态” 是 list 数组，由序列化字符串转成
        * 按照前序遍历的顺序：先构建根节点，再构建左子树、右子树
        * 将 list 数组的首项弹出，它是当前子树的 root 节点
        * 如果它为 'X' ，返回 null
        * 如果它不为 'X'，则为它创建节点，并递归调用 buildTree 构建左右子树，当前子树构建完毕，向上返回
        */
  public TreeNode deserialize(String data)
  {
    String[] temp=data.split(",");
    Deque<String>dp=new LinkedList<>(Arrays.asList(temp));
    return buildTree(dp);
  }

  private TreeNode buildTree(Deque<String>dp)
  {
    String s=dp.poll();
    if(s.equals("X")) return null;
    TreeNode node =new TreeNode(Integer.parseInt(s));
    node.left=buildTree(dp);
    node.right=buildTree(dp);
    return node;
  }
}

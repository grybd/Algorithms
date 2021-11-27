public class Codec{
  //Encodes a tree to a single string.
  public String serialize(TreeNode root)
  {
    if(root==null)
    {
      return"";
    }
    StringBuilder sb=new StringBuilder();
    Queue<TreeNode> queue = new LinkedList<>();
    queue.offer(root);
    while(!queue.isEmpty())
    {
      TreeNode node=queue.poll();
      if(node==null)
      {
        sb.append("X,");
      }
      else{
        sb.append(node.val+",");
        queue.offer(node.left);
        queue.offer(node.right);
      }
    }
    return sb.toString();
  }

  //Decodes your encoded data to tree.
  public TreeNode deserialize(String data)
  {
    if(data=="")
    {
      return null;
    }
    Queue<String>nodes=new ArrayList<>(Arrays.asList(data.split(",")));
    TreeNode root=new TreeNode(Integer.parseInt(nodes.poll()));
    Queue<TreeNode>queue = new ArrayDeque<>();
    queue.offer(root);
    while(!queue.isEmpty())
    {
      TreeNode node =queue.poll();
      String left=nodes.poll();
      String right = nodes.poll();
      if(!left.equals("X"))
      {
        node.left=new TreeNode(Integer.parseInt(left));
        queue.add(node.left);
      }
      if(!right.equals("X"))
      {
        node.right=new TreeNode(Integer.parseInt(right));
        queue.add(node.right);
      }
    }
    return root;
  }
};

   public TreeNode cyclicShiftTree (TreeNode root, int k) {
        // write code here
        List<TreeNode> up = new ArrayList<>();
        up.add(root);
        while (!up.isEmpty()) {
            List<TreeNode> down = new ArrayList<>();
            for (int i = 0; i < up.size(); i++) {
                TreeNode node = up.get(i);
                down.add(node.left);
                down.add(node.right);
            }
            int index = 0;
            for (int i = 0; i < up.size(); i++) {
                TreeNode node = up.get(i);
                node.left = down.get((index++ - k % down.size() + down.size()) % down.size());
                node.right = down.get((index++ - k % down.size() + down.size()) % down.size());
            }
            up.clear();
            for (int i = 0; i < down.size(); i++) {
                if (down.get(i) != null) {
                    up.add(down.get(i));
                }
            }
        }
        return root;
    }

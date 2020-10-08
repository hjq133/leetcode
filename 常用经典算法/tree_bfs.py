# 树的bfs


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


# queue = [1, 2, 3, 4]
# queue.pop()
# queue.append(2)
# print(queue)
def bfs(root: TreeNode):
    queue = [root]
    while len(queue):
        cur = queue.pop(0)  # pop 的时候进行访问visit
        print(cur.val)
        if cur.left is not None:
            queue.append(cur.left)
        if cur.right is not None:
            queue.append(cur.right)


tree = TreeNode(0)
tree.left = TreeNode(1)
tree.right = TreeNode(2)
tree.left.left = TreeNode(3)
tree.left.right = TreeNode(4)
tree.right.right = TreeNode(5)
bfs(tree)

class TreeNode(object):
  """ applicable to all tree nodes including root node """
  def __init__(self, value, left=None, right=None,root=False):
    self.value = value 
    TreeNode.check(left)
    TreeNode.check(right)
    self.left = left
    self.right = right
    self.root = root

  def inorder(self):
    s = list()
    if not self.left:
      s.append('')  
    else:
      s.append(self.left.inorder())

    s.append(str(self.value))

    if not self.right:
      s.append('')
    else:
      s.append(self.right.inorder())

    return ' '.join(s).strip()

  # returns True if success, False otherwise  
  def insert( self, new_value ):
    # TODO ?? what happens if we are inserting strings
    if not new_value and new_value != 0:
      return False

    if new_value == self.value:
      return False

    # need to find the right location in terms of binary tree ordering
    if new_value < self.value:
      if not self.left:
        self.left = TreeNode(new_value) 
        return True
      else:
        return self.left.insert( new_value )
    elif new_value > self.value:
      if not self.right:
        self.right = TreeNode(new_value)
        return True
      return self.right.insert( new_value )

    return False

  @staticmethod    
  def check(node):
    if not node:
      return
    if not isinstance(node, TreeNode):
      raise TypeError('only instances of TreeNode are allowed')      

  def __repr__(self):
    return '(' + repr(self.left) + ',' + \
      str(self.value) + ',' + repr(self.right) + ')'

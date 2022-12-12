class Node:
    
    def __init__(self,data: int):
        self.data = data
        self.left = None
        self.right = None
    
def insert_elements(root: Node, data: int) -> Node:
    if root is None:
        return Node(data)
    if data > root.data:
        root.right = insert_elements(root.right, data)
    elif data < root.data:
        root.left = insert_elements(root.left, data)
    return root

def inorder_traversal(root: Node) -> None:
    if root is not None:
        inorder_traversal(root.left)
        print(root.data, end = " ")
        inorder_traversal(root.right)
        
def postorder_traversal(root: Node) -> None:
    if root is not None:
        postorder_traversal(root.left)
        postorder_traversal(root.right)
        print(root.data, end = " ")

def preorder_traversal(root: Node) -> None:
    if root is not None:
        print(root.data, end = " ")
        preorder_traversal(root.left)
        preorder_traversal(root.right)
        
def min_value(root: Node):
    temp = root
    while(temp.left is not None):
        temp = temp.left
    return temp 

def max_value(root: Node):
    temp = root
    while(temp.right is not None):
        temp = temp.right
    return temp 

def delete_node(root: Node, data: int) -> Node:
    if root is None:
        return root

    if data < root.data:
        root.left = delete_node(root.left, data)
    elif(data > root.data):
        root.right = delete_node(root.right, data)
    else:
        if root.left is None:
            temp = root.right
            root = None
            return temp

        elif root.right is None:
            temp = root.left
            root = None
            return temp

        temp = min_value(root.right)
        root.data = temp.data
        root.right = delete_node(root.right, temp.data)

    return root

    
    
def main(): 
    root = Node(10)
    root = insert_elements(root, 5)
    root = insert_elements(root, 20)
    root = insert_elements(root, 10)
    root = insert_elements(root, 15)
    root = insert_elements(root, 55)
    inorder_traversal(root)
    root = delete_node(root, 10)
    inorder_traversal(root)
    preorder_traversal(root)
    postorder_traversal(root)
    
    
if __name__ == "__main__":
    main()
    
                
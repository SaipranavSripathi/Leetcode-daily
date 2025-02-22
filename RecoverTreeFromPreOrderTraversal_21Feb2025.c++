class Solution {
    public:
        TreeNode* recoverFromPreorder(string traversal) {
            stack<TreeNode*> stack;
            int index = 0;
            int n = traversal.size();
    
            while (index < n) {
                // Count the number of dashes
                int depth = 0;
                while (index < n && traversal[index] == '-') {
                    depth++;
                    index++;
                }
    
                // Extract the node value
                int value = 0;
                while (index < n && isdigit(traversal[index])) {
                    value = value * 10 + (traversal[index] - '0');
                    index++;
                }
    
                // Create the current node
                TreeNode* node = new TreeNode(value);
    
                // Adjust the stack to the correct depth
                while (stack.size() > depth) {
                    stack.pop();
                }
    
                // Attach the node to the parent
                if (!stack.empty()) {
                    if (stack.top()->left == nullptr) {
                        stack.top()->left = node;
                    } else {
                        stack.top()->right = node;
                    }
                }
    
                // Push the current node onto the stack
                stack.push(node);
            }
    
            // The root is the first node in the stack
            while (stack.size() > 1) {
                stack.pop();
            }
    
            return stack.top();
        }
    };
// #include <iostream>
// #include <vector>

// void merge(std::vector<int>& arr, int left, int mid, int right) {
//     int n1 = mid - left + 1;
//     int n2 = right - mid;

//     std::vector<int> leftArray(n1);
//     std::vector<int> rightArray(n2);

//     // Copy data to temporary arrays leftArray[] and rightArray[]
//     for (int i = 0; i < n1; i++)
//         leftArray[i] = arr[left + i];
//     for (int j = 0; j < n2; j++)
//         rightArray[j] = arr[mid + 1 + j];

//     // Merge the temporary arrays back into arr[left..right]
//     int i = 0; // Initial index of first subarray
//     int j = 0; // Initial index of second subarray
//     int k = left; // Initial index of merged subarray

//     while (i < n1 && j < n2) {
//         if (leftArray[i] <= rightArray[j]) {
//             arr[k] = leftArray[i];
//             i++;
//         } else {
//             arr[k] = rightArray[j];
//             j++;
//         }
//         k++;
//     }

//     // Copy the remaining elements of leftArray[], if there are any
//     while (i < n1) {
//         arr[k] = leftArray[i];
//         i++;
//         k++;
//     }

//     // Copy the remaining elements of rightArray[], if there are any
//     while (j < n2) {
//         arr[k] = rightArray[j];
//         j++;
//         k++;
//     }
// }

// void mergeSort(std::vector<int>& arr, int left, int right) {
//     if (left < right) {
//         // Same as (left+right)/2, but avoids overflow for large left and right
//         int mid = left + (right - left) / 2;

//         // Sort first and second halves
//         mergeSort(arr, left, mid);
//         mergeSort(arr, mid + 1, right);

//         // Merge the sorted halves
//         merge(arr, left, mid, right);
//     }
// }

// int main() {
//     std::vector<int> arr = {12, 11, 13, 5, 6, 7};
//     int n = arr.size();

//     std::cout << "Original array: ";
//     for (int i = 0; i < n; i++)
//         std::cout << arr[i] << " ";
//     std::cout << std::endl;

//     // Perform merge sort
//     mergeSort(arr, 0, n - 1);

//     std::cout << "Sorted array: ";
//     for (int i = 0; i < n; i++)
//         std::cout << arr[i] << " ";
//     std::cout << std::endl;

//     return 0;
// }


// #include <iostream>
// #include <vector>

// int partition(std::vector<int>& arr, int low, int high) {
//     int pivot = arr[high];  // Choose the rightmost element as the pivot
//     int i = low - 1;        // Index of smaller element

//     for (int j = low; j < high; j++) {
//         // If the current element is smaller than or equal to the pivot
//         if (arr[j] <= pivot) {
//             i++;
//             std::swap(arr[i], arr[j]);
//         }
//     }

//     // Swap the pivot element with the element at (i + 1)
//     std::swap(arr[i + 1], arr[high]);
//     return i + 1;
// }

// void quickSort(std::vector<int>& arr, int low, int high) {
//     if (low < high) {
//         // Partitioning index is the index of the pivot after partition
//         int partitionIndex = partition(arr, low, high);

//         // Recursively sort elements before and after the partition index
//         quickSort(arr, low, partitionIndex - 1);
//         quickSort(arr, partitionIndex + 1, high);
//     }
// }

// int main() {
//     std::vector<int> arr = {12, 11, 13, 5, 6, 7};
//     int n = arr.size();

//     std::cout << "Original array: ";
//     for (int i = 0; i < n; i++)
//         std::cout << arr[i] << " ";
//     std::cout << std::endl;

//     // Perform quick sort
//     quickSort(arr, 0, n - 1);

//     std::cout << "Sorted array: ";
//     for (int i = 0; i < n; i++)
//         std::cout << arr[i] << " ";
//     std::cout << std::endl;

//     return 0;
// }


// #include <iostream>
// #include <algorithm>

// class AVLNode {
// public:
//     int key;
//     AVLNode* left;
//     AVLNode* right;
//     int height;

//     AVLNode(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
// };

// class AVLTree {
// private:
//     AVLNode* root;

//     int getHeight(AVLNode* node) {
//         if (node == nullptr)
//             return 0;
//         return node->height;
//     }

//     int getBalanceFactor(AVLNode* node) {
//         if (node == nullptr)
//             return 0;
//         return getHeight(node->left) - getHeight(node->right);
//     }

//     void updateHeight(AVLNode* node) {
//         if (node != nullptr) {
//             node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
//         }
//     }

//     AVLNode* rotateRight(AVLNode* y) {
//         AVLNode* x = y->left;
//         AVLNode* T2 = x->right;

//         // Perform rotation
//         x->right = y;
//         y->left = T2;

//         // Update heights
//         updateHeight(y);
//         updateHeight(x);

//         // Return new root
//         return x;
//     }

//     AVLNode* rotateLeft(AVLNode* x) {
//         AVLNode* y = x->right;
//         AVLNode* T2 = y->left;

//         // Perform rotation
//         y->left = x;
//         x->right = T2;

//         // Update heights
//         updateHeight(x);
//         updateHeight(y);

//         // Return new root
//         return y;
//     }

//     AVLNode* balance(AVLNode* node) {
//         // Update height of current node
//         updateHeight(node);

//         // Get balance factor to check for unbalance
//         int balanceFactor = getBalanceFactor(node);

//         // Left Heavy
//         if (balanceFactor > 1) {
//             // Left-Right Case
//             if (getBalanceFactor(node->left) < 0) {
//                 node->left = rotateLeft(node->left);
//             }
//             return rotateRight(node);
//         }
//         // Right Heavy
//         if (balanceFactor < -1) {
//             // Right-Left Case
//             if (getBalanceFactor(node->right) > 0) {
//                 node->right = rotateRight(node->right);
//             }
//             return rotateLeft(node);
//         }

//         // Tree is already balanced
//         return node;
//     }

//     AVLNode* insertNode(AVLNode* node, int key) {
//         // Standard BST Insertion
//         if (node == nullptr)
//             return new AVLNode(key);

//         if (key < node->key)
//             node->left = insertNode(node->left, key);
//         else if (key > node->key)
//             node->right = insertNode(node->right, key);
//         else
//             return node; // Duplicate keys are not allowed

//         // Update height of current node
//         updateHeight(node);

//         // Rebalance the tree
//         return balance(node);
//     }

//     AVLNode* findMinValueNode(AVLNode* node) {
//         AVLNode* current = node;
//         while (current->left != nullptr)
//             current = current->left;
//         return current;
//     }

//     AVLNode* deleteNode(AVLNode* root, int key) {
//         if (root == nullptr)
//             return root;

//         if (key < root->key)
//             root->left = deleteNode(root->left, key);
//         else if (key > root->key)
//             root->right = deleteNode(root->right, key);
//         else {
//             // Node with only one child or no child
//             if (root->left == nullptr || root->right == nullptr) {
//                 AVLNode* temp = root->left ? root->left : root->right;

//                 // No child case
//                 if (temp == nullptr) {
//                     temp = root;
//                     root = nullptr;
//                 } else  // One child case
//                     *root = *temp;  // Copy the contents of the non-empty child

//                 delete temp;
//             } else {
//                 // Node with two children
//                 AVLNode* temp = findMinValueNode(root->right);

//                 // Copy the inorder successor's data to this node
//                 root->key = temp->key;

//                 // Delete the inorder successor
//                 root->right = deleteNode(root->right, temp->key);
//             }
//         }

//         // If the tree had only one node, then return
//         if (root == nullptr)
//             return root;

//         // Update height of current node
//         updateHeight(root);

//         // Rebalance the tree
//         return balance(root);
//     }

// public:
//     AVLTree() : root(nullptr) {}

//     void insert(int key) {
//         root = insertNode(root, key);
//     }

//     void remove(int key) {
//         root = deleteNode(root, key);
//     }

//     void inorderTraversal(AVLNode* node) {
//         if (node != nullptr) {
//             inorderTraversal(node->left);
//             std::cout << node->key << " ";
//             inorderTraversal(node->right);
//         }
//     }

//     void printInorder() {
//         std::cout << "Inorder Traversal: ";
//         inorderTraversal(root);
//         std::cout << std::endl;
//     }
// };

// int main() {
//     AVLTree avl;

//     avl.insert(10);
//     avl.insert(20);
//     avl.insert(30);
//     avl.insert(40);
//     avl.insert(50);
//     avl.insert(25);

//     avl.printInorder();

//     avl.remove(30);

//     avl.printInorder();

//     return 0;
// }


// #include <iostream>

// class TreeNode {
// public:
//     int key;
//     TreeNode* left;
//     TreeNode* right;

//     TreeNode(int k) : key(k), left(nullptr), right(nullptr) {}
// };

// class BinarySearchTree {
// private:
//     TreeNode* root;

//     TreeNode* insertNode(TreeNode* node, int key) {
//         // If the tree is empty, create a new node
//         if (node == nullptr)
//             return new TreeNode(key);

//         // Recursively insert the key
//         if (key < node->key)
//             node->left = insertNode(node->left, key);
//         else if (key > node->key)
//             node->right = insertNode(node->right, key);

//         return node;
//     }

//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if (root == nullptr)
//             return root;

//         // Recursively search for the key to delete
//         if (key < root->key)
//             root->left = deleteNode(root->left, key);
//         else if (key > root->key)
//             root->right = deleteNode(root->right, key);
//         else {
//             // Node with only one child or no child
//             if (root->left == nullptr) {
//                 TreeNode* temp = root->right;
//                 delete root;
//                 return temp;
//             } else if (root->right == nullptr) {
//                 TreeNode* temp = root->left;
//                 delete root;
//                 return temp;
//             }

//             // Node with two children: Get the inorder successor (smallest in the right subtree)
//             TreeNode* temp = minValueNode(root->right);

//             // Copy the inorder successor's content to this node
//             root->key = temp->key;

//             // Delete the inorder successor
//             root->right = deleteNode(root->right, temp->key);
//         }
//         return root;
//     }

//     TreeNode* minValueNode(TreeNode* node) {
//         TreeNode* current = node;
//         // Loop down to find the leftmost leaf
//         while (current->left != nullptr)
//             current = current->left;
//         return current;
//     }

//     TreeNode* searchNode(TreeNode* node, int key) {
//         // Base Cases: root is null or key is present at root
//         if (node == nullptr || node->key == key)
//             return node;

//         // Key is greater than root's key
//         if (key > node->key)
//             return searchNode(node->right, key);

//         // Key is smaller than root's key
//         return searchNode(node->left, key);
//     }

//     void inorderTraversal(TreeNode* node) {
//         if (node != nullptr) {
//             inorderTraversal(node->left);
//             std::cout << node->key << " ";
//             inorderTraversal(node->right);
//         }
//     }

// public:
//     BinarySearchTree() : root(nullptr) {}

//     void insert(int key) {
//         root = insertNode(root, key);
//     }

//     void remove(int key) {
//         root = deleteNode(root, key);
//     }

//     bool search(int key) {
//         return searchNode(root, key) != nullptr;
//     }

//     void printInorder() {
//         std::cout << "Inorder Traversal: ";
//         inorderTraversal(root);
//         std::cout << std::endl;
//     }
// };

// int main() {
//     BinarySearchTree bst;

//     bst.insert(50);
//     bst.insert(30);
//     bst.insert(70);
//     bst.insert(20);
//     bst.insert(40);
//     bst.insert(60);
//     bst.insert(80);

//     bst.printInorder();

//     if (bst.search(40))
//         std::cout << "Key 40 found in the BST." << std::endl;
//     else
//         std::cout << "Key 40 not found in the BST." << std::endl;

//     bst.remove(30);

//     bst.printInorder();

//     return 0;
// }


// #include <iostream>
// #include <unordered_map>
// #include <vector>
// #include <queue>
// #include <stack>

// class Graph {
// private:
//     std::unordered_map<int, std::vector<int>> adjacencyList;

// public:
//     void addEdge(int u, int v) {
//         adjacencyList[u].push_back(v);
//         adjacencyList[v].push_back(u);
//     }

//     void printGraph() {
//         for (const auto &entry : adjacencyList) {
//             int vertex = entry.first;
//             const std::vector<int> &neighbors = entry.second;

//             std::cout << vertex << ": ";
//             for (int neighbor : neighbors) {
//                 std::cout << neighbor << " ";
//             }
//             std::cout << std::endl;
//         }
//     }

//     void dfs(int startVertex) {
//         std::unordered_map<int, bool> visited;
//         std::stack<int> stack;

//         visited[startVertex] = true;
//         stack.push(startVertex);

//         std::cout << "DFS starting from vertex " << startVertex << ": ";
//         while (!stack.empty()) {
//             int currentVertex = stack.top();
//             stack.pop();

//             std::cout << currentVertex << " ";

//             for (int neighbor : adjacencyList[currentVertex]) {
//                 if (!visited[neighbor]) {
//                     visited[neighbor] = true;
//                     stack.push(neighbor);
//                 }
//             }
//         }

//         std::cout << std::endl;
//     }

//     void bfs(int startVertex) {
//         std::unordered_map<int, bool> visited;
//         std::queue<int> q;

//         visited[startVertex] = true;
//         q.push(startVertex);

//         std::cout << "BFS starting from vertex " << startVertex << ": ";
//         while (!q.empty()) {
//             int currentVertex = q.front();
//             q.pop();

//             std::cout << currentVertex << " ";

//             for (int neighbor : adjacencyList[currentVertex]) {
//                 if (!visited[neighbor]) {
//                     visited[neighbor] = true;
//                     q.push(neighbor);
//                 }
//             }
//         }

//         std::cout << std::endl;
//     }
// };

// int main() {
//     Graph graph;

//     graph.addEdge(1, 2);
//     graph.addEdge(1, 3);
//     graph.addEdge(2, 3);
//     graph.addEdge(3, 4);
//     graph.addEdge(4, 1);

//     std::cout << "Graph Representation:" << std::endl;
//     graph.printGraph();

//     graph.dfs(1);
//     graph.bfs(1);

//     return 0;
// }


// #include <iostream>
// #include <vector>

// void insertionSort(std::vector<int>& arr) {
//     int n = arr.size();

//     for (int i = 1; i < n; i++) {
//         int key = arr[i];
//         int j = i - 1;

//         // Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position
//         while (j >= 0 && arr[j] > key) {
//             arr[j + 1] = arr[j];
//             j--;
//         }

//         arr[j + 1] = key;
//     }
// }

// int main() {
//     std::vector<int> arr = {12, 11, 13, 5, 6};

//     std::cout << "Original array: ";
//     for (int num : arr) {
//         std::cout << num << " ";
//     }
//     std::cout << std::endl;

//     // Perform insertion sort
//     insertionSort(arr);

//     std::cout << "Sorted array: ";
//     for (int num : arr) {
//         std::cout << num << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }


// #include <iostream>
// #include <vector>

// void selectionSort(std::vector<int>& arr) {
//     int n = arr.size();

//     for (int i = 0; i < n - 1; i++) {
//         // Find the minimum element in the unsorted part of the array
//         int minIndex = i;
//         for (int j = i + 1; j < n; j++) {
//             if (arr[j] < arr[minIndex]) {
//                 minIndex = j;
//             }
//         }

//         // Swap the found minimum element with the first element
//         std::swap(arr[i], arr[minIndex]);
//     }
// }

// int main() {
//     std::vector<int> arr = {64, 25, 12, 22, 11};

//     std::cout << "Original array: ";
//     for (int num : arr) {
//         std::cout << num << " ";
//     }
//     std::cout << std::endl;

//     // Perform selection sort
//     selectionSort(arr);

//     std::cout << "Sorted array: ";
//     for (int num : arr) {
//         std::cout << num << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }


// #include <iostream>
// #include <vector>
// #include <list>

// class HashTable {
// private:
//     std::vector<std::list<int>> table;
//     int size;

// public:
//     HashTable(int tableSize) : size(tableSize) {
//         table.resize(size);
//     }

//     // Hash function to map values to index
//     int hash(int key) {
//         return key % size;
//     }

//     // Insert a key into the hash table
//     void insert(int key) {
//         int index = hash(key);
//         table[index].push_back(key);
//     }

//     // Search for a key in the hash table
//     bool search(int key) {
//         int index = hash(key);
//         for (int value : table[index]) {
//             if (value == key) {
//                 return true;
//             }
//         }
//         return false;
//     }

//     // Print the hash table
//     void printTable() {
//         for (int i = 0; i < size; ++i) {
//             std::cout << "Bucket " << i << ": ";
//             for (int value : table[i]) {
//                 std::cout << value << " ";
//             }
//             std::cout << std::endl;
//         }
//     }
// };

// int main() {
//     HashTable hashTable(10);

//     hashTable.insert(12);
//     hashTable.insert(22);
//     hashTable.insert(42);
//     hashTable.insert(7);

//     std::cout << "Hash Table:" << std::endl;
//     hashTable.printTable();

//     int searchKey = 22;
//     if (hashTable.search(searchKey)) {
//         std::cout << "Key " << searchKey << " found in the hash table." << std::endl;
//     } else {
//         std::cout << "Key " << searchKey << " not found in the hash table." << std::endl;
//     }

//     return 0;
// }


// #include <iostream>
// #include <vector>
// #include <list>

// class HashTable {
// private:
//     std::vector<std::list<int>> table;
//     int size;

// public:
//     HashTable(int tableSize) : size(tableSize) {
//         table.resize(size);
//     }

//     // Hash function to map values to index
//     int hash(int key) {
//         return key % size;
//     }

//     // Quadratic probing function to calculate the next index
//     int quadraticProbing(int index, int attempt) {
//         return (index + attempt * attempt) % size;
//     }

//     // Insert a key into the hash table with quadratic probing
//     void insert(int key) {
//         int index = hash(key);
//         int attempt = 0;

//         while (!table[index].empty()) {
//             // Collision occurred, use quadratic probing
//             attempt++;
//             index = quadraticProbing(index, attempt);
//         }

//         table[index].push_back(key);
//     }

//     // Search for a key in the hash table
//     bool search(int key) {
//         int index = hash(key);
//         int attempt = 0;

//         while (!table[index].empty()) {
//             for (int value : table[index]) {
//                 if (value == key) {
//                     return true;
//                 }
//             }

//             // Collision occurred, use quadratic probing
//             attempt++;
//             index = quadraticProbing(index, attempt);
//         }

//         return false;
//     }

//     // Print the hash table
//     void printTable() {
//         for (int i = 0; i < size; ++i) {
//             std::cout << "Bucket " << i << ": ";
//             for (int value : table[i]) {
//                 std::cout << value << " ";
//             }
//             std::cout << std::endl;
//         }
//     }
// };

// int main() {
//     HashTable hashTable(10);

//     hashTable.insert(12);
//     hashTable.insert(22);
//     hashTable.insert(42);
//     hashTable.insert(7);

//     std::cout << "Hash Table:" << std::endl;
//     hashTable.printTable();

//     int searchKey = 22;
//     if (hashTable.search(searchKey)) {
//         std::cout << "Key " << searchKey << " found in the hash table." << std::endl;
//     } else {
//         std::cout << "Key " << searchKey << " not found in the hash table." << std::endl;
//     }

//     return 0;
// }

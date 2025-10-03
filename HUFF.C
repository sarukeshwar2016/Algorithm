// Define node structure
struct Node {
    char character;
    int frequency;
    Node *left, *right;
};

// Function to build Huffman Tree
function HuffmanCoding(input_string):
    int freq[256] = {0}

    // Step 1: Count frequencies
    for i = 0 to length of input_string - 1:
        freq[input_string[i]]++

    // Step 2: Create min heap and insert leaf nodes
    MinHeap heap = createMinHeap()
    for i = 0 to 255:
        if freq[i] > 0:
            Node* newNode = createNode(char(i), freq[i])
            insert(heap, newNode)

    // Step 3: Build the Huffman Tree
    while heap.size > 1:
        Node* left = extractMin(heap)
        Node* right = extractMin(heap)

        Node* merged = createNode('\0', left.frequency + right.frequency)
        merged.left = left
        merged.right = right

        insert(heap, merged)

    Node* root = extractMin(heap)

    // Step 4: Generate codes
    string codes[256]
    generateCodes(root, "", codes)

    // Step 5: Encode
    for i = 0 to length of input_string - 1:
        print codes[input_string[i]]

    // Step 6: (Optional) Decode
    decode(encoded_string, root)


// Recursive function to generate Huffman codes
function generateCodes(Node* node, string currentCode, string codes[256]):
    if node is leaf:
        codes[node.character] = currentCode
    else:
        generateCodes(node.left, currentCode + "0", codes)
        generateCodes(node.right, currentCode + "1", codes)


// Function to decode encoded string
function decode(string encoded, Node* root):
    Node* current = root
    for i = 0 to length of encoded - 1:
        if encoded[i] == '0':
            current = current.left
        else:
            current = current.right

        if current is leaf:
            print current.character
            current = root

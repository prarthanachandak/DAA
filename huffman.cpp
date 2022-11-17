// C++(STL) program for Huffman Coding with STL
#include <bits/stdc++.h>
using namespace std;

// A Huffman tree node
struct MinHeapNode {

	char data;
	unsigned freq;

	MinHeapNode *left, *right;

	MinHeapNode(char data, unsigned freq)
	{

		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};

// For comparison of
// two heap nodes (needed in min heap)
struct compare {

	bool operator()(MinHeapNode* l, MinHeapNode* r)

	{
		return (l->freq > r->freq);
	}
};

// Prints huffman codes from
// the root of Huffman Tree.
void printCodes(struct MinHeapNode* root, string str)
{

	if (!root)
		return;

	if (root->data != '$')
		cout << root->data << ": " << str << "\n";

	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

void HuffmanCodes(char data[], int freq[], int size)
{
	struct MinHeapNode *left, *right, *top;

	// Create a min heap & inserts all characters of data[]
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

	for (int i = 0; i < size; ++i)
		minHeap.push(new MinHeapNode(data[i], freq[i]));

	// Iterate while size of heap doesn't become 1
	while (minHeap.size() != 1) {

		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();

		top = new MinHeapNode('$', left->freq + right->freq);

		top->left = left;
		top->right = right;

		minHeap.push(top);
	}

	// Print Huffman codes using
	// the Huffman tree built above
	printCodes(minHeap.top(), "");
}

// Driver Code
int main()
{
	

	int size;
	cin>>size;

	char arr[size];
	int freq[size];

	for(int i=0; i<size; i++){
		cout<<"enter character and frequency\n";
		cin>>arr[i]>>freq[i];
	}

	HuffmanCodes(arr, freq, size);

	return 0;
}

// Huffman coding is a lossless data compression algorithm. The idea is to assign variable-length codes to input characters, lengths of the assigned codes are based on the frequencies of corresponding characters. The most frequent character gets the smallest code and the least frequent character gets the largest code.
//Time complexity: O(nlogn) where n is the number of unique characters. If there are n nodes, extractMin() is called 2*(n – 1) times. extractMin() takes O(logn) time as it calls minHeapify(). So, overall complexity is O(nlogn).
// If the input array is sorted, there exists a linear time algorithm. We will soon be discussing in our next post.


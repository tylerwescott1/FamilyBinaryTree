#include <vector>
#include <cstdlib> 

class familyTree
{
private:
	struct binTreeNode
	{
		int wealth;
		binTreeNode * left;
		binTreeNode * right;

		binTreeNode() : wealth(0), left(nullptr), right(nullptr) {}
		binTreeNode(int w) : wealth(w), left(nullptr), right(nullptr) {}
	};

	binTreeNode * root;

	void deallocateTree(binTreeNode*);
	void updateInheritance(binTreeNode*);
	void outputTree(binTreeNode*);
	binTreeNode* buildTree(const std::vector<int>&, std::size_t);

public:
	familyTree() : root(nullptr) {}
	familyTree(const std::vector<int>&);
	~familyTree();

	void updateInheritance();
	void outputTree();
};
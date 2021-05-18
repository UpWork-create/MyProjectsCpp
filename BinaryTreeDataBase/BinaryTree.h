//---------------------------------------------------------------------------

#ifndef BinaryTreeH
#define BinaryTreeH
#include <vcl.h>
#include "Unit13.h"
class BinaryTree
{
public:
	class TNode
	{
	public:
		TNode(int Key,String Surname)
		{
			this->Key = Key;
			this->Surname = Surname;
			this->right = nullptr;//Данный нод является листом (нет потомков)
			this->left = nullptr;
		}
		TNode(TNode&other)
		{
			this->Key = other.Key;
			this->Surname = other.Surname;
			this->right = other.right;
			this->left = other.left;
		}
		int Key;
		String Surname;
		TNode* left;
		TNode* right;
	};
	~BinaryTree()
	{
		DestroyNode(Root);
	}
	BinaryTree()
	{
		Root = nullptr;
	}

	void DestroyNode(TNode* node);
	void AddItem(int x,String Surname);
	void DeleteItem(int x);
	void PrintNLR(TForm*Form13,TMemo*Memo1);
	void PrintLNR(TForm*Form13,TMemo*Memo1);
	void PrintLRN(TForm*Form13,TMemo*Memo1);
	String SearchFor(int x);
private:
	void Insert(int x,String Surname,TNode*&node);
	void Delete(int x, TNode*& node);
	void NLR(TNode*& node,TMemo *Memo1,TForm*Form13);
	void LNR(TNode*& node,TMemo *Memo1,TForm*Form13);
	void LRN(TNode*& node,TMemo *Memo1,TForm*Form13);
	String Search(TNode* node,int x);
	bool ElementExist(TNode* node, int x);
	TNode* Root;
};

//---------------------------------------------------------------------------
#endif

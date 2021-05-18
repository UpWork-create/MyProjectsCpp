//---------------------------------------------------------------------------

#pragma hdrstop

#include "BinaryTree.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void BinaryTree::DestroyNode(TNode*node)
{
	if (node!=nullptr)//Проверка на существование нода
	{
		DestroyNode(node->left);
		DestroyNode(node->right);
		delete node;
	}
}

void BinaryTree::AddItem(int x,String Surname)
{
	Insert(x,Surname, Root);
}

void BinaryTree::DeleteItem(int x)
{
	Delete(x,Root);
}


void BinaryTree::Insert(int x,String Surname,TNode*&node)
{
	if (!ElementExist(Root, x))
	{
		if (node == nullptr)
			node = new TNode(x, Surname);
		else
		{
			if (x < node->Key)
				Insert(x, Surname, node->left);

			if (x > node->Key)
				Insert(x, Surname, node->right);

		}
	}
	else
		ShowMessage("The key "+IntToStr(x)+" is already exist");
}

void BinaryTree::Delete(int x, TNode*& node)
{
	if (ElementExist(Root, x))
	{
		if (x == node->Key)
		{
			if (node->right == nullptr)
			{
				TNode* temp = node;
				node = node->left;
				delete temp;
				return;
			}
			else
			{
				TNode* temp = node->right;
				if (temp->left == nullptr)
				{
					temp->left = node->left;
					node = new TNode(*temp);
					delete temp;
					return;
				}
				else
				{
					TNode* ptr = temp->left;
					while (ptr->left != nullptr)
					{
						temp = ptr;
						ptr = ptr->left;
					}
					temp->left = ptr->right;
					ptr->left = node->left;
					ptr->right = node->right;
					temp = ptr;
					node = new TNode(*temp);
					delete temp;
					return;
				}
			}
		}
		else if (x < node->Key)
			Delete(x, node->left);
		else
			Delete(x, node->right);
	}
	else
		ShowMessage("There is no element with such index");
}

void BinaryTree::NLR(TNode*& node,TMemo *Memo1,TForm*Form13)
{
	if (node != nullptr)
	{
		Memo1->Lines->Add(IntToStr(node->Key)+" ");
		NLR(node->left,Memo1,Form13);
		NLR(node->right,Memo1,Form13);
	}
}

void BinaryTree::LNR(TNode*&node,TMemo *Memo1,TForm*Form13)
{
	if (node != nullptr)
	{
		LNR(node->left,Memo1,Form13);
		Memo1->Lines->Add(IntToStr(node->Key)+" ");
		LNR(node->right,Memo1,Form13);
	}
}

void BinaryTree::LRN(TNode*& node,TMemo *Memo1,TForm*Form13)
{
	if (node != nullptr)
	{
		LRN(node->left,Memo1,Form13);
		LRN(node->right,Memo1,Form13);
		Memo1->Lines->Add(IntToStr(node->Key)+" ");
	}
}

String BinaryTree::Search(TNode* node,int x)
{
	if (ElementExist(Root, x))
	{
		if (node->Key == x)
			return node->Surname;
		if (x < node->Key)
			return Search(node->left, x);
		else
			return Search(node->right, x);
	}
	else
		ShowMessage("No element with such key");

}

bool BinaryTree::ElementExist(TNode* node, int x)
{
	if (node == nullptr)
		return false;
	else if (node->Key == x)
		return true;

	if (x < node->Key)
		return ElementExist(node->left, x);
	else
		return ElementExist(node->right, x);
}


void BinaryTree::PrintNLR(TForm*Form13,TMemo*Memo1)
{
	NLR(Root,Memo1,Form13);
}

void BinaryTree::PrintLNR(TForm*Form13,TMemo*Memo1)
{
	LNR(Root,Memo1,Form13);
}

void BinaryTree::PrintLRN(TForm*Form13,TMemo*Memo1)
{
	LRN(Root,Memo1,Form13);
}

String BinaryTree::SearchFor(int x)
{
	return Search(Root, x);
}

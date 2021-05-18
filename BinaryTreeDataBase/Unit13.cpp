//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


#include "BinaryTree.h"
#include "Unit13.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
BinaryTree Oak;
String* arr;
int Size=0;
TForm13 *Form13;
//---------------------------------------------------------------------------
__fastcall TForm13::TForm13(TComponent* Owner)
	: TForm(Owner)
{
}

class TPublicGrid: public  TStringGrid
{
    public:
        using TStringGrid::DeleteRow;
};
//---------------------------------------------------------------------------
void __fastcall TForm13::FormCreate(TObject *Sender)
{
Add->Enabled=false;
Delete->Enabled=false;
Panel1->Hide();
Panel2->Hide();
Size=(StringGrid1->RowCount)-1;
	arr=new String[Size];
	arr[0]="Timofey Dudich";
	arr[1]="Dmitry Ermolovich";
	arr[2]="Alex Snetko";
	arr[3]="Stanislav Pushkov";
	arr[4]="Eugen Mazur-Grabovskiy";
	StringGrid1->Cells[0][0]="Full Name";
	StringGrid1->Cells[1][0]="¹";
	for(int i=1;i<Size+1;i++)
	{
		StringGrid1->Cells[0][i]=arr[i-1];
	}
	bool isUnique;
	for(int i=1;i<Size+1;i++)
	{
		do
		{
			StringGrid1->Cells[1][i]=IntToStr(rand()%30);
			isUnique=true;
			for(int j=1;j<i;j++)
			{
				if(StringGrid1->Cells[1][i]==StringGrid1->Cells[1][j])
				{
					isUnique=false;
					break;
                }
			}
		}while(!isUnique);
	}

	for(int i=0;i<Size;i++)
	{
		Oak.AddItem(StrToInt(StringGrid1->Cells[1][i+1]),arr[i]);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm13::FormClose(TObject *Sender, TCloseAction &Action)
{
	delete[]arr;
}
//---------------------------------------------------------------------------
void __fastcall TForm13::PrintClick(TObject *Sender)
{
	switch(ComboBox1->ItemIndex)
	{
		case 0:
			Oak.PrintNLR(this,Memo1);
		break;
		case 1:
			Oak.PrintLNR(this,Memo1);
		break;
		case 2:
			Oak.PrintLRN(this,Memo1);
		break;
	}
    Print->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm13::ComboBox1Change(TObject *Sender)
{
    Print->Enabled=true;
}
//---------------------------------------------------------------------------


void __fastcall TForm13::Button1Click(TObject *Sender)
{
if(Add->Enabled==true)
{
	Name->Text="";
	Number->Text="";
	Add->Enabled=false;
	Panel1->Hide();
	return;
}
	Panel1->Show();
	Add->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm13::AddClick(TObject *Sender)
{

	String SNumber=Number->Text;
	String SName=Name->Text;
	if((SName=="")||(SNumber==""))
	{
		ShowMessage("Empty field");
		return;
	}

	for(int i=1;i<SNumber.Length();i++)
	{
		if(!((SNumber[i]>='0')&&(SNumber[i]<='9')))
		{
		   ShowMessage("Only numbers are avelaible");
		   return;
		}
	}
	for(int i=1;i<SName.Length();i++)
	{
		if(!(((int)SName[i]>=65))&&(((int)SName[i]<=122)))
		{
			if(SName[i]!=' ')
			{
			ShowMessage("Only letters are avelaible");
			return;
			}
		}
	}



	StringGrid1->RowCount++;
	StringGrid1->Cells[0][StringGrid1->RowCount-1]=SName;
	StringGrid1->Cells[1][StringGrid1->RowCount-1]=SNumber;
	Oak.AddItem(StrToInt(Number->Text),Name->Text);
	Name->Text="";
	Number->Text="";
	Add->Enabled=false;
	Panel1->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm13::Button2Click(TObject *Sender)
{
if(Delete->Enabled==true)
{
	DeleteP->Text="";
	Delete->Enabled=false;
	Panel2->Hide();
	return;
}
if(StringGrid1->RowCount==1)
{
	ShowMessage("Empty tree");
    return;
}
	Panel2->Show();
    Delete->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm13::DeleteClick(TObject *Sender)
{

	String SNumber=DeleteP->Text;

	if(SNumber=="")
	{
		ShowMessage("Empty field");
		return;
	}

	for(int i=1;i<SNumber.Length();i++)
	{
		if(!((SNumber[i]>='0')&&(SNumber[i]<='9')))
		{
		   ShowMessage("Only numbers are avelaible");
		   return;
		}
	}
	for(int i=0;i<StringGrid1->RowCount;i++)
	{
		if(StringGrid1->Cells[1][i]==SNumber)
		{
			((TPublicGrid*)StringGrid1)->DeleteRow(i);
		}
	}
	Oak.DeleteItem(StrToInt(SNumber));
	DeleteP->Text="";
	Delete->Enabled=false;
	Panel2->Hide();
}
//---------------------------------------------------------------------------



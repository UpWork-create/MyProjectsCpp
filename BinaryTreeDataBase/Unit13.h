//---------------------------------------------------------------------------

#ifndef Unit13H
#define Unit13H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm13 : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *StringGrid1;
	TTreeView *TreeView1;
	TMemo *Memo1;
	TButton *Print;
	TComboBox *ComboBox1;
	TButton *Add;
	TPanel *Panel1;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *Name;
	TEdit *Number;
	TButton *Button1;
	TButton *Button2;
	TButton *Delete;
	TPanel *Panel2;
	TEdit *DeleteP;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall PrintClick(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall AddClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall DeleteClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm13(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm13 *Form13;
//---------------------------------------------------------------------------
#endif

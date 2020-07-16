//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *Exit;
        TBitBtn *New;
        TBitBtn *Remove;
        TBitBtn *Run;
        TMemo *add;
        TEdit *Name;
        TListBox *List;
        TTimer *Timer1;
        TMemo *del;
        TMemo *cmos;
        TBitBtn *Set;
        TLabel *Label1;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall ExitClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall NewClick(TObject *Sender);
        void __fastcall RemoveClick(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall ListClick(TObject *Sender);
        void __fastcall ListEnter(TObject *Sender);
        void __fastcall ListKeyPress(TObject *Sender, char &Key);
        void __fastcall ListKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall ListKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall ListDblClick(TObject *Sender);
        void __fastcall RunClick(TObject *Sender);
        void __fastcall SetClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 
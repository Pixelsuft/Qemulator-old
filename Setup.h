//---------------------------------------------------------------------------

#ifndef SetupH
#define SetupH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Tabs.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TSets : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TButton *Button4;
        TButton *Button5;
        TButton *Button6;
        TCheckBox *CheckBox1;
        TCheckBox *CheckBox2;
        TCheckBox *CheckBox3;
        TCheckBox *CheckBox4;
        TComboBox *ComboBox1;
        TCheckBox *CheckBox5;
        TCheckBox *CheckBox6;
        TEdit *Edit1;
        TLabel *Label1;
        TLabel *Label2;
        TEdit *Edit2;
        TEdit *Edit3;
        TLabel *Label3;
        TEdit *Edit4;
        TLabel *Label4;
        TEdit *Edit5;
        TLabel *Label5;
        TEdit *Edit6;
        TLabel *Label6;
        TEdit *Edit7;
        TLabel *Label7;
        TEdit *Edit8;
        TLabel *Label8;
        TComboBox *ComboBox2;
        TComboBox *ComboBox3;
        TComboBox *ComboBox4;
        TCheckBox *CheckBox7;
        TCheckBox *CheckBox8;
        TCheckBox *CheckBox9;
        TCheckBox *CheckBox10;
        TButton *Button7;
        TCheckBox *CheckBox11;
        TLabel *Label9;
        TEdit *Edit9;
        TLabel *Label10;
        TComboBox *ComboBox5;
        TLabel *Label11;
        TComboBox *ComboBox6;
        TCheckBox *CheckBox12;
        TCheckBox *CheckBox13;
        TCheckBox *CheckBox14;
        TCheckBox *CheckBox15;
        TCheckBox *CheckBox16;
        TCheckBox *CheckBox17;
        TCheckBox *CheckBox18;
        TCheckBox *CheckBox19;
        TCheckBox *CheckBox20;
        TCheckBox *CheckBox21;
        TCheckBox *CheckBox22;
        TCheckBox *CheckBox23;
        TEdit *Edit10;
        TLabel *Label12;
        TCheckBox *CheckBox24;
        TCheckBox *CheckBox25;
        TCheckBox *CheckBox26;
        TCheckBox *CheckBox27;
        TLabel *Label13;
        TEdit *Edit11;
        TCheckBox *CheckBox28;
        TMemo *cmos;
        TLabel *Label14;
        TTimer *Timer1;
        TLabel *Label15;
        TEdit *Edit12;
        TCheckBox *CheckBox29;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Label15MouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Edit10MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Label12MouseMove(TObject *Sender,
          TShiftState Shift, int X, int Y);
        void __fastcall Edit12MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Label15Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TSets(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSets *Sets;
//---------------------------------------------------------------------------
#endif

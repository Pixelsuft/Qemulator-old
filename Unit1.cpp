//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <iostream.h>
#include <cstdlib.h>
#include <mmsystem.hpp>
#include "Unit1.h"
#include "Boot.h"
#include "Setup.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int i=-1;
bool show=false;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
        caFree;        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose)
{
        CanClose=false;
        system("taskkill /f /im Qemulator.exe");
        //system("taskkill /f /im Project1.exe");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ExitClick(TObject *Sender)
{
        system("taskkill /f /im Qemulator.exe");
       // system("taskkill /f /im Project1.exe");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
        Form1->Width=322;
        Form1->Height=397;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::NewClick(TObject *Sender)
{
        if(!FileExists(Name->Text + "\\cmos.qemulator")){
        List->Items->Add(Name->Text);
        i++;
        add->Lines->Strings[3]="md \"" + Name->Text +"\"";
        add->Lines->SaveToFile("add.bat");
        system("add.bat");
        cmos->Lines->SaveToFile(Name->Text + "\\cmos.qemulator"); }
        List->Items->SaveToFile("qemulator.conf");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RemoveClick(TObject *Sender)
{
        if(i>-1 && FileExists(Name->Text + "\\cmos.qemulator")){
        bool find=false;
        for(int gol=0;find==false;gol++)
        {
                if(List->Items->Strings[gol]==Name->Text)
                {
                        find=true;
                        List->Items->Delete(gol);
                        del->Lines->Strings[3]="cd \"" + Name->Text +"\"";
                        del->Lines->Strings[6]="rd \"" + Name->Text +"\"";
                        del->Lines->SaveToFile("del.bat");
                        system("del.bat");
                }
        }
        i--;               }
        List->Items->SaveToFile("qemulator.conf");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
        Timer1->Enabled=false;
        if(FileExists("qemulator.conf"))List->Items->LoadFromFile("qemulator.conf");
        i=List->Items->Count-1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ListClick(TObject *Sender)
{
        if(i>-1)Name->Text=List->Items->Strings[List->ItemIndex];
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListEnter(TObject *Sender)
{
        //if(i>-1)Name->Text=List->Items->Strings[List->ItemIndex];
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListKeyPress(TObject *Sender, char &Key)
{
        if(i>-1)Name->Text=List->Items->Strings[List->ItemIndex];
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(i>-1)Name->Text=List->Items->Strings[List->ItemIndex];
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(i>-1)Name->Text=List->Items->Strings[List->ItemIndex];
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListDblClick(TObject *Sender)
{
        if(i>-1)Name->Text=List->Items->Strings[List->ItemIndex];
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RunClick(TObject *Sender)
{
        if(i>-1 && FileExists(Name->Text + "\\cmos.qemulator")){
        //Form1->Visible=false;
        Loader->Caption="QEMU (" + Form1->Name->Text + ")";
        Sets->Caption="QEMU (" + Form1->Name->Text + ")";
        Loader->Image1->Top=0;
        Loader->Image1->Left=0;
        Sets->Edit12->Text=Name->Text;
        Loader->Image1->Visible=true;
        Loader->Label1->Visible=false;
        Loader->Label2->Visible=false;
        Loader->Label3->Visible=false;
        Loader->Label4->Visible=false;
        Loader->Label5->Visible=false;
        Loader->Label6->Visible=false;
        Sets->cmos->Lines->LoadFromFile(Form1->Name->Text + "\\cmos.qemulator");
        Loader->Timer1->Enabled=true;
        Loader->Xaker->Caption="nomenu";
        Sets->Timer1->Enabled=true;
        Run->Visible=false;
        Set->Visible=false;
        Label1->Caption="run";
        //Run->HelpKeyword="Нельзя запустить ВМ,пока раннее запущенная не запустится до конца.";
        Loader->Visible=true;
}}
//---------------------------------------------------------------------------

void __fastcall TForm1::SetClick(TObject *Sender)
{
        if(i>-1 && FileExists(Name->Text + "\\cmos.qemulator")){Loader->Caption="QEMU (" + Form1->Name->Text + ")";
        Sets->Caption="QEMU (" + Form1->Name->Text + ")";
        Sets->cmos->Lines->LoadFromFile(Form1->Name->Text + "\\cmos.qemulator");
        Sets->Timer1->Enabled=true;
        Sets->Edit12->Text=Name->Text;
        Label1->Caption="set";
        //Form1->Visible=false;
        Run->Visible=false;
        Set->Visible=false;
        Sets->Visible=true;  }
}
//---------------------------------------------------------------------------


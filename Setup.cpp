//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <iostream.h>
#include <cstdlib.h>
#include <mmsystem.hpp>
#include "Setup.h"
#include "Boot.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSets *Sets;
bool display=false;
bool disks=false;
bool sound=false;
bool other=false;
bool sys=false;
//---------------------------------------------------------------------------
__fastcall TSets::TSets(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSets::FormClose(TObject *Sender, TCloseAction &Action)
{
        caFree;        
}
//---------------------------------------------------------------------------
void __fastcall TSets::FormCloseQuery(TObject *Sender, bool &CanClose)
{
        CanClose=false;
        Sets->Visible=false;
        Form1->Run->Visible=true;
        Form1->Set->Visible=true;
        Form1->Visible=true;

}
//---------------------------------------------------------------------------
void __fastcall TSets::Button4Click(TObject *Sender)
{
        if(Form1->Label1->Caption=="set")
        {
        Sets->Visible=false;
        Form1->Run->Visible=true;
        Form1->Set->Visible=true;
        Form1->Visible=true;
        }
        else
        {
        Sets->Visible=false;
        Loader->Top=Sets->Top;
        Loader->Left=Sets->Left;
        Loader->Timer1->Enabled=true;
        Loader->Visible=true;
        }
}
//---------------------------------------------------------------------------
void __fastcall TSets::Button1Click(TObject *Sender)
{
        if(display==false)
        {
        CheckBox1->Visible=true;
        CheckBox2->Visible=true;
        CheckBox3->Visible=true;
        CheckBox4->Visible=true;
        CheckBox5->Visible=true;
        CheckBox6->Visible=true;
        CheckBox15->Visible=true;
        CheckBox29->Visible=true;
        ComboBox1->Visible=true;
        Edit1->Visible=true;
        Label14->Visible=true;
        display=true;
        }
        else
        {
        CheckBox1->Visible=false;
        CheckBox2->Visible=false;
        CheckBox3->Visible=false;
        CheckBox4->Visible=false;
        CheckBox5->Visible=false;
        CheckBox6->Visible=false;
        CheckBox15->Visible=false;
        CheckBox29->Visible=false;
        ComboBox1->Visible=false;
        Edit1->Visible=false;
        Label14->Visible=false;
        display=false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TSets::Button2Click(TObject *Sender)
{
        if(disks==false)
        {
        Label1->Visible=true;
        Label2->Visible=true;
        Label3->Visible=true;
        Label4->Visible=true;
        Label5->Visible=true;
        Label6->Visible=true;
        Label7->Visible=true;
        Label8->Visible=true;
        Edit2->Visible=true;
        Edit3->Visible=true;
        Edit4->Visible=true;
        Edit5->Visible=true;
        Edit6->Visible=true;
        Edit7->Visible=true;
        Edit8->Visible=true;
        ComboBox2->Visible=true;
        ComboBox3->Visible=true;
        ComboBox4->Visible=true;
        disks=true;
        }
        else
        {
        Label1->Visible=false;
        Label2->Visible=false;
        Label3->Visible=false;
        Label4->Visible=false;
        Label5->Visible=false;
        Label6->Visible=false;
        Label7->Visible=false;
        Label8->Visible=false;
        Edit2->Visible=false;
        Edit3->Visible=false;
        Edit4->Visible=false;
        Edit5->Visible=false;
        Edit6->Visible=false;
        Edit7->Visible=false;
        Edit8->Visible=false;
        ComboBox2->Visible=false;
        ComboBox3->Visible=false;
        ComboBox4->Visible=false;
        disks=false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TSets::Button3Click(TObject *Sender)
{
        if(sound==false)
        {
        CheckBox7->Visible=true;
        CheckBox8->Visible=true;
        CheckBox9->Visible=true;
        CheckBox10->Visible=true;
        CheckBox11->Visible=true;
        sound=true;
        }
        else
        {
        CheckBox7->Visible=false;
        CheckBox8->Visible=false;
        CheckBox9->Visible=false;
        CheckBox10->Visible=false;
        CheckBox11->Visible=false;
        sound=false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TSets::Button7Click(TObject *Sender)
{
        if(sys==false)
        {
        Label9->Visible=true;
        Label10->Visible=true;
        Label11->Visible=true;
        Label12->Visible=true;
        Edit9->Visible=true;
        Edit10->Visible=true;
        CheckBox12->Visible=true;
        CheckBox13->Visible=true;
        CheckBox14->Visible=true;
        CheckBox16->Visible=true;
        CheckBox17->Visible=true;
        CheckBox18->Visible=true;
        CheckBox19->Visible=true;
        CheckBox20->Visible=true;
        CheckBox21->Visible=true;
        CheckBox22->Visible=true;
        CheckBox23->Visible=true;
        ComboBox5->Visible=true;
        ComboBox6->Visible=true;
        sys=true;
        }
        else
        {
        Label9->Visible=false;
        Label10->Visible=false;
        Label11->Visible=false;
        Label12->Visible=false;
        Edit9->Visible=false;
        Edit10->Visible=false;
        CheckBox12->Visible=false;
        CheckBox13->Visible=false;
        CheckBox14->Visible=false;
        CheckBox16->Visible=false;
        CheckBox17->Visible=false;
        CheckBox18->Visible=false;
        CheckBox19->Visible=false;
        CheckBox20->Visible=false;
        CheckBox21->Visible=false;
        CheckBox22->Visible=false;
        CheckBox23->Visible=false;
        ComboBox5->Visible=false;
        ComboBox6->Visible=false;
        sys=false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TSets::Button6Click(TObject *Sender)
{
        if(other==false)
        {
        CheckBox24->Visible=true;
        CheckBox25->Visible=true;
        CheckBox26->Visible=true;
        CheckBox27->Visible=true;
        CheckBox28->Visible=true;
        Label13->Visible=true;
        Edit11->Visible=true;
        other=true;
        }
        else
        {
        CheckBox24->Visible=false;
        CheckBox26->Visible=false;
        CheckBox25->Visible=false;
        CheckBox27->Visible=false;
        CheckBox28->Visible=false;
        Label13->Visible=false;
        Edit11->Visible=false;
        other=false;
        }
}
//---------------------------------------------------------------------------

void __fastcall TSets::Button5Click(TObject *Sender)
{
        if(CheckBox1->Checked)cmos->Lines->Strings[2]="true";
        else cmos->Lines->Strings[2]="false";
        if(CheckBox2->Checked)cmos->Lines->Strings[4]="true";
        else cmos->Lines->Strings[4]="false";
        if(CheckBox3->Checked)cmos->Lines->Strings[6]="true";
        else cmos->Lines->Strings[6]="false";
        if(CheckBox4->Checked)cmos->Lines->Strings[8]="true";
        else cmos->Lines->Strings[8]="false";
        if(CheckBox5->Checked)cmos->Lines->Strings[12]="true";
        else cmos->Lines->Strings[12]="false";
        if(CheckBox6->Checked)cmos->Lines->Strings[14]="true";
        else cmos->Lines->Strings[14]="false";
        if(CheckBox15->Checked)cmos->Lines->Strings[17]="true";
        else cmos->Lines->Strings[17]="false";
        cmos->Lines->Strings[10]=ComboBox1->Text;
        cmos->Lines->Strings[15]=Edit1->Text;
        cmos->Lines->Strings[19]=Edit2->Text;
        cmos->Lines->Strings[21]=Edit3->Text;
        cmos->Lines->Strings[23]=Edit4->Text;
        cmos->Lines->Strings[25]=Edit5->Text;
        cmos->Lines->Strings[27]=Edit6->Text;
        cmos->Lines->Strings[29]=Edit7->Text;
        cmos->Lines->Strings[31]=Edit8->Text;
        cmos->Lines->Strings[85]=Edit11->Text;
        cmos->Lines->Strings[33]=ComboBox2->Text;
        cmos->Lines->Strings[34]=ComboBox3->Text;
        cmos->Lines->Strings[35]=ComboBox4->Text;
        if(CheckBox7->Checked)cmos->Lines->Strings[37]="true";
        else cmos->Lines->Strings[37]="false";
        if(CheckBox8->Checked)cmos->Lines->Strings[39]="true";
        else cmos->Lines->Strings[39]="false";
        if(CheckBox9->Checked)cmos->Lines->Strings[41]="true";
        else cmos->Lines->Strings[41]="false";
        if(CheckBox10->Checked)cmos->Lines->Strings[43]="true";
        else cmos->Lines->Strings[43]="false";
        if(CheckBox11->Checked)cmos->Lines->Strings[45]="true";
        else cmos->Lines->Strings[45]="false";
        if(CheckBox12->Checked)cmos->Lines->Strings[53]="true";
        else cmos->Lines->Strings[53]="false";
        if(CheckBox13->Checked)cmos->Lines->Strings[55]="true";
        else cmos->Lines->Strings[55]="false";
        if(CheckBox14->Checked)cmos->Lines->Strings[57]="true";
        else cmos->Lines->Strings[57]="false";
        if(CheckBox16->Checked)cmos->Lines->Strings[59]="true";
        else cmos->Lines->Strings[59]="false";
        if(CheckBox17->Checked)cmos->Lines->Strings[61]="true";
        else cmos->Lines->Strings[61]="false";
        if(CheckBox18->Checked)cmos->Lines->Strings[63]="true";
        else cmos->Lines->Strings[63]="false";
        if(CheckBox19->Checked)cmos->Lines->Strings[65]="true";
        else cmos->Lines->Strings[65]="false";
        if(CheckBox20->Checked)cmos->Lines->Strings[67]="true";
        else cmos->Lines->Strings[67]="false";
        if(CheckBox21->Checked)cmos->Lines->Strings[69]="true";
        else cmos->Lines->Strings[69]="false";
        if(CheckBox22->Checked)cmos->Lines->Strings[71]="true";
        else cmos->Lines->Strings[71]="false";
        if(CheckBox23->Checked)cmos->Lines->Strings[73]="true";
        else cmos->Lines->Strings[73]="false";
        if(CheckBox24->Checked)cmos->Lines->Strings[77]="true";
        else cmos->Lines->Strings[77]="false";
        if(CheckBox25->Checked)cmos->Lines->Strings[79]="true";
        else cmos->Lines->Strings[79]="false";
        if(CheckBox26->Checked)cmos->Lines->Strings[89]="true";
        else cmos->Lines->Strings[89]="false";
        if(CheckBox27->Checked)cmos->Lines->Strings[81]="true";
        else cmos->Lines->Strings[81]="false";
        if(CheckBox28->Checked)cmos->Lines->Strings[83]="true";
        else cmos->Lines->Strings[83]="false";
        if(CheckBox29->Checked)cmos->Lines->Strings[87]="true";
        else cmos->Lines->Strings[87]="false";
        cmos->Lines->SaveToFile(Edit12->Text + "\\cmos.qemulator");
        if(Form1->Label1->Caption=="set")
        {
        Sets->Visible=false;
        Form1->Run->Visible=true;
        Form1->Set->Visible=true;
        Form1->Visible=true;
        }
        else
        {
        Sets->Visible=false;
        Loader->Top=Sets->Top;
        Loader->Left=Sets->Left;
        Loader->Timer1->Enabled=true;
        Loader->Visible=true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TSets::Timer1Timer(TObject *Sender)
{
        Timer1->Enabled=false;
        if(cmos->Lines->Strings[2]=="true")CheckBox1->Checked=true;
        else CheckBox1->Checked=false;
        if(cmos->Lines->Strings[4]=="true")CheckBox2->Checked=true;
        else CheckBox2->Checked=false;
        if(cmos->Lines->Strings[6]=="true")CheckBox3->Checked=true;
        else CheckBox3->Checked=false;
        if(cmos->Lines->Strings[8]=="true")CheckBox4->Checked=true;
        else CheckBox4->Checked=false;
        ComboBox1->Text=cmos->Lines->Strings[10];
        Edit1->Text=cmos->Lines->Strings[15];
        if(cmos->Lines->Strings[12]=="true")CheckBox5->Checked=true;
        else CheckBox5->Checked=false;
        if(cmos->Lines->Strings[14]=="true")CheckBox6->Checked=true;
        else CheckBox6->Checked=false;
        if(cmos->Lines->Strings[17]=="true")CheckBox15->Checked=true;
        else CheckBox15->Checked=false;
        Edit2->Text=cmos->Lines->Strings[19];
        Edit3->Text=cmos->Lines->Strings[21];
        Edit4->Text=cmos->Lines->Strings[23];
        Edit5->Text=cmos->Lines->Strings[25];
        Edit6->Text=cmos->Lines->Strings[27];
        Edit7->Text=cmos->Lines->Strings[29];
        Edit8->Text=cmos->Lines->Strings[31];
        ComboBox2->Text=cmos->Lines->Strings[33];
        ComboBox3->Text=cmos->Lines->Strings[34];
        ComboBox4->Text=cmos->Lines->Strings[35];
        if(cmos->Lines->Strings[37]=="true")CheckBox7->Checked=true;
        else CheckBox7->Checked=false;
        if(cmos->Lines->Strings[39]=="true")CheckBox8->Checked=true;
        else CheckBox8->Checked=false;
        if(cmos->Lines->Strings[41]=="true")CheckBox9->Checked=true;
        else CheckBox9->Checked=false;
        if(cmos->Lines->Strings[43]=="true")CheckBox10->Checked=true;
        else CheckBox10->Checked=false;
        if(cmos->Lines->Strings[45]=="true")CheckBox11->Checked=true;
        else CheckBox11->Checked=false;
        if(cmos->Lines->Strings[53]=="true")CheckBox12->Checked=true;
        else CheckBox12->Checked=false;
        if(cmos->Lines->Strings[55]=="true")CheckBox13->Checked=true;
        else CheckBox13->Checked=false;
        if(cmos->Lines->Strings[57]=="true")CheckBox14->Checked=true;
        else CheckBox14->Checked=false;
        if(cmos->Lines->Strings[59]=="true")CheckBox16->Checked=true;
        else CheckBox16->Checked=false;
        if(cmos->Lines->Strings[61]=="true")CheckBox17->Checked=true;
        else CheckBox17->Checked=false;
        if(cmos->Lines->Strings[63]=="true")CheckBox18->Checked=true;
        else CheckBox18->Checked=false;
        if(cmos->Lines->Strings[65]=="true")CheckBox19->Checked=true;
        else CheckBox19->Checked=false;
        if(cmos->Lines->Strings[67]=="true")CheckBox20->Checked=true;
        else CheckBox20->Checked=false;
        if(cmos->Lines->Strings[69]=="true")CheckBox21->Checked=true;
        else CheckBox21->Checked=false;
        if(cmos->Lines->Strings[71]=="true")CheckBox22->Checked=true;
        else CheckBox22->Checked=false;
        if(cmos->Lines->Strings[73]=="true")CheckBox23->Checked=true;
        else CheckBox23->Checked=false;
        if(cmos->Lines->Strings[77]=="true")CheckBox24->Checked=true;
        else CheckBox24->Checked=false;
        if(cmos->Lines->Strings[79]=="true")CheckBox25->Checked=true;
        else CheckBox25->Checked=false;
        if(cmos->Lines->Strings[89]=="true")CheckBox26->Checked=true;
        else CheckBox26->Checked=false;
        if(cmos->Lines->Strings[81]=="true")CheckBox27->Checked=true;
        else CheckBox27->Checked=false;
        if(cmos->Lines->Strings[83]=="true")CheckBox28->Checked=true;
        else CheckBox28->Checked=false;
        if(cmos->Lines->Strings[87]=="true")CheckBox29->Checked=true;
        else CheckBox29->Checked=false;
        Edit10->Text=cmos->Lines->Strings[75];
        Edit11->Text=cmos->Lines->Strings[85];
        Edit9->Text=cmos->Lines->Strings[47];
        ComboBox5->Text=cmos->Lines->Strings[49];
        ComboBox6->Text=cmos->Lines->Strings[51];
}
//---------------------------------------------------------------------------


void __fastcall TSets::Label15MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
        Label15->Font->Color=clRed;        
}
//---------------------------------------------------------------------------

void __fastcall TSets::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
Label15->Font->Color=clBlue;
}
//---------------------------------------------------------------------------

void __fastcall TSets::Edit10MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
Label15->Font->Color=clBlue;        
}
//---------------------------------------------------------------------------

void __fastcall TSets::Label12MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
Label15->Font->Color=clBlue;        
}
//---------------------------------------------------------------------------

void __fastcall TSets::Edit12MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
Label15->Font->Color=clBlue;        
}
//---------------------------------------------------------------------------

void __fastcall TSets::Label15Click(TObject *Sender)
{
        ShellExecute(Handle, "open", "http://www.pixelsuft.zzz.com.ua/", 0, 0, SW_SHOW );        
}
//---------------------------------------------------------------------------


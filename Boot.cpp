//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <iostream.h>
#include <cstdlib.h>
#include <mmsystem.hpp>
#include "Boot.h"
#include "Setup.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLoader *Loader;
AnsiString boot="def";
//---------------------------------------------------------------------------
__fastcall TLoader::TLoader(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TLoader::FormClose(TObject *Sender, TCloseAction &Action)
{
        caFree;        
}
//---------------------------------------------------------------------------
void __fastcall TLoader::FormCloseQuery(TObject *Sender, bool &CanClose)
{
        CanClose=false;
        Loader->Visible=false;
        Timer1->Enabled=false;
        Timer2->Enabled=false;
        Timer3->Enabled=false;
        Loader->AlphaBlendValue=0;
        Form1->Run->Visible=true;
        Form1->Set->Visible=true;
        Form1->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TLoader::Timer1Timer(TObject *Sender)
{
        boot="def";
        if(Loader->AlphaBlendValue>250)
        {
                Timer1->Enabled=false;
                Loader->AlphaBlendValue=255;
                Timer2->Enabled=true;
        }
        else Loader->AlphaBlendValue+=2;
}
//---------------------------------------------------------------------------
void __fastcall TLoader::Timer3Timer(TObject *Sender)
{
        if(Loader->AlphaBlendValue<5)
        {
                Timer3->Enabled=false;
                Timer2->Enabled=false;
                Timer1->Enabled=false;
                Timer4->Enabled=true;
        }
        else Loader->AlphaBlendValue-=2;
}
//---------------------------------------------------------------------------
void __fastcall TLoader::Timer2Timer(TObject *Sender)
{
        Timer2->Enabled=false;
        Timer3->Enabled=true;        
}
//---------------------------------------------------------------------------
void __fastcall TLoader::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key==VK_ESCAPE)
        {
                if(Image1->Visible==true){
                Timer1->Enabled=false;
                Timer2->Enabled=false;
                Timer3->Enabled=false;
                Loader->Visible=false;
                Loader->AlphaBlendValue=0;
                Sets->Left=Loader->Left;
                Sets->Top=Loader->Top;
                Sets->Visible=true;
        }
        }
        else if(Key==VK_F12)
        {
                Timer1->Enabled=false;
                Timer2->Enabled=false;
                Timer3->Enabled=false;
                Loader->Visible=true;
                Loader->AlphaBlendValue=255;
                Image1->Visible=false;
                Label1->Visible=true;
                Label2->Visible=true;
                Label3->Visible=true;
                Label4->Visible=true;
                Label5->Visible=true;
                Label6->Visible=true;
                Xaker->Caption="menu";
        }
        else if(Key==65 && Xaker->Caption=="menu")
        {
                //boot A
                //Loader->Visible=false;
        Timer1->Enabled=false;
        Timer2->Enabled=false;
        Timer3->Enabled=false;
        boot="A";
        Timer4->Enabled=true;
        /*Loader->AlphaBlendValue=0;
        Form1->Run->Visible=true;
        Form1->Set->Visible=true;
        Form1->Visible=true;*/
        }
        else if(Key==66 && Xaker->Caption=="menu")
        {
                //boot B
                //Loader->Visible=false;
        Timer1->Enabled=false;
        Timer2->Enabled=false;
        Timer3->Enabled=false;
        boot="B";
        Timer4->Enabled=true;
       /* Loader->AlphaBlendValue=0;
        Form1->Run->Visible=true;
        Form1->Set->Visible=true;
        Form1->Visible=true;*/
        }
        else if(Key==49 && Xaker->Caption=="menu")
        {
                //boot HD
                //Loader->Visible=false;
        Timer1->Enabled=false;
        Timer2->Enabled=false;
        Timer3->Enabled=false;
        boot="C";
        Timer4->Enabled=true;
        /*Loader->AlphaBlendValue=0;
        Form1->Run->Visible=true;
        Form1->Set->Visible=true;
        Form1->Visible=true;*/
        }
        else if(Key==67 && Xaker->Caption=="menu")
        {
                //boot CD
                //Loader->Visible=false;
        Timer1->Enabled=false;
        Timer2->Enabled=false;
        Timer3->Enabled=false;
        boot="D";
        Timer4->Enabled=true;
        /*Loader->AlphaBlendValue=0;
        Form1->Run->Visible=true;
        Form1->Set->Visible=true;
        Form1->Visible=true; */
        }
        else if(Key==78 && Xaker->Caption=="menu")
        {
                //boot NET
                //Loader->Visible=false;
        Timer1->Enabled=false;
        Timer2->Enabled=false;
        Timer3->Enabled=false;
        boot="N";
        Timer4->Enabled=true;
        /*Loader->AlphaBlendValue=0;
        Form1->Run->Visible=true;
        Form1->Set->Visible=true;
        Form1->Visible=true;*/
        }
}
//---------------------------------------------------------------------------


void __fastcall TLoader::Timer4Timer(TObject *Sender)
{
Timer4->Enabled=false;
Loader->AlphaBlendValue=255;
                launch->Lines->Strings[3]="start qemu-system-" + Sets->ComboBox6->Text;
                if(Sets->CheckBox15->Checked==false)launch->Lines->Strings[3]=launch->Lines->Strings[3] + "w";
                launch->Lines->Strings[3]=launch->Lines->Strings[3]+" -no-reboot -name \"" + Sets->Edit12->Text + "\"";
                if(Sets->CheckBox21->Checked==true)launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -nodefaults";
                if(Sets->CheckBox1->Checked==true)launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -monitor vc";
                if(Sets->CheckBox2->Checked==true)launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -monitor stdio";
                if(Sets->CheckBox3->Checked==true)launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -serial vc";
                if(Sets->CheckBox4->Checked==true)launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -parallel vc";
                launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -vga " + Sets->ComboBox1->Text;
                if(Sets->Edit2->Text!="")launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -fda \"" + Sets->Edit2->Text + "\"";
                if(Sets->Edit3->Text!="")launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -fdb \"" + Sets->Edit3->Text + "\"";
                if(Sets->Edit4->Text!="")launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -hda \"" + Sets->Edit4->Text + "\"";
                if(Sets->Edit5->Text!="")launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -hdb \"" + Sets->Edit5->Text + "\"";
                if(Sets->Edit6->Text!="")launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -hdc \"" + Sets->Edit6->Text + "\"";
                if(Sets->Edit7->Text!="")launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -hdd \"" + Sets->Edit7->Text + "\"";
                if(Sets->Edit8->Text!="")launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -cdrom \"" + Sets->Edit8->Text + "\"";
                if(boot=="def")
                {
                if(Sets->ComboBox2->Text!=""){
                        if(Sets->ComboBox2->Text=="Floppy A")launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -boot menu=off,order=a";
                        else if(Sets->ComboBox2->Text=="Floppy B")launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -boot menu=off,order=b";
                        else if(Sets->ComboBox2->Text=="Hard Disk")launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -boot menu=off,order=c";
                        else if(Sets->ComboBox2->Text=="CDROM")launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -boot menu=off,order=d";
                        else if(Sets->ComboBox2->Text=="Network")launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -boot menu=off,order=n";
                        if(Sets->ComboBox3->Text=="Floppy A")launch->Lines->Strings[3]=launch->Lines->Strings[3] + "a";
                        else if(Sets->ComboBox3->Text=="Floppy B")launch->Lines->Strings[3]=launch->Lines->Strings[3] + "b";
                        else if(Sets->ComboBox3->Text=="Hard Disk")launch->Lines->Strings[3]=launch->Lines->Strings[3] + "c";
                        else if(Sets->ComboBox3->Text=="CDROM")launch->Lines->Strings[3]=launch->Lines->Strings[3] + "d";
                        else if(Sets->ComboBox3->Text=="Network")launch->Lines->Strings[3]=launch->Lines->Strings[3] + "n";
                        if(Sets->ComboBox4->Text=="Floppy A")launch->Lines->Strings[3]=launch->Lines->Strings[3] + "a";
                        else if(Sets->ComboBox4->Text=="Floppy B")launch->Lines->Strings[3]=launch->Lines->Strings[3] + "b";
                        else if(Sets->ComboBox4->Text=="Hard Disk")launch->Lines->Strings[3]=launch->Lines->Strings[3] + "c";
                        else if(Sets->ComboBox4->Text=="CDROM")launch->Lines->Strings[3]=launch->Lines->Strings[3] + "d";
                        else if(Sets->ComboBox4->Text=="Network")launch->Lines->Strings[3]=launch->Lines->Strings[3] + "n";

                }}
                else
                {
                        if(boot=="A")launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -boot a";
                        else if(boot=="B")launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -boot b";
                        else if(boot=="C")launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -boot c";
                        else if(boot=="D")launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -boot d";
                        else if(boot=="N")launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -boot n";
                }
                if(Sets->CheckBox6->Checked==true)launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -display vnc=" + Sets->Edit1->Text;
                if(Sets->CheckBox5->Checked==true)launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -sdl";

                if(Sets->CheckBox7->Checked==true)launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -soundhw sb16";
                if(Sets->CheckBox8->Checked==true)launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -soundhw ac97";
                if(Sets->CheckBox9->Checked==true)launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -soundhw hda";
                if(Sets->CheckBox10->Checked==true)launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -soundhw gus";
                if(Sets->CheckBox11->Checked==true)launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -soundhw pcspk";
                if(Sets->Edit9->Text!="")launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -m " + Sets->Edit9->Text;
                if(Sets->ComboBox5->Text!="")launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -cpu " + Sets->ComboBox5->Text;
                if(Sets->CheckBox12->Checked==true)launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -accel kvm";
                if(Sets->CheckBox13->Checked==true)launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -accel hax";
                if(Sets->CheckBox14->Checked==true)launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -accel whpx";
                if(Sets->CheckBox16->Checked==true)launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -machine vmport=on";
                if(Sets->CheckBox17->Checked==true)launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -usbdevice tablet";
                if(Sets->CheckBox18->Checked==true)launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -usbdevice mouse";
                if(Sets->CheckBox19->Checked==true)launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -no-hpet";
                if(Sets->CheckBox20->Checked==true)launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -no-acpi";
                if(Sets->CheckBox22->Checked==true)launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -no-fd-bootchk";
                if(Sets->CheckBox23->Checked==true)launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -net nic,macaddr="+Sets->Edit10->Text+",model=ne2k_pci";
                if(Sets->CheckBox24->Checked==true)launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -ctrl-grab";
                if(Sets->CheckBox25->Checked==true)launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -no-quit";
                if(Sets->CheckBox26->Checked==true)launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -watchdog ib700";
                if(Sets->CheckBox27->Checked==true)launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -no-kvm";
                if(Sets->CheckBox28->Checked==true)launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -win2k-hack";
                if(Sets->cmos->Lines->Strings[87]=="true")launch->Lines->Strings[3]=launch->Lines->Strings[3] + " -full-screen";
                if(Sets->Edit11->Text!="")launch->Lines->Strings[3]=launch->Lines->Strings[3] + " " +Sets->Edit11->Text;
                Loader->AlphaBlendValue=0;
                launch->Lines->SaveToFile("starter.bat");
                system("start starter.bat");
                Loader->Visible=false;
                Form1->Run->Visible=true;
                Form1->Set->Visible=true;
}
//---------------------------------------------------------------------------


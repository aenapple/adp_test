//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "mserial.h"
#include <fstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
	: TForm(Owner)
{
	ComThread = 0;
    CheckBoxFixedClick(NULL);
}
//---------------------------------------------------------------------------
class TComThread : public TThread
{
   protected:
   		MSerial Serial;
        AnsiString Com;
        DWORD BaudRate;
    void __fastcall Execute(void)
    {
        
        if ( False == Serial.Open(Com.c_str(), BaudRate, Data8Bit, NonParity, OneStopBit, 10) )
        {
        	MessageBox(NULL, "Couldn't open port!", "Error!", MB_OK);
        	return;
        }
        Serial.ResetRB();
        Serial.ResetWB();
        unsigned char buf[20000];
        int bills = 0;
        FormMain->Series1->Clear();
        FormMain->indexBinBuffer= 0;
        while (!Terminated)
        {
        	int bytesAvailable = Serial.GetRBSize();
            if (bytesAvailable > 1) Serial.Read( buf, bytesAvailable & (~0x1) );
            {

                unsigned short* ptr = (unsigned short*)buf;
                for (int i = 0; i<bytesAvailable/2; i++)
                {

                	FormMain->Series1->AddXY(bills++, *ptr++);
                }

                /*
                unsigned char* ptr = buf;
                for (int i = 0; i<bytesAvailable; i++)
                {
                        FormMain->binBuffer[FormMain->indexBinBuffer]= *ptr++;
                        FormMain->indexBinBuffer++;
                	FormMain->Series1->AddXY(bills++, *ptr++);
                }
                */

            }
            Sleep(150);
        }
        Serial.Close();

    }
   public:
	__fastcall TComThread(bool CreateSuspended, AnsiString Com, DWORD BaudRate)
        : TThread(CreateSuspended)
        {
    		this->Com = Com;
        	this->BaudRate = BaudRate;
        };
};

//---------------------------------------------------------------------------
void __fastcall TFormMain::StartClick(TObject *Sender)
{
    if (ComThread)
    {
    	MessageBox(NULL, "Alredy started!", "Error!", MB_OK);
        return;
    }
	ComThread = new TComThread( true, this->ComboBoxCom->Text, StrToInt(this->ComboBoxBitrate->Text) );
    ComThread->Resume();
}

//---------------------------------------------------------------------------
void __fastcall TFormMain::StopClick(TObject *Sender)
{
     if(!ComThread) return;
     ComThread->Terminate();
     Sleep(150);
     ComThread = 0;
}

//---------------------------------------------------------------------------
void __fastcall TFormMain::SaveClick(TObject *Sender)
{
	if (this->SaveDialog1->Execute())
    {
    	TFileStream* f = new TFileStream(this->SaveDialog1->FileName, fmCreate);
        for (int i=0; i< /*this->indexBinBuffer*/this->Series1->Count(); i++)
        {
            AnsiString bcount = IntToStr(i);
            int v = Series1->YValues->operator [](i);
            //unsigned char v = (unsigned char) Series1->YValues->operator [](i);
            AnsiString val = IntToStr(v);
            	f->Write(bcount.c_str(), bcount.Length());
            f->Write("    ", 4);
            f->Write(val.c_str(), val.Length());
            if (i!=this->Series1->Count()-1) f->Write("\n", 1);

            //f->Write(&this->binBuffer[i], 1);
        }
        delete f;
    }
}

//---------------------------------------------------------------------------
void __fastcall TFormMain::LoadClick(TObject *Sender)
{
	if (this->OpenDialog1->Execute())
    {
    	std::fstream f;
        f.open(this->OpenDialog1->FileName.c_str(), std::fstream::in);
        this->Series1->Clear();
        int i;
        int val;
        while (!f.eof())
        {
            f >> i;
            f >> val;
            this->Series1->AddXY(i, val);
        }
    }	
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::CheckBoxFixedClick(TObject *Sender)
{
    if ( CheckBoxFixed->Checked )
    {
    	Chart->LeftAxis->Automatic = false;
        Chart->LeftAxis->Minimum = 0;
        Chart->LeftAxis->Maximum = 620;
        Chart->BottomAxis->Automatic = false;
    	Chart->BottomAxis->Minimum = 0;
        Chart->BottomAxis->Maximum = 3600;
    }
    else
    {
    	Chart->LeftAxis->Automatic = true;
        Chart->BottomAxis->Automatic = true;
        //Chart->LeftAxis->Minimum = 0;
        //Chart->LeftAxis->Maximum = 0xFFFF;
        //Chart->BottomAxis->Minimum = 0;
        //Chart->BottomAxis->Maximum = 4000;
    }
}
//---------------------------------------------------------------------------




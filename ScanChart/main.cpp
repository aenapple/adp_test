//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
        : TForm(Owner)
{
  fileBinScanning= NULL;
}

//---------------------------------------------------------------------------
void __fastcall TFormMain::BtnOpenFileClick(TObject *Sender)
{
  unsigned short bufferData[128];
  String str;

  if (this->DialogOpenFile->Execute())
  {
    if(fileBinScanning != NULL) delete(fileBinScanning);
    fileBinScanning = new TFileStream(this->DialogOpenFile->FileName, fmOpenRead);

    this->indexRecord= 0;

    this->Series1->Clear();

    fileBinScanning->Position= this->indexRecord * 256;

    if(fileBinScanning->Read(bufferData, 256) == 256)
    {
      this->indexRecord++;
      this->flafDirection= true;

      for(int i=0; i < 128; i++)
      {
        this->Series1->AddXY(i, bufferData[i]);

        str= IntToStr(this->indexRecord);
        this->EditNumberRecord->SetTextBuf(str.c_str());

      }

    }


  }


}

//---------------------------------------------------------------------------
void __fastcall TFormMain::FormClose(TObject *Sender, TCloseAction &Action)
{
  if(fileBinScanning != NULL) delete(fileBinScanning);
}

//---------------------------------------------------------------------------
void __fastcall TFormMain::BtnNextClick(TObject *Sender)
{
  unsigned short bufferData[128];
  unsigned int result;
  String str;


  if(fileBinScanning == NULL) return;

  this->Series1->Clear();

  if(this->flafDirection == false)
  {
    this->indexRecord++;
    this->flafDirection= true;
  }
  fileBinScanning->Position= this->indexRecord * 256;

  if(fileBinScanning->Read(bufferData, 256) == 256)
  {
    this->indexRecord++;

    for(int i=0; i < 128; i++)
    {
      this->Series1->AddXY(i, bufferData[i]);

      str= IntToStr(this->indexRecord);
      this->EditNumberRecord->SetTextBuf(str.c_str());

    }

  }


}

//---------------------------------------------------------------------------
void __fastcall TFormMain::BtnPrevClick(TObject *Sender)
{
  unsigned short bufferData[128];
  unsigned int result;
  String str;

  if(fileBinScanning == NULL) return;

  this->Series1->Clear();

  if(this->flafDirection == true)
  {
    this->indexRecord--;
    this->flafDirection= false;
  }

  if(this->indexRecord > 0) this->indexRecord--;
  fileBinScanning->Position= this->indexRecord * 256;



  if(fileBinScanning->Read(bufferData, 256) == 256)
  {
    for(int i=0; i < 128; i++)
    {
      this->Series1->AddXY(i, bufferData[i]);

      str= IntToStr(this->indexRecord+1);
      this->EditNumberRecord->SetTextBuf(str.c_str());

    }

  }


}
//---------------------------------------------------------------------------


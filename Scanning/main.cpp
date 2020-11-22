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
  //this->fileBinCalculate= NULL;
  this->fileBinScanning= NULL;

}

//---------------------------------------------------------------------------
void __fastcall TFormMain::BtnOpenFileCalculateClick(TObject *Sender)
{
  TFileStream* fileScanned;

  this->DialogOpenFile->Filter= "BIN-Files|*.bin";
  if(this->DialogOpenFile->Execute())
  {
    fileScanned = new TFileStream(this->DialogOpenFile->FileName, fmOpenRead);

    this->EditOpenFileCalculate->SetTextBuf(this->DialogOpenFile->FileName.c_str());

    this->Calculate(fileScanned);

    delete(fileScanned);
  }

}

//---------------------------------------------------------------------------
void TFormMain::Calculate(TFileStream* fileScanned)
{
  unsigned short bufferData[128];
  unsigned short kData[128];
  unsigned long calculateData[240];


  /*fileScanned->Position= 4*256;
  if(fileScanned->Read(bufferData, 256) == 256)
  {
    for(int k=0; k < 128; k++) kData[k]= bufferData[k];
  }
  //if(fileScanned->Read(bufferData, 256) == 256)
  //{
  //  for(int k=0; k < 128; k++) kData[k] += bufferData[k];
  //}
  for(int k=0; k < 128; k++) kData[k]= kData[k] / 2 + 200;
  */

  this->SeriesCalculate->Clear();

  fileScanned->Position= 0;
  for(int i=0; i < 240; i++)
  {
    if(fileScanned->Read(bufferData, 256) == 256)
    {
      calculateData[i]= 0;
      for(int k=0; k < 128; k++)
      {
        calculateData[i] += bufferData[k];
      }

      this->SeriesCalculate->AddXY(i, calculateData[i]);

    }
    else break;

  }

}

//---------------------------------------------------------------------------
void __fastcall TFormMain::ButtonOpenFileImageColorClick(TObject *Sender)
{
  TFileStream* fileScanned;

  this->DialogOpenFile->Filter= "BIN-Files|*.bin";
  if(this->DialogOpenFile->Execute())
  {
    fileScanned = new TFileStream(this->DialogOpenFile->FileName, fmOpenRead);

    this->EditOpenFileImage->SetTextBuf(this->DialogOpenFile->FileName.c_str());

    this->ShowScannedFile(fileScanned, 1);

    delete(fileScanned);
  }

}

//---------------------------------------------------------------------------
void TFormMain::ShowScannedFile(TFileStream* fileScanned, unsigned char colorOrWb)
{
  unsigned short stepHeight;
  unsigned short stepWidth;
  unsigned short bufferData[128];
  unsigned short redColor;
  unsigned short greenColor;
  unsigned short blueColor;
  unsigned long color;

  stepHeight= (this->ImageImage->ClientHeight - 10) / 128;
  stepWidth= (this->ImageImage->ClientWidth - 10) / 240;

  fileScanned->Position= 0;
  for(int i=0; i < 240; i++)
  {
    if(fileScanned->Read(bufferData, 256) == 256)
    {
      for(int l=0; l < stepWidth; l++)
      {

        for(int k=0; k < 128; k++)
        {
          for(int n=0; n < stepHeight; n++)
          {
            if(colorOrWb == 0) this->ImageImage->Canvas->Pixels[5+i*stepWidth+l][5+k*stepHeight+n]= (TColor)RGB((bufferData[k]>>4), (bufferData[k]>>4), (bufferData[k]>>4));
            else this->ImageImage->Canvas->Pixels[5+i*stepWidth+l][5+k*stepHeight+n]= (TColor)RGB(CalculateRed(bufferData[k]), CalculateGreen(bufferData[k]), CalculateBlue(bufferData[k]));
          }

        }

      }

    }
    else break;

  }


}

//---------------------------------------------------------------------------
unsigned short TFormMain::CalculateRed(unsigned short data)
{
  /*
  unsigned short result;

  if(data > 2047)
  {
    result= (data - 2048) / 8;
  }
  else result= 0;


  return(result);
  */

  return(data / 16);
}

//---------------------------------------------------------------------------
unsigned short TFormMain::CalculateGreen(unsigned short data)
{
  unsigned short result;

  if(data > 2047)
  {
    if(data < (2047+8)) result= 255;
    else result= (256 - (data - 2047) / 8);
  }
  else
  {
    result= (data - 1) / 8;
  }

  return(result);
}

//---------------------------------------------------------------------------
unsigned short TFormMain::CalculateBlue(unsigned short data)
{
  /*
  unsigned short result;

  if(data < 2048)
  {
    result= (2048 - data) / 8;
  }
  else result= 0;

  return(result);
  */

  return((256- data / 16));
}

//---------------------------------------------------------------------------
void __fastcall TFormMain::ButtonOpenFileBWClick(TObject *Sender)
{
  TFileStream* fileScanned;

  this->DialogOpenFile->Filter= "BIN-Files|*.bin";
  if(this->DialogOpenFile->Execute())
  {
    fileScanned = new TFileStream(this->DialogOpenFile->FileName, fmOpenRead);

    this->EditOpenFileImage->SetTextBuf(this->DialogOpenFile->FileName.c_str());

    this->ShowScannedFile(fileScanned, 0);

    delete(fileScanned);
  }

}
//---------------------------------------------------------------------------


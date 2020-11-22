//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Chart.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControlMain;
        TTabSheet *TabSheetOneRecord;
        TTabSheet *TabSheetCalculate;
        TTabSheet *TabSheetImage;
        TChart *ChartOneRecord;
        TLineSeries *SeriesOneRecord;
        TChart *ChartCalculate;
        TLineSeries *SeriesCalculate;
        TOpenDialog *DialogOpenFile;
        TBitBtn *BtnOpenFileCalculate;
        TEdit *EditOpenFileCalculate;
        TPanel *PanelImage;
  TButton *ButtonOpenFileImageColor;
  TImage *ImageImage;
  TEdit *EditOpenFileImage;
  TButton *ButtonOpenFileBW;
        void __fastcall BtnOpenFileCalculateClick(TObject *Sender);
        void __fastcall ButtonOpenFileImageColorClick(TObject *Sender);
  void __fastcall ButtonOpenFileBWClick(TObject *Sender);

private:	// User declarations
  TFileStream* fileBinScanning;
  //TFileStream* fileBinCalculate;

  void Calculate(TFileStream*);
  void ShowScannedFile(TFileStream*, unsigned char);

  unsigned short CalculateRed(unsigned short);
  unsigned short CalculateGreen(unsigned short);
  unsigned short CalculateBlue(unsigned short);


public:		// User declarations
        __fastcall TFormMain(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif

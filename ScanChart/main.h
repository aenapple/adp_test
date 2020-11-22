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
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Series.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
        TPanel *PanelMain;
        TChart *ChartScan;
        TLineSeries *Series1;
        TBitBtn *BtnOpenFile;
        TOpenDialog *DialogOpenFile;
        TLineSeries *Series2;
        TBitBtn *BtnNext;
        TBitBtn *BtnPrev;
        TEdit *EditNumberRecord;
        void __fastcall BtnOpenFileClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall BtnNextClick(TObject *Sender);
        void __fastcall BtnPrevClick(TObject *Sender);

private:	// User declarations
  TFileStream* fileBinScanning;
  unsigned short indexRecord;
  bool flafDirection;

public:		// User declarations
        __fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif

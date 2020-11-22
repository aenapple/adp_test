//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Series.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TComThread;
class TFormMain : public TForm
{
__published:	// IDE-managed Components
	TChart *Chart;
	TPanel *Panel;
	TButton *Start;
	TButton *Stop;
	TButton *Save;
	TButton *Load;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TComboBox *ComboBoxBitrate;
	TComboBox *ComboBoxCom;
	TCheckBox *CheckBoxFixed;
        TFastLineSeries *Series1;
	void __fastcall StartClick(TObject *Sender);
	void __fastcall StopClick(TObject *Sender);
	void __fastcall SaveClick(TObject *Sender);
	void __fastcall LoadClick(TObject *Sender);
	void __fastcall CheckBoxFixedClick(TObject *Sender);
private:	//  User declarations
	TComThread* ComThread;


public:		// User declarations
	__fastcall TFormMain(TComponent* Owner);

        unsigned char binBuffer[500000];
        int indexBinBuffer;
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif

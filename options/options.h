//---------------------------------------------------------------------------

#ifndef optionsH
#define optionsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFormOptions : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
    TPageControl *TabControll;
    TTabSheet *TabSheet1;
    TTabSheet *TabSheet3;
    TGroupBox *GroupBox1;
    TTrackBar *textureQuality;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TEdit *Edit1;
    TLabel *Label5;
    TLabel *Label6;
    TEdit *Edit2;
    TEdit *Edit3;
    TLabel *Label7;
    TEdit *Edit4;
    TEdit *Edit5;
    TLabel *Label10;
    TLabel *Label12;
    TLabel *Label11;
    TLabel *Label9;
    TLabel *Label8;
    TEdit *Edit6;
    TEdit *Edit7;
    TEdit *Edit8;
    TEdit *Edit9;
    TGroupBox *GroupBox;
    TGroupBox *GroupBox2;
    TLabel *Label13;
    TLabel *Label14;
    TTrackBar *TrackBar1;
    TLabel *Label15;
    void __fastcall FormKeyPress(TObject *Sender, char &Key);
private:	// Anwender-Deklarationen
public:		// Anwender-Deklarationen
    __fastcall TFormOptions(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormOptions *FormOptions;
//---------------------------------------------------------------------------
#endif

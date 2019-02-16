//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "options.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormOptions *FormOptions;
//---------------------------------------------------------------------------
__fastcall TFormOptions::TFormOptions(TComponent* Owner)
    : TForm(Owner)
{
    Top     = 0;
    Left    = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFormOptions::FormKeyPress(TObject *Sender, char &Key)
{
    if( Key == 'o' ) Hide();    
}
//---------------------------------------------------------------------------

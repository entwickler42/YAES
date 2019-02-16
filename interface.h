//---------------------------------------------------------------------------

#ifndef interfaceH
#define interfaceH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "TOpenGLAPPanel.h"
#include <ExtCtrls.hpp>
#include <Buttons.hpp>

#include "world/world.h"
#include "camera/mousecamera.h"
#include <Dialogs.hpp>

//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
    TOpenGLAPPanel *surface;
    TSpeedButton *btnQuit;
    TOpenDialog *OpenDialog;
    TSaveDialog *SaveDialog;
    void __fastcall FormKeyPress(TObject *Sender, char &Key);
    void __fastcall surfaceInit(TObject *Sender);
    void __fastcall surfacePaint(TObject *Sender);
    void __fastcall surfaceResize(TObject *Sender);
    void __fastcall surfaceMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall surfaceMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall btnQuitClick(TObject *Sender);
    void __fastcall surfaceMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
private:	// Anwender-Deklarationen
    int mouse_x, mouse_y, mouse_down_x, mouse_down_y;
    World  *world;
    MouseCamera *camera;

public:		// Anwender-Deklarationen
    __fastcall TMainForm(TComponent* Owner);
    __fastcall ~TMainForm();
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif

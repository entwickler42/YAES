//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("debug\debug.cpp", FormDebug);
USEFORM("interface.cpp", MainForm);
USEFORM("debug\vertexmap.cpp", FormVertexMap);
USEFORM("options\options.cpp", FormOptions);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->Title = "YaES";
         Application->CreateForm(__classid(TMainForm), &MainForm);
         Application->CreateForm(__classid(TFormDebug), &FormDebug);
         Application->CreateForm(__classid(TFormVertexMap), &FormVertexMap);
         Application->CreateForm(__classid(TFormOptions), &FormOptions);
         Application->Run();
    }
    catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    catch (...)
    {
         try
         {
             throw Exception("");
         }
         catch (Exception &exception)
         {
             Application->ShowException(&exception);
         }
    }
    return 0;
}
//---------------------------------------------------------------------------

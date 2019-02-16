//---------------------------------------------------------------------------

#include <vcl.h>
#include "debug/debug.h"
#include "debug/vertexmap.h"
#include "options/options.h"
#pragma hdrstop

#include <math.h>
#include "interface.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TOpenGLAPPanel"
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
    : TForm(Owner)
{
    world  = new World(surface);
    camera = new MouseCamera();
    camera->move_UD(-6.5f);
    camera->rotate_UD(30.0f);
}

//---------------------------------------------------------------------------
__fastcall TMainForm::~TMainForm()
{
    delete world;
    delete camera;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormKeyPress(TObject *Sender, char &Key)
{
    AnsiString buf;
    
    switch(Key)
    {
        case 'Q': exit(0);break;
        case '1': camera->setMode(EGO) ;break;
        case '2': camera->setMode(OBJECT) ;break;
        case 'l':
            OpenDialog->Execute();
            if(OpenDialog->FileName.Length() > 0 )  world->load(OpenDialog->FileName.c_str());
            world->needs_update = true;
            surface->Repaint();
            break;
        case 'L':
            SaveDialog->Execute();
//            if(SaveDialog->FileName.Length() > 0 )  world->saveFile(SavenDialog->FileName.c_str());
            break;
        case 'o': FormOptions->Showing ? FormOptions->Hide() : FormOptions->Show(); break;
        case 'i': FormDebug->Showing ? FormDebug->Hide() : FormDebug->Show() ;break;
        case 'p':
            FormVertexMap->Showing ? FormVertexMap->Hide() : FormVertexMap->Show();
            FormVertexMap->ListBox->Clear();
/*            for(unsigned int i=0;i<world->sector_v.size();i++)
                for(unsigned int j=0; j<world->sector_v[i].size; j++)
                {
                    double x,y,z,u,v;

                    for(unsigned int k=0;k<3;k++)
                    {
                        x = world->sector_v[i].triangle[j].vertex[k].x;
                        y = world->sector_v[i].triangle[j].vertex[k].y;
                        z = world->sector_v[i].triangle[j].vertex[k].z;
                        u = world->sector_v[i].triangle[j].vertex[k].u;
                        v = world->sector_v[i].triangle[j].vertex[k].v;

                        buf.sprintf("%0.2f %0.2f %0.2f %0.2f %0.2f",x,y,z,u,v);
                        FormVertexMap->ListBox->AddItem(buf,FormVertexMap->ListBox);
                    }
                }    */
            break;

        // Steuerung
        case 'x':
            camera->move_OW(-0.2f);
            surface->Repaint();
            break;
        case 'y':
            camera->move_OW( 0.2f);
            surface->Repaint();
            break;
        case 'w':
            camera->move_NS( 0.2f);
            surface->Repaint();
            break;
        case 'W':
            camera->move_NS( 0.4f);
            surface->Repaint();
            break;
        case 's':
            camera->move_NS(-0.2f);
            surface->Repaint();
            break;
        case 'S':
            camera->move_NS(-0.4f);
            surface->Repaint();
            break;
        case 'd':
            camera->rotate_OW(-2.0f );
            surface->Repaint();
            break;
        case 'D':
            camera->rotate_OW(-4.0f );
            surface->Repaint();
            break;
        case 'a':
            camera->rotate_OW(2.0f);
            surface->Repaint();
            break;
        case 'A':
            camera->rotate_OW(4.0f);
            surface->Repaint();
            break;
        case 'r':
            camera->rotate_UD(2.0f);
            surface->Repaint();
            break;
        case 'f':
            camera->rotate_UD(-2.0f);
            surface->Repaint();
            break;
        case 'q':
            camera->rotate_NS(2.0f);
            surface->Repaint();
            break;
        case 'e':
            camera->rotate_NS(-2.0f);
            surface->Repaint();
            break;
        case 't':
            camera->move_NS_UD(2.0f);
            surface->Repaint();
            break;
        case 'g':
            camera->move_NS_UD(-2.0f);
            surface->Repaint();
            break;
        case 'T':
            camera->rotate_Y_aroundPoint(2.0f, surface->Width / 2 , surface->Height / 2);
            surface->Repaint();
            break;
        case 'G':
            camera->rotate_Y_aroundPoint(-2.0f, surface->Width / 2 , surface->Height / 2);
            surface->Repaint();
            break;
    };
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::surfaceInit(TObject *Sender)
{
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glEnable(GL_DEPTH_TEST);

    surfaceResize(Sender);
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::surfaceResize(TObject *Sender)
{
    glViewport(0,0,surface->Width,surface->Height);

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();

    gluPerspective(45.0f,(GLfloat)surface->Width/(GLfloat)surface->Height,0.1f,150.0f);
	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();

    surface->Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::surfacePaint(TObject *Sender)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // get camera values
    AnsiString buf;

    buf.sprintf("%0.2f",camera->xpos());
    FormDebug->camX->SetTextBuf(buf.c_str());
    buf.sprintf("%0.2f",camera->ypos());
    FormDebug->camY->SetTextBuf(buf.c_str());
    buf.sprintf("%0.2f",camera->zpos());
    FormDebug->camZ->SetTextBuf(buf.c_str());
    buf.sprintf("%0.2f",camera->xrot());
    FormDebug->rotX->SetTextBuf(buf.c_str());
    buf.sprintf("%0.2f",camera->yrot());
    FormDebug->rotY->SetTextBuf(buf.c_str());
    buf.sprintf("%0.2f",camera->zrot());
    FormDebug->rotZ->SetTextBuf(buf.c_str());

    // Read Options on Change
    if(world->getFilter() != FormOptions->textureQuality->Position) world->setFilter(FormOptions->textureQuality->Position);

    // Draw Crossfade
    glPushMatrix();
        glColor3f(1.0f,1.0f,1.0f);
        glTranslatef(0.0f, 0.0f, -0.11f);

        glBegin(GL_LINES);
            glVertex3f(0.0f ,-0.0015f, 0.0f);
            glVertex3f(0.0f , 0.0015f, 0.0f);

            glVertex3f(-0.0015f ,0.0f, 0.0f);
            glVertex3f( 0.0015f ,0.0f, 0.0f);
        glEnd();

        glColor3f(1.0f, 1.0f, 1.0f);
    glPopMatrix();

    // Draw Scene
    camera->look();
    world->paint();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::surfaceMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    mouse_down_x = X;   mouse_down_y = Y;
    camera->onDown(X,Y,Button);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::surfaceMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    mouse_x = X;    mouse_y = Y;

    // Update Mouse coordinates
    AnsiString buf;

    buf.sprintf("%i",X);
    FormDebug->X->SetTextBuf(buf.c_str());

    buf.sprintf("%i",Y);
    FormDebug->Y->SetTextBuf(buf.c_str());

    // calculate GL Mouse coordinates
    GLdouble x,y,z,model[16],proj[16];
    GLfloat c;
    GLint    view[4];

    glReadPixels (X,surface->Height-Y, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &c);

    glGetDoublev  (GL_MODELVIEW_MATRIX, model);
    glGetDoublev  (GL_PROJECTION_MATRIX, proj);
    glGetIntegerv (GL_VIEWPORT, view);

    gluUnProject(X,surface->Height-Y,c,model,proj,view,&x,&y,&z);

    buf.sprintf("%0.2f",x);
    FormDebug->X_GL->SetTextBuf(buf.c_str());

    buf.sprintf("%0.2f",y);
    FormDebug->Y_GL->SetTextBuf(buf.c_str());

    buf.sprintf("%0.2f",z);
    FormDebug->Z_GL->SetTextBuf(buf.c_str());

    camera->onMove(X,Y);
    surface->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::btnQuitClick(TObject *Sender)
{
    exit(0);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::surfaceMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    camera->onUp(X,Y,Button);
}
//---------------------------------------------------------------------------




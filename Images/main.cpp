//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormPaint(TObject *Sender)
{
  Grafik();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormResize(TObject *Sender)
{
  TRect ret = Rect(0,0,ClientWidth,ClientHeight);
  Canvas->FillRect(ret); // ������� Grafik();
}
//---------------------------------------------------------------------------
#include "math.h" // ��� ������� � sin � exp
// �������, ������ ������� ���� ���������
float f(float data)
{
  return 2*sin(data)*exp(data/5);
}

void TForm1::Grafik(void)
{
float x1, x2; // ������� ��������� ��������� �������
float y1, y2; // ������� ��������� �������� ������� float x;
// �������� �������
float dataY, dataX; // �������� ������� � ����� �
float dx; // ���������� ���������
int l, b; // ����� ������ ���� ������� ������ �������
int w, h; // ������ � ������ ������� ������ �������
float mx, my; // ������� �� ���� X � Y
int dataX0, dataY0; // ������ ���������
// ������� ������ �������
1-10; // X � ���������� ������ �������� ����
b = Form1->ClientHeight - 20; // Y � ���������� ������ ������� ����
h = Form1->ClientHeight - 40; // ������
w = Form1->Width - 20; // ������
x1 = 0; // ������ ������� ��������� ���������
x2 = 25; // ������� ������� ��������� ��������� dx = 0.01;
 //��� ���������
// ������ ������������ � ����������� ��������
// ������� �� ������� [xl,x2]
dataX = x1;
y1 = f(dataX); // �������
y2 = f(dataX); // ��������
do
{
dataY = f(dataX);
if (dataY < y1) y1 = dataY;
if (dataY > y2) y2 = dataY;
dataX += dx;
} while (dataX <= x2);

// �������� �������
my = (float)h/abs(y2-y1); // ������� �� ��� Y
mx = w/abs(x2-x1); // ������� �� ��� X
// ���
dataX0 = 1+abs(x1*mx);
dataY0 = b-abs(y1*my);
Canvas->MoveTo(dataX0,b);Canvas->LineTo(dataX0,b-h);
Canvas->MoveTo(1,dataY0);Canvas->LineTo(1+w,dataY0);
//Canvas->TextOutA(dataX0+5,b-h,FloatToStrF(y2,ffGeneral,6.3));
//Canvas->TextOutA(dataX0+5,b,FloatToStrF(y1,ffGeneral, 6.3));
// ���������� ������� x = xl;
do {
dataY = f (dataX);
Canvas->Pixels[dataX0+dataX*mx][dataY0-dataY*my] = clRed;
dataX += dx;
}
while(dataX <= x2);

  for(int i=0; i < 100; i++)
  {
    Canvas->Pixels[i][i] = clRed;
  }

}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  for(int i=0; i < 100; i++)
  {
    Canvas->Pixels[i+100][i+100] = (TColor)RGB(0,255,0); //clRed;

    //Panel1->Canvas->Pixels[i+100][i+100] = (TColor)RGB(255,255,0); //clRed;

    //this->PageControl2->Canvas->Pixels[i+100][i+100] = (TColor)RGB(0,255,0); //clRed;

    this->Image1->Canvas->Pixels[i+100][i+100] = (TColor)RGB(100,i+100,200); //clRed;
    this->Image1->Canvas->Pixels[i+100][i+101] = (TColor)RGB(100,i+100,200); //clRed;
    this->Image1->Canvas->Pixels[i+100][i+102] = (TColor)RGB(100,i+100,200); //clRed;
    this->Image1->Canvas->Pixels[i+100][i+103] = (TColor)RGB(100,i+100,200); //clRed;
    this->Image1->Canvas->Pixels[i+100][i+104] = (TColor)RGB(100,i+100,200); //clRed;
    this->Image1->Canvas->Pixels[i+100][i+105] = (TColor)RGB(100,i+100,200); //clRed;
    this->Image1->Canvas->Pixels[i+100][i+106] = (TColor)RGB(100,i+100,200); //clRed;
    this->Image1->Canvas->Pixels[i+100][i+107] = (TColor)RGB(100,i+100,200); //clRed;
    this->Image1->Canvas->Pixels[i+100][i+108] = (TColor)RGB(100,0,200); //clRed;
    this->Image1->Canvas->Pixels[i+100][i+109] = (TColor)RGB(100,0,200); //clRed;
  }



  this->Image1->ClientWidth;



}
//---------------------------------------------------------------------------


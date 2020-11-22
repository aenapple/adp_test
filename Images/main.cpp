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
  Canvas->FillRect(ret); // стереть Grafik();
}
//---------------------------------------------------------------------------
#include "math.h" // дл€ доступа к sin и exp
// функци€, график которой надо построить
float f(float data)
{
  return 2*sin(data)*exp(data/5);
}

void TForm1::Grafik(void)
{
float x1, x2; // границы изменени€ аргумента функции
float y1, y2; // границы изменени€ значени€ функции float x;
// аргумент функции
float dataY, dataX; // значение функции в точке х
float dx; // приращение аргумента
int l, b; // левый нижний угол области вывода графика
int w, h; // ширина и высота области вывода графика
float mx, my; // масштаб по ос€м X и Y
int dataX0, dataY0; // начало координат
// область вывода графика
1-10; // X Ц координата левого верхнего угла
b = Form1->ClientHeight - 20; // Y Ц координата левого нижнего угла
h = Form1->ClientHeight - 40; // высота
w = Form1->Width - 20; // ширина
x1 = 0; // нижн€€ граница диапазона аргумента
x2 = 25; // верхн€€ граница диапазона аргумента dx = 0.01;
 //шаг аргумента
// найдем максимальное и минимальное значение
// функции на отрезке [xl,x2]
dataX = x1;
y1 = f(dataX); // минимум
y2 = f(dataX); // максимум
do
{
dataY = f(dataX);
if (dataY < y1) y1 = dataY;
if (dataY > y2) y2 = dataY;
dataX += dx;
} while (dataX <= x2);

// вычислим масштаб
my = (float)h/abs(y2-y1); // масштаб по оси Y
mx = w/abs(x2-x1); // масштаб по оси X
// оси
dataX0 = 1+abs(x1*mx);
dataY0 = b-abs(y1*my);
Canvas->MoveTo(dataX0,b);Canvas->LineTo(dataX0,b-h);
Canvas->MoveTo(1,dataY0);Canvas->LineTo(1+w,dataY0);
//Canvas->TextOutA(dataX0+5,b-h,FloatToStrF(y2,ffGeneral,6.3));
//Canvas->TextOutA(dataX0+5,b,FloatToStrF(y1,ffGeneral, 6.3));
// построение графика x = xl;
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


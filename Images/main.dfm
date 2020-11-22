object Form1: TForm1
  Left = 264
  Top = 116
  Width = 1305
  Height = 750
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnPaint = FormPaint
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 936
    Top = 648
    Width = 137
    Height = 25
    Caption = 'Button1'
    TabOrder = 0
    OnClick = Button1Click
  end
  object PageControl1: TPageControl
    Left = 864
    Top = 296
    Width = 393
    Height = 281
    ActivePage = TabSheet2
    TabIndex = 1
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = 'TabSheet1'
    end
    object TabSheet2: TTabSheet
      Caption = 'TabSheet2'
      ImageIndex = 1
      object Image1: TImage
        Left = 0
        Top = 0
        Width = 385
        Height = 257
      end
    end
  end
end

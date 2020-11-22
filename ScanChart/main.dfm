object FormMain: TFormMain
  Left = 311
  Top = 110
  Width = 1016
  Height = 738
  AutoSize = True
  Caption = 'Scanning'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object PanelMain: TPanel
    Left = 0
    Top = 0
    Width = 1000
    Height = 700
    Caption = 'PanelMain'
    TabOrder = 0
    object ChartScan: TChart
      Left = 1
      Top = 1
      Width = 1000
      Height = 560
      BackWall.Brush.Color = clWhite
      BackWall.Brush.Style = bsClear
      Title.Text.Strings = (
        'Scanning Value')
      BottomAxis.Automatic = False
      BottomAxis.AutomaticMaximum = False
      BottomAxis.AutomaticMinimum = False
      BottomAxis.Maximum = 128
      LeftAxis.Automatic = False
      LeftAxis.AutomaticMaximum = False
      LeftAxis.AutomaticMinimum = False
      LeftAxis.Maximum = 4096
      Legend.Visible = False
      RightAxis.Visible = False
      View3D = False
      TabOrder = 0
      object Series1: TLineSeries
        Marks.ArrowLength = 8
        Marks.Visible = False
        SeriesColor = clRed
        Title = 'SeriesScan'
        Pointer.InflateMargins = True
        Pointer.Style = psRectangle
        Pointer.Visible = False
        XValues.DateTime = False
        XValues.Name = 'X'
        XValues.Multiplier = 1
        XValues.Order = loAscending
        YValues.DateTime = False
        YValues.Name = 'Y'
        YValues.Multiplier = 1
        YValues.Order = loNone
      end
      object Series2: TLineSeries
        Marks.ArrowLength = 8
        Marks.Visible = False
        SeriesColor = clGreen
        Title = 'SeriesScan2'
        Pointer.InflateMargins = True
        Pointer.Style = psRectangle
        Pointer.Visible = False
        XValues.DateTime = False
        XValues.Name = 'X'
        XValues.Multiplier = 1
        XValues.Order = loAscending
        YValues.DateTime = False
        YValues.Name = 'Y'
        YValues.Multiplier = 1
        YValues.Order = loNone
      end
    end
    object BtnOpenFile: TBitBtn
      Left = 17
      Top = 569
      Width = 121
      Height = 25
      Caption = 'Open File'
      TabOrder = 1
      OnClick = BtnOpenFileClick
    end
    object BtnNext: TBitBtn
      Left = 145
      Top = 657
      Width = 121
      Height = 25
      Caption = 'Next'
      TabOrder = 2
      OnClick = BtnNextClick
    end
    object BtnPrev: TBitBtn
      Left = 17
      Top = 657
      Width = 121
      Height = 25
      Caption = 'Prev'
      TabOrder = 3
      OnClick = BtnPrevClick
    end
    object EditNumberRecord: TEdit
      Left = 105
      Top = 625
      Width = 72
      Height = 21
      TabOrder = 4
      Text = '0'
    end
  end
  object DialogOpenFile: TOpenDialog
    Filter = 'BIN-files|*.bin'
    Left = 24
    Top = 608
  end
end

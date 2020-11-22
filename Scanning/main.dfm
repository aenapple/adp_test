object FormMain: TFormMain
  Left = 295
  Top = 116
  Width = 1216
  Height = 838
  AutoSize = True
  Caption = 'Scanning'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object PageControlMain: TPageControl
    Left = 0
    Top = 0
    Width = 1200
    Height = 800
    ActivePage = TabSheetImage
    TabIndex = 2
    TabOrder = 0
    object TabSheetOneRecord: TTabSheet
      Caption = 'One Record'
      object ChartOneRecord: TChart
        Left = -1
        Top = 0
        Width = 1194
        Height = 553
        BackWall.Brush.Color = clWhite
        BackWall.Brush.Style = bsClear
        Title.Text.Strings = (
          'One Record')
        BottomAxis.Automatic = False
        BottomAxis.AutomaticMaximum = False
        BottomAxis.AutomaticMinimum = False
        BottomAxis.Maximum = 130
        LeftAxis.Automatic = False
        LeftAxis.AutomaticMaximum = False
        LeftAxis.AutomaticMinimum = False
        LeftAxis.Maximum = 4100
        Legend.Visible = False
        View3D = False
        TabOrder = 0
        object SeriesOneRecord: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clRed
          Title = 'SeriesOneRecord'
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
    end
    object TabSheetCalculate: TTabSheet
      Caption = 'Calculate'
      ImageIndex = 1
      object ChartCalculate: TChart
        Left = 0
        Top = 0
        Width = 1193
        Height = 505
        BackWall.Brush.Color = clWhite
        BackWall.Brush.Style = bsClear
        Title.Text.Strings = (
          'Calculate')
        BottomAxis.Automatic = False
        BottomAxis.AutomaticMaximum = False
        BottomAxis.AutomaticMinimum = False
        BottomAxis.Maximum = 240
        Legend.Visible = False
        View3D = False
        TabOrder = 0
        object SeriesCalculate: TLineSeries
          Marks.ArrowLength = 8
          Marks.Visible = False
          SeriesColor = clRed
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
      object BtnOpenFileCalculate: TBitBtn
        Left = 24
        Top = 536
        Width = 137
        Height = 25
        Caption = 'Open File'
        TabOrder = 1
        OnClick = BtnOpenFileCalculateClick
      end
      object EditOpenFileCalculate: TEdit
        Left = 8
        Top = 512
        Width = 681
        Height = 21
        TabOrder = 2
      end
    end
    object TabSheetImage: TTabSheet
      Caption = 'Image'
      ImageIndex = 2
      object PanelImage: TPanel
        Left = 0
        Top = 0
        Width = 1193
        Height = 513
        TabOrder = 0
        object ImageImage: TImage
          Left = 112
          Top = 64
          Width = 970
          Height = 394
        end
      end
      object ButtonOpenFileImageColor: TButton
        Left = 8
        Top = 576
        Width = 121
        Height = 25
        Caption = 'Open File Color'
        TabOrder = 1
        OnClick = ButtonOpenFileImageColorClick
      end
      object EditOpenFileImage: TEdit
        Left = 16
        Top = 528
        Width = 641
        Height = 21
        TabOrder = 2
      end
      object ButtonOpenFileBW: TButton
        Left = 144
        Top = 576
        Width = 121
        Height = 25
        Caption = 'Open File B/W'
        TabOrder = 3
        OnClick = ButtonOpenFileBWClick
      end
    end
  end
  object DialogOpenFile: TOpenDialog
    Left = 1240
    Top = 192
  end
end

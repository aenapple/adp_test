object FormMain: TFormMain
  Left = 634
  Top = 297
  Width = 583
  Height = 551
  Caption = 'Box Push Time'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Chart: TChart
    Left = 0
    Top = 0
    Width = 567
    Height = 461
    BackWall.Brush.Color = clWhite
    BackWall.Brush.Style = bsClear
    Title.Text.Strings = (
      #1043#1088#1072#1092#1080#1082' '#1074#1088#1077#1084#1077#1085#1080' '#1087#1077#1088#1077#1090#1072#1083#1082#1080#1074#1072#1085#1080#1103' '#1086#1090' '#1082#1086#1083#1080#1095#1077#1089#1090#1074#1072' '#1073#1072#1085#1082#1085#1086#1090'.')
    Legend.Visible = False
    View3D = False
    Align = alClient
    TabOrder = 0
    object CheckBoxFixed: TCheckBox
      Left = 8
      Top = 8
      Width = 97
      Height = 17
      Caption = 'Fixed axis'
      Checked = True
      State = cbChecked
      TabOrder = 0
      OnClick = CheckBoxFixedClick
    end
    object Series1: TFastLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clRed
      LinePen.Color = clRed
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
  object Panel: TPanel
    Left = 0
    Top = 461
    Width = 567
    Height = 52
    Align = alBottom
    TabOrder = 1
    object Start: TButton
      Left = 16
      Top = 8
      Width = 75
      Height = 25
      Caption = 'Start'
      TabOrder = 0
      OnClick = StartClick
    end
    object Stop: TButton
      Left = 104
      Top = 8
      Width = 75
      Height = 25
      Caption = 'Stop'
      TabOrder = 1
      OnClick = StopClick
    end
    object Save: TButton
      Left = 192
      Top = 8
      Width = 75
      Height = 25
      Caption = 'Save'
      TabOrder = 2
      OnClick = SaveClick
    end
    object Load: TButton
      Left = 280
      Top = 8
      Width = 75
      Height = 25
      Caption = 'Load'
      TabOrder = 3
      OnClick = LoadClick
    end
    object ComboBoxBitrate: TComboBox
      Left = 368
      Top = 8
      Width = 89
      Height = 21
      ItemHeight = 13
      ItemIndex = 1
      TabOrder = 4
      Text = '57600'
      Items.Strings = (
        '9600'
        '57600')
    end
    object ComboBoxCom: TComboBox
      Left = 472
      Top = 8
      Width = 81
      Height = 21
      ItemHeight = 13
      ItemIndex = 0
      TabOrder = 5
      Text = 'COM1'
      Items.Strings = (
        'COM1'
        'COM2'
        'COM3'
        'COM4'
        'COM5'
        'COM6'
        'COM7'
        'COM8')
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 184
    Top = 88
  end
  object SaveDialog1: TSaveDialog
    Left = 232
    Top = 88
  end
end

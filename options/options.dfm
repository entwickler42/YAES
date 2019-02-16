object FormOptions: TFormOptions
  Left = 262
  Top = 145
  BorderStyle = bsNone
  Caption = 'Options'
  ClientHeight = 187
  ClientWidth = 270
  Color = clBlack
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWhite
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  OnKeyPress = FormKeyPress
  PixelsPerInch = 96
  TextHeight = 13
  object TabControll: TPageControl
    Left = 0
    Top = 0
    Width = 270
    Height = 187
    ActivePage = TabSheet1
    Align = alClient
    TabIndex = 0
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'OpenGL'
      object GroupBox1: TGroupBox
        Left = 0
        Top = 8
        Width = 261
        Height = 61
        Caption = 'Texture Quality'
        TabOrder = 0
        object Label1: TLabel
          Left = 16
          Top = 32
          Width = 30
          Height = 17
          Caption = 'High'
        end
        object Label2: TLabel
          Left = 112
          Top = 32
          Width = 37
          Height = 13
          Caption = 'Medium'
        end
        object Label3: TLabel
          Left = 228
          Top = 32
          Width = 20
          Height = 13
          Caption = 'Low'
        end
        object textureQuality: TTrackBar
          Left = 8
          Top = 16
          Width = 245
          Height = 17
          Max = 2
          Orientation = trHorizontal
          PageSize = 1
          Frequency = 1
          Position = 1
          SelEnd = 0
          SelStart = 0
          TabOrder = 0
          ThumbLength = 15
          TickMarks = tmBottomRight
          TickStyle = tsNone
        end
      end
      object GroupBox2: TGroupBox
        Left = 1
        Top = 84
        Width = 261
        Height = 61
        Caption = 'Rendering Quality'
        TabOrder = 1
        object Label13: TLabel
          Left = 16
          Top = 32
          Width = 22
          Height = 13
          Caption = 'High'
        end
        object Label14: TLabel
          Left = 112
          Top = 32
          Width = 37
          Height = 13
          Caption = 'Medium'
        end
        object Label15: TLabel
          Left = 228
          Top = 32
          Width = 20
          Height = 13
          Caption = 'Low'
        end
        object TrackBar1: TTrackBar
          Left = 8
          Top = 16
          Width = 245
          Height = 17
          Max = 2
          Orientation = trHorizontal
          PageSize = 1
          Frequency = 1
          Position = 1
          SelEnd = 0
          SelStart = 0
          TabOrder = 0
          ThumbLength = 15
          TickMarks = tmBottomRight
          TickStyle = tsNone
        end
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Steuerung'
      ImageIndex = 2
      object GroupBox: TGroupBox
        Left = 0
        Top = 0
        Width = 261
        Height = 157
        TabOrder = 0
        object Label4: TLabel
          Left = 23
          Top = 28
          Width = 74
          Height = 13
          Caption = 'Move Forward :'
        end
        object Label5: TLabel
          Left = 12
          Top = 52
          Width = 84
          Height = 13
          Caption = 'Move Backward :'
        end
        object Label6: TLabel
          Left = 48
          Top = 76
          Width = 49
          Height = 13
          Caption = 'Turn Left :'
        end
        object Label7: TLabel
          Left = 40
          Top = 100
          Width = 56
          Height = 13
          Caption = 'Turn Right :'
        end
        object Label10: TLabel
          Left = 64
          Top = 124
          Width = 32
          Height = 13
          Caption = 'Duck :'
        end
        object Label12: TLabel
          Left = 177
          Top = 100
          Width = 25
          Height = 13
          Caption = 'Use :'
        end
        object Label11: TLabel
          Left = 172
          Top = 76
          Width = 31
          Height = 13
          Caption = 'Jump :'
        end
        object Label9: TLabel
          Left = 144
          Top = 52
          Width = 59
          Height = 13
          Caption = 'Stafe Right :'
        end
        object Label8: TLabel
          Left = 152
          Top = 28
          Width = 52
          Height = 13
          Caption = 'Stafe Left :'
        end
        object Edit1: TEdit
          Left = 108
          Top = 24
          Width = 17
          Height = 21
          Color = clBlack
          TabOrder = 0
          Text = 'w'
        end
        object Edit2: TEdit
          Left = 108
          Top = 48
          Width = 17
          Height = 21
          Color = clBlack
          TabOrder = 1
          Text = 's'
        end
        object Edit3: TEdit
          Left = 108
          Top = 72
          Width = 17
          Height = 21
          Color = clBlack
          TabOrder = 2
          Text = 'a'
        end
        object Edit4: TEdit
          Left = 108
          Top = 96
          Width = 17
          Height = 21
          Color = clBlack
          TabOrder = 3
          Text = 'd'
        end
        object Edit5: TEdit
          Left = 108
          Top = 120
          Width = 17
          Height = 21
          Color = clBlack
          TabOrder = 4
          Text = 'c'
        end
        object Edit6: TEdit
          Left = 216
          Top = 24
          Width = 17
          Height = 21
          Color = clBlack
          TabOrder = 5
          Text = 'y'
        end
        object Edit7: TEdit
          Left = 216
          Top = 48
          Width = 17
          Height = 21
          Color = clBlack
          TabOrder = 6
          Text = 'x'
        end
        object Edit8: TEdit
          Left = 216
          Top = 72
          Width = 17
          Height = 21
          Color = clBlack
          TabOrder = 7
          Text = ' '
        end
        object Edit9: TEdit
          Left = 216
          Top = 96
          Width = 17
          Height = 21
          Color = clBlack
          TabOrder = 8
          Text = 'e'
        end
      end
    end
  end
end

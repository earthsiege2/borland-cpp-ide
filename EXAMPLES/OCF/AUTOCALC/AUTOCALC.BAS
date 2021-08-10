Function CalcTest()
  On Error Resume Next
  Set Calc = GetObject(class:="OCCalc.Application")
  Created = Err
  If Err Then Set Calc = CreateObject("OCCalc.Application")
  On Error GoTo 0
  With Calc
    .Operand = 123
    .Op = "Equals"
    .Evaluate
    .Operand = 333
    .Op = "Add"
    .Evaluate
    .Window.Color = 123456
    .Display
    .Button Key:="+10000+200000="
    .Window.Caption = Now()
     CalcTest = Calc
    Debug.Print CalcTest
    Debug.Print .Array.Count
    For Each Item In .Array
      Debug.Print Item;
    Next Item
    Debug.Print
    Debug.Print .Window.Buttons.Count
    For Each Key In .Window.Buttons
      Save = Key.Text
      Key.Activate = True
      For i = 1 To 24
        j = (i Mod 4) And (24 - i)
        If ((i Mod 8) < 4) Then
          Key.Text = Save & Space(j)
        Else
          Key.Text = Space(j) & Save
        End If
      Next i
      Key.Activate = False
     Next Key
    .Accumulator = .LookAtWindow(Window:=.Window)
    .Display
    .Window.Color = RGB(255, 255, 0)
    If Created Then .Quit
  End With
End Function


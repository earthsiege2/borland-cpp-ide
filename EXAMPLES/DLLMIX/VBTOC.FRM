VERSION 4.00
Begin VB.Form Form1 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Calling from Visual Basic to a Borland C++ DLL"
   ClientHeight    =   3156
   ClientLeft      =   2256
   ClientTop       =   1596
   ClientWidth     =   7032
   BeginProperty Font 
      name            =   "MS Sans Serif"
      charset         =   0
      weight          =   700
      size            =   7.8
      underline       =   0   'False
      italic          =   0   'False
      strikethrough   =   0   'False
   EndProperty
   ForeColor       =   &H80000008&
   Height          =   3540
   Icon            =   "vbtoc.frx":0000
   Left            =   2208
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   Picture         =   "vbtoc.frx":030A
   ScaleHeight     =   3156
   ScaleWidth      =   7032
   Top             =   1260
   Width           =   7128
   Begin VB.CommandButton cmdClose 
      Caption         =   "Close"
      BeginProperty Font 
         name            =   "MS Sans Serif"
         charset         =   0
         weight          =   400
         size            =   7.8
         underline       =   0   'False
         italic          =   0   'False
         strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   4800
      TabIndex        =   5
      Top             =   2520
      Width           =   975
   End
   Begin VB.CommandButton cmdUnhandled 
      Caption         =   "Unhandled Exception"
      BeginProperty Font 
         name            =   "MS Sans Serif"
         charset         =   0
         weight          =   400
         size            =   7.8
         underline       =   0   'False
         italic          =   0   'False
         strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   4080
      TabIndex        =   4
      Top             =   2040
      Width           =   2655
   End
   Begin VB.CommandButton cmdExceptionTest 
      Caption         =   "Exception Test"
      BeginProperty Font 
         name            =   "MS Sans Serif"
         charset         =   0
         weight          =   400
         size            =   7.8
         underline       =   0   'False
         italic          =   0   'False
         strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   4080
      TabIndex        =   3
      Top             =   1560
      Width           =   2655
   End
   Begin VB.CommandButton cmdAverage 
      Caption         =   "double Average(double, float)"
      BeginProperty Font 
         name            =   "MS Sans Serif"
         charset         =   0
         weight          =   400
         size            =   7.8
         underline       =   0   'False
         italic          =   0   'False
         strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   4080
      TabIndex        =   2
      Top             =   1080
      Width           =   2655
   End
   Begin VB.CommandButton cmdMultiply 
      Caption         =   "long Multiply(short, int)"
      BeginProperty Font 
         name            =   "MS Sans Serif"
         charset         =   0
         weight          =   400
         size            =   7.8
         underline       =   0   'False
         italic          =   0   'False
         strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   4080
      TabIndex        =   1
      Top             =   600
      Width           =   2655
   End
   Begin VB.CommandButton cmdMessage 
      Caption         =   "int Message(const char *)"
      BeginProperty Font 
         name            =   "MS Sans Serif"
         charset         =   0
         weight          =   400
         size            =   7.8
         underline       =   0   'False
         italic          =   0   'False
         strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   4080
      TabIndex        =   0
      Top             =   120
      Width           =   2655
   End
End
Attribute VB_Name = "Form1"
Attribute VB_Creatable = False
Attribute VB_Exposed = False

 Private Declare Function VBMessage Lib "Bcdll.dll" (ByVal msg As String) As Integer
 Private Declare Sub VBExceptionTest Lib "Bcdll.dll" ()
 Private Declare Sub VBUnhandledException Lib "Bcdll.dll" ()
 Private Declare Function VBMultiply Lib "Bcdll.dll" (ByVal num1 As Integer, ByVal num2 As Long) As Long
 Private Declare Function VBAverage Lib "Bcdll.dll" (ByVal num1 As Double, ByVal num2 As Single) As Double
 


Private Sub cmdAverage_Click()
    Dim num1 As Double
    Dim num2 As Single
    
    num1 = 6232.001
    num2 = 128.327
    
    MsgBox "The Average of 6232.001 and 128.327 is : " & VBAverage(num1, num2), vbOKOnly, "Visual Basic"
    
End Sub

Private Sub cmdClose_Click()
    Unload Form1
End Sub

Private Sub cmdExceptionTest_Click()
    
    Call VBExceptionTest

End Sub

Private Sub cmdMessage_Click()

        VBMessage ("A message from Visual Basic")

End Sub


Private Sub cmdMultiply_Click()
    
    MsgBox "55 * -1024 = " & VBMultiply(55, -1024), vbOKOnly, "Visual Basic"
    
End Sub


Private Sub cmdUnhandled_Click()
    'Note that VB does not have exception handling capabilities.
    'The exception will be passed from the DLL to the Visual Basic app and cause the application to terminate.
    
    result = MsgBox("Visual Basic is not able to catch exceptions. If you continue the application will terminate. Do you wish to continue?", vbYesNo + vbExclamation + vbApplicationModal, "Visual Basic")
    
    If result = vbYes Then
        Call VBUnhandledException
    Else
        MsgBox "Exception was not thrown.", vbOKOnly, "Visual Basic"
    End If
    
End Sub












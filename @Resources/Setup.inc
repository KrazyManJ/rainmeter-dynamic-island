[Rainmeter]
    @Include=#@#Vars.inc
    Update=1
    DynamicVariables=1
    SkinWidth=(#C_SKIN_WIDTH#+#C_SKIN_MARGIN#*2)
    SkinHeight=(#C_SKIN_HEIGHT#+#C_SKIN_MARGIN#*2)
    ; OnRefreshAction=[!UnpauseMeasure Transition] ;Open on start (Debug)
;
; ======================================================================================
;   CONTEXT MENU
; ======================================================================================
;
    RightMouseUpAction=[!SkinCustomMenu]
    ContextTitle=Battery
    ContextAction=[!ActivateConfig #CURRENTCONFIG# "DI_Battery.ini"]
    ContextTitle2=Compact (Custom)
    ContextAction2=[!ActivateConfig #CURRENTCONFIG# "DI_Custom_Compact.ini"]
    ContextTitle3=Music
    ContextAction3=[!ActivateConfig #CURRENTCONFIG# "DI_Music.ini"]
    ContextTitle4=Volume
    ContextAction4=[!ActivateConfig #CURRENTCONFIG# "DI_Volume.ini"]
    ContextTitle5=----
    ContextAction5=[]
    ContextTitle6=Center
    ContextAction6=[!Move (#PSCREENAREAWIDTH#/2-#C_SKIN_WIDTH#/2-#C_SKIN_MARGIN#) 0]
    ContextTitle7=Rainmeter...
    ContextAction7=[!SkinMenu]
;
; ======================================================================================
;   INITIALIZE VARIABLES
; ======================================================================================
;
[Variables]
    ; Change these values depending on size of largest widget
        C_SKIN_WIDTH=600
        C_SKIN_HEIGHT=250
        C_SKIN_MARGIN=10
    
    ; This section needs to be included in widgets including this file
        C_CLOSED_W=0
        C_CLOSED_H=0
        C_OPENED_W=0
        C_OPENED_H=0
        C_PREV_TYPE=""
        C_NEXT_TYPE=""

    ; Other Variables / Constants
        FONTFACE=SF Pro Display
        C_HALF=(#C_SKIN_MARGIN#+#C_SKIN_WIDTH#/2)
        V_CUR_W=(#C_CLOSED_W#+[Transition]*((#C_OPENED_W#-#C_CLOSED_W#)/100))
        V_CUR_H=(#C_CLOSED_H#+[Transition]*((#C_OPENED_H#-#C_CLOSED_H#)/100))
        V_CUR_BORDER=(#C_CLOSED_H#/2+([Transition]/500*(#C_OPENED_H#-#C_CLOSED_H#)))
        V_CUR_X=(#C_SKIN_MARGIN#+(#C_SKIN_WIDTH#-#V_CUR_W#)/2)
        V_CUR_Y=#C_SKIN_MARGIN#
;
; ======================================================================================
;   Functions
; ======================================================================================
;

;
; Function to calculate byte value from transition
; Useful for color values
;
[F_ByteTransition]
    Measure=Calc
    Formula=[&Script:Map([&Transition],0,100,0,255)]
    DynamicVariables=1

;
; ======================================================================================
;   TRANSITION
; ======================================================================================
;
    [FadeInvertor]
        Measure=Calc
        IfCondition=Transition = 100
        IfTrueAction=[!SetOption Transition InvertMeasure 1][!PauseMeasure Transition][!ShowMeterGroup Big]
        IfCondition2=Transition = 0
        IfTrueAction2=[!SetOption Transition InvertMeasure 0][!PauseMeasure Transition][!HideMeterGroup Big]
    [Transition]
        Measure=Loop
        StartValue=0
        EndValue=100
        Increment=15
        LoopCount=1
        Paused=1
;
; ======================================================================================
;   ISLAND
; ======================================================================================
;
    [ClickTriggerRegion]
        Meter=Shape
        Shape=Rectangle #V_CUR_X#,#V_CUR_Y#,#V_CUR_W#,#C_CLOSED_H#,#V_CUR_BORDER# | Fill Color 0,0,0,0 | StrokeWidth 0
        LeftMouseUpAction=[!CommandMeasure Transition "Reset"][!UnpauseMeasure Transition][!ToggleMeterGroup Big]
        MouseScrollDownAction=[!ActivateConfig #CURRENTCONFIG# #C_NEXT_TYPE#]
        MouseScrollUpAction=[!ActivateConfig #CURRENTCONFIG# #C_PREV_TYPE#]
        DynamicVariables=1

    [Island]
        Meter=Shape
        Shape=Rectangle #V_CUR_X#,#V_CUR_Y#,#V_CUR_W#,#V_CUR_H#,#V_CUR_BORDER# | Fill Color 0,0,0 | StrokeWidth 0
        DynamicVariables=1
    [Script]
        Measure=Script
        ScriptFile=#@#Script.lua
        Disabled=1

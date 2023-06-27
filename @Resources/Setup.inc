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
    ContextTitle4=----
    ContextAction4=[]
    ContextTitle5=Center
    ContextAction5=[!Move (#PSCREENAREAWIDTH#/2-#C_SKIN_WIDTH#/2-#C_SKIN_MARGIN#) 0]
    ContextTitle6=Rainmeter...
    ContextAction6=[!SkinMenu]

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
        Shape=Rectangle #V_CUR_X#,#V_CUR_Y#,#V_CUR_W#,#V_CUR_H#,#V_CUR_BORDER# | Fill Color 0,0,0,180 | StrokeWidth 0
        DynamicVariables=1
    [Script]
        Measure=Script
        ScriptFile=#@#Script.lua
        Disabled=1
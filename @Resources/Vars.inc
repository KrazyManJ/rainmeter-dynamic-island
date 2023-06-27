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
; Function to calculate byte value from transition
; Useful for color values
;
[F_ByteTransition]
    Measure=Calc
    Formula=[&Script:Map([&Transition],0,100,0,255)]
    DynamicVariables=1
function Map(value, fMin, fMax, tMin, tMax)
    return (value - fMin) * (tMax - tMin) / (fMax - fMin) + tMin;
end

function Ternary(cond, one, elseVal)
    if cond then return elseVal else return one end
end

function ToggleConfigValue(varName, varVal, firstVal, secondVal)
    local var = Ternary(varVal == firstVal, firstVal, secondVal)
    SKIN:Bang("!WriteKeyValue", "Variables", varName, var, "#@#Config.inc")
    SKIN:Bang("!SetVariable", varName, var)
end
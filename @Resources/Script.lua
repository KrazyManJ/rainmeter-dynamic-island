function Map(value, fMin, fMax, tMin, tMax)
    return (value - fMin) * (tMax - tMin) / (fMax - fMin) + tMin;
end

function Ternary(cond, one, elseVal)
    if cond then
        return one
    else
        return elseVal
    end
end

function ToggleConfigValue(varName, varVal, firstVal, secondVal)
    local var = Ternary(varVal == firstVal, secondVal, firstVal)
    SKIN:Bang("!WriteKeyValue", "Variables", varName, var, "#@#Config.inc")
    SKIN:Bang("!SetVariable", varName, var)
end

function ColorToString(r, g, b, a) return math.floor(r) .. "," .. math.floor(g) .. "," .. math.floor(b) .. "," .. math.floor(a) end

function ColorShade(r1, g1, b1, a1, r2, g2, b2, a2)
    return (r1 + r2) / 2, (g1 + g2) / 2, (b1 + b2) / 2, (a1 + a2) / 2
end

function GetLuminance(r, g, b) return (0.2126 * r + 0.7152 * g + 0.0722 * b) end

function LightenIfDark(r, g, b, a)
    if GetLuminance(r, g, b) < 55 then
        return (r + 255) / 2, (g + 255) / 2, (b + 255) / 2, a
    else
        return r, g, b, a
    end
end

function ColorShadeAndLighten(r1, g1, b1, a1, r2, g2, b2, a2)
    local rl1, gl1, bl1, al1 = LightenIfDark(r1,g1,b1,a1)
    local rl2, gl2, bl2, al2 = LightenIfDark(r2,g2,b2,a2)
    return ColorToString(ColorShade(rl1,gl1,bl1,al1,rl2,gl2,bl2,al2))
end

function LightenIfDarkString(r,g,b,a) 
    return ColorToString(LightenIfDark(r,g,b,a)) 
end